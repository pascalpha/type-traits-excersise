//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PRIMARY_IS_ENUM_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PRIMARY_IS_ENUM_H

#include "moscow/traits/traits.h"
#include "moscow/traits/primary/is_void.h"
#include "moscow/traits/primary/is_integral.h"
#include "moscow/traits/primary/is_floating_point.h"
#include "moscow/traits/primary/is_array.h"
#include "moscow/traits/primary/is_pointer.h"
#include "moscow/traits/primary/is_union.h"
#include "moscow/traits/primary/is_class.h"
#include "moscow/traits/primary/is_function.h"
#include "moscow/traits/composite/is_reference.h"
#include "moscow/traits/composite/is_member_pointer.h"

namespace moscow {
/**
 * \brief defines value = true if T is enum.
 *
 * T is an enum iff T is not one of the other primary types
 */
template<typename T> using is_enum = bool_constant<
	!is_void_v<T> && !is_integral_v<T> && !is_floating_point_v<T> && !is_array_v<T> && !is_pointer_v<T> &&
		!is_reference_v<T> && !is_member_pointer_v<T> && !is_union_v<T> && !is_class_v<T> && !is_function_v<T>>;

/**
 * \brief value helper for is_enum
 * \tparam T
 */
moscow_value_helper(is_enum);
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PRIMARY_IS_ENUM_H
