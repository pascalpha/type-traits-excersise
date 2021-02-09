//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_ARRAYS_REMOVE_EXTENT_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_ARRAYS_REMOVE_EXTENT_H

#include "moscow/traits/traits.h"

namespace moscow {
/**
 * removing extent from non-array type
 * @tparam T
 */
template<typename T> struct remove_extent { using type = T; };
/**
 * remove extent from unbounded array type
 * @tparam T
 */
template<typename T> struct remove_extent<T[]> { using type = T; };
/**
 * remove extent from bounded array type
 * @tparam T
 * @tparam N
 */
template<typename T, size_t N> struct remove_extent<T[N]> { using type = T; };

/**
 * type helper for remove_extent
 */
moscow_type_helper(remove_extent);
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_ARRAYS_REMOVE_EXTENT_H
