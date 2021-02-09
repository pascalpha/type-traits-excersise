//
// Created by mamin on 2/9/2021.
//
#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_CONST_VOLATILITY_REMOVE_VOLATILE_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_CONST_VOLATILITY_REMOVE_VOLATILE_H

#include "moscow/traits/traits.h"

namespace moscow {

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

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_CONST_VOLATILITY_REMOVE_VOLATILE_H
