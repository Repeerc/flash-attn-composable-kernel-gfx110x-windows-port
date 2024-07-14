// !!! This is a file automatically generated by hipify!!!
#pragma once
// this file is to avoid circular dependency between HIPFunctions.h and
// HIPExceptions.h

#include <c10/hip/HIPMacros.h>

#include <mutex>

namespace c10 {
namespace hip {
C10_HIP_API const char* get_hip_check_suffix() noexcept;
C10_HIP_API std::mutex* getFreeMutex();
} // namespace hip
} // namespace c10