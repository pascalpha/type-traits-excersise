//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_REFERENCES_ADD_RVALUE_REFERENCE_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_REFERENCES_ADD_RVALUE_REFERENCE_H

#include "moscow/traits/traits.h"
#include "moscow/traits/properties/is_referenceable.h"

namespace moscow {
namespace detail {
/**
 * \brief adding rvalue reference to non-referenceable type does nothing
 * \tparam T
 */
template<typename T, bool = is_referenceable_v<T>> struct add_rvalue_reference_impl { using type = T; };
/**
 * \brief add rvalue reference to referenceable type
 * \tparam T
 */
template<typename T> struct add_rvalue_reference_impl<T, true> { using type = T &&; };
} // namespace detail
/**
 * \brief add rvalue reference
 */
template<typename T> using add_rvalue_reference = detail::add_rvalue_reference_impl<T>;
/**
 * \brief type helper for add_rvalue_reference
 */
moscow_type_helper(add_rvalue_reference);
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_REFERENCES_ADD_RVALUE_REFERENCE_H
