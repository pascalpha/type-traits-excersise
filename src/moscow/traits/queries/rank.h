//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_QUERIES_RANK_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_QUERIES_RANK_H

#include "moscow/traits/traits.h"

namespace moscow {
/**
 * rank of non-array type
 * @tparam T
 */
template<typename T> struct rank : integral_constant<size_t, 0> {};

/**
 * rank of unbounded array type
 * @tparam T
 */
template<typename T> struct rank<T[]> : integral_constant<size_t, rank<T>::value + 1> {};

/**
 * rank of bounded array type
 * @tparam T
 * @tparam N
 */
template<typename T, size_t N> struct rank<T[N]> : integral_constant<size_t, rank<T>::value + 1> {};

/**
 * value helper for rank
 * @tparam T
 */
template<typename T> size_t constexpr rank_v = rank<T>::value;
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_QUERIES_RANK_H
