//
// Created by mamin on 2/9/2021.
//
#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PROPERTIES_IS_POLYMORPHIC_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PROPERTIES_IS_POLYMORPHIC_H

#include "moscow/traits/traits.h"
#include "moscow/traits/misc/enable_if.h"

namespace moscow {
namespace detail {
/**
 * failed polymorphic test
 * @tparam T
 * @param ...
 * @return
 */
template<typename T> auto is_polymorphic_impl(...) -> false_type;
/**
 * succeeded polymorphic test
 *
 * pointer type can be dynamically converted to cv qualified void*
 * @tparam T
 * @return
 */
template<typename T> auto is_polymorphic_impl(int)
-> typename selector<decltype(dynamic_cast<const volatile void *>(static_cast<T *>(nullptr))), true_type>::second;
} // namespace detail

/**
 * defines value = true if T is polymorphic
 */
template<typename T> using is_polymorphic = decltype(detail::is_polymorphic_impl<T>(0));

/**
 * type helper fpr is_polymorphic
 * @tparam T
 */
moscow_value_helper(is_polymorphic);
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PROPERTIES_IS_POLYMORPHIC_H
