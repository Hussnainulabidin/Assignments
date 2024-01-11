

#include"Header.h"
#include "pch.h"

// Test case
TEST(Question_1, Test1) {
	std::string str = "mytttiiifsdjjojsadhsadunefwefwefwefdshjyiohdgwrg";
	int k = 4;
	std::string ans = "ytttisdjjojsadhsadunefwefwefwefdshjyiohdgwrg";
    EXPECT_EQ(ans, largestString(str,k)); // This expectation will fail
}

TEST(Question_1, Test2) {
	std::string str = "codingisnofununtilyoudodsa";
	int k = 8;
	std::string ans = "sofununtilyoudodsa";
	EXPECT_EQ(ans, largestString(str, k)); // This expectation will fail
}

TEST(Question_1, Test3) {
	std::string str = "rebmasitohsui";
	int k = 3;
	std::string ans = "rmsitohsui";
	EXPECT_EQ(ans, largestString(str, k)); // This expectation will fail
}

TEST(Question_1, Test4) {
	std::string str = "farigballdamhadbj";
	int k = 5;
	std::string ans = "rilldamhadbj";
	EXPECT_EQ(ans, largestString(str, k)); // This expectation will fail
}

TEST(Question_1, Test5) {
	std::string str = "maajyutrrabcde";
	int k = 2;
	std::string ans = "mjyutrrabcde";
	EXPECT_EQ(ans, largestString(str, k)); // This expectation will fail
}



