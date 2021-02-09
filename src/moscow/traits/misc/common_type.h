//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_MISC_COMMON_TYPE_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_MISC_COMMON_TYPE_H

#include "moscow/traits/traits.h"
#include "moscow/traits/typedef/void_t.h"
#include "moscow/traits/misc/declval.h"
#include "moscow/traits/misc/decay.h"

namespace moscow {
/**
 * extract common type of a set of types
 * @tparam ...
 */
template<typename...> struct common_type {};

/**
 * extract common type of a single type
 * @tparam T
 */
template<typename T> struct common_type<T> { using type = T; };

namespace detail {
/**
 * obtain result type for ternary operator
 */
template<typename T, typename U> using ternary_result = decltype(declval<bool>() ? declval<T>() : declval<U>());
/**
 * two way common type implementation
 * @tparam T
 * @tparam U
 */
template<typename T, typename U, typename = void> struct common_type_impl {};
/**
 * two way common type implementation, ternary result available for two types
 * @tparam T
 * @tparam U
 */
template<typename T, typename U>
struct common_type_impl<T, U, void_t<ternary_result<T, U>>> { using type = decay_t<ternary_result<T, U>>; };
/**
 * multi-way common type implementation
 * @tparam Dummy
 * @tparam T
 * @tparam U
 * @tparam R
 */
template<typename Dummy, typename T, typename U, typename ... R> struct common_type_multi_impl {};
/**
 * multi-way common type implementation, common type available for the first two types
 * @tparam T
 * @tparam U
 * @tparam R
 */
template<typename T, typename U, typename ... R>
struct common_type_multi_impl<void_t<typename common_type<T, U>::type>, T, U, R...>
    : common_type<typename common_type<T, U>::type, R...> {
};
} // namespace detail
/**
 * common type of two types possibly decayed
 * @tparam T
 * @tparam U
 */
template<typename T, typename U> struct common_type<T, U> : detail::common_type_impl<decay_t<T>, decay_t<U>> {};
/**
 * common type of multiple types possibly decayed
 * @tparam T
 * @tparam U
 * @tparam R
 */
template<typename T, typename U, typename... R>
struct common_type<T, U, R...> : detail::common_type_multi_impl<void, T, U, R...> {};
/**
 * type helper for common_type
 */
template<typename... T>
using common_type_t = typename common_type<T...>::type;
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_MISC_COMMON_TYPE_H
