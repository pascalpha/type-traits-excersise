//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PRIMARY_IS_MEMBER_FUNCTION_POINTER_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PRIMARY_IS_MEMBER_FUNCTION_POINTER_H

#include "moscow/traits/helper.h"
#include "moscow/traits/composite/is_member_pointer.h"

namespace moscow {
/**
 * \brief defines value = true if T is member function pointer
 */
template<typename T>
using is_member_function_pointer = bool_constant<detail::is_member_pointer_impl<remove_cv_t<T>>::is_func>;

/**
 * \brief value helper for is_member_function_pointer
 * \tparam T
 */
moscow_value_helper(is_member_function_pointer);
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PRIMARY_IS_MEMBER_FUNCTION_POINTER_H
