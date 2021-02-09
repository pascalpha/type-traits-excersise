//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_COMPOSITE_IS_SCALAR_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_COMPOSITE_IS_SCALAR_H

#include "moscow/traits/traits.h"
#include "moscow/traits/primary/is_void.h"
#include "moscow/traits/primary/is_nullptr.h"
#include "moscow/traits/primary/is_pointer.h"
#include "moscow/traits/primary/is_enum.h"
#include "moscow/traits/composite/is_arithmetic.h"
#include "moscow/traits/composite/is_member_pointer.h"

namespace moscow {
/**
 * \brief defines value = true if T is scalar (either arithmetic, pointer, member pointer, null pointer or enum)
 */
template<typename T> using is_scalar = bool_constant<
	is_arithmetic_v<T> || is_member_pointer_v<T> || is_pointer_v<T> ||
		is_null_pointer_v<T> || is_enum_v<T>>;

/**
 * \brief value helper for is_scalar
 * \tparam T
 */
moscow_value_helper(is_scalar);
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_COMPOSITE_IS_SCALAR_H
