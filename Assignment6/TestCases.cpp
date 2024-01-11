#include <gtest/gtest.h>
#include "header.h"
TEST(q1, base) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T1.txt");
    string result  =  obj.GetPath(1, 6);
    string org = "1-1 -> 2-1 -> 3-1 -> 4-1 -> 4-2 -> 5-2 -> 6-2";
    // for each pair the first value gives the location node id and the second value tells the current layer;
    EXPECT_EQ(result, org);
}

TEST(q1, add_del) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T1.txt");
    obj.addNode(1,5);
    obj.DeleteNode(1,2);
    string result = obj.GetPath(1,6);
    string org = "1-1 -> 1-2 -> 2-2 -> 3-2 -> 3-1 -> 4-1 -> 5-1 -> 6-1";
    EXPECT_EQ(result, org);
}
TEST(q1, t2) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T2.txt");
    string result  =  obj.GetPath(4, 6);
    string org = "4-1 -> 3-1 -> 3-2 -> 3-3 -> 4-3 -> 5-3 -> 6-3";
    // for each pair the first value gives the location node id and the second value tells the current layer;
    EXPECT_EQ(result, org);
}


TEST(q1, base) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T1.txt");
    string result  =  obj.GetPath(1, 6);
    string org = "1-1 -> 2-1 -> 3-1 -> 4-1 -> 4-2 -> 5-2 -> 6-2";
    // for each pair the first value gives the location node id and the second value tells the current layer;
    EXPECT_EQ(result, org);
}
// q2 has no restriction on starting layer
TEST(q2, t1) {
    Transport_Cost_Calculator obj;
    obj.ReadFile("Q2T1.txt");
    EXPECT_EQ(48,obj.GetMinCost(1,4));
    //1-1 -> 2-1 -> 3-1 -> 3-2 -> 3-3 -> 4-3
    //     1  +   5   +  5   +  5   + 32   = 48
}
TEST(q2, t2) {
    Transport_Cost_Calculator obj;
    obj.ReadFile("Q2T1.txt");
    EXPECT_EQ(4,obj.GetMinCost(4,5));
}
int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
