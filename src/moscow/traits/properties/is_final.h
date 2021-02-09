//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PROPERTIES_IS_FINAL_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PROPERTIES_IS_FINAL_H

#include "moscow/traits/traits.h"
#include "moscow/traits/intrinsics/intrinsics.h"

namespace moscow {
/**
 * defines value = true if T is final
 */
template<typename T> using is_final = bool_constant<_moscow_is_final(T)>;

/**
 * value helper for is_final
 * @tparam T
 */
moscow_value_helper(is_final);
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PROPERTIES_IS_FINAL_H
