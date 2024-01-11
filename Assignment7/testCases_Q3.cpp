

#include"Header.h"
#include "pch.h"



// Test case Question-3
TEST(Question_3, Test1) {
	int arr[5] = { 1,2,3,4,5 };
	int arr2[1] = { 5 };
	int k = 1;
	int size = 5;
	int* result = maxSubsequence(arr, size, k);
	for (int i = 0; i < k; i++)
		EXPECT_EQ(arr2[i], result[i]);
}

TEST(Question_3, Test2) {
	int arr[10] = { 3, -1, -2, 4, 6, -2, 2, 4, 6, -1 };
	int arr2[5] = { 6, -2 , 2 , 4 , 6 };
	int k = 5;
	int size = 10;
	int* result = maxSubsequence(arr, size, k);
	for (int i = 0; i < k; i++)
		EXPECT_EQ(arr2[i], result[i]);
}

TEST(Question_3, Test3) {
	int arr[5] = { 0, 0 , 0 , 0 , 0};
	int arr2[5] = { 0, 0 , 0 , 0 , 0 };
	int k = 5;
	int size = 5;
	int* result = maxSubsequence(arr, size, k);
	for (int i = 0; i < k; i++)
		EXPECT_EQ(arr2[i], result[i]);
}

TEST(Question_3, Test4) {
	int arr[5] = { -5,-1,-1,-1,-1 };
	int arr2[2] = { -1, -1};
	int k = 2;
	int size = 5;
	int* result = maxSubsequence(arr, size, k);
	for (int i = 0; i < k; i++)
		EXPECT_EQ(arr2[i], result[i]);
}

TEST(Question_3, Test5) {
	int arr[8] = { 10, -5, 7, -3, 5, 1, -2, -6 };
	int arr2[5] = { 7, -3, 5, 1 };
	int k = 4;
	int size = 8;
	int* result = maxSubsequence(arr, size, k);
	for (int i = 0; i < k; i++)
		EXPECT_EQ(arr2[i], result[i]);
}


