//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PRIMARY_IS_CLASS_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PRIMARY_IS_CLASS_H

#include "moscow/traits/helper.h"
#include "moscow/traits/primary/is_union.h"

namespace moscow {
namespace detail {
/**
 * \brief function template accepting class / union type
 * \tparam T
 */
template<typename T> auto is_class_or_union_impl(int T::*) -> void;
/**
 * \brief function template accepting other types
 * \tparam T
 * \param ...
 * \return
 */
template<typename T> auto is_class_or_union_impl(...) -> void *;
} // namespace detail
/**
 * \brief defines value = true if T is class
 */
template<typename T>
using is_class = bool_constant<is_same_v<void, decltype(detail::is_class_or_union_impl<T>(0))> && !is_union_v<T>>;

/**
 * \brief value helper for is_class
 * \tparam T
 */
moscow_value_helper(is_class);
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PRIMARY_IS_CLASS_H
