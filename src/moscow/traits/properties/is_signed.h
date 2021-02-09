//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PROPERTIES_IS_SIGNED_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PROPERTIES_IS_SIGNED_H

#include "moscow/traits/traits.h"
#include "moscow/traits/primary/is_integral.h"
#include "moscow/traits/composite/is_arithmetic.h"

namespace moscow {
namespace detail {
/**
 * \brief is signed integer
 * \tparam T
 */
template<typename T, bool = is_integral_v<T>> struct is_signed_arithmetic_impl : bool_constant<T(-1) < T(0)> {};
/**
 * \brief is floating point
 * \tparam T
 */
template<typename T> struct is_signed_arithmetic_impl<T, false> : true_type {};
/**
 * \brief is arithmetic
 * \tparam T
 */
template<typename T, bool = is_arithmetic_v<T>> struct is_signed_impl : is_signed_arithmetic_impl<T> {};
/**
 * \brief is not arithmetic
 * \tparam T
 */
template<typename T> struct is_signed_impl<T, false> : false_type {};
} // namespace detail

/**
 * \brief defines value = true if T is signed arithmetic type
 */
template<typename T> using is_signed = detail::is_signed_impl<T>;

/**
 * \brief value helper for is_signed
 * \tparam T
 */
moscow_value_helper(is_signed);
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PROPERTIES_IS_SIGNED_H
