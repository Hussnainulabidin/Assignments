//Name : Hussnain Ul Abidin
//Roll No : 22i-1102_K

#include <iostream>
#include "Array.h"

using namespace std;

Array::Array()
{
    ary = nullptr;
    length = 0;
}

Array::Array(int size)
{
    ary = new int[size]{0};
    this->length = size;
}

Array::Array(int *arr, int size)
{
    ary = new int[size];
    this->length = size;
    for (int i = 0; i < size; ++i)
    {
        ary[i] = arr[i];
    }
}

Array::Array(const Array &A)
{
    this->length = A.length;
    this->ary = new int[this->length];

    for (int i = 0; i < this->length; ++i)
    {
        this->ary[i] = A.ary[i];
    }
}

int Array::size()
{
    return this->length;
}

int &Array::operator[](int i)
{
    if (i < this->length)
    {
        return this->ary[i];
    }
    else
    {
        cout << "out_of_range" << endl;
    }
}

int &Array::operator[](int i) const
{
    if (i < this->length)
    {
        return this->ary[i];
    }
    else
    {
        cout << "out_of_range" << endl;
    }
}

const Array &Array::operator=(const Array &A)
{
    this->length = A.length;
    this->ary = new int[this->length];

    for (int i = 0; i < this->length; ++i)
    {
        this->ary[i] = A.ary[i];
    }
    return *(this);
}

Array Array::operator+(const Array &A)
{
    int len1 = this->length;
    int len2 = A.length;

    int length = 0;
    int maxlen = 0;
    if (len1 < len2)
    {
        length = len1;
        maxlen = len2;
    }
    else if (len2 < len1)
    {
        length = len2;
        maxlen = len1;
    }
    else
    {
        length = len1;
        maxlen = len1;
    }

    Array ans(maxlen);

    for (int i = 0; i < maxlen; ++i)
    {
        if (i >= len1)
        {
            ans[i] = this->ary[i];
        }
        else if (i >= len2)
        {
            ans[i] = A.ary[i];
        }
        ans[i] = this->ary[i] + A.ary[i];
    }
    return ans;
}

Array Array::operator-(const Array &A)
{
    int len1 = this->length;
    int len2 = A.length;

    int length = 0;
    int maxlen = 0;
    if (len1 < len2)
    {
        length = len1;
        maxlen = len2;
    }
    else if (len2 < len1)
    {
        length = len2;
        maxlen = len1;
    }
    else
    {
        length = len1;
        maxlen = len1;
    }

    Array ans(maxlen);

    for (int i = 0; i < maxlen; ++i)
    {
        if (i >= len1)
        {
            ans[i] = this->ary[i];
        }
        else if (i >= len2)
        {
            ans[i] = A.ary[i];
        }
        ans[i] = this->ary[i] - A.ary[i];
    }
    return ans;
}

Array Array::operator+=(const Array &A)
{
    int len1 = this->length;
    int len2 = A.length;

    int length = 0;
    int maxlen = 0;
    if (len1 < len2)
    {
        length = len1;
        maxlen = len2;
    }
    else if (len2 < len1)
    {
        length = len2;
        maxlen = len1;
    }
    else
    {
        length = len1;
        maxlen = len1;
    }

    for (int i = 0; i < maxlen; ++i)
    {
        if (i >= len1)
        {
            break;
            // this->ary[i] = this->ary[i];
        }
        else if (i >= len2)
        {
            this->ary[i] = A.ary[i];
        }
        this->ary[i] = this->ary[i] + A.ary[i];
    }
    return *this;
}

Array Array::operator-=(const Array &A)
{
    int len1 = this->length;
    int len2 = A.length;

    int length = 0;
    int maxlen = 0;
    if (len1 < len2)
    {
        length = len1;
        maxlen = len2;
    }
    else if (len2 < len1)
    {
        length = len2;
        maxlen = len1;
    }
    else
    {
        length = len1;
        maxlen = len1;
    }

    for (int i = 0; i < maxlen; ++i)
    {
        if (i >= len1)
        {
            break;
            // this->ary[i] = this->ary[i];
        }
        else if (i >= len2)
        {
            this->ary[i] = A.ary[i];
        }
        this->ary[i] = this->ary[i] - A.ary[i];
    }
    return *this;
}

Array Array::operator++()
{
    Array ans(this->length);
    int len = this->length;

    for (int i = 0; i < len; ++i)
    {
        this->ary[i] += 1;
        ans.ary[i] = this->ary[i];
    }
    return ans;
}

Array Array::operator++(int)
{
    Array ans(this->length);
    int len = this->length;

    for (int i = 0; i < len; ++i)
    {
        ans.ary[i] = this->ary[i];
        this->ary[i] += 1;
    }
    return ans;
}

Array Array::operator--()
{
    Array ans(this->length);
    int len = this->length;

    for (int i = 0; i < len; ++i)
    {
        this->ary[i] -= 1;
        ans.ary[i] = this->ary[i];
    }
    return ans;
}

Array Array::operator--(int)
{
    Array ans(this->length);
    int len = this->length;

    for (int i = 0; i < len; ++i)
    {
        ans.ary[i] = this->ary[i];
        this->ary[i] -= 1;
    }
    return ans;
}

bool Array::operator==(const Array &A)
{
    int len = A.length;
    if (len != this->length)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < len; ++i)
        {
            if (this->ary[i] != A.ary[i])
            {
                return false;
            }
        }
    }
    return true;
}

bool Array::operator!()
{
    if (this->ary == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Array::operator()(int idx, int val)
{
    int len = this->length;
    bool check = false;
    if (idx >= len || this->ary[idx] != val)
    {
        return -1;
    }
    else
    {

        int *temp = this->ary;
        this->ary = new int[len - 1];
        for (int i = 0; i < len; ++i)
        {
            if (temp[i] == val)
            {
                continue;
            }
            this->ary[i] = temp[i];
        }
    }
    return 1;
}

ostream &operator<<(ostream &input, const Array &A)
{
    for (int i = 0; i < A.length; ++i)
    {
        cout << A.ary[i] << " ";
    }
    cout << endl;
    return input;
}

istream &operator>>(istream &output, const Array &A)
{
    for (int i = 0; i < A.length; ++i)
    {
        cin >> A.ary[i];
    }
    return output;
}
