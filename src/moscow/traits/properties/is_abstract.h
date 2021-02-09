//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PROPERTIES_IS_ABSTRACT_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PROPERTIES_IS_ABSTRACT_H

#include "moscow/traits/traits.h"
#include "moscow/traits/intrinsics/intrinsics.h"

namespace moscow {
/**
 * defines value = true if T is abstract
 */
template<typename T> using is_abstract = bool_constant<_moscow_is_abstract(T)>;

/**
 * value helper for is_abstract
 * @tparam T
 */
moscow_value_helper(is_abstract);
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PROPERTIES_IS_ABSTRACT_H
