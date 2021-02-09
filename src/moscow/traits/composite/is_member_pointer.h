//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_COMPOSITE_IS_MEMBER_POINTER_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_COMPOSITE_IS_MEMBER_POINTER_H

#include "moscow/traits/traits.h"
#include "moscow/traits/primary/is_function.h"
#include "moscow/traits/const_volatility/remove_cv.h"

namespace moscow {
namespace detail {
template<typename T> struct is_member_pointer_impl {
  static constexpr bool is_member = false;
  static constexpr bool is_func = false;
  static constexpr bool is_obj = false;
};

template<typename T, typename U> struct is_member_pointer_impl<T U::*> {
  static constexpr bool is_member = true;
  static constexpr bool is_func = is_function_v<T>;
  static constexpr bool is_obj = !is_func;
};
} // namespace detail
/**
 * \brief defines value = true if T is a member pointer
 */
template<typename T>
using is_member_pointer = bool_constant<detail::is_member_pointer_impl<remove_cv_t < T>>::is_member>;

/**
 * \brief value helper for is_member_pointer
 * \tparam T
 */
moscow_value_helper(is_member_pointer);
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_COMPOSITE_IS_MEMBER_POINTER_H
