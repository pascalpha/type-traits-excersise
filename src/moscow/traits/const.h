//
// Created by mamin on 2/8/2021.
//
#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_CONST_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_CONST_H

#include "helper.h"

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

/**
 * defines type to be template argument with const qualifier removed if present
 * @tparam T
 */
template<typename T> struct remove_const { using type = T; };
/**
 * defines type to be template argument with const qualifier removed if present
 * @tparam T
 */
template<typename T> struct remove_const<T const> { using type = T; };

/**
 * type helper for remove_const
 */
moscow_type_helper(remove_const);
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_CONST_H
