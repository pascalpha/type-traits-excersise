//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PROPERTIES_IS_BOUNDED_ARRAY_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PROPERTIES_IS_BOUNDED_ARRAY_H

#include "moscow/traits/traits.h"

namespace moscow {
/**
 * failed detector of bounded array
 * @tparam T
 */
template<typename T> struct is_bounded_array : false_type {};

/**
 * succeeded detector if bounded array
 * @tparam T
 * @tparam N
 */
template<typename T, size_t N> struct is_bounded_array<T[N]> : true_type {};

/**
 * value helper for is_bounded_array
 * @tparam T
 */
moscow_value_helper(is_bounded_array);
} // namespace moscow
#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PROPERTIES_IS_BOUNDED_ARRAY_H
