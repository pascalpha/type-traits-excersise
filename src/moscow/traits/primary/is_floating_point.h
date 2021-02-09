//
// Created by mamin on 2/8/2021.
//
#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_IS_FLOATING_POINT_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_IS_FLOATING_POINT_H

#include "moscow/traits/const_volatility/remove_cv.h"
#include "moscow/traits/helper.h"

namespace moscow {
namespace detail {
template<typename> struct is_floating_point_impl : false_type {};
template<> struct is_floating_point_impl<float> : true_type {};
template<> struct is_floating_point_impl<double> : true_type {};
template<> struct is_floating_point_impl<long double> : true_type {};
} // namespace detail

/**
 * checks whether T is a floating point type
 */
template<typename T> using is_floating_point = detail::is_floating_point_impl<remove_cv_t<T>>;

/**
 * value helper for is_floating_point
 * @tparam T
 */
moscow_value_helper(is_floating_point);
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_FLOATING_POINT_H
