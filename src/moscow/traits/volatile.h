//
// Created by mamin on 2/8/2021.
//
#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_VOLATILE_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_VOLATILE_H

#include "helper.h"

namespace moscow {
/**
 * defines value = false if template argument is not volatile qualified
 */
template<typename> struct is_volatile : false_type {};

/**
 * defines value = true if template argument is volatile qualified
 * @tparam T
 */
template<typename T> struct is_volatile<T volatile> : true_type {};

/**
 * value helper for is_volatile
 * @tparam T
 */
moscow_value_helper(is_volatile);

/**
 * defines type to be template argument with volatile qualifier removed if present
 * @tparam T
 */
template<typename T> struct remove_volatile { using type = T; };
/**
 * defines type to be template argument with volatile qualifier removed if present
 * @tparam T
 */
template<typename T> struct remove_volatile<T volatile> { using type = T; };

/**
 * type helper for remove_volatile
 */
moscow_type_helper(remove_volatile);
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_VOLATILE_H
