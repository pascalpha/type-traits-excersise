//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_MISC_DECLVAL_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_MISC_DECLVAL_H

#include "moscow/traits/traits.h"
#include "moscow/traits/references/add_rvalue_reference.h"

namespace moscow {
/**
 * \brief symbolic function for declaring value in unevaluated context
 * \tparam T
 * \return
 */
template<typename T> [[maybe_unused]] add_rvalue_reference_t<T> declval() noexcept;
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_MISC_DECLVAL_H
