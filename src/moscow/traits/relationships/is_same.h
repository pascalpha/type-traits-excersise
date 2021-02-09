//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_RELATIONSHIPS_IS_SAME_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_RELATIONSHIPS_IS_SAME_H

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
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_RELATIONSHIPS_IS_SAME_H
