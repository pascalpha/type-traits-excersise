//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_POINTERS_ADD_POINTER_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_POINTERS_ADD_POINTER_H

#include "moscow/traits/traits.h"
#include "moscow/traits/primary/is_void.h"
#include "moscow/traits/properties/is_referenceable.h"

namespace moscow {
namespace detail {
/**
 * \brief add pointer to referenceable types or void
 * \tparam T
 */
template<typename T> auto add_pointer_impl(int) -> remove_reference_t<T> *;
/**
 * \brief adding pointer to non-void non-referenceable types does nothing
 * \tparam T
 */
template<typename T> auto add_pointer_impl(...) -> T;
} // namespace detail
/**
 * \brief add pointer to a type
 */
template<typename T> using add_pointer = identity<decltype(detail::add_pointer_impl<T>(0))>;
/**
 * \brief type helper for add_pointer
 */
moscow_type_helper(add_pointer);
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_POINTERS_ADD_POINTER_H
