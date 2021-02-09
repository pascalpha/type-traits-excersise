//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_COMPOSITE_IS_ARITHMETIC_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_COMPOSITE_IS_ARITHMETIC_H

#include "moscow/traits/traits.h"
#include "moscow/traits/primary/is_integral.h"
#include "moscow/traits/primary/is_floating_point.h"

namespace moscow {
/**
 * \brief defines value = true if T is arithmetic (either integral or floating point)
 */
template<typename T> using is_arithmetic = bool_constant<is_integral_v<T> || is_floating_point_v<T>>;

/**
 * \brief value helper for is_arithmetic
 * \tparam T
 */
moscow_value_helper(is_arithmetic);
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_COMPOSITE_IS_ARITHMETIC_H
