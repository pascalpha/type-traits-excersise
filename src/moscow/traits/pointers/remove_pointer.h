//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_POINTERS_REMOVE_POINTER_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_POINTERS_REMOVE_POINTER_H

#include "moscow/traits/helper.h"

namespace moscow {
/**
 * \brief remove pointer applied to non-pointer type does nothing
 * \tparam T
 */
template<typename T> struct remove_pointer { using type = T; };
/**
 * \brief remove pointer
 * \tparam T
 */
template<typename T> struct remove_pointer<T *> { using type = T; };
/**
 * \brief remove const pointer
 * \tparam T
 */
template<typename T> struct remove_pointer<T *const> { using type = T; };
/**
 * \brief remove volatile pointer
 * \tparam T
 */
template<typename T> struct remove_pointer<T *volatile> { using type = T; };
/**
 * \brief remove const volatile pointer
 * \tparam T
 */
template<typename T> struct remove_pointer<T *const volatile> { using type = T; };

/**
 * \brief type helper for remove_pointer
 */
moscow_type_helper(remove_pointer);
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_POINTERS_REMOVE_POINTER_H
