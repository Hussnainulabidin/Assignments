//Name : Hussanin  Ul Abidin    --- Roll No : 22i-1102  ---- Section : K
#include <iostream>
#include <time.h>

using namespace std;

/////////////////////////////////////////////  QUESTION 1 ///////////////////////////////////////////////////////

template <class T>
class ArrayBasics
{
public:
    static T findMax(T* arr, int indexStart, int indexEnd)
    {
        T maxValue = arr[indexStart];
        for (int i = indexStart; i <= indexEnd; ++i)
        {
            if (arr[i] > maxValue)
            {
                maxValue = arr[i];
            }
        }
        return maxValue;
    }
    static int findMaxPos(T* arr, int indexStart, int indexEnd)
    {
        T maxValue = arr[indexStart];
        int maxIndex = indexStart;
        for (int i = indexStart + 1; i <= indexEnd; ++i)
        {
            if (arr[i] > maxValue)
            {
                maxValue = arr[i];
                maxIndex = i;
            }
        }
        return maxIndex;
    }
    static T findMin(T* arr, int indexStart, int indexEnd)
    {
        T minValue = arr[indexStart];
        for (int i = indexStart; i <= indexEnd; ++i)
        {
            if (arr[i] < minValue)
            {
                minValue = arr[i];
            }
        }
        return minValue;
    }
    static int findMinPos(T* arr, int indexStart, int indexEnd)
    {
        T minValue = arr[indexStart];
        int minIndex = indexStart;
        for (int i = indexStart + 1; i <= indexEnd; ++i)
        {
            if (arr[i] < minValue)
            {
                minValue = arr[i];
                minIndex = i;
            }
        }
        return minIndex;
    }
    static void swap(T *arr, int i, int j)
    {
        T temp = 0;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    static T* createRandomArray(int size, int min, int max)
    {
        srand(time(0));
        T* newArr = new T[size];
        int limit = max - min + 1;
        for (int i = 0; i < size; ++i)
        {
            T randN = (rand() % limit);
            randN += min;
            newArr[i] = randN;
        }
        return newArr;
    }
    static T** createRandomMatrix(int rows, int cols, int min, int max)
    {
        T** newArr = new T * [rows];
        for (int i = 0; i < rows; ++i)
        {
            newArr[i] = new T[cols];
        }
        int limit = max - min + 1;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                T randN = (rand() % limit);
                randN += min;
                newArr[i][j] = randN;
            }
        }
        return newArr;
    }
    static T* copyArray(T* arr, int size)
    {
        T* newArr = new T[size];
        for (int i = 0; i < size; ++i)
        {
            newArr[i] = arr[i];
        }
        return newArr;
    }
    static T** copyMatrix(T** arr, int rows, int cols)
    {
        T** newArr = new T * [rows];
        for (int i = 0; i < rows; ++i)
        {
            newArr[i] = new T[cols];
        }
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                newArr[i][j] = arr[i][j];
            }
        }
        return newArr;
    }
    static int findInArray(T* arr, int q, int size)
    {
        bool isPresent = false;
        for (int i = 0; i < size; ++i)
        {
            if (arr[i] == q)
            {
                return i;
            }
        }
        return -1;
    }
    static int findInSortedArray(T* arr, int q, int size)
    {
        int low = 0;
        int high = size - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] == q)
            {
                return mid;
            }
            if (q > arr[mid])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }
    static int findFirstInSortedArray(T* arr, int q, int size)
    {
        int low = 0;
        int high = size - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] == q && arr[mid - 1] != q)
            {
                return mid;
            }
            if (q > arr[mid])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return -1;;
    }
    static void shiftRight(T* arr, int i, int j)
    {
        for (int k = j - 1; k >= i; --k)
        {
            arr[k + 1] = arr[k];
        }
    }
    static void shiftLeft(T* arr, int i, int j)
    {
        for (int k = i + 1; k <= j; ++k)
        {
            arr[k - 1] = arr[k];
        }
    }
};

template<class U>
class ArrayUtility
{
public:
    static void maxSortWithSwap(U* arr, int size)
    {
        for (int i = 0; i < size; ++i)
        {
            int maxPos = ArrayBasics<int>::findMaxPos(arr, i, size - 1);
            ArrayBasics<int>::swap(arr, i, maxPos);
        }
    }
    static void maxSortWithShiftRight(U* arr, int size)
    {
        for (int i = 0; i < size; ++i)
        {
            int maxPos = ArrayBasics<int>::findMaxPos(arr, i, size - 1);
            int maxElement = arr[maxPos];
            ArrayBasics<int>::shiftRight(arr, i, maxPos);
            arr[i] = maxElement;
        }
    }
};


/////////////////////////////////////////////  QUESTION 2 ///////////////////////////////////////////////////////

template <class T>
class WarehouseAlgorithm
{
public:
    static bool hasClosePair(T* arr, int size, int value)
    {
        bool* dictionary = new bool[value + 1] {false};
        dictionary[0] = true;
        int* indexDictionary = new int[value + 1] {-1};
        int index = 0;
        for (index; index < size; ++index)
        {
            if (dictionary[value - arr[index]] == true && value - arr[index] > 0 && value - arr[index] < value)
            {
                int distance = indexDictionary[value - arr[index]] - index;
                if (distance < 0)
                    distance *= -1;
                if (distance < size / 10)
                    return true;
            }
            else if (value - arr[index] > 0 && value - arr[index] < value)
            {
                dictionary[arr[index]] = true;
                indexDictionary[arr[index]] = index;
            }
        }
        return false;
    }
    /*
        PART B:
        // ->Lets us take an array of size n = 10;
        // ->the constraint is given that r < n^2
        // ->If we take the square of n = 10 with result in n = 100
        // ->Now the constraint given in the question is |i-j| < n / 10 and n = 100 / 10 result a value = 10
        // ->which is the again the size of array , so if transverse the array to find r reams by combining bi and bj
        // ->The max difference between then can be equal to size of which take u alot more than and we have to transverse the whole array
        // to find the pair.
        // ->Another worst case can be defined in this is that if the pair is not present in the array we still have to tranverse that whole array
        //   and return a false answer
    */
};


/////////////////////////////////////////////  QUESTION 3 ///////////////////////////////////////////////////////

template<class T>
void create2DArray(T**& ptr, int n, int m)
{
    ptr = new T * [n];
    for (int i = 0; i < n; ++i)
    {
        ptr[i] = new T[m]{ 0 };
    }
}

template<class T>
T maximizeProfit(int m, int n, T a[], T p[], int s)
{
    T** allprofits = nullptr;
    int** noOfOrderFilled = nullptr;
    create2DArray(allprofits, n + 1, m + 1);
    create2DArray(noOfOrderFilled, n + 1, m + 1);
    T previousMaxProfit = 0;
    T currentProfit = 0;
    int barrelsSold = 0;
    int currentSold = 0;

    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 0; j < m + 1; ++j)
        {
            currentSold = 0;
            allprofits[i][j] = allprofits[i - 1][j]; //first exclusing the first then checking get the max if current order if added from previous profits
            noOfOrderFilled[i][j] = noOfOrderFilled[i - 1][j];

            currentSold = noOfOrderFilled[i - 1][j];

            if (a[i - 1] <= j) // checking if the current order can be fit in the barrels avaliable
            {
                int without_current_order = allprofits[i - 1][j];

                //allprofits[i - 1][j - a[i - 1]] checks if which order can best fit with the current order maximize profit

                int with_current_order = allprofits[i - 1][j - a[i - 1]] + p[i - 1];

                currentSold = a[i - 1] + noOfOrderFilled[i - 1][j - a[i - 1]];

                if (with_current_order >= without_current_order)
                {
                    allprofits[i][j] = with_current_order; // Include the current order if the profit is higher without including
                    noOfOrderFilled[i][j] = currentSold;
                }
                else
                {
                    noOfOrderFilled[i][j] = noOfOrderFilled[i - 1][j];
                    currentSold = noOfOrderFilled[i - 1][j];
                }
            }

            currentProfit = allprofits[i][j] - ((m - currentSold) * s);

            if (previousMaxProfit < currentProfit)
            {
                previousMaxProfit = currentProfit;
            }
        }
    }
    return previousMaxProfit;
}

/////////////////////////////////////////////  QUESTION 4 ///////////////////////////////////////////////////////

template<class T>
void makeBookingSchedules(T R[][2], int n, T bookingSchedule[][3], int& m)
{
    m = 0;
    T startTime = 0;
    T endTime = 1;
    int totalRooms = 0;
    int lastindex = 0;

    T maxEndTime = R[0][1];

    for (int i = 1; i < n; ++i)
    {
        if (maxEndTime < R[i][1])
        {
            maxEndTime = R[i][1];
        }
    }

    int* totalRoomInTime = new int[maxEndTime];
    int* previousRoom = new int[maxEndTime] {-1};
    bool matchingPrevious = true;

    int previousRoomCountEnd = 0;
    int previousRoomCountStart = 0;
    int index = 0;
    int newcount = 0;
    for (int i = 0; i < maxEndTime; ++i)
    {
        newcount = 0;
        lastindex = index;
        index = 0;
        matchingPrevious = true;
        totalRooms = 0;
        for (int j = 0; j < n; ++j)
        {
            if (startTime >= R[j][0] && endTime <= R[j][1])
            {
                totalRooms += 1;
                if (previousRoom[index] != j && matchingPrevious == true)
                {
                    index = 0;
                    j = -1;
                    totalRooms = 0;
                    previousRoom = new int[maxEndTime] {-1};
                    matchingPrevious = false;
                    continue;
                }
                if (matchingPrevious == false)
                {
                    previousRoom[index] = j;
                }
                index++;
            }
        }
        if (matchingPrevious && lastindex == index && totalRooms != 0)
        {
            bookingSchedule[m - 1][0] = totalRooms;
            bookingSchedule[m - 1][2] = endTime;
        }
        else if (totalRooms != 0)
        {
            bookingSchedule[m][0] = totalRooms;
            bookingSchedule[m][2] = endTime;
            bookingSchedule[m][1] = startTime;
            m++;
        }
        startTime += 1;
        endTime += 1;
    }

}


template<class T>
void mergeBookingSchedules(T R1[][2], int n1, T R2[][2], int n2, T bookingSchedule[][3], int& m)
{
    const int n = n1 + n2;
    int index = 0;
    int index2 = 0;
    T** R = new T * [n];
    for (int i = 0; i < n; ++i)
        R[i] = new T[2];
    for (int i = 0; i < n; ++i)
    {
        if (i < n1)
        {
            R[i][0] = R1[index][0];
            R[i][1] = R1[index][1];
            index++;
        }
        else
        {
            R[i][0] = R2[index2][0];
            R[i][1] = R2[index2][1];
            index2++;
        }
    }

    m = 0;
    T startTime = 0;
    T endTime = 1;
    int totalRooms = 0;
    int lastindex = 0;

    T maxEndTime = R[0][1];

    for (int i = 1; i < n; ++i)
    {
        if (maxEndTime < R[i][1])
        {
            maxEndTime = R[i][1];
        }
    }

    int* totalRoomInTime = new int[maxEndTime];
    int* previousRoom = new int[maxEndTime] {-1};
    bool matchingPrevious = true;

    int previousRoomCountEnd = 0;
    int previousRoomCountStart = 0;
    index = 0;
    int newcount = 0;
    for (int i = 0; i < maxEndTime; ++i)
    {
        newcount = 0;
        lastindex = index;
        index = 0;
        matchingPrevious = true;
        totalRooms = 0;
        for (int j = 0; j < n; ++j)
        {
            if (startTime >= R[j][0] && endTime <= R[j][1])
            {

                totalRooms += 1;
                if (previousRoom[index] != j && matchingPrevious == true)
                {
                    index = 0;
                    j = -1;
                    totalRooms = 0;
                    previousRoom = new int[maxEndTime] {-1};
                    matchingPrevious = false;
                    continue;
                }
                if (matchingPrevious == false)
                {
                    previousRoom[index] = j;
                }
                index++;
            }
        }
        if (matchingPrevious && lastindex == index && totalRooms != 0)
        {
            bookingSchedule[m - 1][0] = totalRooms;
            bookingSchedule[m - 1][2] = endTime;
        }
        else if (totalRooms != 0)
        {
            bookingSchedule[m][0] = totalRooms;
            bookingSchedule[m][2] = endTime;
            bookingSchedule[m][1] = startTime;
            m++;
        }
        startTime += 1;
        endTime += 1;
    }

}


