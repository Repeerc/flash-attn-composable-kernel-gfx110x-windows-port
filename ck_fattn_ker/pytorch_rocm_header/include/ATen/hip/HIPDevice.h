// !!! This is a file automatically generated by hipify!!!
#pragma once

#include <ATen/hip/Exceptions.h>

#include <hip/hip_runtime.h>
#include <hip/hip_runtime.h>

namespace at::cuda {

inline Device getDeviceFromPtr(void* ptr) {
  hipPointerAttribute_t attr{};

  AT_CUDA_CHECK(hipPointerGetAttributes(&attr, ptr));

#if !defined(USE_ROCM)
  TORCH_CHECK(attr.type != cudaMemoryTypeUnregistered,
    "The specified pointer resides on host memory and is not registered with any CUDA device.");
#endif

  return {c10::DeviceType::CUDA, static_cast<DeviceIndex>(attr.device)};
}

} // namespace at::cuda
