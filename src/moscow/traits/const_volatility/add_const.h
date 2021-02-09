//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_CONST_VOLATILITY_ADD_CONST_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_CONST_VOLATILITY_ADD_CONST_H

#include "moscow/traits/helper.h"

namespace moscow {
/**
 * \brief const qualify T
 * \tparam T
 */
template<typename T> struct add_const { using type = T const; };

/**
 * \brief type helper for add_const
 */
moscow_type_helper(add_const);
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_CONST_VOLATILITY_ADD_CONST_H
