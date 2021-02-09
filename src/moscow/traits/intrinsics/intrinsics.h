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

/*Primary*/
/**
 * tell union from class
 */
#define _moscow_is_union(t) __is_union(t)

/*type properties*/
#define _moscow_is_final(t) __is_final(t)
#define _moscow_is_abstract(t) __is_abstract(t)
#define _moscow_is_aggregate(t) __is_aggregate(t)
#define _moscow_is_empty(t) __is_empty(t)

/*type operations*/
/*trivial family of traits*/
#endif // __GNUC__ || __clang__

#endif //EXERCISE_MOSCOW_SRC_MOSCOW_TRAITS_INTRINSICS_INTRINSICS_H
