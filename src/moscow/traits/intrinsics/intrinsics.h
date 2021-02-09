//
// Created by admin on 2021/2/9.
//

#ifndef EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_INTRINSICS_INTRINSICS_H
#define EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_INTRINSICS_INTRINSICS_H

/**
 * \brief aliasing the minimum compiler magics.
 * Some traits are simply not implementable in the C++ language itself and need compiler support.
 * The list includes the following:
 * 		1. one if is_union / is_class
 * 		2. all of the trivial family of traits
 */

#if __GNUC__ || __clang__
#define _moscow_is_union(t) __is_union(t)
#endif

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_INTRINSICS_INTRINSICS_H
