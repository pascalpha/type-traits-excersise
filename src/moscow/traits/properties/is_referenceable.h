//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PROPERTIES_IS_REFERENCEABLE_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PROPERTIES_IS_REFERENCEABLE_H

#include "moscow/traits/traits.h"

namespace moscow {
namespace detail {
/**
 * \brief succeeded referenceable overload detector
 * \tparam T
 * \return
 */
template<typename T> auto is_referenceable_impl(int) -> T &;
/**
 * \brief failed referenceable overload detector
 * \tparam T
 * \param ...
 */
template<typename T> auto is_referenceable_impl(...) -> void;
} // namespace detail
/**
 * \brief defines value = true if T is referenceable
 */
template<typename T>
using is_referenceable = bool_constant<!is_same_v<void, decltype(detail::is_referenceable_impl<T>(0))>>;

/**
 * \brief value helper for is_referenceable
 * \tparam T
 */
moscow_value_helper(is_referenceable);
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_PROPERTIES_IS_REFERENCEABLE_H
