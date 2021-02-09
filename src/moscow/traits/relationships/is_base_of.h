//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_RELATIONSHIPS_IS_BASE_OF_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_RELATIONSHIPS_IS_BASE_OF_H

#include "moscow/traits/traits.h"
#include "moscow/traits/primary/is_class.h"

namespace moscow {
namespace detail {
/**
 * try converting a pointer to B*
 * @tparam B
 * @return
 */
template<typename B> [[maybe_unused]] auto pointer_convert(const volatile B *) -> true_type;
/**
 * failed to convert a pointer to B*
 * @return
 */
template<typename> [[maybe_unused]] auto pointer_convert(const volatile void *) -> false_type;
/**
 * same type
 * @param ...
 * @return
 */
template<typename, typename> [[maybe_unused]]  auto is_base_of_impl(...) -> true_type;
/**
 * check whether D* can be implicitly converted to B*
 * @tparam B
 * @tparam D
 * @return
 */
template<typename B, typename D> [[maybe_unused]]
auto is_base_of_impl(int) -> decltype(pointer_convert<B>(static_cast<D *>(nullptr)));
} // namespace detail
/**
 * checks if Base is a possibly private or protected base class or the same class of Derived
 */
template<typename Base, typename Derived>
using is_base_of = bool_constant<is_class_v<Base> && is_class_v<Derived> &&
    decltype(detail::is_base_of_impl<Base, Derived>(0))::value>;
/**
 * value helper for is_base_of
 * @tparam Base
 * @tparam Derived
 */
template<typename Base, typename Derived>
bool constexpr is_base_of_v = is_base_of<Base, Derived>::value;
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_RELATIONSHIPS_IS_BASE_OF_H
