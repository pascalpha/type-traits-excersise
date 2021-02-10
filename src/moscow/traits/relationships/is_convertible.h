//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_RELATIONSHIPS_IS_CONVERTIBLE_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_RELATIONSHIPS_IS_CONVERTIBLE_H

#include "moscow/traits/traits.h"
#include "moscow/traits/primary/is_void.h"

namespace moscow {
namespace detail {
/**
 * succeeded returnable test
 * @tparam T
 * @return
 */
template<typename T> auto is_returnable_impl(int)
-> typename selector<decltype(static_cast<T(*)()>(nullptr)), true_type>::second;
/**
 * failed returnable test
 * @param ...
 * @return
 */
template<typename> auto is_returnable_impl(...) -> false_type;

/**
 * succeeded implicit conversion test
 * @tparam From
 * @tparam To
 * @return
 */
template<typename From, typename To> auto is_implicitly_convertible_impl(int)
-> typename selector<decltype(declval<void(&)(To)>()(declval<From>())), true_type>::second;
/**
 * failed implicit conversion test
 * @param ...
 * @return
 */
template<typename, typename> auto is_implicitly_convertible_impl(...) -> false_type;
} // namespace detail
/**
 * defines value = true if From type can be converted to To type
 */
template<typename From, typename To>
using is_convertible = bool_constant<(is_void_v < From > && is_void_v < To > ) ||
    (decltype(detail::is_returnable_impl<To>(0))::value &&
        decltype(detail::is_implicitly_convertible_impl<From, To>(0))::value)>;

/**
 * value helper for is_convertible
 * @tparam From
 * @tparam To
 */
template<typename From, typename To>
bool constexpr is_convertible_v = is_convertible<From, To>::value;
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_RELATIONSHIPS_IS_CONVERTIBLE_H
