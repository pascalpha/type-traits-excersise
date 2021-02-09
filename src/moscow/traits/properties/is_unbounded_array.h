//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PROPERTIES_IS_UNBOUNDED_ARRAY_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PROPERTIES_IS_UNBOUNDED_ARRAY_H

#include "moscow/traits/traits.h"

namespace moscow {
/**
 * failed detector for unbounded array
 * @tparam T
 */
template<typename T> struct is_unbounded_array : false_type {};
/**
 * succeeded detector for bounded array
 * @tparam T
 */
template<typename T> struct is_unbounded_array<T[]> : true_type {};

/**
 * value helper for is_unbounded_array
 * @tparam T
 */
moscow_value_helper(is_unbounded_array);
} // namespace moscow
#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PROPERTIES_IS_UNBOUNDED_ARRAY_H
