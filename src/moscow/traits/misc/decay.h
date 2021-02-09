//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_MISC_DECAY_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_MISC_DECAY_H

#include "moscow/traits/traits.h"
#include "moscow/traits/const_volatility/remove_cv.h"
#include "moscow/traits/primary/is_function.h"
#include "moscow/traits/references/remove_reference.h"
#include "moscow/traits/misc/conditional.h"

namespace moscow {
/**
 * decay function / array type to pointer type.
 *
 * These decays will be applied whenever passing arguments by value into functions
 * @tparam T
 */
template<typename T> struct decay {
private:
  using unref = remove_reference_t<T>;
public:
  using type = conditional_t<is_function_v<unref>, unref *, remove_cv_t<unref>>;
};

/**
 * decay unbounded array
 * @tparam T
 */
template<typename T> struct decay<T[]> { using type = T *; };
/**
 * decay unbounded array reference
 * @tparam T
 */
template<typename T> struct decay<T(&)[]> { using type = T *; };
/**
 * decay bounded array
 * @tparam T
 * @tparam N
 */
template<typename T, size_t N> struct decay<T[N]> { using type = T *; };
/**
 * decay bounded array reference
 * @tparam T
 * @tparam N
 */
template<typename T, size_t N> struct decay<T(&)[N]> { using type = T *; };

/**
 * type helper for decay
 */
moscow_type_helper(decay);
} // namespace moscow
#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_MISC_DECAY_H
