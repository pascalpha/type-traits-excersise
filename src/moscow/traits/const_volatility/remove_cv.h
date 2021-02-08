//
// Created by mamin on 2/8/2021.
//
#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_CV_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_CV_H

#include "moscow/traits/helper.h"
#include "moscow/traits/const_volatility/remove_const.h"
#include "moscow/traits/const_volatility/remove_volatile.h"

namespace moscow {
/**
 * defines type to be template argument with const volatile qualifier removed if present
 * @tparam T
 */
template<typename T> struct remove_cv { using type = remove_volatile_t<remove_const_t<T>>; };

/**
 * type helper for remove_cv
 */
moscow_type_helper(remove_cv);
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_CV_H
