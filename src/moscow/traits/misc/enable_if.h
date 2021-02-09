//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_MISC_ENABLE_IF_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_MISC_ENABLE_IF_H

namespace moscow {
/**
 * failed template dispatcher
 * @tparam T
 */
template<bool, typename T = void> struct enable_if {};
/**
 * succeeded template dispatcher
 * @tparam T
 */
template<typename T> struct enable_if<true, T> { using type = T; };

/**
 * helper template alias for template dispatcher
 */
template<bool B, typename T> using enable_if_t = typename enable_if<B, T>::type;
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_MISC_ENABLE_IF_H
