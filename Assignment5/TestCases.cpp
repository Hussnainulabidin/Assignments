#include <gtest/gtest.h>
#include "source.h" // Include the actual implementation


//******************************************************
//***************** Question 1 *************************
//******************************************************

bool isSortedDescending(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i - 1] < arr[i]) {
            return false; // If any adjacent elements are out of order, return false.
        }
    }
    return true; // If all elements are in descending order, return true.
}

TEST(Array, FindMax1) {
    int A[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int result = ArrayBasics<int>::findMax(A, 2, 7);
    EXPECT_EQ(result, 9);
}

TEST(Array, FindMax2) {
    float A[] = {4.5, 5.3, 8.1 ,7.4, 2, 1, 0};
    float result = ArrayBasics<float>::findMax(A, 0, 3);
    EXPECT_EQ(result, 8.1f);
}

TEST(Array, FindMaxPos1) {
    int A[] = {3, 1, 4, 1, 5, 9, 2, 0, 9, 9};
    int result = ArrayBasics<int>::findMaxPos(A, 2, 7);
    EXPECT_EQ(result, 5); // Position of the maximum value (9) is 5.
}

TEST(Array, FindMaxPos2) {
    float A[] = {8, 1, 3, 4.1, 5.1, 2.3, 0};
    int result = ArrayBasics<float>::findMaxPos(A, 1, 3);
    EXPECT_EQ(result, 3); 
}

TEST(Array, FindMin1) {
    int A[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int result = ArrayBasics<int>::findMin(A, 2, 6);
    EXPECT_EQ(result, 1);
}

TEST(Array, FindMin2) {
    float A[] = {4.1, 2.2, 3.3, 0.1, 8, 9, 1};
    float result = ArrayBasics<float>::findMin(A, 1, 6);
    EXPECT_EQ(result, 0.1f);
}

TEST(Array, FindMinPos1) {
    int A[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int result = ArrayBasics<int>::findMinPos(A, 2, 7);
    EXPECT_EQ(result, 3); // Position of the minimum value (1) is 3.
}

TEST(Array, FindMinPos2) {
    float A[] = {3.1, 1.2, 4.3, 1.4, 0, 9, 2, 6, 5, 3};
    int result = ArrayBasics<float>::findMinPos(A, 2, 7);
    EXPECT_EQ(result, 4);
}

TEST(Array, Swap1) {
    int A[] = {3, 1, 4, 1, 5};
    ArrayBasics<int>::swap(A, 1, 3);
    EXPECT_EQ(A[1], 1); // After swapping, A[1] should be 1.
    EXPECT_EQ(A[3], 1); // After swapping, A[3] should be 1.
}

TEST(Array, Swap2) {
    float A[] = {3, 1.1, 4, 1, 5};
    ArrayBasics<float>::swap(A, 0, 4);
    EXPECT_EQ(A[0], 5); 
    EXPECT_EQ(A[4], 3); 
}

TEST(Array, CreateRandomArray1) {
    int* A = ArrayBasics<int>::createRandomArray(10, 1, 100);
    // Check if the array has the correct size and values within the specified range.
    for (int i = 0; i < 10; ++i) {
        EXPECT_GE(A[i], 1); // Values should be greater than or equal to 1.
        EXPECT_LE(A[i], 100); // Values should be less than or equal to 100.
    }
    delete[] A;
}

TEST(Array, CreateRandomArray2) {
    int* A = ArrayBasics<int>::createRandomArray(10, 30, 70);
    // Check if the array has the correct size and values within the specified range.
    for (int i = 0; i < 10; ++i) {
        EXPECT_GE(A[i], 30); // Values should be greater than or equal to 30.
        EXPECT_LE(A[i], 70); // Values should be less than or equal to 70.
    }
    delete[] A;
}

TEST(Array, CreateRandomMatrix1) {
    int** matrix = ArrayBasics<int>::createRandomMatrix(3, 4, 1, 100);
    // Check if the matrix has the correct dimensions and values within the specified range.
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            EXPECT_GE(matrix[i][j], 1); // Values should be greater than or equal to 1.
            EXPECT_LE(matrix[i][j], 100); // Values should be less than or equal to 100.
        }
        delete[] matrix[i]; // Clean up inner arrays.
    }
    delete[] matrix; // Clean up the outer array.
}

TEST(Array, CreateRandomMatrix2) {
    int** matrix = ArrayBasics<int>::createRandomMatrix(10, 10, 40, 60);
    // Check if the matrix has the correct dimensions and values within the specified range.
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            EXPECT_GE(matrix[i][j], 40); // Values should be greater than or equal to 40.
            EXPECT_LE(matrix[i][j], 60); // Values should be less than or equal to 60.
        }
        delete[] matrix[i]; // Clean up inner arrays.
    }
    delete[] matrix; // Clean up the outer array.
}

TEST(Array, CopyArray1) {
    int A[] = {1, 2, 3, 4, 5};
    int size = sizeof(A)/sizeof(A[0]);
    int* copy = ArrayBasics<int>::copyArray(A, size);
    // Check if the copied array is equal to the original.
    for (int i = 0; i < size; ++i) {
        EXPECT_EQ(copy[i], A[i]);
    }
    delete[] copy;
}

TEST(Array, CopyArray2) {
    int A[] = {1, 2, 3, 4, 5, 6, 0};
    int size = sizeof(A)/sizeof(A[0]);
    int* copy = ArrayBasics<int>::copyArray(A, size);
    // Check if the copied array is equal to the original.
    for (int i = 0; i < size; ++i) {
        EXPECT_EQ(copy[i], A[i]);
    }
    delete[] copy;
}

TEST(Array, CopyMatrix) {
    int rows = 3, cols = 4;
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = i * cols + j;
        }
    }

    int** copy = ArrayBasics<int>::copyMatrix(matrix, rows, cols);
    // Check if the copied matrix is equal to the original.
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            EXPECT_EQ(copy[i][j], matrix[i][j]);
        }
        delete[] copy[i]; // Clean up inner arrays.
    }
    delete[] copy; // Clean up the outer array.

    // Clean up the original matrix.
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

TEST(Array, FindInArray1) {
    int A[] = {1, 2, 3, 4, 5};
    int size = sizeof(A)/sizeof(A[0]);
    int result = ArrayBasics<int>::findInArray(A, 3, size);
    EXPECT_EQ(result, 2); // Position of 3 in A is 2.
}

TEST(Array, FindInArray2) {
    float A[] = {1, 2, 3, 4, 5.1, 6.5, 7.9, 8, 0};
    int size = sizeof(A)/sizeof(A[0]);
    int result = ArrayBasics<float>::findInArray(A, 8, size);
    EXPECT_EQ(result, 7); 
}

TEST(Array, FindInSortedArray1) {
    int A[] = {1, 2, 3, 4, 5};
    int size = sizeof(A)/sizeof(A[0]);
    int result = ArrayBasics<int>::findInSortedArray(A, 3, size);
    EXPECT_EQ(result, 2); // Position of 3 in A is 2.
}

TEST(Array, FindInSortedArray2) {
    float A[] = {1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7};
    int size = sizeof(A)/sizeof(A[0]);
    int result = ArrayBasics<float>::findInSortedArray(A, 0, size);
    EXPECT_EQ(result, -1); 
}

TEST(Array, FindFirstInSortedArray1) {
    int A[] = {1, 2, 2, 3, 3, 3, 4, 5};
    int size = sizeof(A)/sizeof(A[0]);
    int result = ArrayBasics<int>::findFirstInSortedArray(A, 3, size);
    EXPECT_EQ(result, 3); // First position of 3 in sorted A is 3.
}

TEST(Array, FindFirstInSortedArray2) {
    int A[] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 5};
    int size = sizeof(A)/sizeof(A[0]);
    int result = ArrayBasics<int>::findFirstInSortedArray(A, 4, size);
    EXPECT_EQ(result, 6); 
}

TEST(ArrayUtilityTest, MaxSortWithShiftRight) {
    int A[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int size = sizeof(A) / sizeof(A[0]);

    ArrayUtility<int>::maxSortWithShiftRight(A, size);

    // Check if the array is sorted in descending order.
    EXPECT_TRUE(isSortedDescending(A, size));
}

TEST(ArrayUtilityTest, MaxSortWithSwap) {
    int A[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int size = sizeof(A) / sizeof(A[0]);

    ArrayUtility<int>::maxSortWithSwap(A, size);

    // Check if the array is sorted in descending order.
    EXPECT_TRUE(isSortedDescending(A, size));
}

//******************************************************
//***************** Question 2 *************************
//******************************************************

TEST(WarehouseAlgorithmTest, Test1a) {
    int B[] = {3, 5, 2, 8, 10, 1, 7, 11, 12, 13, 14, 16, 18, 17, 19, 20, 21, 22, 23, 24, 25, 26, 28, 30, 32, 36, 35, 38, 39, 40, 42, 45, 46, 48, 50, 51, 52, 53, 54, 55, 57, 58, 60};
    int n = sizeof(B) / sizeof(B[0]);
    int r = 12;
    EXPECT_TRUE(WarehouseAlgorithm<int>::hasClosePair(B, n, r));
}

TEST(WarehouseAlgorithmTest, Test2a) {
    int B[] = {6, 5, 2, 8, 10, 1, 7, 11, 12, 13, 14, 16};
    int n = sizeof(B) / sizeof(B[0]);
    int r = 4;
    EXPECT_FALSE(WarehouseAlgorithm<int>::hasClosePair(B, n, r));
}

TEST(WarehouseAlgorithmTest, Test3a) {
    int B[] = {3, 8, 2, 4, 0, 19, 18, 16, 14, 13, 20, 22, 24, 25, 27, 28, 29, 30, 31, 33, 34, 36, 38, 39, 40, 50, 60, 70};
    int n = sizeof(B) / sizeof(B[0]);
    int r = 11;
    EXPECT_TRUE(WarehouseAlgorithm<int>::hasClosePair(B, n, r));
}

TEST(WarehouseAlgorithmTest, Test4a) {
    int B[] = {3, 5, 2, 8, 0, 19, 18, 16, 14, 13, 80, 67};
    int n = sizeof(B) / sizeof(B[0]);
    int r = 9;
    EXPECT_FALSE(WarehouseAlgorithm<int>::hasClosePair(B, n, r));
}

//******************************************************
//***************** Question 3 *************************
//******************************************************

TEST(MaximizeProfitTest, NoStorageCosts) {
    int m = 10;
    int n = 5;
    int a[] = {2, 3, 1, 4, 5};
    int p[] = {20, 30, 10, 40, 50};
    int s = 0;

    int result = maximizeProfit<int>(m, n, a, p, s);
    
    EXPECT_EQ(result, 100);
    // Orders selected: {3, 4, 5}
}

TEST(MaximizeProfitTest, WithStorageCosts) {
    int m = 20;
    int n = 5;
    int a[] = {2, 3, 1, 4, 5};
    int p[] = {20, 30, 10, 40, 50};
    int s = 5;
    
    int result = maximizeProfit<int>(m, n, a, p, s);
    
    EXPECT_EQ(result, 125);
}

//******************************************************
//***************** Question 4 *************************
//******************************************************

TEST(BookingScheduleTest, MergeTwoBookingSchedules) {
    int R1[][2] = {
        {3, 5},
        {4, 8},
        {10,12}
    };
    int n1 = sizeof(R1) / sizeof(R1[0]);

    int R2[][2] = {
        {2, 4},
        {0, 6}
    };
    int n2 = sizeof(R2) / sizeof(R2[0]);

    int mergedSchedule[50][3]; // Assuming a maximum of 50 bookings
    int m;

    mergeBookingSchedules<int>(R1, n1, R2, n2, mergedSchedule, m);

    // Define the expected merged schedule (B)
    int expectedSchedule[][3] = {
        {1, 0, 2},
        {2, 2, 3},
        {3, 3, 4},
        {3, 4, 5},
        {2, 5, 6},
        {1, 6, 8},
        {1, 10, 12}
    };

    // Check if the merged schedule matches the expected schedule
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 3; j++) {
            ASSERT_EQ(mergedSchedule[i][j], expectedSchedule[i][j]);
        }
    }
}

TEST(BookingScheduleTest, MakeBookingSchedules) {
    int R[][2] = {
        {0, 2},
        {4, 6},
        {1, 7},
        {8, 9},
        {7, 10},
        {9, 10},
        {4, 10}
    };
    int n1 = sizeof(R1) / sizeof(R1[0]);

    int Schedule[50][3]; // Assuming a maximum of 50 bookings
    int m;

    makeBookingSchedules<int>(R, n1, Schedule, m);

    // Define the expected merged schedule (B)
    int expectedSchedule[][3] = {
        {1, 0, 1},
        {2, 1, 2},
        {1, 2, 4},
        {3, 4, 6},
        {2, 6, 7},
        {2, 7, 8},
        {3, 8, 9},
        {3, 9, 10}
    };

    // Check if the merged schedule matches the expected schedule
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 3; j++) {
            ASSERT_EQ(Schedule[i][j], expectedSchedule[i][j]);
        }
    }
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
