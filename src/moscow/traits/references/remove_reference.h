//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_REFERENCES_REMOVE_REFERENCE_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_REFERENCES_REMOVE_REFERENCE_H

#include "moscow/traits/helper.h"

namespace moscow {
/**
 * \brief remove reference applied to non-reference type
 * \tparam T
 */
template<typename T> struct remove_reference { using type = T; };
/**
 * \brief remove reference applied to lvalue reference
 * \tparam T
 */
template<typename T> struct remove_reference<T &> { using type = T; };
/**
 * \brief remove reference applied to rvalue reference
 * \tparam T
 */
template<typename T> struct remove_reference<T &&> { using type = T; };

/**
 * \brief type helper for remove_reference
 */
moscow_type_helper(remove_reference);
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_REFERENCES_REMOVE_REFERENCE_H
