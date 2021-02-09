//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_MISC_DISABLE_IF_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_MISC_DISABLE_IF_H

namespace moscow {
/**
 * succeeded template dispatcher
 * @tparam T
 */
template<bool, typename T = void> struct disable_if { using type = T; };
/**
 * failed template dispatcher
 * @tparam T
 */
template<typename T> struct disable_if<true, T> {};

/**
 * helper template alias for template dispatcher
 */
template<bool B, typename T> using disable_if_t = typename disable_if<B, T>::type;
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_MISC_DISABLE_IF_H
