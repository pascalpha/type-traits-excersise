//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_RELATIONSHIPS_IS_SAME_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_RELATIONSHIPS_IS_SAME_H

#include "moscow/traits/misc/remove_cvref.h"

namespace moscow {
/**
 * failed identity checker
 * @tparam T
 * @tparam U
 */
template<typename T, typename U> struct is_same : false_type {};
/**
 * succeeded identity checker
 * @tparam T
 */
template<typename T> struct is_same<T, T> : true_type {};

/**
 * helper template alias for identity checker
 */
template<typename T, typename U>
bool constexpr is_same_v = is_same<T, U>::value;

/**
 * \brief defines value = true if two types are the same regardless of cv qualifiers and references
 */
template<typename T, typename U> using is_uncvref_same = is_same<remove_cvref_t<T>, remove_cvref_t<U>>;

/**
 * \brief value helper for is_uncvref_same
 * \tparam T
 * \tparam U
 */
template<typename T, typename U> bool constexpr is_uncvref_same_v = is_uncvref_same<T, U>::value;
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_RELATIONSHIPS_IS_SAME_H
