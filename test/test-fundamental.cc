#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
//
// Created by admin on 2021/2/8.
//

#include <moscow/type_traits>

#include <gtest/gtest.h>
#include <iostream>

using namespace moscow;

class fundamental : public testing::Test {

};

TEST_F(fundamental, const_volatile) {
  EXPECT_TRUE((is_same_v<void, remove_const_t<void>>));
  EXPECT_TRUE((is_same_v<void, remove_const_t<void const>>));
  EXPECT_FALSE((is_same_v<void, remove_const_t<void volatile>>));
  EXPECT_FALSE((is_same_v<void, remove_const_t<void const volatile>>));

  EXPECT_TRUE((is_same_v<void, remove_cv_t<void>>));
  EXPECT_TRUE((is_same_v<void, remove_cv_t<void const>>));
  EXPECT_TRUE((is_same_v<void, remove_cv_t<void volatile>>));
  EXPECT_TRUE((is_same_v<void, remove_cv_t<void const volatile>>));

  EXPECT_TRUE((is_same_v<void, remove_volatile_t<void>>));
  EXPECT_FALSE((is_same_v<void, remove_volatile_t<void const>>));
  EXPECT_TRUE((is_same_v<void, remove_volatile_t<void volatile>>));
  EXPECT_FALSE((is_same_v<void, remove_volatile_t<void const volatile>>));
}

TEST_F(fundamental, integral) {
  EXPECT_TRUE((is_integral_v<const int volatile>));
  EXPECT_TRUE((is_integral_v<bool>));
  EXPECT_TRUE((is_integral_v<long long volatile>));
  EXPECT_FALSE((is_integral_v<void>));
  EXPECT_FALSE((is_integral_v<nullptr_t>));
  EXPECT_FALSE((is_integral_v<double>));
  EXPECT_FALSE((is_integral_v<float>));
}

TEST_F(fundamental, floating_point) {
  EXPECT_FALSE((is_floating_point_v<int>));
  EXPECT_FALSE((is_floating_point_v<bool>));
  EXPECT_FALSE((is_floating_point_v<long long>));
  EXPECT_FALSE((is_floating_point_v<void>));
  EXPECT_FALSE((is_floating_point_v<nullptr_t>));
  EXPECT_TRUE((is_floating_point_v<const volatile double>));
  EXPECT_TRUE((is_floating_point_v<const float>));
}

TEST_F(fundamental, misc) {
  struct X {};
  union Y {};
  enum Z {};
  EXPECT_TRUE(!(is_union_v<X>));
  EXPECT_TRUE((is_union_v<Y>));
  EXPECT_TRUE(!(is_union_v<double>));

  EXPECT_TRUE((is_class_v<X>));
  EXPECT_TRUE(!(is_class_v<Y>));
  EXPECT_TRUE(!(is_class_v<double>));

  EXPECT_TRUE(!(is_function_v<X>));
  EXPECT_TRUE(!(is_function_v<Y>));
  EXPECT_TRUE(!(is_function_v<double>));
  EXPECT_TRUE((is_function_v<void(int *)>));
  EXPECT_TRUE(!(is_function_v<void (&)(int *, int)>));

  EXPECT_FALSE((is_enum_v<X>));
  EXPECT_FALSE((is_enum_v<Y>));
  EXPECT_FALSE((is_enum_v<int>));
  EXPECT_FALSE((is_enum_v<double>));
  EXPECT_TRUE((is_enum_v<Z>));

  EXPECT_TRUE((is_uncvref_same_v<int, int>));
  EXPECT_TRUE((is_uncvref_same_v<int, int const volatile>));
  EXPECT_TRUE((is_uncvref_same_v<int, int const volatile &>));
  EXPECT_TRUE((is_uncvref_same_v<int, int const &&>));
  EXPECT_FALSE((is_uncvref_same_v<int, int const *>));
  EXPECT_FALSE((is_uncvref_same_v<int, int const[]>));
  EXPECT_FALSE((is_uncvref_same_v<int, void>));
}

TEST_F(fundamental, object) {
  class X;
  EXPECT_TRUE(!(is_member_pointer_v<double>));
  EXPECT_TRUE((is_member_pointer_v<int X::*>));
  EXPECT_TRUE((is_member_object_pointer_v<int X::*>));
  EXPECT_TRUE(!(is_member_function_pointer_v<int X::*>));
  EXPECT_TRUE((is_member_function_pointer_v<int (X::*)(int)>));
  EXPECT_TRUE(!(is_member_object_pointer_v<int (X::*)(int)>));
}

TEST_F(fundamental, signedness) {
  EXPECT_TRUE((is_signed_v<signed>));
  EXPECT_TRUE((is_signed_v<signed int>));
  EXPECT_TRUE((is_signed_v<signed long>));
  EXPECT_TRUE((is_signed_v<double>));
  EXPECT_TRUE((is_signed_v<float>));

  EXPECT_TRUE(!(is_signed_v<unsigned>));
  EXPECT_TRUE(!(is_signed_v<unsigned int>));
  EXPECT_TRUE(!(is_signed_v<unsigned long>));
  EXPECT_TRUE(!(is_signed_v<double &>));
  EXPECT_TRUE(!(is_signed_v<signed[]>));

  EXPECT_FALSE((is_unsigned_v<signed>));
  EXPECT_FALSE((is_unsigned_v<signed int>));
  EXPECT_FALSE((is_unsigned_v<signed long>));
  EXPECT_FALSE((is_unsigned_v<double>));
  EXPECT_FALSE((is_unsigned_v<float>));

  EXPECT_TRUE((is_unsigned_v<unsigned>));
  EXPECT_TRUE((is_unsigned_v<unsigned int>));
  EXPECT_TRUE((is_unsigned_v<unsigned long>));
  EXPECT_TRUE(!(is_unsigned_v<double &>));
  EXPECT_TRUE(!(is_unsigned_v<signed[]>));
}

TEST_F(fundamental, pointer) {
  EXPECT_TRUE((is_same_v<int, remove_pointer_t<int *>>));
  EXPECT_TRUE((is_same_v<int, remove_pointer_t<int *const>>));
  EXPECT_TRUE((is_same_v<int, remove_pointer_t<int *volatile>>));
  EXPECT_TRUE((is_same_v<int, remove_pointer_t<int *const volatile>>));
  EXPECT_TRUE((is_same_v<int, remove_pointer_t<int >>));
  EXPECT_TRUE((is_same_v<void, remove_pointer_t<void *const volatile>>));

  EXPECT_TRUE((is_same_v<int *, add_pointer_t<int>>));
  EXPECT_TRUE((is_same_v<const int *, add_pointer_t<const int>>));
  EXPECT_TRUE((is_same_v<int *, add_pointer_t<int &>>));
  EXPECT_TRUE((is_same_v<int (*)(), add_pointer_t<int()>>));
}

TEST_F(fundamental, extent) {
  EXPECT_EQ(1, (extent_v<int[1][2][3][4][5], 0>));
  EXPECT_EQ(2, (extent_v<int[1][2][3][4][5], 1>));
  EXPECT_EQ(3, (extent_v<int[1][2][3][4][5], 2>));
  EXPECT_EQ(4, (extent_v<int[1][2][3][4][5], 3>));
  EXPECT_EQ(5, (extent_v<int[1][2][3][4][5], 4>));

  EXPECT_EQ(0, (extent_v<int[][2][3][4][5], 0>));
  EXPECT_EQ(2, (extent_v<int[][2][3][4][5], 1>));
  EXPECT_EQ(3, (extent_v<int[][2][3][4][5], 2>));
  EXPECT_EQ(4, (extent_v<int[][2][3][4][5], 3>));
  EXPECT_EQ(5, (extent_v<int[][2][3][4][5], 4>));

  EXPECT_EQ(0, (extent_v<int[3], 4>));

  EXPECT_EQ(5, (rank_v<int[1][2][3][4][5]>));
  EXPECT_EQ(0, (rank_v<int>));
  EXPECT_EQ(5, (rank_v<int[][2][3][4][5]>));

  EXPECT_TRUE((is_same_v<int, remove_extent_t<int[]>>));
  EXPECT_TRUE((is_same_v<int, remove_extent_t<int[2]>>));
  EXPECT_TRUE((is_same_v<int[2], remove_extent_t<int[][2]>>));
  EXPECT_TRUE((is_same_v<int[2], remove_extent_t<int[2][2]>>));
  EXPECT_TRUE((is_same_v<int (&)[2][2], remove_extent_t<int (&)[2][2]>>));

  EXPECT_TRUE((is_same_v<int, remove_all_extents_t<int[]>>));
  EXPECT_TRUE((is_same_v<int, remove_all_extents_t<int[2]>>));
  EXPECT_TRUE((is_same_v<int, remove_all_extents_t<int[][2]>>));
  EXPECT_TRUE((is_same_v<int, remove_all_extents_t<int[2][2]>>));
  EXPECT_TRUE((is_same_v<int (&)[2][2], remove_all_extents_t<int (&)[2][2]>>));

}

TEST_F(fundamental, decay) {
  EXPECT_TRUE((is_same_v<int (*)[3], decay_t<int[][3]>>));
  EXPECT_TRUE((is_same_v<int (*)[3], decay_t<int[3][3]>>));
  EXPECT_TRUE((is_same_v<int (*)[3], decay_t<int (&)[3][3]>>));
  EXPECT_TRUE((is_same_v<int (*)[3], decay_t<int (&)[][3]>>));
  EXPECT_TRUE((is_same_v<int (*)(int), decay_t<int (&)(int)>>));
  EXPECT_TRUE((is_same_v<int (*)(int), decay_t<int(int)>>));
  EXPECT_TRUE((is_same_v<int, decay_t<const int volatile &>>));
}

TEST_F(fundamental, common) {
  EXPECT_TRUE((is_same_v<int, common_type_t<int, bool &>>));
  EXPECT_TRUE((is_same_v<long, common_type_t<int, long, unsigned >>));
  EXPECT_TRUE((is_same_v<unsigned long, common_type_t<int, long, unsigned long>>));
  EXPECT_TRUE((is_same_v<double, common_type_t<int, double>>));
  EXPECT_TRUE((is_same_v<void *, common_type_t<int *, void *, double *>>));
  EXPECT_TRUE((is_same_v<int (*)(), common_type_t<int (*)(), int (&)()>>));
  EXPECT_TRUE((is_same_v<int (*)(), common_type_t<int (&)(), int()>>));
}

TEST_F(fundamental, relations) {
  struct Base {};
  struct Derived : Base {};
  struct Protected : protected Base {};
  struct Private : private Base {};
  struct Inherited : Derived {};

  EXPECT_FALSE((is_base_of_v<int, int>));
  EXPECT_FALSE((is_base_of_v<int, double *>));
  EXPECT_FALSE((is_base_of_v<void *, void>));

  EXPECT_TRUE((is_base_of_v<Base, Derived>));
  EXPECT_TRUE((is_base_of_v<Base, Base>));
  EXPECT_TRUE((is_base_of_v<Base, Protected>));
  EXPECT_TRUE((is_base_of_v<Base, Private>));

  EXPECT_FALSE((is_base_of_v<Derived, Base>));
  EXPECT_FALSE((is_base_of_v<Derived, Protected>));
  EXPECT_TRUE((is_base_of_v<Base, Inherited>));
}

TEST_F(fundamental, empty) {
  struct Base {};
  struct Derived : Base {};
  struct Protected : protected Base { double i; };
  struct Private : private Base {};
  struct Inherited : Derived {};
  struct Final final : Base {};
  EXPECT_TRUE((is_empty_v<Base>));
  EXPECT_TRUE((is_empty_v<Derived>));
  EXPECT_TRUE((is_empty_v<Private>));
  EXPECT_TRUE((is_empty_v<Inherited>));
  EXPECT_TRUE((is_final_v<Final>));
  EXPECT_FALSE((is_final_v<Base>));

  EXPECT_FALSE((is_empty_v<Protected>));
  EXPECT_FALSE((is_empty_v<int>));
}

TEST_F(fundamental, polymorphic) {
  struct Base { virtual void func(); };
  struct Derived : Base {};
  struct Protected : protected Base { double i = 0; };
  struct Private : private Base {};
  struct Inherited : Derived {};
  struct Final final : Base {};

  EXPECT_TRUE((is_polymorphic_v<Base>));
  EXPECT_TRUE((is_polymorphic_v<Derived>));
  EXPECT_TRUE((is_polymorphic_v<Protected>));
  EXPECT_TRUE((is_polymorphic_v<Private>));
  EXPECT_TRUE((is_polymorphic_v<Inherited>));
  EXPECT_TRUE((is_polymorphic_v<Final>));
  EXPECT_FALSE((is_polymorphic_v<int>));
  EXPECT_FALSE((is_polymorphic_v<const void>));
  EXPECT_FALSE((is_polymorphic_v<int *>));
}

TEST_F(fundamental, convertible) {
  struct Base { virtual void func(); };
  struct Derived : Base {};
  struct Protected : protected Base { double i = 0; };
  struct Private : private Base {};
  struct Inherited : Derived {};
  struct Final final : Base {};

  EXPECT_TRUE((is_convertible_v<void *, const void *>));
  EXPECT_TRUE((is_convertible_v<int *, const void *>));
  EXPECT_TRUE((is_convertible_v<Derived *, Base *>));
  EXPECT_TRUE((is_convertible_v<Final *, Base *>));
  EXPECT_TRUE((is_convertible_v<Inherited *, Base *>));
  EXPECT_FALSE((is_convertible_v<Protected *, Base *>));
  EXPECT_FALSE((is_convertible_v<const void *, const int *>));
}
#pragma clang diagnostic pop