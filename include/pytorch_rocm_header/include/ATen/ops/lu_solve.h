#pragma once

// @generated by torchgen/gen.py from Function.h

#include <ATen/Context.h>
#include <ATen/DeviceGuard.h>
#include <ATen/TensorUtils.h>
#include <ATen/TracerMode.h>
#include <ATen/core/Generator.h>
#include <ATen/core/Reduction.h>
#include <ATen/core/Tensor.h>
#include <c10/core/Scalar.h>
#include <c10/core/Storage.h>
#include <c10/core/TensorOptions.h>
#include <c10/util/Deprecated.h>
#include <c10/util/Optional.h>



#include <ATen/ops/lu_solve_ops.h>

namespace at {


// aten::lu_solve.out(Tensor self, Tensor LU_data, Tensor LU_pivots, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & lu_solve_out(at::Tensor & out, const at::Tensor & self, const at::Tensor & LU_data, const at::Tensor & LU_pivots) {
    return at::_ops::lu_solve_out::call(self, LU_data, LU_pivots, out);
}
// aten::lu_solve.out(Tensor self, Tensor LU_data, Tensor LU_pivots, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & lu_solve_outf(const at::Tensor & self, const at::Tensor & LU_data, const at::Tensor & LU_pivots, at::Tensor & out) {
    return at::_ops::lu_solve_out::call(self, LU_data, LU_pivots, out);
}

// aten::lu_solve(Tensor self, Tensor LU_data, Tensor LU_pivots) -> Tensor
inline at::Tensor lu_solve(const at::Tensor & self, const at::Tensor & LU_data, const at::Tensor & LU_pivots) {
    return at::_ops::lu_solve::call(self, LU_data, LU_pivots);
}

}