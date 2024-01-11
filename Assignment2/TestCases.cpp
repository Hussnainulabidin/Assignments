//#include "pch.h"
#include "ZooCage.cpp"
#include "String.cpp"
#include "BinaryStore.cpp"
#include <gtest/gtest.h>

// QUESTION 1

// ADD_CAGE TEST
TEST(ZooCage, add_Cage) {
	ZooChain obj;
	char name1[6] = "LION";
	char name2[6] = "TIGER";
	char name3[7] = "MONKEY";
	obj.add_Cage(name1, 12);
	obj.add_Cage(name2, 7);
	obj.add_Cage(name3, 20);
	char* test = obj.start->link->name;
	EXPECT_EQ(0, strcmp(name2, test));
	EXPECT_EQ(NULL, (obj.start->link->link->link));

	EXPECT_TRUE(true);
}

// PRINT_CHAIN TEST
TEST(ZooCage, print_Chain) {
	ZooChain obj;
	obj.print_Chain();
	char name1[6] = "LION";
	char name2[6] = "TIGER";
	char name3[7] = "MONKEY";
	obj.add_Cage(name1, 12);
	obj.add_Cage(name2, 7);
	obj.add_Cage(name3, 20);
	obj.print_Chain();

	EXPECT_TRUE(true);
}

// DELETE_CAGE TEST
TEST(ZooCage, delete_Chain) {
	ZooChain obj;
	char name1[6] = "LION";
	obj.add_Cage(name1, 12);
	obj.delete_Chain(12);
	EXPECT_EQ(NULL, (obj.start));
	char name2[6] = "TIGER";
	char name3[7] = "MONKEY";
	obj.add_Cage(name1, 12);
	obj.add_Cage(name2, 7);
	obj.add_Cage(name3, 20);
	obj.delete_Chain(7);
	EXPECT_EQ(0, strcmp(name3, (obj.start->link->name)));
	EXPECT_EQ(NULL, obj.start->link->link);
	char name4[5] = "DEER";
	obj.add_Cage(name4, 5);
	EXPECT_EQ(0, strcmp(name4, (obj.start->link->link->name)));

}

// SORT_CHAIN TEST
TEST(ZooCage, Sort_Chain) {
	ZooChain obj;
	char name1[6] = "LION";
	char name2[6] = "TIGER";
	char name3[7] = "MONKEY";
	obj.add_Cage(name1, 12);
	obj.add_Cage(name2, 7);
	obj.add_Cage(name3, 20);
	obj.Sort_Chain();

	EXPECT_EQ(0, strcmp(name2, (obj.start->name)));
	EXPECT_EQ(0, strcmp(name1, (obj.start->link->name)));
	EXPECT_EQ(0, strcmp(name3, (obj.start->link->link->name)));
	
	char name4[5] = "DEER";
	obj.add_Cage(name4, 5);

	obj.Sort_Chain();
	EXPECT_EQ(0, strcmp(name2, (obj.start->link->name)));
	EXPECT_EQ(0, strcmp(name1, (obj.start->link->link->name)));
	EXPECT_EQ(0, strcmp(name3, (obj.start->link->link->link->name)));
	EXPECT_EQ(0, strcmp(name4, (obj.start->name)));

}

TEST(ZooCage, remove_Duplicate) {
	ZooChain obj;
	char name1[6] = "LION";
	char name2[6] = "TIGER";
	char name3[7] = "MONKEY";
	obj.add_Cage(name1, 12);
	obj.add_Cage(name2, 7);
	obj.add_Cage(name3, 20);
	obj.add_Cage(name3, 20);
	obj.add_Cage(name1, 12);
	obj.remove_Duplicate();

	char* test = obj.start->link->name;
	EXPECT_EQ(0, strcmp(name2, test));
	EXPECT_EQ(NULL, (obj.start->link->link->link));

	ZooChain obj1;
	obj1.add_Cage(name1, 12);
	obj1.add_Cage(name1, 12);
	obj1.add_Cage(name1, 12);
	obj.remove_Duplicate();
	EXPECT_EQ(0, strcmp(name1, obj.start->name));
}

TEST(ZooCage, update_name_at_cageNumber) {
	ZooChain obj;
	char name1[6] = "LION";
	char name2[6] = "TIGER";
	char name3[7] = "MONKEY";
	obj.add_Cage(name1, 12);
	obj.add_Cage(name2, 7);
	obj.add_Cage(name3, 20);

	obj.update_name_at_cageNumber(7, "ZEBRA");
	obj.update_name_at_cageNumber(12, "ELEPHANT");
	obj.update_name_at_cageNumber(20, "WOLF");

	EXPECT_EQ(0, strcmp(obj.start->name, "ELEPHANT"));
	EXPECT_EQ(0, strcmp(obj.start->link->name, "ZEBRA"));
	EXPECT_EQ(0, strcmp(obj.start->link->link->name, "WOLF"));

}

// QUESTION 2

TEST(String, Constructors) {
	char s[] = "OOP-A02";
	String str(s);
	ASSERT_EQ(0, strcmp("OOP-A02", str.getdata()));

	String str1(5);
	ASSERT_EQ(0, strcmp("", str1.getdata()));

	String str2(str);
	ASSERT_EQ(0, strcmp(str2.getdata(), str.getdata()));
	ASSERT_NE(str2.getdata(), str1.getdata());

}

TEST(String, getChar) {
	char s[] = "Hello World!";
	String str(s);
	ASSERT_EQ('o', str.getChar(4));
	ASSERT_EQ('\0', str.getChar(12));

	String str1(str);
	ASSERT_EQ('H', str.getChar(0));
}

TEST(String, isEmpty) {
	char st[] = "OOP-A02";
	String str(st);
	ASSERT_EQ(false, str.isEmpty());
	ASSERT_EQ(7, str.length());

	String str1(5);
	ASSERT_EQ(true, str1.isEmpty());
	ASSERT_EQ(0, str1.length());
}

TEST(String, index_at) {
	char st[] = "OOP-Assignment02";
	String str(st);
	ASSERT_EQ(0, str.index_at('O'));
	ASSERT_EQ(2, str.index_at('P'));
	ASSERT_EQ(5, str.index_at('s'));
	ASSERT_EQ(14, str.index_at('0'));
	ASSERT_EQ(-1, str.index_at('F'));

	char st1[] = "Spring 2022";
	char t[] = "2022";
	String test(t);
	string test1(t);
	String str1(st1);
	ASSERT_EQ(2, str1.index_at("ring"));
	ASSERT_EQ(7, str1.index_at(test));
	ASSERT_EQ(7, str1.index_at(test1));
}

TEST(String, isEqual) {
	char st[] = "OOP-Assignment02";
	String str(st);

	char t1[] = "OOP", t2[] = "Assignment02", t3[] = "oop assignment02", t4[] = "OOP-Assignment02";
	ASSERT_EQ(false, str.isEqual(t1));
	ASSERT_EQ(false, str.isEqual(t2));
	ASSERT_EQ(false, str.isEqual(t3));
	ASSERT_EQ(true, str.isEqual(t4));

	char st1[] = "Spring 2023";
	String str1(st1);

	char t11[] = "spring 2023", t12[] = "sprIng 2022";
	ASSERT_EQ(false, str1.isEqual(t11));
	ASSERT_EQ(false, str1.isEqual(t12));
	ASSERT_EQ(true, str1.isEqual(st1));
}

TEST(String, append_string) {
	char st[] = "Assignment02";
	String str(st);
	char t1[] = "Ass";
	string t2 = "02";
	String str1(str);
	char t3 = 'g';
	str.append_string(t1);
	ASSERT_EQ(0, strcmp(str.getdata(), "Assignment02Ass"));
	str.append_string(t2);
	ASSERT_EQ(0, strcmp(str.getdata(), "Assignment02Ass02"));
	str.append_string(str1);
	ASSERT_EQ(0, strcmp(str.getdata(), "Assignment02Ass02Assignment02"));
	str.append_string(t3);
	ASSERT_EQ(0, strcmp(str.getdata(), "Assignment02Ass02Assignment02g"));
}

TEST(String, remove_string) {
	char st[] = "Spring 2023";
	String str(st);
	
	str.remove_string(' ');
	ASSERT_EQ(0, strcmp(str.getdata(), "Spring2023"));
	ASSERT_EQ(10, str.length());

	string t1 = "ring";
	str.remove_string(t1);
	ASSERT_EQ(0, strcmp(str.getdata(), "Sp2023"));
	ASSERT_EQ(6, str.length());

	char t2[] = "20";
	str.remove_string(t2);
	ASSERT_EQ(0, strcmp(str.getdata(), "Sp23"));
	ASSERT_EQ(4, str.length());

	String str1("Sp");
	str.remove_string(str1);
	ASSERT_EQ(0, strcmp(str.getdata(), "23"));
	ASSERT_EQ(2, str.length());

}

TEST(String, assign_string) {
	char st[] = "OOP-Assignment02";
	String str(st);
	
	str.assign_string("hello world");
	ASSERT_EQ(0, strcmp(str.getdata(), "hello world"));
	ASSERT_EQ(11, str.length());

	string t1 = "Spring2023";
	str.assign_string(t1);
	ASSERT_EQ(0, strcmp(str.getdata(), "Spring2023"));
	ASSERT_EQ(10, str.length());

	String str1("OOP-Assignment02");
	str.assign_string(str1);
	ASSERT_EQ(0, strcmp(str.getdata(), "OOP-Assignment02"));
	ASSERT_EQ(16, str.length());

}

// QUESTION 3

TEST(BinaryStore, start) {
	BinaryStore x(3);
	x.add_Address("0000");
	x.add_Address("0001");
	x.add_Address("0010");

	x.set_Byte("0000", "01010101");
	x.set_Byte("0010", "01010100");

	EXPECT_EQ(strcmp(x.Get("0000"), "01010101"), 0);
	EXPECT_EQ(x.Get("0001"), nullptr);
	EXPECT_EQ(strcmp(x.Get("0010"), "01010100"), 0);

}

TEST(BinaryStore, start1) {
	BinaryStore x(2);
	x.add_Address("0000");
	x.add_Address("0001");

	x.set_Byte("0000", "01010101");
	x.set_Byte("0010", "01010100");

	EXPECT_EQ(strcmp(x.Get("0000"), "01010101"), 0);
	EXPECT_EQ(strcmp(x.Get("0010"), "01010100"), 0);

	x.set_Byte("0000", "01111110");
	EXPECT_EQ(strcmp(x.Get("0000"), "01111110"), 0);
}

TEST(BinaryStore, Add) {
	BinaryStore x;
	char byt[] = "00001110";
	char byt2[] = "01110000";
	EXPECT_EQ(0, strcmp(x.Add(byt, byt2), "01111110"));
}

TEST(BinaryStore, Add1) {
	BinaryStore x;
	char byt[] = "00001010";
	char byt2[] = "01010110";
	EXPECT_EQ(strcmp(x.Add(byt, byt2), "01100000"), 0);

}

TEST(BinaryStore, comp_EQUAL) {
	BinaryStore x;
	char byt[] = "10001110";
	char byt2[] = "10001110";
	EXPECT_TRUE(x.comp_EQUAL(byt, byt2));
}

TEST(BinaryStore, comp_EQUAL1) {
	BinaryStore x;
	char byt[] = "10101110";
	char byt2[] = "10001110";
	EXPECT_FALSE(x.comp_EQUAL(byt, byt2));
}

TEST(BinaryStore, comp_OR) {
	BinaryStore x;
	char byt[] = "10101110";
	char byt2[] = "10001110";
	EXPECT_EQ(strcmp(x.comp_OR(byt, byt2), "10101110"), 0);
}

TEST(BinaryStore, comp_AND) {
	BinaryStore x;
	char byt[] = "11111110";
	char byt2[] = "10001010";
	EXPECT_TRUE(strcmp(x.comp_AND(byt, byt2), "10001010") == 0);
}

TEST(BinaryStore, comp_AND1) {
	BinaryStore x;
	char byt[] = "11111110";
	char byt2[] = "10001010";
	EXPECT_TRUE(strcmp(x.comp_AND(byt, byt2), "10001010") == 0);
}

TEST(BinaryStore, comp_NOT) {
	BinaryStore x;
	char byt[] = "11111110";
	char byt2[] = "10001010";
	EXPECT_TRUE(strcmp(x.comp_NOT(byt), "00000001") == 0);
	EXPECT_TRUE(strcmp(x.comp_NOT(byt2), "01110101") == 0);
}

// QUESTION 4
// Demo of file.

int main(int argc, char** argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

