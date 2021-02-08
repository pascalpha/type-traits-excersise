//
// Created by admin on 2021/2/8.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_HELPER_H_
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_HELPER_H_

/**
 * \brief integral constant type
 * \tparam T
 * \tparam v
 */
template<typename T, T v> struct integral_constant {
  constexpr static const value = v;

  using value_type = T;
  using type = integral_constant;
  inline constexpr value_type operator()() const noexcept { return value; }
};

/**
 * \brief bool constant type
 */
template<bool B> using bool_constant = integral_constant<bool, B>;

/**
 * \brief true type
 */
using true_type = bool_constant<true>;

/**
 * \brief false type
 */
using false_type = bool_constant<false>;

namespace detail {
  
} // namespace detail

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_HELPER_H_
