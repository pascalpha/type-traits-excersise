//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_QUERIES_EXTENT_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_QUERIES_EXTENT_H

#include "moscow/traits/traits.h"

namespace moscow {
/**
 * querying extent of non-array type yields 0
 * @tparam T
 * @tparam N
 */
template<typename T, size_t N = 0> struct extent : integral_constant<size_t, 0> {};

/**
 * querying extent of unbounded array type yields 0
 * @tparam T
 */
template<typename T> struct extent<T[], 0> : integral_constant<size_t, 0> {};

/**
 * querying extent of multidimensional array recursively
 * @tparam T
 * @tparam N
 */
template<typename T, size_t N> struct extent<T[], N> : extent<T, N - 1> {};

/**
 * querying extent of bounded array yields the result
 * @tparam T
 * @tparam I
 */
template<typename T, size_t I> struct extent<T[I], 0> : integral_constant<size_t, I> {};

/**
 * querying extent of multidimensional array recursively
 * @tparam T
 * @tparam I
 * @tparam N
 */
template<typename T, size_t I, size_t N> struct extent<T[I], N> : extent<T, N - 1> {};

/**
 * value helper for extent
 * @tparam T
 * @tparam N
 */
template<typename T, size_t N> size_t constexpr extent_v = extent<T, N>::value;
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_QUERIES_EXTENT_H
