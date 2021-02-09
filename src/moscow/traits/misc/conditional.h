//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_MISC_CONDITIONAL_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_MISC_CONDITIONAL_H

namespace moscow {
/**
 * template dispatcher, else clause
 * @tparam T
 */
template<bool, typename Then, typename Else> struct conditional { using type = Else; };
/**
 * template dispatcher, then clause
 * @tparam Then
 * @tparam Else
 */
template<typename Then, typename Else> struct conditional<true, Then, Else> { using type = Then; };

/**
 * helper template alias for template dispatcher
 */
template<bool If, typename Then, typename Else> using conditional_t = typename conditional<If, Then, Else>::type;

} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_MISC_CONDITIONAL_H
