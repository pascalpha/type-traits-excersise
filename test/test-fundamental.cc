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
}
#pragma clang diagnostic pop