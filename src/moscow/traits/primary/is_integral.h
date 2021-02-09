//
// Created by mamin on 2/8/2021.
//
#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PRIMARY_IS_INTEGRAL_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PRIMARY_IS_INTEGRAL_H

#include "moscow/traits/const_volatility/remove_cv.h"
#include "moscow/traits/helper.h"

namespace moscow {
namespace detail {
template<typename> struct is_integral_impl : false_type {};
template<> struct is_integral_impl<bool> : true_type {};
template<> struct is_integral_impl<char> : true_type {};
template<> struct is_integral_impl<unsigned char> : true_type {};
template<> struct is_integral_impl<char16_t> : true_type {};
template<> struct is_integral_impl<char32_t> : true_type {};
template<> struct is_integral_impl<wchar_t> : true_type {};
template<> struct is_integral_impl<short> : true_type {};
template<> struct is_integral_impl<unsigned short> : true_type {};
template<> struct is_integral_impl<int> : true_type {};
template<> struct is_integral_impl<unsigned int> : true_type {};
template<> struct is_integral_impl<long> : true_type {};
template<> struct is_integral_impl<unsigned long> : true_type {};
template<> struct is_integral_impl<long long> : true_type {};
template<> struct is_integral_impl<unsigned long long> : true_type {};
} // namespace detail

/**
 * checks whether T is an integral type
 * @tparam T
 */
template<typename T> using is_integral = detail::is_integral_impl<remove_cv_t < T>>;

/**
 * value helper for is_integral
 * @tparam T
 */
moscow_value_helper(is_integral);
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PRIMARY_IS_INTEGRAL_H
