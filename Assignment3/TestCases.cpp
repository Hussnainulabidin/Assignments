#include "Array.cpp"
#include "BigInt.cpp"
#include "Book.cpp"
#include <gtest/gtest.h>
// Q1: Array.cpp

TEST(ArrayTest, DefaultConstructor) {
    Array arr;
    EXPECT_EQ(arr.size(), 0);
}


TEST(ArrayTest, ParametrizedConstructor) {
    Array arr(5);
    EXPECT_EQ(arr.size(), 5);
}
TEST(ArrayTest, ParameterizedConstructor) {
  Array a(3);
  EXPECT_EQ(a[0], 0);
  EXPECT_EQ(a[1], 0);
  EXPECT_EQ(a[2], 0);
}

TEST(ArrayTest, ConstructorWithExistingArray) {
  int arr[3] = {1, 2, 3};
  Array a(arr, 3);
  EXPECT_EQ(a[0], 1);
  EXPECT_EQ(a[1], 2);
  EXPECT_EQ(a[2], 3);
}

TEST(ArrayTest, InitializingWithExistingArray) {
    int values[5] = {1, 2, 3, 4, 5};
    Array arr(values, 5);
    EXPECT_EQ(arr.size(), 5);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 3);
    EXPECT_EQ(arr[3], 4);
    EXPECT_EQ(arr[4], 5);
}

TEST(ArrayTest, CopyConstructor) {
    Array arr1(5);
    Array arr2(arr1);
    EXPECT_EQ(arr1.size(), arr2.size());
}


TEST(ArrayTest, OperatorPlus) {
    int values1[3] = {1, 2, 3};
    int values2[3] = {4, 5, 6};
    Array arr1(values1, 3);
    Array arr2(values2, 3);
    Array result = arr1 + arr2;
    EXPECT_EQ(result[0], 5);
    EXPECT_EQ(result[1], 7);
    EXPECT_EQ(result[2], 9);
}

TEST(ArrayTest, OperatorMinus) {
    int values1[3] = {4, 5, 6};
    int values2[3] = {1, 2, 3};
    Array arr1(values1, 3);
    Array arr2(values2, 3);
    Array result = arr1 - arr2;
    EXPECT_EQ(result[0], 3);
    EXPECT_EQ(result[1], 3);
    EXPECT_EQ(result[2], 3);
}

TEST(ArrayTest, OperatorPlusEquals) {
    int values1[3] = {1, 2, 3};
    int values2[3] = {4, 5, 6};
    Array arr1(values1, 3);
    Array arr2(values2, 3);
    arr1 += arr2;
    EXPECT_EQ(arr1[0], 5);
    EXPECT_EQ(arr1[1], 7);
    EXPECT_EQ(arr1[2], 9);
}

TEST(ArrayTest, OperatorMinusEquals) {
    int values1[3] = {4, 5, 6};
    int values2[3] = {1, 2, 3};
    Array arr1(values1, 3);
    Array arr2(values2, 3);
    arr1 -= arr2;
    EXPECT_EQ(arr1[0], 3);
    EXPECT_EQ(arr1[1], 3);
    EXPECT_EQ(arr1[2], 3);
}

TEST(ArrayTest, OperatorPrefixPlusPlus) {
    int values[3] = {1, 2, 3};
    Array arr(values, 3);
    ++arr;
    EXPECT_EQ(arr[0], 2);
    EXPECT_EQ(arr[1], 3);
    EXPECT_EQ(arr[2], 4);
}

TEST(ArrayTest, OperatorPostfixPlusPlus) {
    int values[3] = {1, 2, 3};
    Array arr(values, 3);
    arr++;
    EXPECT_EQ(arr[0], 2);
    EXPECT_EQ(arr[1], 3);
    EXPECT_EQ(arr[2], 4);
    }


TEST(ArrayTest, OperatorPostfixMinusMinus) {
    int values[3] = {4, 5, 6};
    Array arr(values, 3);
    arr--;
    // the postfix operator returns a copy of the Array before subtracting one from each element
    EXPECT_EQ(arr[0], 3);
    EXPECT_EQ(arr[1], 4);
    EXPECT_EQ(arr[2], 5);
}

TEST(ArrayTest, OperatorEquals) {
    int values[3] = {1, 2, 3};
    Array arr1(values, 3);
    Array arr2 = arr1;
    EXPECT_EQ(arr2[0], 1);
    EXPECT_EQ(arr2[1], 2);
    EXPECT_EQ(arr2[2], 3);
}

TEST(ArrayTest, OperatorEqualEqual) {
    int values1[3] = {1, 2, 3};
    int values2[3] = {1, 2, 3};
    Array arr1(values1, 3);
    Array arr2(values2, 3);
    EXPECT_TRUE(arr1 == arr2);
}

TEST(ArrayTest, OperatorNot) {
    Array arr;
    EXPECT_TRUE(!arr);
    int values[3] = {1, 2, 3};
    Array arr2(values, 3);
    EXPECT_FALSE(!arr2);
}

TEST(ArrayTest, OperatorParentheses) {
    int values[3] = {1, 2, 3};
    Array arr(values, 3);
    EXPECT_EQ(arr(1, 3), -1); // should return -1 because 3 is not at index 1
    EXPECT_EQ(arr(2, 3), 1); // should return 1 and set arr[2] to 0
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 0);
}

TEST(ArrayTest, InputOperator) {

    Array arr(3);
    std::stringstream ss;
    ss << "1 2 3";
    ss >> arr;
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 3);
}






// Q2: BigInt  


TEST(BigInt, Constructors) { 
    string expected1="119622220865480194561963161495657715064383733760000000000";
    string expected2="99999";
    BigInt a(expected1);
    BigInt b(99999);
    BigInt c(a);
    string s1=(string)a;
    string s2=(string)b;
    string s3=(string)c;
    ASSERT_EQ(0, s1.compare(expected1));
    ASSERT_EQ(0, s2.compare(expected2));
    ASSERT_EQ(0, s3.compare(expected1));
    
}
TEST(BigInt, Addition) { 
        string str="9999999999999999999";
	BigInt a(str);
	BigInt b=a+1;
	BigInt c;
	c=a+b;
        BigInt d(2);
        d+=a;
        
        string s1=(string)b; string expected1="10000000000000000000";
        string s2=(string)c; string expected2="19999999999999999999";
        string s3=(string)d; string expected3="10000000000000000001";
        
        ASSERT_EQ(0, s1.compare(expected1));
        ASSERT_EQ(0, s2.compare(expected2));
        ASSERT_EQ(0, s3.compare(expected3));
       
        
}

TEST(BigInt, Subtraction) { 
        string str="10000000000000000000";
	BigInt a(str);
	BigInt b=a-1;
	BigInt c;
	c=a-b;
        BigInt d(2);
        a-=d;
        
        string s1=(string)b; string expected1="9999999999999999999";
        string s2=(string)c; string expected2="1";
        string s3=(string)a; string expected3="9999999999999999998";
        
        ASSERT_EQ(0, s1.compare(expected1));
        ASSERT_EQ(0, s2.compare(expected2));
        ASSERT_EQ(0, s3.compare(expected3));
    
}
TEST(BigInt, Mul) { 
        string str="119622220865480194561963161495657715064383733760000000000";
	BigInt a(str);
	BigInt b;
	BigInt c=a*b;
	
        BigInt d(46);
        a*=d;
        
        string s1=(string)c; string expected1="0";
        string s2=(string)a; string expected2="5502622159812088949850305428800254892961651752960000000000";
                
        ASSERT_EQ(0, s1.compare(expected1));
        ASSERT_EQ(0, s2.compare(expected2));
        
    
}

TEST(BigInt, Compund Operator ){
    
    BigInt a("-123456789");
    BigInt b("-987654321");
    a *= b;
    
    EXPECT_EQ((string)a, "121932631112635269");
    
    BigInt e("-123456789");
    BigInt f("-987654321");
    e += f;
    EXPECT_EQ((string)e, "-1111111110");
    
    BigInt c("987654321");
    BigInt d("123456789");
    c -= d;
    EXPECT_EQ((string)c, "864197532");

}

TEST(BigInt, LogicalOperators) { 
        string str1="119622220865480194561963161495657715064383733760000000000";
	string str2="5502622159812088949850305428800254892961651752960000000000";
	BigInt a(str1);
	BigInt c(str1);
	BigInt b(str2);
	                
        ASSERT_EQ(true, a==c);
        ASSERT_EQ(true, a== "119622220865480194561963161495657715064383733760000000000");
        ASSERT_EQ(false, a==b);
        ASSERT_EQ(false, a=="395740357023972035970293759348693475203957209357203752035");
        ASSERT_EQ(true, a!=b);
        ASSERT_EQ(true, a<=b);
        ASSERT_EQ(false, a>=b);
        ASSERT_EQ(false, a>b);
        ASSERT_EQ(true, a<b);
        
    
}

TEST(BigInt, UnaryOperators) { 
        string str1="9999999999999999999";
	string str2="10000000000000000000";
	BigInt a(str1);
	BigInt c(str1);
	BigInt b(str2);
	a++;
	string s1=(string)a; string expected1="10000000000000000000";
        ASSERT_EQ(0, s1.compare(expected1));
	
	--a;
	string s2=(string)a; string expected2="9999999999999999999";
        ASSERT_EQ(0, s2.compare(expected2));
	
	++b;
	string s3=(string)b; string expected3="10000000000000000001";
        ASSERT_EQ(0, s3.compare(expected3));
	
	b--;
	string s4=(string)b; string expected4="10000000000000000000";
        ASSERT_EQ(0, s4.compare(expected4));                
        
        
    
}
TEST(BigInt, InputOutput) { 
        BigInt s1;
        cin>>s1;// input "2019" on terminal
        BigInt s2("2019");
        cout<<s1;
        ASSERT_EQ(true,s2==s1 );
    
}






int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
