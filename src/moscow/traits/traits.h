//
// Created by admin on 2021/2/8.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_HELPER_H_
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_HELPER_H_

namespace moscow {
using size_t = decltype(sizeof(nullptr));
/**
 * \brief integral constant type
 * \tparam T
 * \tparam v
 */
template<typename T, T v> struct integral_constant {
  constexpr static const T value = v;

  using value_type = T;
  using type = integral_constant;
  inline constexpr value_type operator()() const noexcept { return value; }
};

/**
 * \brief bool constant type
 */
template<bool B> using bool_constant = integral_constant<bool, B>;

/**
 * \brief true type
 */
using true_type = bool_constant<true>;

/**
 * \brief false type
 */
using false_type = bool_constant<false>;

namespace detail {
template<bool> struct meta_selector;
template<> struct meta_selector<true> {};
template<> struct meta_selector<false> {};

template<template<typename...> typename Temp, typename... Ts, typename = Temp<Ts...>> true_type sfinae_impl(int);
template<template<typename...> typename Temp, typename... Ts> false_type sfinae_impl(...);
template<template<typename...> typename Temp, typename... Ts> using sfinae = decltype(sfinae_impl<Temp, Ts...>(0));
} // namespace detail


/**
 * placeholder template
 */
template<typename> using void_t = void;

/**
 * identity metafunction
 * @tparam T
 */
template<typename T> struct identity { using type = T; };

#define moscow_value_helper(Template)\
template<typename T> bool constexpr Template##_v = Template<T>::value

#define moscow_type_helper(Template)\
template<typename T> using Template##_t = typename Template<T>::type
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_HELPER_H_
