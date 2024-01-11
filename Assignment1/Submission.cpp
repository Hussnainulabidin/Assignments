#include <iostream>
using namespace std;


// Name    : Hussnain Ul Abidin
// Roll no : 22i-1102
// Section : K

char* removeSentence(char* Para, char* input)   //Q1 part A
{
	int len = 0;
    for (int i = 0; Para[i] != '\0'; ++i)
    {
        len += 1;
    }
    char *ptr = new char[len];
    for (int i = 0; Para[i] != '\0'; ++i)
    {
        ptr[i] = Para[i];
    }
    bool check = false;
    int start_ind = 0;
    int end_ind = 0;
    for (int i = 0; ptr[i] != '\0'; ++i)
    {

        check = false;
        if (ptr[i] == input[0])
        {
            check = true;
            start_ind = i;
            int k = i + 1;
            for (int j = 1; input[j] != '\0'; ++j)
            {
                if (ptr[k] != input[j])
                {
                    check = false;
                    break;
                }
                k++;
            }
            if (check == true)
            {
                end_ind = k;
                break;
            }
        }
    }
    int j = start_ind;
    for (int i = end_ind + 1; Para[i] != '\0'; ++i)
    {
        ptr[j] = ptr[i];
        j++;
    }
    ptr[j] = '\0';
    return ptr;
}

bool FindSubString(char* Str, char* substr, int& start, int& end)   //Q1 Part B
{
    bool flag = false;
    bool reverse = false;
    for (int i = 0; Str[i] != '\0'; ++i)
    {
        flag = false;
        if (Str[i] == substr[0])  //Checking if the first char if sub array us equal to any char of main array
        {
            int k = i + 1;
            if (Str[k] == '\0')
                k = 0;
            start = i;
            if (Str[k] == substr[1]) // if next char is also equal then start checking from here in forward direction
            {
                flag = true;
                // if (str[k] == '\0')
                //     k = 0;
                for (int j = 1; substr[j] != '\0'; ++j)
                {
                    if (Str[k] == '\0')     //if end of main array us reached start checking from first index
                    {
                        k = 0;
                    }
                    if (substr[j] != Str[k])    //if any char is no same braking through the loop and making flag false
                    {
                        flag = false;
                        break;
                    }
                    k++;
                }
            }
            if (Str[i - 1] == substr[1])// if previous char is equal then start checking from here in backward direction
            {
                flag = true; //makin flag true to return
                k = i - 1;
                reverse = true;
                for (int j = 1; substr[j] != '\0'; ++j) // start interating to check all char are equal
                {
                    if (Str[k] == '\0')  //if end of main array us reached start checking from first index
                    {
                        k = 0;
                    }
                    if (substr[j] != Str[k])  //if any char is no same braking through the loop and making flag false
                    {
                        flag = false;
                        break;
                    }
                    k--;
                }
            }
            if (flag)
            {
                end = k - 1;
                break;
            }
        }
    }
    if (reverse == true || flag == false)
    {
        start = -1;
        end = -1;
    }
    return flag;
}

char*** ConvertToDynamic(char arr[], int x, int y, int z) //Converts 1D Array to 3D dynamically allocated array
{
    //Making a 3D array in the heap
    char*** ptr = new char **[x];
    for (int i = 0; i < x; ++i)
    {
        ptr[i] = new char*[y];
    }

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            ptr[i][j] = new char[z];
        }
    }
    int idx = 0;
    //copy all the char if 1D array in 3D dynamic array
    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            for (int k = 0; k < z; ++k)
            {
                if (k == z - 1)
                {
                    ptr[i][j][k] = '\0';
                    break;
                }
                ptr[i][j][k] = arr[idx];
                idx++;
            }
        }
    }
    return ptr;
}

bool MatchString3DArray(char*** mat, int xSize, int ySize, int zSize, char * input, int**& resultMat, int& colSize)//find substring
{
    colSize = 0;
    for (int i = 0; input[i] != '\0'; ++i) //checking the length if input array
    {
        colSize += 1;
    }
    resultMat = new int *[3];              //creating an 2d array to store indexes of result in it
    for (int i = 0; i < 3; ++i)
    {
        resultMat[i] = new int[colSize];
    }
    int idx = 0;
    bool check = false;
    int count = 0;

    // Searching horizontally

    for (int i = 0; i < xSize; ++i)
    {
        for (int j = 0; j < ySize; ++j)
        {
            count = 0;
            check = false;
            for (int k = 0; mat[i][j][k] != '\0'; ++k)
            {
                check = false;
                count = 0;
                if (mat[i][j][k] == input[0]) // if first index matches start interating from here
                {
                    if (mat[i][j][k + 1] == input[1])
                    {
                        int z = k + 1;
                        check = true;
                        count += 1;
                        for (int x = 1; input[x] != '\0'; ++x)
                        {
                            if (mat[i][j][z] != input[x])
                            {
                                check = false;
                                break;
                            }
                            count += 1;
                            z++;
                        }
                        if (count == colSize)
                        {
                            for (int x = 0; x < colSize; ++x)
                            {
                                resultMat[0][x] = i;
                                resultMat[1][x] = j;
                                resultMat[2][x] = k + x;
                            }
                            return check;
                        }
                        
                        count = 0;
                    }
                    if (i + 1 < xSize)
                        if (mat[i + 1][j][k] == input[1])
                        {
                            int z = i + 1;
                            check = true;
                            count += 1;
                            for (int x = 1; input[x] != '\0'; ++x)
                            {
                                if (mat[z][j][k] != input[x])
                                {
                                    check = false;
                                    break;
                                }
                                count += 1;
                                z++;
                            }
                            if (count == colSize)
                            {
                                for (int x = 0; x < colSize; ++x)
                                {
                                    resultMat[0][x] = i + x;
                                    resultMat[1][x] = j;
                                    resultMat[2][x] = k;
                                }
                                return check;
                            }
                            count = 0;
                        }
                    if (k - 1 >= 0)
                        if (mat[i][j][k - 1] == input[1])
                        {
                            int z = k - 1;
                            check = true;
                            count += 1;
                            for (int x = 1; input[x] != '\0'; ++x)
                            {
                                if (mat[i][j][z] != input[x])
                                {
                                    check = false;
                                    break;
                                }
                                count += 1;
                                z--;
                            }
                            if (count == colSize)
                            {
                                for (int x = 0; x < colSize; ++x)
                                {
                                    resultMat[0][x] = i;
                                    resultMat[1][x] = j;
                                    resultMat[2][x] = k - x;
                                }
                                return check;
                            }
                            count = 0;
                        }
                    if(i-1 >= 0)
                        if(mat[i-1][j][k] == input[i])
                        {
                            int z = i - 1;
                            check = true;
                            count += 1;
                            for (int x = 1; input[x] != '\0'; ++x)
                            {
                                if (mat[z][j][k] != input[x])
                                {
                                    check = false;
                                    break;
                                }
                                count += 1;
                                z--;
                            }
                            if (count == colSize)
                            {
                                for (int x = 0; x < colSize; ++x)
                                {
                                    resultMat[0][x] = i-x;
                                    resultMat[1][x] = j;
                                    resultMat[2][x] = k;
                                }
                                return check;
                            }
                            count = 0;
                        }
                }
            }
        }
    }
    check = false;
    count = 0;

    // searching vertically
    for (int i = 0; i < xSize; ++i)
    {
        for (int k = 0; k < zSize - 1; ++k)
        {
            for (int j = 0; j < ySize; ++j)
            {
                int count = 0;
                check = false;
                if (mat[i][j][k] == input[0])
                {
                    if (j + 1 < ySize)
                        if (mat[i][j + 1][k] == input[1])
                        {
                            check = true;
                            int z = j + 1;
                            count += 1;
                            for (int x = 1; input[x] != '\0'; ++x)
                            {
                                if (mat[i][z][k] != input[x])
                                {
                                    check = false;
                                    break;
                                }
                                count += 1;
                                z++;
                            }
                            if (count == colSize)
                            {
                                for (int x = 0; x < colSize; ++x)
                                {
                                    resultMat[0][x] = i;
                                    resultMat[1][x] = j + x;
                                    resultMat[2][x] = k;
                                }
                                return check;
                            }
                            count = 0;
                        }
                    if (j - 1 >= 0)
                        if (mat[i][j - 1][k] == input[1])
                        {
                            check = true;
                            int z = j - 1;
                            count += 1;
                            for (int x = 1; input[x] != '\0'; ++x)
                            {
                                if (mat[i][z][k] != input[x])
                                {
                                    check = false;
                                    break;
                                }
                                count += 1;
                                z--;
                            }
                            if (count == colSize)
                            {
                                for (int x = 0; x < colSize; ++x)
                                {
                                    resultMat[0][x] = i;
                                    resultMat[1][x] = j - x;
                                    resultMat[2][x] = k;
                                }
                                return check;
                            }
                            count = 0;
                        }
                    if (i - 1 >= 0)
                        if (mat[i - 1][j][k] == input[1])
                        {
                            check = true;
                            int z = i - 1;
                            count += 1;
                            for (int x = 1; input[x] != '\0'; ++x)
                            {
                                if (mat[z][j][k] != input[x])
                                {
                                    check = false;
                                    break;
                                }
                                count += 1;
                                z--;
                            }
                            if (count == colSize)
                            {
                                for (int x = 0; x < colSize; ++x)
                                {
                                    resultMat[0][x] = i - x;
                                    resultMat[1][x] = j;
                                    resultMat[2][x] = k;
                                }
                                return check;
                            }
                        }
                    if (i + 1 < xSize && j + 1 < ySize)
                        if (mat[i + 1][j + 1][k] == input[1])
                        {
                            check = true;
                            int z = i + 1;
                            int a = j + 1;
                            count += 1;
                            for (int x = 1; input[x] != '\0'; ++x)
                            {
                                if (mat[z][a][k] != input[x])
                                {
                                    check = false;
                                    break;
                                }
                                count += 1;
                                z++;
                                a++;
                            }
                            if (count == colSize)
                            {
                                for (int x = 0; x < colSize; ++x)
                                {
                                    resultMat[0][x] = i + x;
                                    resultMat[1][x] = j + x;
                                    resultMat[2][x] = k;
                                }
                                return check;
                            }
                        }
                    if (i - 1 >= 0 && j - 1 >= 0)
                        if (mat[i - 1][j - 1][k] == input[1])
                        {
                            check = true;
                            int z = i - 1;
                            int a = j - 1;
                            count += 1;
                            for (int x = 1; input[x] != '\0'; ++x)
                            {
                                if (mat[z][a][k] != input[x])
                                {
                                    check = false;
                                    break;
                                }
                                count += 1;
                                z--;
                                a--;
                            }
                            if (count == colSize)
                            {
                                for (int x = 0; x < colSize; ++x)
                                {
                                    resultMat[0][x] = i - x;
                                    resultMat[1][x] = j - x;
                                    resultMat[2][x] = k;
                                }
                                return check;
                            }
                        }
                }
            }
        }
    }
    count = 0;
    check = false;


    // checking diagonlly
    for (int i = 0; i < xSize; ++i)
    {
        for (int j = 0; j < ySize; ++j)
        {
            for (int k = 0; k < zSize; ++k)
            {
                if (mat[i][j][k] == input[0])
                {
                    count = 0;
                    check = false;
                    if (j + 1 < ySize && k + 1 < zSize - 1)
                        if (mat[i][j + 1][k + 1] == input[1])
                        {
                            check = true;
                            int z = j + 1;
                            int a = k + 1;
                            count += 1;
                            for (int x = 1; input[x] != '\0'; ++x)
                            {
                                if (mat[i][z][a] != input[x])
                                {
                                    check = false;
                                    break;
                                }
                                count += 1;
                                z++;
                                a++;
                            }
                            if (count == colSize)
                            {
                                for (int x = 0; x < colSize; ++x)
                                {
                                    resultMat[0][x] = i;
                                    resultMat[1][x] = j + x;
                                    resultMat[2][x] = k + x;
                                }
                                return check;
                            }
                            count = 0;
                        }
                    if (j - 1 >= 0 && k + 1 < zSize-1)
                        if (mat[i][j - 1][k + 1] == input[1])
                        {
                            check = true;
                            int z = j - 1;
                            int a = k + 1;
                            count += 1;
                            for (int x = 1; input[x] != '\0'; ++x)
                            {
                                if (mat[i][z][a] != input[x])
                                {
                                    check = false;
                                    break;
                                }
                                count += 1;
                                z--;
                                a++;
                            }
                            if (count == colSize)
                            {
                                for (int x = 0; x < colSize; ++x)
                                {
                                    resultMat[0][x] = i;
                                    resultMat[1][x] = j - x;
                                    resultMat[2][x] = k + x;
                                }
                            
                            return check;
                            }
                            count = 0;
                        }
                    if(k - 1 >= 0 && j + 1 < ySize )
                        if(mat[i][j+1][k-1] == input[1])
                        {
                            check = true;
                            int z = j + 1;
                            int a = k - 1;
                            count += 1;
                            for (int x = 1; input[x] != '\0'; ++x)
                            {
                                if (mat[i][z][a] != input[x])
                                {
                                    check = false;
                                    break;
                                }
                                count += 1;
                                z++;
                                a--;
                            }
                            if (count == colSize)
                            {
                                for (int x = 0; x < colSize; ++x)
                                {
                                    resultMat[0][x] = i;
                                    resultMat[1][x] = j + x;
                                    resultMat[2][x] = k - x;
                                }
                                return check;
                            }
                            count = 0;
                        }
                    if(j-1 >= 0 && k-1 >= 0 )
                        if(mat[i][j-1][k-1] && input[1])
                        {
                            check = true;
                            int z = j - 1;
                            int a = k - 1;
                            count += 1;
                            for (int x = 1; input[x] != '\0'; ++x)
                            {
                                if (mat[i][z][a] != input[x])
                                {
                                    check = false;
                                    break;
                                }
                                count += 1;
                                z--;
                                a--;
                            }

                            if (count == colSize)
                            {
                                for (int x = 0; x < colSize; ++x)
                                {
                                    resultMat[0][x] = i;
                                    resultMat[1][x] = j - x;
                                    resultMat[2][x] = k - x;
                                }
                                return check;
                            }
                            count = 0;
                        }
                }
            }
        }
    }
    
    for(int i = 0 ; i < 3; ++i)
    {
        for(int j = 0 ; j < colSize ; ++j)
        {
            resultMat[i][j] = -1;
        }
    }

    return false;
}

void DeleteArray(char***& arr, int x, int y, int z)  //Delete 3D array
{
    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            delete [] arr[i][j];
            
        }
        delete[] arr[i];

    }
    delete[] arr;
    arr = nullptr;
}

bool isperfectNumber(int n)
{
    static int ans = 0;
    static int num = n;
    if(n < 2 )
        return false;
    if(num % (n-1) == 0)
    {
        ans +=  n-1 + isperfectNumber(n - 1);
    }
    else if(num % (n-1) != 0)
    {
        isperfectNumber(n - 1);
    }
    if( ans == num)
        return true;
    else
        return false;
}

int findVowels(char* str)
{
    if(*str == '\0')
    {
        return 0;
    }
    if(*str == 'a'  || *str == 'e'  || *str == 'i'  || *str == 'o'  || *str == 'u'  || *str == 'A'  || *str == 'E'  || *str == 'I'  || *str == 'O'  || *str == 'U')
    {
        return 1 + findVowels(++str);
    }
    else
        return 0 + findVowels(++str);
}

int pascal(int row, int col)
{
    if(row != col && col != 0)
    {
        return pascal(row - 1, col) + pascal(row-1, col - 1);
    }
    else
    {
        return 1;
    }
}

void spaces(int s)
{
    if(s < 1 )
    {
        return;
    }
    else
        cout << " ";
    spaces(s-1);
}

void PrintPattern1(int start, int end)
{
    if(start >= end)
        return;
    else
    {
        spaces(end-2);
        cout << "*";
        cout << endl;
    }
    PrintPattern1(start , end-2);
    start -= 2;
    spaces(end-2);
    if(end > 2)
    {
        cout << "*";
        cout << endl;
    }
}

void spaces2(int n)
{
    if(n <= 0)
        return;
    else
        cout << " ";
    spaces2(n - 1);
}

void star2(int n)
{
    if(n < 1)
        return;
    else
        cout << "*";
    star2(n - 1);
}

void printdiamond(int n , int spaces)
{
    if(n <= 0)
        return;
    else
    {
        star2(n);
        spaces2(spaces);
        star2(n);
        cout << endl;
    }
    printdiamond(n - 1 , spaces+2);
    if(n > 0)
    {
        star2(n);
        spaces2(spaces);
        star2(n);
        cout << endl;
    }
}

void printHollowDiamond(int n)
{
    int spaces = 0;
    printdiamond(n, spaces);
}


void printspaces(int s)
{
    if (s <= 0)
        return;
    else
        cout << "  ";
    printspaces(s - 1);
}

void printdot(int d)
{
    if (d <= 0)
        return;
    else
        cout << " .";
    printdot(d - 1);
}

void printstar(int s)
{
    if (s <= 0)
        return;
    else
        cout << " *";
    printstar(s - 1);
}

void PrintPattern2(int n, int m)
{
    if (n <= 0 || m < 0)
        return;
    else
    {
        printspaces(n - 1);
        cout << " #";
        printdot(n);
        printstar(m - n);
        cout << " |";
        printstar(m - n);
        printdot(n);

        cout << " #";
        cout << endl;
    }
    PrintPattern2(n - 1, m + 1);
    if(n != 1)
    {
        printspaces(n - 1);
        cout << " #";
        printdot(n);
        printstar(m - n);
        cout << " |";
        printstar(m - n);
        printdot(n);
        cout << " #";
        cout << endl;
    }
}

int **snakeBoardCreation(int rows, int col)
{
    int **ptr = new int *[rows];
    for (int i = 0; i < rows; ++i)
    {
        ptr[i] = new int[col];
    }
    int num = 1;
    for (int i = rows - 1; i >= 0; --i)
    {
        if (i % 2 == 0)
            for (int j = 0; j < col; ++j)
            {
                if (num <= rows * col)
                {
                    ptr[i][j] = num;
                }
                num++;
            }
        else
            for (int j = col - 1; j >= 0; --j)
            {
                if (num <= rows * col)
                {
                    ptr[i][j] = num;
                }
                num++;
            }
    }
    return ptr;
}

void displayBoard(int **ptr, int rows, int col, int turn, int posi)
{

    static int posi1 = 0;
    static int posi2 = 0;
    if (turn == 1)
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (ptr[i][j] == 0)
                {
                    ptr[i][j] = posi1;
                }
            }
        }
        posi1 = posi;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (ptr[i][j] == posi)
                {
                    cout << "hello" << endl;
                    ptr[i][j] = 0;
                }
            }
        }
    }
    else if (turn == 2)
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (ptr[i][j] == -1)
                {
                    ptr[i][j] = posi1;
                }
            }
        }
        posi2 = posi;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (ptr[i][j] == posi)
                {
                    ptr[i][j] = -1;
                }
            }
        }
    }
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (ptr[i][j] < 10)
            {
                cout << "|  " << ptr[i][j] << "    |";
            }
            else
                cout << "|  " << ptr[i][j] << "   |";
        }
        cout << endl;
    }
}
void snake_ladderCreation(int **&snake, int **&ladder, int rows, int col)
{
    int limit = (rows * col) - 4;
    srand(time(NULL));
    snake = new int *[2];
    for (int i = 0; i < 2; ++i)
    {
        snake[i] = new int[col - 2];
    }
    for (int j = 0; j < col - 2; ++j)
    {
        snake[0][j] = rand() % limit + 3;
        int limit2 = snake[0][j] - 4;
        if (limit2 <= 0)
        {
            j -= 1;
            continue;
        }
        snake[1][j] = rand() % limit2 + 2;
        for (int i = 0; i < j; ++i)
        {
            if (snake[0][j] == snake[0][i])
            {
                j -= 1;
                break;
            }
        }
    }
    cout << "SNAKE" << endl;
    cout << "Head            Tail" << endl;
    for (int j = 0; j < col - 2; ++j)
    {
        cout << snake[0][j] << "               " << snake[1][j] << endl;
    }
    ladder = new int *[2];
    for (int i = 0; i < 2; ++i)
    {
        ladder[i] = new int[col - 2];
    }
    for (int j = 0; j < col - 2; ++j)
    {
        ladder[0][j] = rand() % limit + 3;
        int limit2 = ladder[0][j] - 4;
        if (limit2 <= 0)
        {
            j -= 1;
            continue;
        }
        ladder[1][j] = rand() % limit2 + 2;
        for (int i = 0; i < j; ++i)
        {
            if (ladder[1][j] == ladder[1][i])
            {
                j -= 1;
                break;
            }
        }
        for (int i = 0; i < col - 2; ++i)
        {
            if (ladder[0][j] == snake[0][i])
            {
                j -= 1;
                break;
            }
        }
    }
    cout << "\nLADDER " << endl;
    cout << "Top               Bottom" << endl;
    for (int j = 0; j < col - 2; ++j)
    {
        cout << ladder[0][j] << "                   " << ladder[1][j] << endl;
    }
}

void playDice(int &posi_P1, int &posi_P2, int row, int col , int& turn)
{
    srand(time(NULL));
    // static int turn = 1;
    int num = 0;
    if (turn ==1)
    {
        cout << "---------------------------------------" << endl;
        cout << "Player -- 1 (TURN)" << endl;
        cout << "Press Enter to Roll to Dice  :";
        cin.get();
        cin.ignore();
        num = rand() % 6 + 1;
        cout << "Player --1 Got " << num << endl;
        turn += 1;

        posi_P1 += num;
        if (posi_P1 > row * col)
        {
            posi_P1 -= num;
        }
        cout << endl;
    }
    else if(turn == 2)
    {
        cout << "---------------------------------------" << endl;
        cout << "Player -- 2 (TURN)" << endl;
        cout << "Press Enter to Roll to Dice  :";
        cin.ignore();
        cin.get();
        num = rand() % 6 + 1;
        cout << "Player --2 Got " << num << endl;
        turn -= 1;
        posi_P2 -= num;
        if (posi_P2 > row * col)
        {
            posi_P2 -= num;
        }
        cout << endl;
    }
    // return turn;
}

bool checkSankehead(int &posi, int **snake, int col)
{
    for (int i = 0; i < col - 2; ++i)
    {
        if (posi == snake[0][i])
        {
            posi = snake[1][i];
            cout << "\n---------------------------" << endl;
            cout << "oops, snake got you" << endl;
            cout << "Demoted to position " << snake[1][i] << endl;
            cout << "---------------------------\n"
                 << endl;
            return true;
        }
    }
    return false;
}

bool checkaladderfoot(int &posi, int **ladder, int col)
{
    for (int i = 0; i < col - 2; ++i)
    {
        if (posi == ladder[1][i])
        {
            posi = ladder[0][i];
            cout << "\n---------------------------" << endl;
            cout << "you got lucky" << endl;
            cout << "Promoted to position " << ladder[0][i] << endl;
            cout << "---------------------------\n"
                 << endl;
            return true;
        }
    }
    return false;
}

bool wincheck(int posi, int row, int col, int turn)
{
    if (posi == row * col)
    {
        cout << "Congratulation player -- " << turn << " won" << endl;
        return true;
    }
    return false;
}

int startgame(int &turn)
{
    int num = 0;
    srand(time(NULL));
    if (turn == 1)
    {
        cout << "---------------------------------------" << endl;
        cout << "Player -- 1 (TURN)" << endl;
        cout << "Press Enter to Roll to Dice  :";
        cin.ignore();
        cin.get();
        num = rand() % 6 + 1;
        cout << "Player --1 Got " << num << endl;
        turn += 1;
    }
    else if(turn == 2)
    {
        cout << "---------------------------------------" << endl;
        cout << "Player -- 2 (TURN)" << endl;
        cout << "Press Enter to Roll to Dice  :";
        cin.get();
        cin.ignore();
        num = rand() % 6 + 1;
        cout << "Player --2 Got " << num << endl;
        turn -= 1;
    }
    return num;
}

void deleteALL(int **snakes , int **ladder , int **board , int rows , int col) 
{
    for(int i = 0 ; i < 2; ++i)
    {
        delete[] snakes[i];
        delete[] ladder[i];
    }
    delete[] snakes;
    delete[] ladder;
    snakes = nullptr;
    ladder = nullptr;
    for(int i = 0 ; i < rows ; ++i)
    {
        delete[] board[i];
    }
    delete[] board;
    board = nullptr;
}

void startSnakeGame() // controller of the game
{
    int M, N;
    int **snake;
    int **ladder;
    int posi_P1 = 1;
    int posi_P2 = 1;
    int turn = 1;
    bool check;
    int dice_to_start = 0;
    bool start_game = false;

    cout << "------------------WELCOME TO SNAKE LADDER GAME------------------" << endl;
    cout << "Player 1  = [0]                               Player 2 = [-1]" << endl;
    cout << "Enter the Number of Rows : ";
    cin >> M;
    cout << "Enter the Number of Columns : ";
    cin >> N;

    int **board = snakeBoardCreation(M, N);
    displayBoard(board, M, N, 0, 0);
    snake_ladderCreation(snake, ladder, M, N);
    while (true)
    {
        if (start_game == false)
        {
            while (true)
            {
                dice_to_start = startgame(turn);
                if (dice_to_start == 6 && turn == 2)
                {
                    posi_P1 = 6;
                    start_game = true;
                    break;
                }
                else if(dice_to_start == 6 && turn == 1)
                {
                    posi_P2 = 6;
                    start_game = true;
                    break;
                }
            }
        }
        else
            playDice(posi_P1, posi_P2, M, N , turn);
        if (turn == 2)
        {

            checkSankehead(posi_P1, snake, N);
            checkaladderfoot(posi_P1, ladder, N);
            displayBoard(board, M, N, turn - 1, posi_P1);
            check = wincheck(posi_P1, M, N, turn - 1);
        }
        if (turn == 1)
        {
            checkSankehead(posi_P2, snake, N);
            checkaladderfoot(posi_P2, ladder, N);
            displayBoard(board, M, N, turn + 1, posi_P2);
            check = wincheck(posi_P2, M, N, turn - 1);
        }

        if (check == true)
        {
            break;
        }
        cout << "---------------------------------------" << endl;
        cout << "Player -- 1 position : " << posi_P1 << endl;
        cout << "Player -- 2 position : " << posi_P2 << endl;
        cout << endl;
        }

    deleteALL(snake , ladder , board , M , N);
}

