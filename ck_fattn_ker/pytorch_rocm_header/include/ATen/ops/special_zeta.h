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



#include <ATen/ops/special_zeta_ops.h>

namespace at {


// aten::special_zeta(Tensor self, Tensor other) -> Tensor
inline at::Tensor special_zeta(const at::Tensor & self, const at::Tensor & other) {
    return at::_ops::special_zeta::call(self, other);
}

// aten::special_zeta.self_scalar(Scalar self, Tensor other) -> Tensor
inline at::Tensor special_zeta(const at::Scalar & self, const at::Tensor & other) {
    return at::_ops::special_zeta_self_scalar::call(self, other);
}

// aten::special_zeta.other_scalar(Tensor self, Scalar other) -> Tensor
inline at::Tensor special_zeta(const at::Tensor & self, const at::Scalar & other) {
    return at::_ops::special_zeta_other_scalar::call(self, other);
}

// aten::special_zeta.out(Tensor self, Tensor other, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & special_zeta_out(at::Tensor & out, const at::Tensor & self, const at::Tensor & other) {
    return at::_ops::special_zeta_out::call(self, other, out);
}
// aten::special_zeta.out(Tensor self, Tensor other, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & special_zeta_outf(const at::Tensor & self, const at::Tensor & other, at::Tensor & out) {
    return at::_ops::special_zeta_out::call(self, other, out);
}

// aten::special_zeta.self_scalar_out(Scalar self, Tensor other, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & special_zeta_out(at::Tensor & out, const at::Scalar & self, const at::Tensor & other) {
    return at::_ops::special_zeta_self_scalar_out::call(self, other, out);
}
// aten::special_zeta.self_scalar_out(Scalar self, Tensor other, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & special_zeta_outf(const at::Scalar & self, const at::Tensor & other, at::Tensor & out) {
    return at::_ops::special_zeta_self_scalar_out::call(self, other, out);
}

// aten::special_zeta.other_scalar_out(Tensor self, Scalar other, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & special_zeta_out(at::Tensor & out, const at::Tensor & self, const at::Scalar & other) {
    return at::_ops::special_zeta_other_scalar_out::call(self, other, out);
}
// aten::special_zeta.other_scalar_out(Tensor self, Scalar other, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & special_zeta_outf(const at::Tensor & self, const at::Scalar & other, at::Tensor & out) {
    return at::_ops::special_zeta_other_scalar_out::call(self, other, out);
}

}
