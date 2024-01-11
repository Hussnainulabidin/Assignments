#include "Submission.cpp"
#include <gtest/gtest.h>


// Q1: String and Array Manipulation

TEST(RemoveSentence,Test1)
{
	char* Para = "Helpdesk: There is an icon on your computer labeled My Computer. Double click on it. User: What's your computer doing on mine?";
	char* input = "Double click on it.";
	char* output = "Helpdesk: There is an icon on your computer labeled My Computer. User: What's your computer doing on mine?";
	ASSERT_EQ(0,strcmp(output, removeSentence(Para, input)));
}

TEST(RemoveSentence,Test2)
{
	char* Para = "A son asked his father (a programmer) why the sun rises in the east, and sets in the west. His response? It works, don’t touch!";
	char* input = "(a programmer)";
	char* output = "A son asked his father why the sun rises in the east, and sets in the west. His response? It works, don’t touch!";
	ASSERT_EQ(0,strcmp(output, removeSentence(Para, input)));
}

TEST(FindSubString,Test1)
{
	char* Str = "abcdab";
	char* substr = "dababc";
	int start = 0, end = 0;
	ASSERT_EQ(true, FindSubString(Str,substr,start, end));
	ASSERT_EQ(3, start);
	ASSERT_EQ(2, end);
}

TEST(FindSubString,Test2)
{
	char* Str = "plagiarism";
	char* substr = "mp";
	int start = 0, end = 0;
	ASSERT_EQ(true, FindSubString(Str,substr,start, end));
	ASSERT_EQ(9, start);
	ASSERT_EQ(0, end);
}

TEST(FindSubString,Test3)
{
	char* Str = "affects";
	char* substr = "sad";
	int start = 0, end = 0;
	ASSERT_EQ(false, FindSubString(Str,substr,start, end));
	ASSERT_EQ(-1, start);
	ASSERT_EQ(-1, end);
}

// Q2: 3D String Matching

TEST(StringMatching, XCheck) 
{
	char arr[28] = "sbtaicztieahrnltagtsjvehfyf";
	char*** mat = ConvertToDynamic(arr, 3, 3, 4);

	char* str = "tag";
	int c = 3, ans[3][3] = { {1, 1, 1},
							 {2, 2, 2},
							 {0, 1, 2} };
	int col, ** res;

	ASSERT_EQ(1, MatchString3DArray(mat, 3, 3, 4, str, res, col));
	ASSERT_EQ(c, col);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < c; j++)
			ASSERT_EQ(ans[i][j], res[i][j]);

	DeleteArray(mat, 3, 3, 4);
	ASSERT_EQ(NULL, mat);

}

TEST(StringMatching, YCheck) 
{
	char arr[28] = "sbtaicztieahrnltagtsjvehfyf";
	char*** mat = ConvertToDynamic(arr, 3, 3, 4);

	char* str = "yes";
	int c = 3, ans[3][3] = { {2, 2, 2},
							 {2, 1, 0},
							 {1, 1, 1} };
	int col, ** res;

	ASSERT_EQ(1, MatchString3DArray(mat, 3, 3, 4, str, res, col));
	ASSERT_EQ(c, col);
	
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < c; j++) 
			ASSERT_EQ(ans[i][j], res[i][j]);
	
	DeleteArray(mat, 3, 3, 4);
	ASSERT_EQ(NULL, mat);
}

TEST(StringMatching, ZCheck) 
{
	char arr[28] = "sbtaicztieahrnltagtsjvehfyf";
	char*** mat = ConvertToDynamic(arr, 3, 3, 4);

	char* str = "set";
	int c = 3, ans[3][3] = { {0, 1, 2},
							 {0, 0, 0},
							 {0, 0, 0} };
	int col, ** res;

	ASSERT_EQ(1, MatchString3DArray(mat, 3, 3, 4, str, res, col));
	ASSERT_EQ(c, col);
	
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < c; j++)
			ASSERT_EQ(ans[i][j], res[i][j]);

	DeleteArray(mat, 3, 3, 4);
	ASSERT_EQ(NULL, mat);
}

TEST(StringMatching, DiagonalCheck) 
{
	char arr[28] = "sbtaicztieahrnltagtsjvehfyf";
	char*** mat = ConvertToDynamic(arr, 3, 3, 4);

	char* str = "zi";
	int c = 2, ans[3][2] = { {0, 0},
							 {2, 1},
							 {0, 1} };
	int col, ** res;

	ASSERT_EQ(1, MatchString3DArray(mat, 3, 3, 4, str, res, col));
	ASSERT_EQ(c, col);
	
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < c; j++)
			ASSERT_EQ(ans[i][j], res[i][j]);

	DeleteArray(mat, 3, 3, 4);
	ASSERT_EQ(NULL, mat);
}

// Q3: Recursive Funstions

TEST(PerfectNumber,Test1)
{
    ASSERT_EQ(true, isperfectNumber(28));
}

TEST(PerfectNumber,Test2)
{
    ASSERT_EQ(false, isperfectNumber(17));
}

TEST(FindVowels,Test1)
{
	char* input = "rm -rf /osama/bin/laden";
    ASSERT_EQ(6, findVowels(input));
}

TEST(FindVowels,Test2)
{
    char* input = "it’s not a bug — it’s an undocumented feature";
    ASSERT_EQ(15, findVowels(input));
}

TEST(FindVowels,Test3)
{
    char* input = "when all else fails … reboot";
    ASSERT_EQ(9, findVowels(input));
}

TEST(PascalTriangle,Test1)
{
    ASSERT_EQ(6, pascal(4,2));
}

TEST(PascalTriangle,Test2)
{
    ASSERT_EQ(1, pascal(9,9));
}

int main(int argc, char** argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

