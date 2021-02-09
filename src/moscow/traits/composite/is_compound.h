//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_COMPOSITE_IS_COMPOUND_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_COMPOSITE_IS_COMPOUND_H

#include "moscow/traits/traits.h"
#include "moscow/traits/composite/is_fundamental.h"

namespace moscow {
/**
 * \brief defines value = true if T is compound, i.e. not fundamental
 */
template<typename T> using is_compound = bool_constant<!is_fundamental_v<T>>;

/**
 * \brief value helper for is_compound
 * \tparam T
 */
moscow_value_helper(is_compound);
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_COMPOSITE_IS_COMPOUND_H
