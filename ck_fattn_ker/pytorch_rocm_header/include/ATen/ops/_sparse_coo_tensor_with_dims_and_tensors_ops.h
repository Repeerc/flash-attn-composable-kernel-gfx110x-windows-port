#pragma once

// @generated by torchgen/gen.py from Operator.h

#include <tuple>
#include <vector>

// Forward declarations of any types needed in the operator signatures.
// We can't directly include these classes because it will cause circular include dependencies.
// This file is included by TensorBody.h, which defines the Tensor class.
#include <ATen/core/ATen_fwd.h>

namespace at {
namespace _ops {


struct TORCH_API _sparse_coo_tensor_with_dims_and_tensors {
  using schema = at::Tensor (int64_t, int64_t, c10::SymIntArrayRef, const at::Tensor &, const at::Tensor &, c10::optional<at::ScalarType>, c10::optional<at::Layout>, c10::optional<at::Device>, c10::optional<bool>, c10::optional<bool>);
  using ptr_schema = schema*;
  // See Note [static constexpr char* members for windows NVCC]
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(name, "aten::_sparse_coo_tensor_with_dims_and_tensors")
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(overload_name, "")
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(schema_str, "_sparse_coo_tensor_with_dims_and_tensors(int sparse_dim, int dense_dim, SymInt[] size, Tensor indices, Tensor values, *, ScalarType? dtype=None, Layout? layout=None, Device? device=None, bool? pin_memory=False, bool? is_coalesced=None) -> Tensor")
  static at::Tensor call(int64_t sparse_dim, int64_t dense_dim, c10::SymIntArrayRef size, const at::Tensor & indices, const at::Tensor & values, c10::optional<at::ScalarType> dtype, c10::optional<at::Layout> layout, c10::optional<at::Device> device, c10::optional<bool> pin_memory, c10::optional<bool> is_coalesced);
  static at::Tensor redispatch(c10::DispatchKeySet dispatchKeySet, int64_t sparse_dim, int64_t dense_dim, c10::SymIntArrayRef size, const at::Tensor & indices, const at::Tensor & values, c10::optional<at::ScalarType> dtype, c10::optional<at::Layout> layout, c10::optional<at::Device> device, c10::optional<bool> pin_memory, c10::optional<bool> is_coalesced);
};

struct TORCH_API _sparse_coo_tensor_with_dims_and_tensors_out {
  using schema = at::Tensor & (int64_t, int64_t, c10::SymIntArrayRef, const at::Tensor &, const at::Tensor &, c10::optional<bool>, at::Tensor &);
  using ptr_schema = schema*;
  // See Note [static constexpr char* members for windows NVCC]
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(name, "aten::_sparse_coo_tensor_with_dims_and_tensors")
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(overload_name, "out")
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(schema_str, "_sparse_coo_tensor_with_dims_and_tensors.out(int sparse_dim, int dense_dim, SymInt[] size, Tensor indices, Tensor values, *, bool? is_coalesced=None, Tensor(a!) out) -> Tensor(a!)")
  static at::Tensor & call(int64_t sparse_dim, int64_t dense_dim, c10::SymIntArrayRef size, const at::Tensor & indices, const at::Tensor & values, c10::optional<bool> is_coalesced, at::Tensor & out);
  static at::Tensor & redispatch(c10::DispatchKeySet dispatchKeySet, int64_t sparse_dim, int64_t dense_dim, c10::SymIntArrayRef size, const at::Tensor & indices, const at::Tensor & values, c10::optional<bool> is_coalesced, at::Tensor & out);
};

}} // namespace at::_ops