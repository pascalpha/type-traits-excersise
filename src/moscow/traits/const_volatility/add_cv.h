//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_CONST_VOLATILITY_ADD_CV_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_CONST_VOLATILITY_ADD_CV_H

#include "moscow/traits/helper.h"

namespace moscow {
/**
 * \brief const volatile qualify T
 * \tparam T
 */
template<typename T> struct add_cv { using type = T const volatile; };

/**
 * \brief type helper for add_cv
 */
moscow_type_helper(add_cv);
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_CONST_VOLATILITY_ADD_CV_H
