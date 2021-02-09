//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PRIMARY_IS_POINTER_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PRIMARY_IS_POINTER_H

#include "moscow/traits/traits.h"
#include "moscow/traits/const_volatility/remove_cv.h"

namespace moscow {
namespace detail {
/**
 * \brief failed pointer check
 * \tparam T
 */
template<typename T> struct is_pointer_impl : false_type {};
/**
 * \brief succeeded pointer check
 * \tparam T
 */
template<typename T> struct is_pointer_impl<T *> : true_type {};
} // namespace detail
/**
 * \brief defines value = true if T is a possibly cv qualified pointer.
 * This by definition excludes nullptr_t
 */
template<typename T> using is_pointer = detail::is_pointer_impl<remove_cv_t<T>>;

/**
 * \brief value helper for is_pointer
 * \tparam T
 */
moscow_value_helper(is_pointer);
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PRIMARY_IS_POINTER_H
