//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PRIMARY_IS_UNION_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PRIMARY_IS_UNION_H

#include "moscow/traits/helper.h"
#include "moscow/traits/intrinsics/intrinsics.h"

namespace moscow {
/**
 * \brief defines value = true if T is union
 */
template<typename T> using is_union = bool_constant<_moscow_is_union(T)>;

/**
 * \brief value helper for is_union
 * \tparam T
 */
moscow_value_helper(is_union);

} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PRIMARY_IS_UNION_H
