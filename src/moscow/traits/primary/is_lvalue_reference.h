//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PRIMARY_IS_LVALUE_REFERENCE_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PRIMARY_IS_LVALUE_REFERENCE_H

#include "moscow/traits/traits.h"

namespace moscow {
/**
 * \brief defines value = true if T is lvalue reference
 * \tparam T
 */
template<typename T> struct is_lvalue_reference : false_type {};
/**
 * \brief defines value = true if T is lvalue reference
 * \tparam T
 */
template<typename T> struct is_lvalue_reference<T&> : true_type {};

/**
 * \brief value helper for is_lvalue_reference
 * \tparam T
 */
moscow_value_helper(is_lvalue_reference);
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PRIMARY_IS_LVALUE_REFERENCE_H
