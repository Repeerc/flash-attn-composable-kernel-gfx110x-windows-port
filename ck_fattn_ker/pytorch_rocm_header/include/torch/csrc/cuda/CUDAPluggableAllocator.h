#pragma once

#include <c10/core/Allocator.h>
#include <c10/hip/HIPGraphsC10Utils.h>
#include <c10/hip/HIPMacros.h>
#include <ATen/hip/impl/HIPStreamMasqueradingAsCUDA.h>

#include <ATen/hip/impl/HIPCachingAllocatorMasqueradingAsCUDA.h>

#include <array>
#include <mutex>

namespace torch::cuda::CUDAPluggableAllocator {

#if defined(TORCH_HIP_VERSION)
using streamType = c10::hip::HIPStream;
#else
using streamType = c10::hip::HIPStreamMasqueradingAsCUDA;
#endif

std::shared_ptr<c10::hip::HIPCachingAllocator::HIPAllocator>
getCurrentAllocator();
std::shared_ptr<c10::hip::HIPCachingAllocator::HIPAllocator>
createCustomAllocator(
    std::function<void*(size_t, int, hipStream_t)> alloc_fn,
    std::function<void(void*, size_t, int, hipStream_t)> free_fn);
void changeCurrentAllocator(
    const std::shared_ptr<c10::hip::HIPCachingAllocator::HIPAllocator>&
        allocator);

struct _AllocationMetadata {
  _AllocationMetadata();
  _AllocationMetadata(size_t size, int device_idx, hipStream_t stream);
  size_t size;
  int device_idx;
  hipStream_t stream;
};

struct CUDAPluggableAllocator
    : public c10::hip::HIPCachingAllocator::HIPAllocator {
  CUDAPluggableAllocator(
      std::function<void*(size_t, int, hipStream_t)> alloc_fn,
      std::function<void(void*, size_t, int, hipStream_t)> free_fn);

  CUDAPluggableAllocator(CUDAPluggableAllocator& other);

  void set_init_fn(std::function<void(int)> init_fn);

  void set_reset_fn(std::function<void()> reset_fn);

  void set_memory_fraction_fn(
      std::function<void(double, int)> memory_fraction_fn);

  void set_base_alloc_fn(std::function<void*(void*, size_t*)> base_alloc_fn);

  void set_record_stream_fn(
      std::function<void(void* ptr, hipStream_t stream)> record_stream_fn);

  void set_begin_allocate_stream_to_pool(
      std::function<void(int, hipStream_t, c10::hip::MempoolId_t)>
          capture_begin_fn);

  void set_end_allocate_stream_to_pool_fn(
      std::function<void(int, hipStream_t)> capture_about_to_end_fn);

  void set_release_pool(
      std::function<void(int, c10::hip::MempoolId_t)> capture_destroy_fn);

  void* malloc(size_t size, int device, hipStream_t stream);

  c10::DataPtr allocate(size_t size) const override;
  c10::DeleterFnPtr raw_deleter() const override;

  void* raw_alloc(size_t nbytes) override;
  void* raw_alloc_with_stream(size_t nbytes, hipStream_t stream) override;
  void raw_delete(void* ptr) override;
  void init(int device_count) override;
  bool initialized() override;
  void setMemoryFraction(double fraction, int device) override;
  void emptyCache() override;
  void cacheInfo(int dev_id, size_t* largestBlock) override;
  void* getBaseAllocation(void* ptr, size_t* size) override;

  void recordStream(const c10::DataPtr&, streamType stream) override;

  c10::hip::HIPCachingAllocator::DeviceStats getDeviceStats(
      int device) override;
  void resetAccumulatedStats(int device) override;
  void resetPeakStats(int device) override;
  c10::hip::HIPCachingAllocator::SnapshotInfo snapshot() override;
  void beginAllocateStreamToPool(
      int device,
      hipStream_t stream,
      c10::hip::MempoolId_t mempool_id) override;
  void endAllocateStreamToPool(int device, hipStream_t stream) override;
  void releasePool(int device, c10::hip::MempoolId_t mempool_id) override;
  std::shared_ptr<void> getIpcDevPtr(std::string handle) override;
  void recordHistory(
      bool enabled,
      c10::hip::HIPCachingAllocator::CreateContextFn context_recorder,
      size_t alloc_trace_max_entries,
      c10::hip::HIPCachingAllocator::RecordContext when) override;
  void attachOutOfMemoryObserver(
      c10::hip::HIPCachingAllocator::OutOfMemoryObserver observer) override;
  void attachAllocatorTraceTracker(
      c10::hip::HIPCachingAllocator::AllocatorTraceTracker tracker) override;
  std::shared_ptr<c10::hip::HIPCachingAllocator::AllocatorState>
  getCheckpointState(int device, at::cuda::MempoolId_t id) override;
  c10::hip::HIPCachingAllocator::CheckpointDelta setCheckpointPoolState(
      int device,
      std::shared_ptr<c10::hip::HIPCachingAllocator::AllocatorState> pps)
      override;
  void enablePeerAccess(int dev, int dev_to_access) override;
  hipError_t memcpyAsync(
      void* dst,
      int dstDevice,
      const void* src,
      int srcDevice,
      size_t count,
      hipStream_t stream,
      bool p2p_enabled) override;
  std::string name() override;

 protected:
  std::function<void*(size_t, int, hipStream_t)> alloc_fn_;
  std::function<void(void*, size_t, int, hipStream_t)> free_fn_;
  std::function<void(int)> init_fn_;
  std::function<void()> reset_fn_;
  std::function<void(double, int)> memory_fraction_fn_;
  std::function<void*(void*, size_t*)> base_alloc_fn_;
  std::function<void(void* ptr, hipStream_t stream)> record_stream_fn_;
  std::function<void(int, hipStream_t, c10::hip::MempoolId_t)>
      begin_allocate_stream_to_pool_fn_;
  std::function<void(int, hipStream_t)> end_allocate_stream_to_pool_fn_;
  std::function<void(int, c10::hip::MempoolId_t)> relase_pool_fn_;
  std::mutex allocator_mutex_;
  // We do the bookeeping here in order to simplify custom allocators
  std::unordered_map<void*, _AllocationMetadata> allocation_metadata_;

  bool initialized_ = false;
};
} // namespace torch::cuda::CUDAPluggableAllocator