//
// Created by mamin on 2/8/2021.
//
#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PRIMARY_IS_NULLPTR_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PRIMARY_IS_NULLPTR_H

#include "moscow/traits/const_volatility/remove_cv.h"
#include "moscow/traits/relationships/is_same.h"

namespace moscow {
/**
 * type of nullptr
 */
using nullptr_t = decltype(nullptr);

/**
 * defines value = true if T is nullptr_t, possibly const volatile qualified
 * @tparam T
 */
template<typename T> using is_null_pointer = is_same <nullptr_t, remove_cv_t<T>>;

/**
 * value helper for is_null_pointer
 * @tparam T
 */
moscow_value_helper(is_null_pointer);
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PRIMARY_IS_NULLPTR_H
