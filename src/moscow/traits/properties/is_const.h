//
// Created by mamin on 2/8/2021.
//
#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PROPERTIES_IS_CONST_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PROPERTIES_IS_CONST_H

#include "moscow/traits/traits.h"

namespace moscow {
/**
 * defines value = false if template argument is not const qualified
 */
template<typename> struct is_const : false_type {};

/**
 * defines value = true if template argument is const qualified
 * @tparam T
 */
template<typename T> struct is_const<T const> : true_type {};

/**
 * value helper for is_const
 * @tparam T
 */
moscow_value_helper(is_const);
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PROPERTIES_IS_CONST_H
