//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_COMPOSITE_IS_FUNDAMENTAL_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_COMPOSITE_IS_FUNDAMENTAL_H

#include "moscow/traits/helper.h"
#include "moscow/traits/primary/is_nullptr.h"
#include "moscow/traits/primary/is_void.h"
#include "moscow/traits/composite/is_arithmetic.h"

namespace moscow {
/**
 * \brief defines value = true if T is fundamental (either void or nullptr_t or arithmetic)
 */
template<typename T> using is_fundamental = bool_constant<is_void_v<T> || is_null_pointer_v<T> || is_arithmetic_v<T>>;

/**
 * \brief value helper for is_fundamental
 * \tparam T
 */
moscow_value_helper(is_fundamental);
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_COMPOSITE_IS_FUNDAMENTAL_H
