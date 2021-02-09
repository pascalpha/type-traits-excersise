//
// Created by mamin on 2/8/2021.
//
#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PRIMARY_IS_VOID_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PRIMARY_IS_VOID_H

#include "moscow/traits/const_volatility/remove_cv.h"
#include "moscow/traits/relationships/is_same.h"

namespace moscow {
/**
 * defines value = true if T is void possibly const volatile qualified
 * @tparam T
 */
template<typename T> using is_void = is_same<void, remove_cv_t<T>>;

/**
 * value helper for is_void
 * @tparam T
 */
moscow_value_helper(is_void);
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PRIMARY_IS_VOID_H
