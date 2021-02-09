//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_MISC_REMOVE_CVREF_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_MISC_REMOVE_CVREF_H

#include "moscow/traits/helper.h"
#include "moscow/traits/const_volatility/remove_cv.h"
#include "moscow/traits/references/remove_reference.h"

namespace moscow {
/**
 * \brief remove const volatility qualifiers and references from T
 */
template<typename T> using remove_cvref = remove_cv_t<remove_reference_t<T>>;

/**
 * \brief type helper for remove_cvref
 */
moscow_type_helper(remove_cvref);
} // namespace moscow

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_MISC_REMOVE_CVREF_H
