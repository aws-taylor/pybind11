#pragma once

#include "common.h"

#include <type_traits>

#ifndef PYBIND11_USE_SMART_HOLDER_AS_DEFAULT
// #define PYBIND11_USE_SMART_HOLDER_AS_DEFAULT
// Currently the main purpose of this switch is to enable non-intrusive comprehensive testing. If
// and when `smart_holder` will actually become the released default is currently open. In the
// meantime, the full functionality is easily available by using `py::classh`, which is just a
// handy shortcut for `py::class_<T, py::smart_holder>` (see `pybind11/smart_holder.h`). Classes
// wrapped in this way are fully compatible with everything existing.
#endif

PYBIND11_NAMESPACE_BEGIN(PYBIND11_NAMESPACE)
PYBIND11_NAMESPACE_BEGIN(detail)

template <typename T>
struct is_smart_holder_type : std::false_type {};

// Tag to be used as base class, inspected by is_smart_holder_type_caster<T> test.
struct is_smart_holder_type_caster_base_tag {};

template <typename T>
struct is_smart_holder_type_caster;

PYBIND11_NAMESPACE_END(detail)
PYBIND11_NAMESPACE_END(PYBIND11_NAMESPACE)
