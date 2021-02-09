//
// Created by mamin on 2/9/2021.
//
#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PRIMARY_IS_ARRAY_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PRIMARY_IS_ARRAY_H

#include "moscow/traits/const_volatility/remove_cv.h"
#include "moscow/traits/helper.h"

namespace moscow {
/**
 * checks if T is an array type
 */
template<typename> struct is_array : false_type {};

/**
 * unbounded array
 * @tparam T
 */
template<typename T> struct is_array<T[]> : true_type {};

/**
 * bounded array
 * @tparam T
 * @tparam N
 */
template<typename T, size_t N> struct is_array<T[N]> : true_type {};

/**
 * \brief value helper for is_array
 * \tparam T
 */
moscow_value_helper(is_array);
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_ARRAY_H
