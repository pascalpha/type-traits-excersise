//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_CONST_VOLATILITY_ADD_VOLATILE_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_CONST_VOLATILITY_ADD_VOLATILE_H

#include "moscow/traits/traits.h"

namespace moscow {
/**
 * \brief volatile qualify T
 * \tparam T
 */
template<typename T> struct add_volatile { using type = T volatile; };

/**
 * \brief type helper for add_volatile
 */
moscow_type_helper(add_volatile);
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_CONST_VOLATILITY_ADD_VOLATILE_H
