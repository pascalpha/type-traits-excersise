//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_ARRAYS_REMOVE_ALL_EXTENTS_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_ARRAYS_REMOVE_ALL_EXTENTS_H

#include "moscow/traits/traits.h"

namespace moscow {
/**
 * removing all extents of non-array type does nothing
 * @tparam T
 */
template<typename T> struct remove_all_extents { using type = T; };
/**
 * remove all extents of unbounded array type
 * @tparam T
 */
template<typename T> struct remove_all_extents<T[]> { using type = typename remove_all_extents<T>::type; };
/**
 * remove all extents of bounded array type
 * @tparam T
 * @tparam N
 */
template<typename T, size_t N> struct remove_all_extents<T[N]> { using type = typename remove_all_extents<T>::type; };
/**
 * type helper for remove_all_extents
 */
moscow_type_helper(remove_all_extents);
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_ARRAYS_REMOVE_ALL_EXTENTS_H
