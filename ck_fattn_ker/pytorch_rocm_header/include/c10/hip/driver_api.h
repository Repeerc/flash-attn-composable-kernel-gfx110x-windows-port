// !!! This is a file automatically generated by hipify!!!
#pragma once
#include <hip/hip_runtime.h>
#define NVML_NO_UNVERSIONED_FUNC_DEFS
#include <rocm_smi/rocm_smi.h>

#define C10_HIP_DRIVER_CHECK(EXPR)                                        \
  do {                                                                     \
    hipError_t __err = EXPR;                                                 \
    if (__err != hipSuccess) {                                           \
      const char* err_str;                                                 \
      hipError_t get_error_str_err C10_UNUSED =                              \
          c10::hip::DriverAPI::get()->hipDrvGetErrorString_(__err, &err_str); \
      if (get_error_str_err != hipSuccess) {                             \
        AT_ERROR("HIP driver error: unknown error");                      \
      } else {                                                             \
        AT_ERROR("HIP driver error: ", err_str);                          \
      }                                                                    \
    }                                                                      \
  } while (0)

#define C10_LIBHIP_DRIVER_API(_) \
  _(cuMemAddressReserve)          \
  _(cuMemRelease)                 \
  _(cuMemMap)                     \
  _(cuMemAddressFree)             \
  _(cuMemSetAccess)               \
  _(cuMemUnmap)                   \
  _(cuMemCreate)                  \
  _(hipDrvGetErrorString)

#define C10_NVML_DRIVER_API(_)        \
  _(nvmlInit_v2)                      \
  _(nvmlDeviceGetHandleByPciBusId_v2) \
  _(nvmlDeviceGetComputeRunningProcesses)

namespace c10 {
namespace hip {

struct DriverAPI {
#define CREATE_MEMBER(name) decltype(&name) name##_;
  C10_LIBHIP_DRIVER_API(CREATE_MEMBER)
  C10_NVML_DRIVER_API(CREATE_MEMBER)
#undef CREATE_MEMBER
  static DriverAPI* get();
  static void* get_nvml_handle();
};

} // namespace hip
} // namespace c10
