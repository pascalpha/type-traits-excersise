//
// Created by mamin on 2/9/2021.
//
#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_CONST_VOLATILITY_REMOVE_CONST_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_CONST_VOLATILITY_REMOVE_CONST_H

#include "moscow/traits/helper.h"

namespace moscow {

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

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_CONST_VOLATILITY_REMOVE_CONST_H
