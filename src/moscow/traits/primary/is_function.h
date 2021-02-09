//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PRIMARY_IS_FUNCTION_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PRIMARY_IS_FUNCTION_H

#include "moscow/traits/traits.h"
#include "moscow/traits/composite/is_reference.h"
#include "moscow/traits/properties/is_const.h"

namespace moscow {
/**
 * \brief defines value = true if T is function
 *
 * A type is a function iff it is not a reference and applying const qualifier does not affect it
 */
template<typename T> using is_function = bool_constant<!(is_reference_v<T> || is_const_v<const T>)>;

/**
 * \brief value helper for is_function
 * \tparam T
 */
moscow_value_helper(is_function);
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PRIMARY_IS_FUNCTION_H
