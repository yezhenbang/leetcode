#include "pch.h"

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	testing::FLAGS_gtest_filter = "*.testing_*";
	RUN_ALL_TESTS();
}

#include "util\calc.hpp"
TEST(calc, testing_)
{
	ASSERT_EQ(CalcMidExpression("1+((4+25*4)/4-6)*2"), 41);
}