//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PROPERTIES_IS_EMPTY_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PROPERTIES_IS_EMPTY_H

#include "moscow/traits/traits.h"
#include "moscow/traits/primary/is_class.h"

namespace moscow {
namespace detail {
/**
 * inherited class with a member field
 * @tparam T
 */
template<typename T> struct type_and_double : public T { double _; };
/**
 * class with the same member field
 * @tparam T
 */
template<typename T> struct trivial_double { double _; };
/**
 * Class types are final if the size of the two specified classes are equal
 * @tparam T
 */
template<typename T, bool = is_class_v < T>>
struct is_empty_impl : bool_constant<sizeof(trivial_double<T>) == sizeof(type_and_double<T>)> {};
/**
 * Non-class types are not final.
 * @tparam T
 */
template<typename T> struct is_empty_impl<T, false> : false_type {};
} // namespace detail
/**
 * defines value = true if T is empty.
 *
 * Known issue: cannot detect final empty classes!
 */
template<typename T> using is_empty = detail::is_empty_impl<T>;

/**
 * value helper for is_empty
 * @tparam T
 */
moscow_value_helper(is_empty);
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PROPERTIES_IS_EMPTY_H
