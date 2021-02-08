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
#pragma clang diagnostic pop