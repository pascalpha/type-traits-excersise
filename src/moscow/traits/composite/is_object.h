//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_COMPOSITE_IS_OBJECT_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_COMPOSITE_IS_OBJECT_H

#include "moscow/traits/helper.h"
#include "moscow/traits/primary/is_array.h"
#include "moscow/traits/primary/is_class.h"
#include "moscow/traits/primary/is_union.h"
#include "moscow/traits/composite/is_scalar.h"

namespace moscow {
/**
 * \brief defines value = true if T is object (either scalar, array, union, or class)
 */
template<typename T> using is_object = bool_constant<is_scalar_v<T> || is_array_v<T> || is_union_v<T> || is_class_v<T>>;

/**
 * \brief value helper for is_object
 * \tparam T
 */
moscow_value_helper(is_object);
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_COMPOSITE_IS_OBJECT_H
