//
// Created by mamin on 2/9/2021.
//
#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PROPERTIES_IS_AGGREGATE_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PROPERTIES_IS_AGGREGATE_H

#include "moscow/traits/traits.h"
#include "moscow/traits/intrinsics/intrinsics.h"

namespace moscow {
/**
 * defines value = true if T is aggregate
 */
template<typename T> using is_aggregate = bool_constant<_moscow_is_aggregate(T)>;

/**
 * value helper for is_aggregate
 * @tparam T
 */
moscow_value_helper(is_aggregate);
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PROPERTIES_IS_AGGREGATE_H
