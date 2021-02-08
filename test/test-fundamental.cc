#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
//
// Created by admin on 2021/2/8.
//

#include <moscow/config.h>

#include <gtest/gtest.h>
#include <iostream>
class fundamental : public testing::Test
{

};

TEST_F(fundamental, main)
{
	std::cout << VERSION << std::endl;
}
#pragma clang diagnostic pop