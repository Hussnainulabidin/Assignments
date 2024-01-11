//Name : Hussnain Ul Abidin
//Roll No : 22i-1102_K
#include <iostream>
#include "BigInt.h"

using namespace std;

BigInt::BigInt(int val = 0)
{
    int rem = 1;
    int num = val;
    int len = 0;
    if (val == 0)
    {
        this->number = new char[2];
        len = 2;
        this->number[0] = 0 + '0';
        this->number[1] = '\0';
        return;
    }

    while (val != 0)
    {
        rem = val % 10;
        val = val / 10;
        len += 1;
    }
    number = new char[len + 1];
    this->len = len + 1;
    rem = 1;
    val = num;
    int i = 0;
    while (val != 0)
    {
        rem = val % 10;
        val = val / 10;
        number[i] = rem + '0';
        i++;
    }
    char temp;
    for (int i = 0; i < len / 2; ++i)
    {
        temp = number[i];
        number[i] = number[len - (i + 1)];
        number[len - (i + 1)] = temp;
    }
    number[len] = '\0';
}

BigInt::BigInt(const string &text)
{
    int len = 0;
    for (int i = 0; text[i] != '\0'; ++i)
    {
        len++;
    }
    number = new char[len + 1];
    this->len = len + 1;
    for (int i = 0; text[i] != '\0'; ++i)
    {
        number[i] = text[i];
    }
    number[len] = '\0';
}

BigInt::BigInt(const BigInt &copy)
{

    this->len = copy.len;
    number = new char[this->len];
    for (int i = 0; i < len; ++i)
    {
        this->number[i] = copy.number[i];
    }
}

BigInt::operator string()
{
    string num;
    num = this->number;
    return num;
}

string BigInt::toString()
{
    string num = number;
    return num;
}

char *BigInt::get_number()
{
    return this->number;
}
int BigInt::get_length()
{
    return len;
}
void BigInt::set_number(char *num)
{
    this->number = num;
}
void BigInt::set_length(int x)
{
    this->len = x;
}

BigInt BigInt::operator+(int val) const
{
    BigInt temp;
    temp.number = new char[this->len];
    int rem = 1;
    int num = val;
    int len = 0;
    while (val != 0)
    {
        rem = val % 10;
        val = val / 10;
        len += 1;
    }
    int *ptr = new int[len];
    val = num;
    int ind = 0;
    while (val != 0)
    {
        rem = val % 10;
        val = val / 10;
        ptr[ind] = rem;
        ind++;
    }
    int num1;
    int ans;
    int carry = 0;
    ind = 0;
    for (int i = this->len - 2; i >= 0; --i)
    {
        num1 = this->number[i] - '0';
        if (ind < len)
        {
            ans = num1 + ptr[ind] + carry;
            if (ans > 9)
            {
                temp.number[i] = (ans % 10) + '0';
                carry = ans / 10;
            }
            else
            {
                temp.number[i] = ans + '0';
            }
            ind++;
        }
        else if (carry != 0)
        {
            ans = num1 + carry;
            if (ans > 9)
            {
                temp.number[i] = (ans % 10) + '0';
                carry = ans / 10;
            }
            else
            {
                temp.number[i] = ans + '0';
            }
            ind++;
        }
        else if (carry == 0)
        {
            break;
        }
    }
    if (carry != 0)
    {
        char *temp2 = temp.number;
        temp.number = new char[this->len + 2];
        temp.number[0] = carry + '0';
        ind = 1;
        for (int i = 0; i < this->len; ++i)
        {
            temp.number[ind] = temp2[i];
            ind++;
        }
        temp.number[ind] = '\0';
        temp.len = ind;
    }
    return temp;
}

BigInt BigInt::operator+(const BigInt &val) const
{
    BigInt temp;
    int len1 = this->len;
    int len2 = val.len;
    int length = 0;
    int carry = 0;
    int ans;
    int num1, num2;
    if (len1 > len2)
    {
        length = len1;
        temp.number = new char[len1];
        int j = len2 - 2;
        for (int i = len1 - 2; i >= 0; --i)
        {
            num1 = this->number[i] - '0';
            num2 = val.number[j] - '0';
            if (j >= 0)
            {
                ans = num1 + num2 + carry;
                if (ans > 9)
                {
                    temp.number[i] = (ans % 10) + '0';
                    carry = ans / 10;
                }
                else
                {
                    temp.number[i] = ans + '0';
                }
                j--;
            }
            else if (carry != 0)
            {
                ans = num1 + carry;
                if (ans > 9)
                {
                    temp.number[i] = (ans % 10) + '0';
                    carry = ans / 10;
                }
                else
                {
                    temp.number[i] = ans + '0';
                }
                j--;
            }
            else if (carry == 0)
            {
                temp.number[i] = this->number[i];
                break;
            }
        }
    }
    else
    {
        length = len2;
        temp.number = new char[len2];
        temp.number[len2 - 1] = '\0';
        int j = len1 - 2;
        for (int i = len2 - 2; i >= 0; --i)
        {
            num1 = this->number[j] - '0';
            num2 = val.number[i] - '0';
            if (j >= 0)
            {
                ans = num1 + num2 + carry;
                if (ans > 9)
                {
                    temp.number[i] = (ans % 10) + '0';
                    carry = ans / 10;
                }
                else
                {
                    temp.number[i] = ans + '0';
                }
                j--;
            }
            else if (carry != 0)
            {
                ans = num2 + carry;
                if (ans > 9)
                {
                    temp.number[i] = (ans % 10) + '0';
                    carry = ans / 10;
                }
                else
                {
                    temp.number[i] = ans + '0';
                }
                j--;
            }
            else if (carry == 0)
            {
                temp.number[i] = val.number[i];
                break;
            }
        }
    }
    if (carry != 0)
    {
        char *temp2 = temp.number;
        temp.number = new char[length + 1];
        temp.number[0] = carry + '0';
        int ind = 1;
        for (int i = 0; i < this->len; ++i)
        {
            temp.number[ind] = temp2[i];
            ind++;
        }
        temp.number[ind] = '\0';
        temp.len = ind + 1;
    }
    return temp;
}

BigInt BigInt::operator+=(const BigInt &rhs)
{
    bool neg_num1 = false;
    bool neg_num2 = false;
    bool neg_ans = false;
    char *temp;
    char *num1ptr;
    char *num2ptr;
    int len1 = this->len;
    int len2 = rhs.len;
    int length = 0;
    int carry = 0;
    int ans;
    int num1, num2;

    if (rhs.number[0] == '-')
    {
        neg_num1 = true;
        num2ptr = new char[len2];
        for (int i = 1; i < len2; ++i)
        {
            num2ptr[i - 1] = rhs.number[i];
        }
    }
    else
    {
        num2ptr = rhs.number;
    }
    if (this->number[0] == '-')
    {
        neg_num2 = true;
        num1ptr = new char[len1];
        for (int i = 1; i < len1; ++i)
        {
            num1ptr[i - 1] = this->number[i];
        }
    }
    else
    {
        num1ptr = this->number;
    }
    if (neg_num1 && !neg_num2)
    {
        BigInt ans = rhs - *(this);
    }
    else if (neg_num2 && neg_num1)
    {

        BigInt ans = *(this) - rhs;
    }
    if (neg_num1 && neg_num2)
    {
        len1 -= 1;
        len2 -= 1;
        neg_ans = true;
    }

    if (len1 > len2)
    {
        temp = new char[len1];
        length = len1;
        int j = len2 - 2;
        for (int i = len1 - 2; i >= 0; --i)
        {
            num1 = num1ptr[i] - '0';
            num2 = num2ptr[j] - '0';
            if (j >= 0)
            {
                ans = num1 + num2 + carry;
                if (ans > 9)
                {
                    temp[i] = (ans % 10) + '0';
                    carry = ans / 10;
                }
                else
                {
                    temp[i] = ans + '0';
                }
                j--;
            }
            else if (carry != 0)
            {
                ans = num1 + carry;
                if (ans > 9)
                {
                    temp[i] = (ans % 10) + '0';
                    carry = ans / 10;
                }
                else
                {
                    this[i] = ans + '0';
                }
                j--;
            }
            else if (carry == 0)
            {
                // this->number[i] = this->number[i];
                break;
            }
        }
    }
    else
    {
        temp = new char[len2];
        temp[len2 - 1] = '\0';
        length = len2;
        int j = len1 - 2;
        for (int i = len2 - 2; i >= 0; --i)
        {
            num1 = num1ptr[j] - '0';
            num2 = num2ptr[i] - '0';

            if (j >= 0)
            {
                ans = num1 + num2 + carry;
                if (ans > 9)
                {
                    temp[i] = (ans % 10) + '0';
                    carry = ans / 10;
                }
                else
                {
                    temp[i] = ans + '0';
                }
                j--;
            }
            else if (carry != 0)
            {
                ans = num2 + carry;
                if (ans > 9)
                {
                    temp[i] = (ans % 10) + '0';
                    carry = ans / 10;
                }
                else
                {
                    temp[i] = ans + '0';
                }
                j--;
            }
            else if (carry == 0)
            {
                temp[i] = rhs.number[i];
                break;
            }
        }
    }
    int ind = 0;
    if (neg_ans)
    {
        ind+=1;
        length+=1;
    }
    if (carry != 0)
    {
        char *temp2 = temp;
        temp = new char[length + 1];
        temp[ind] = carry + '0';
        ind += 1;
        for (int i = 0; i < length + 1; ++i)
        {
            temp[ind] = temp2[i];
            ind++;
        }
        this->len = ind;
        temp[ind] = '\0';
    }
    else if(neg_ans)
    {
        char *temp2 = temp;
        temp = new char[length + 1];
        for (int i = 0; i < length + 1; ++i)
        {
            temp[ind] = temp2[i];
            ind++;
        }
        this->len = ind;
        temp[ind] = '\0'; 
    }
    if(neg_num1)
    {
        temp[0] = '-';
    }

    this->number = temp;
    return *(this);
}

BigInt BigInt::operator-(int val) const
{
    BigInt temp;
    temp.number = new char[this->len];
    int rem = 1;
    int num = val;
    int len = 0;
    while (val != 0)
    {
        rem = val % 10;
        val = val / 10;
        len += 1;
    }
    int *ptr = new int[len];
    val = num;
    int ind = 0;
    while (val != 0)
    {
        rem = val % 10;
        val = val / 10;
        ptr[ind] = rem;
        ind++;
    }
    int num1;
    int ans;
    int carry = 0;
    ind = 0;
    char *number1 = new char[this->len];
    for (int i = 0; i < this->len; ++i)
    {
        number1[i] = this->number[i];
    }
    for (int i = this->len - 2; i >= 0; --i)
    {
        num1 = number1[i] - '0';
        if (ind < len)
        {
            if (num1 < ptr[ind])
            {
                int temp1 = 0;
                int k = 0;
                for (k = i - 1; k >= 0; --k)
                {
                    temp1 = number1[k] - '0';
                    if (temp1 != 0)
                    {
                        carry = 1;
                        temp1 -= 1;
                        number1[k] = temp1 + '0';
                        break;
                    }
                }
                for (k += 1; k <= i; ++k)
                {
                    temp1 = number1[k] - '0';
                    temp1 += 10;
                    if (k != i)
                    {
                        temp1 -= 1;
                        number1[k] = temp1 + '0';
                    }
                }
                num1 = num1 + 10;
            }
            ans = num1 - ptr[ind];
            if (ans > 9)
            {
                temp.number[i] = (ans % 10) + '0';
                carry = ans / 10;
            }
            else
            {
                temp.number[i] = ans + '0';
            }
            ind++;
        }
        else if (carry != 0)
        {
            ans = num1;
            if (ans > 9)
            {
                temp.number[i] = (ans % 10) + '0';
                carry = ans / 10;
            }
            else
            {
                temp.number[i] = ans + '0';
            }
            ind++;
        }
        else if (carry == 0)
        {
            break;
        }
    }
    if (temp.number[0] == '0')
    {
        int ind = 0;
        char *ptr = temp.number;
        for (int i = 1; i < this->len; ++i)
        {
            temp.number[ind] = ptr[i];
            ind++;
        }
        temp.len = ind;
    }

    return temp;
}

BigInt BigInt::operator-(const BigInt &val) const
{
    BigInt temp;
    int len1 = this->len;
    int len2 = val.len;
    int length = 0;
    int carry = 0;
    int ans;
    int num1, num2;

    if (len1 > len2)
    {
        char *number1 = new char[this->len];
        for (int i = 0; i < this->len; ++i)
        {
            number1[i] = this->number[i];
        }
        length = len1;
        temp.number = new char[len1];
        int j = len2 - 2;
        for (int i = len1 - 2; i >= 0; --i)
        {
            num1 = number1[i] - '0';
            num2 = val.number[j] - '0';
            if (j >= 0)
            {
                if (num1 < num2)
                {
                    int temp1 = 0;
                    int k = 0;
                    for (k = i - 1; k >= 0; --k)
                    {
                        temp1 = number1[k] - '0';
                        if (temp1 != 0)
                        {
                            carry = 1;
                            temp1 -= 1;
                            number1[k] = temp1 + '0';
                            break;
                        }
                    }
                    for (k += 1; k <= i; ++k)
                    {
                        temp1 = number1[k] - '0';
                        temp1 += 10;
                        if (k != i)
                        {
                            temp1 -= 1;
                            number1[k] = temp1 + '0';
                        }
                    }
                    num1 = num1 + 10;
                }
                ans = num1 - num2;
                if (ans > 9)
                {
                    temp.number[i] = (ans % 10) + '0';
                    carry = ans / 10;
                }
                else
                {
                    temp.number[i] = ans + '0';
                }
                j--;
            }
            else if (carry != 0)
            {
                ans = num1;
                if (ans > 9)
                {
                    temp.number[i] = (ans % 10) + '0';
                    carry = ans / 10;
                }
                else
                {
                    temp.number[i] = ans + '0';
                }
                j--;
            }
            else if (carry == 0)
            {
                temp.number[i] = this->number[i];
                break;
            }
        }
    }
    else
    {
        char *number1 = new char[len2];
        for (int i = 0; i < len2; ++i)
        {
            number1[i] = val.number[i];
        }
        length = len2;
        temp.number = new char[len2];
        temp.number[len2 - 1] = '\0';
        int j = len1 - 2;
        for (int i = len2 - 2; i >= 0; --i)
        {
            num1 = this->number[j] - '0';
            num2 = number1[i] - '0';

            if (j >= 0)
            {
                if (num1 > num2)
                {
                    int temp1 = 0;
                    int k = 0;
                    for (k = i - 1; k >= 0; --k)
                    {
                        temp1 = number1[k] - '0';
                        if (temp1 != 0)
                        {
                            carry = 1;
                            temp1 -= 1;
                            number1[k] = temp1 + '0';
                            break;
                        }
                    }
                    for (k += 1; k <= i; ++k)
                    {
                        temp1 = number1[k] - '0';
                        temp1 += 10;
                        if (k != i)
                        {
                            temp1 -= 1;
                            number1[k] = temp1 + '0';
                        }
                    }
                    num2 = num2 + 10;
                }
                ans = num2 - num1;
                if (ans > 9)
                {
                    temp.number[i] = (ans % 10) + '0';
                    carry = ans / 10;
                }
                else
                {
                    temp.number[i] = ans + '0';
                }
                j--;
            }
            else if (carry != 0)
            {
                ans = num2;
                if (ans > 9)
                {
                    temp.number[i] = (ans % 10) + '0';
                    carry = ans / 10;
                }
                else
                {
                    temp.number[i] = ans + '0';
                }
                j--;
            }
            else if (carry == 0)
            {
                temp.number[i] = val.number[i];
                break;
            }
        }
    }
    if (temp.number[0] == '0')
    {
        int zero = 0;
        for (int i = 0; i < length; ++i)
        {
            if (temp.number[i] == '0')
            {
                zero += 1;
            }
            else
            {
                break;
            }
        }
        int length1 = length - zero;
        char *temp2 = temp.number;
        temp.number = new char[length1];
        int ind = 0;
        for (int i = 0; i < length; ++i)
        {
            if (temp2[i] != '0')
            {
                temp.number[ind] = temp2[i];
                ind++;
            }
        }
        temp.len = ind;
        temp.number[ind] = '\0';
    }
    return temp;
}

BigInt BigInt::operator*(const BigInt &val) const
{
    BigInt ans;
    if (val.number[0] == '0' || this->number[0] == '0')
    {
        ans.number = new char[2];
        ans.number[0] = '0';
        ans.number[1] = '\0';
        return ans;
    }
    else
    {
        bool neg_num1 = false;
        bool neg_num2 = false;
        bool neg_ans = false;
        int num3 = 0;
        int len1 = this->len;
        int len2 = val.len;
        int j;
        char *num1, *num2;
        int **ptr;
        int length;
        int len = 0;
        int k = 0;
        int ind = 0;
        int mainlen = 0;

        if (this->number[0] == '-')
        {
            neg_num1 = true;
            len1 -= 1;
        }
        if (val.number[0] == '-')
        {
            neg_num2 = true;
            len2 -= 1;
        }
        if (neg_num1 && neg_num2)
        {
            neg_ans = false;
        }
        else if (neg_num1 || neg_num2)
        {
            neg_ans = true;
        }

        if (len1 > len2)
        {

            if (neg_num1 || neg_num2)
            {
                num1 = new char[len1];
                for (int i = 1; i < len1; ++i)
                {
                    num1[i] = this->number[i];
                }
                num2 = new char[len2];
                for (int i = 1; i < len2; ++i)
                {
                    num2[i] = val.number[i];
                }
            }
            else
            {
                num2 = val.number;
                num1 = this->number;
            }
            j = len2 - 2;
            length = len1 - 1;
            len = len2 - 1;
            mainlen = len1 + len2 - 2;

            ptr = new int *[len2 - 2];
            for (int i = 0; i < len2 - 1; ++i)
            {
                ptr[i] = new int[mainlen]{0};
            }
        }
        else
        {
            if (neg_num1 || neg_num2)
            {
                num2 = new char[len2];
                for (int i = 1; i < len2 + 1; ++i)
                {
                    num2[i - 1] = this->number[i];
                }
                num1 = new char[len1];
                for (int i = 1; i < len1 + 1; ++i)
                {
                    num1[i - 1] = val.number[i];
                }
            }
            else
            {
                num2 = this->number;
                num1 = val.number;
            }
            length = len2 - 1;
            mainlen = len1 + len2 - 2;

            ptr = new int *[len1 - 2];
            len = len1 - 1;
            for (int i = 0; i < len1 - 1; ++i)
            {
                ptr[i] = new int[mainlen]{0};
            }
            j = len1 - 2;
        }

        int n1, n2, carry = 0;

        for (j; j >= 0; --j)
        {
            int l;
            for (l = 0; l < k; ++l)
            {
                ptr[k][l] = 0;
            }
            ind = l;
            for (int i = len1 - 2; i >= 0; --i)
            {
                n1 = num1[i] - '0';
                n2 = num2[j] - '0';
                num3 = n1 * n2 + carry;
                carry = 0;
                if (num3 > 9)
                {
                    ptr[k][ind] = num3 % 10;
                    carry = num3 / 10;
                }
                else
                {
                    ptr[k][ind] = num3;
                }
                ind++;
            }
            if (carry != 0)
            {
                ptr[k][ind] = carry;
                ind++;
            }

            k++;
            ind = 0;
            carry = 0;
        }

        ind = 0;
        carry = 0;
        int sum = 0;
        length = len1 + len2 - 2;

        int *ptr2 = new int[mainlen];
        for (int i = 0; i < mainlen; ++i)
        {
            for (int j = 0; j < len; ++j)
            {
                sum += ptr[j][i];
                ind++;
            }
            ind = 0;
            sum += carry;
            carry = 0;
            if (sum > 9)
            {
                ptr2[i] = sum % 10;
                carry = sum / 10;
            }
            else
            {
                ptr2[i] = sum;
            }
            sum = 0;
        }

        ans.number = new char[mainlen + 2];

        if (neg_ans)
        {
            ind += 1;
            ans.number[0] = '-';
        }
        int zero = 0;
        for (int i = mainlen - 1; i >= 0; --i)
        {
            if (ptr2[i] == 0)
            {
                zero += 1;
            }
            else
            {
                break;
            }
        }

        ind = mainlen - 2;
        ind -= zero;
        ans.number[mainlen - zero] = '\0';
        for (int i = 0; i <= mainlen; ++i)
        {
            ans.number[ind] = ptr2[i] + '0';
            ind--;
        }
        ans.number[mainlen + 1] = '\0';
    }
    return ans;
}

BigInt BigInt::operator*=(const BigInt &val)
{
    BigInt ans;
    if (val.number[0] == '0' || this->number[0] == '0')
    {
        ans.number = new char[2];
        ans.number[0] = '0';
        ans.number[1] = '\0';
        return ans;
    }
    else
    {
        bool neg_num1 = false;
        bool neg_num2 = false;
        bool neg_ans = false;
        int num3 = 0;
        int len1 = this->len;
        int len2 = val.len;
        int j;
        char *num1, *num2;
        int **ptr;
        int length;
        int len = 0;
        int k = 0;
        int ind = 0;
        int mainlen = 0;

        if (this->number[0] == '-')
        {
            neg_num1 = true;
            len1 -= 1;
        }
        if (val.number[0] == '-')
        {
            neg_num2 = true;
            len2 -= 1;
        }
        if (neg_num1 && neg_num2)
        {
            neg_ans = false;
        }
        else if (neg_num1 || neg_num2)
        {
            neg_ans = true;
        }

        if (len1 > len2)
        {

            if (neg_num1 || neg_num2)
            {
                num1 = new char[len1];
                for (int i = 1; i < len1; ++i)
                {
                    num1[i] = this->number[i];
                }
                num2 = new char[len2];
                for (int i = 1; i < len2; ++i)
                {
                    num2[i] = val.number[i];
                }
            }
            else
            {
                num2 = val.number;
                num1 = this->number;
            }
            j = len2 - 2;
            length = len1 - 1;
            len = len2 - 1;
            mainlen = len1 + len2 - 2;

            ptr = new int *[len2 - 2];
            for (int i = 0; i < len2 - 1; ++i)
            {
                ptr[i] = new int[mainlen]{0};
            }
        }
        else
        {
            if (neg_num1 || neg_num2)
            {
                num2 = new char[len2];
                for (int i = 1; i < len2 + 1; ++i)
                {
                    num2[i - 1] = this->number[i];
                }
                num1 = new char[len1];
                for (int i = 1; i < len1 + 1; ++i)
                {
                    num1[i - 1] = val.number[i];
                }
            }
            else
            {
                num2 = this->number;
                num1 = val.number;
            }
            length = len2 - 1;
            mainlen = len1 + len2 - 2;

            ptr = new int *[len1 - 2];
            len = len1 - 1;
            for (int i = 0; i < len1 - 1; ++i)
            {
                ptr[i] = new int[mainlen]{0};
            }
            j = len1 - 2;
        }

        int n1, n2, carry = 0;

        for (j; j >= 0; --j)
        {
            int l;
            for (l = 0; l < k; ++l)
            {
                ptr[k][l] = 0;
            }
            ind = l;
            for (int i = len1 - 2; i >= 0; --i)
            {
                n1 = num1[i] - '0';
                n2 = num2[j] - '0';
                num3 = n1 * n2 + carry;
                carry = 0;
                if (num3 > 9)
                {
                    ptr[k][ind] = num3 % 10;
                    carry = num3 / 10;
                }
                else
                {
                    ptr[k][ind] = num3;
                }
                ind++;
            }
            if (carry != 0)
            {
                ptr[k][ind] = carry;
                ind++;
            }

            k++;
            ind = 0;
            carry = 0;
        }

        ind = 0;
        carry = 0;
        int sum = 0;
        length = len1 + len2 - 2;

        int *ptr2 = new int[mainlen];
        for (int i = 0; i < mainlen; ++i)
        {
            for (int j = 0; j < len; ++j)
            {
                sum += ptr[j][i];
                ind++;
            }
            ind = 0;
            sum += carry;
            carry = 0;
            if (sum > 9)
            {
                ptr2[i] = sum % 10;
                carry = sum / 10;
            }
            else
            {
                ptr2[i] = sum;
            }
            sum = 0;
        }
        ind = mainlen - 1;

        this->number = new char[mainlen + 2];
        if (neg_ans)
        {
            ind += 1;
            this->number[0] = '-';
        }
        int zero = 0;
        for (int i = mainlen - 1; i >= 0; --i)
        {
            if (ptr2[i] == 0)
            {
                zero += 1;
            }
            else
            {
                break;
            }
        }
        ind -= zero;
        number[mainlen - zero] = '\0';
        for (int i = 0; i <= mainlen - 1 - zero; ++i)
        {
            number[ind] = ptr2[i] + '0';
            ind--;
        }
    }
    return *this;
}

BigInt BigInt::operator-=(const BigInt &val)
{
    char *temp;
    int len1 = this->len;
    int len2 = val.len;
    int length = 0;
    int carry = 0;
    int ans;
    int num1, num2;
    temp = new char[len1];

    char *number1 = new char[this->len];
    for (int i = 0; i < this->len; ++i)
    {
        number1[i] = this->number[i];
    }
    length = len1;
    int j = len2 - 2;
    for (int i = len1 - 2; i >= 0; --i)
    {
        num1 = number1[i] - '0';
        num2 = val.number[j] - '0';
        if (j >= 0)
        {
            if (num1 < num2)
            {
                int temp1 = 0;
                int k = 0;
                for (k = i - 1; k >= 0; --k)
                {
                    temp1 = number1[k] - '0';
                    if (temp1 != 0)
                    {
                        carry = 1;
                        temp1 -= 1;
                        
                        number1[k] = temp1 + '0';
                        break;
                    }
                }
                for (k += 1; k <= i; ++k)
                {
                    temp1 = number1[k] - '0';
                    temp1 += 10;
                    if (k != i)
                    {
                        temp1 -= 1;
                        number1[k] = temp1 + '0';
                    }
                }
                num1 = num1 + 10;
                
            }
            ans = num1 - num2;
            if (ans > 9)
            {
                temp[i] = (ans % 10) + '0';
                carry = ans / 10;
            }
            else
            {
                temp[i] = ans + '0';
            }
            j--;
        }
        else if (carry != 0)
        {
            ans = num1;
            if (ans > 9)
            {
                temp[i] = (ans % 10) + '0';
                carry = ans / 10;
            }
            else
            {
                temp[i] = ans + '0';
            }
            j--;
        }
        else if (carry == 0)
        {
            temp[i] = this->number[i];
            break;
        }
    }
    if (temp[0] == '0')
    {
        int zero = 0;
        for (int i = 0; i < length; ++i)
        {
            if (temp[i] == '0')
            {
                zero += 1;
            }
            else
            {
                break;
            }
        }
        int length1 = length - zero;
        char *temp2 = temp;
        temp = new char[length1];
        int ind = 0;
        for (int i = 0; i < length; ++i)
        {
            if (temp2[i] != '0')
            {
                temp[ind] = temp2[i];
                ind++;
            }
        }
        temp[ind] = '\0';
        this->len = ind;
        this->number = temp;
    }
    else
    {
        this->number = temp;
    }

    return *this;
}

bool BigInt::operator==(const BigInt &val) const
{
    int len1 = this->len;
    int len2 = val.len;
    if (len1 != len2)
    {
        return false;
    }
    else
    {
        for (int i = 0; this->number[i] != '\0'; ++i)
        {
            if (this->number[i] != val.number[i])
            {
                return false;
            }
        }
    }
    return true;
}

bool BigInt::operator==(const char *val) const
{
    int len1 = this->len;
    int len2 = 0;
    for (int i = 0; val[i] != '\0'; ++i)
    {
        len2++;
    }
    len2 += 1;
    if (len1 != len2)
    {
        return false;
    }
    else
    {
        for (int i = 0; this->number[i] != '\0'; ++i)
        {
            if (this->number[i] != val[i])
            {
                return false;
            }
        }
    }
    return true;
}

bool BigInt::operator!=(const BigInt &val) const
{
    int len1 = this->len;
    int len2 = val.len;
    bool check = false;
    if (this->len != val.len)
    {
        return true;
    }
    else
    {
        for (int i = 0; this->number[i] != '\0'; ++i)
        {
            if (this->number[i] != val.number[i])
            {
                check = true;
            }
        }
    }
    return check;
}

bool BigInt::operator<(const BigInt &val) const
{
    int len1 = this->len;
    int len2 = val.len;
    if (len1 < len2)
    {
        return true;
    }
    else if (len > len2)
    {
        return false;
    }
    else if (len1 == len2)
    {
        for (int i = 0; this->number[i] != '\0'; ++i)
        {
            if (this->number[i] < val.number[i])
            {
                return true;
            }
        }
    }
    return false;
}

bool BigInt::operator>(const BigInt &val) const
{
    int len1 = this->len;
    int len2 = val.len;
    if (len1 > len2)
    {
        return true;
    }
    else if (len < len2)
    {
        return false;
    }
    else if (len1 == len2)
    {
        for (int i = 0; this->number[i] != '\0'; ++i)
        {
            if (this->number[i] > val.number[i])
            {
                return true;
            }
        }
    }
    return false;
}

bool BigInt::operator>=(const BigInt &val) const
{
    bool check = false;
    int len1 = this->len;
    int len2 = val.len;
    if (len1 > len2)
    {
        return true;
    }
    else if (len1 < len2)
    {
        return false;
    }
    else if (len1 == len2)
    {
        for (int i = 0; this->number[i] = '\0'; ++i)
        {
            if (this->number[i] < val.number[i])
            {
                check = false;
                break;
            }
        }
        return check;
    }
    return false;
}

bool BigInt::operator<=(const BigInt &val) const
{
    bool check = false;
    int len1 = this->len;
    int len2 = val.len;
    if (len1 < len2)
    {
        return true;
    }
    else if (len1 > len2)
    {
        return false;
    }
    else if (len1 == len2)
    {
        for (int i = 0; this->number[i] = '\0'; ++i)
        {
            if (this->number[i] > val.number[i])
            {
                check = false;
                break;
            }
        }
        return check;
    }
    return false;
}

BigInt &BigInt::operator++()
{
    int num1;
    int carry = 0;
    int len1 = this->len;
    num1 = this->number[len1 - 2] - '0';
    num1 += 1;
    if (num1 > 9)
    {
        this->number[len - 2] = 0 + '0';
        carry = 1;
    }
    else
    {
        this->number[len - 2] = num1 + '0';
    }
    if (carry == 1)
    {
        for (int i = len1 - 3; i >= 0; --i)
        {
            num1 = this->number[i] - '0';
            num1 += carry;
            if (num1 > 9)
            {
                this->number[i] = 0 + '0';
                carry = 1;
            }
            if (carry == 0)
            {
                break;
            }
        }
    }
    if (carry == 1)
    {
        char *temp = this->number;
        this->number = new char[len1 + 1];
        this->number[0] = carry + '0';
        int ind = 1;
        for (int i = 0; i < len1; ++i)
        {
            number[ind] = temp[i];
            ind++;
        }
    }
    return *this;
}

BigInt &BigInt::operator++(int)
{
    int num1;
    int carry = 0;
    int len1 = this->len;
    num1 = this->number[len1 - 2] - '0';
    num1 += 1;
    BigInt inc;
    inc.number = new char[len1];
    inc.len = len1;
    for (int i = 0; i < len1; ++i)
    {
        inc.number[i] = this->number[i];
    }
    if (num1 > 9)
    {
        this->number[len - 2] = 0 + '0';
        carry = 1;
    }
    else
    {
        this->number[len - 2] = num1 + '0';
    }
    if (carry == 1)
    {
        for (int i = len1 - 3; i >= 0; --i)
        {
            num1 = this->number[i] - '0';
            num1 += carry;
            if (num1 > 9)
            {
                this->number[i] = 0 + '0';
                carry = 1;
            }
            if (carry == 0)
            {
                break;
            }
        }
    }
    if (carry == 1)
    {
        char *temp = this->number;
        this->number = new char[len1 + 1];
        this->number[0] = carry + '0';
        int ind = 1;
        for (int i = 0; i < len1; ++i)
        {
            number[ind] = temp[i];
            ind++;
        }
        this->len = ind;
    }
    return inc;
}

BigInt &BigInt::operator--()
{
    int num1;
    int len1 = this->len;
    int carry = 0;
    num1 = number[len - 2] - '0';
    if (num1 == 0)
    {
        int temp1 = 0;
        int k = 0;
        for (k = (len - 2) - 1; k >= 0; --k)
        {
            temp1 = this->number[k] - '0';
            if (temp1 != 0)
            {
                carry = 1;
                temp1 -= 1;
                this->number[k] = temp1 + '0';
                break;
            }
        }
        for (k += 1; k <= len - 2; ++k)
        {
            temp1 = this->number[k] - '0';
            temp1 += 10;
            if (k != len - 2)
            {
                temp1 -= 1;
                this->number[k] = temp1 + '0';
            }
        }
        num1 = num1 + 10;
        num1 -= 1;
        this->number[len - 2] = num1 + '0';
    }
    else
    {
        num1 -= 1;
        this->number[len - 2] = num1 + '0';
    }
    if (this->number[0] == '0')
    {
        int zero = 0;
        for (int i = 0; i < len - 1; ++i)
        {
            if (this->number[i] == '0')
            {
                zero += 1;
            }
            else
            {
                break;
            }
        }
        int length1 = len1 - zero;
        char *temp2 = this->number;
        this->number = new char[length1];
        int ind = 0;
        for (int i = 0; i < len; ++i)
        {
            if (temp2[i] != '0')
            {
                this->number[ind] = temp2[i];
                ind++;
            }
        }
        this->number[ind] = '\0';
        this->len = ind;
    }
    return *this;
}

BigInt &BigInt::operator--(int)
{
    int num1;
    int len1 = this->len;
    int carry = 0;
    num1 = number[len - 2] - '0';
    BigInt val;
    val.number = new char[len1];
    for (int i = 0; i < len1; ++i)
    {
        val.number[i] = this->number[i];
    }
    if (num1 == 0)
    {
        int temp1 = 0;
        int k = 0;
        for (k = (len - 2) - 1; k >= 0; --k)
        {
            temp1 = this->number[k] - '0';
            if (temp1 != 0)
            {
                carry = 1;
                temp1 -= 1;
                this->number[k] = temp1 + '0';
                break;
            }
        }
        for (k += 1; k <= len - 2; ++k)
        {
            temp1 = this->number[k] - '0';
            temp1 += 10;
            if (k != len - 2)
            {
                temp1 -= 1;
                this->number[k] = temp1 + '0';
            }
        }
        num1 = num1 + 10;
        num1 -= 1;
        this->number[len - 2] = num1 + '0';
    }
    else
    {
        num1 -= 1;
        this->number[len - 2] = num1 + '0';
    }
    if (this->number[0] == '0')
    {
        int zero = 0;
        for (int i = 0; i < len - 1; ++i)
        {
            if (this->number[i] == '0')
            {
                zero += 1;
            }
            else
            {
                break;
            }
        }
        cout << "zero  = " << zero << endl;
        int length1 = len1 - zero;
        char *temp2 = this->number;
        this->number = new char[length1];
        int ind = 0;
        for (int i = 0; i < len - 2; ++i)
        {
            if (temp2[i] != '0')
            {
                this->number[ind] = temp2[i];
                ind++;
            }
        }
        this->number[ind] = '\0';
        this->len = ind;
    }
    return val;
}

ostream &operator<<(ostream &output, const BigInt &val)
{
    cout << val.number << endl;
    return output;
}

istream &operator>>(istream &input, BigInt &val)
{
    int len = 0;
    cout << "Enter length : ";
    cin >> len;
    val.set_length(len + 1);
    char *temp = new char[len + 2];
    cin.ignore();
    cout << "Enter Number : ";
    cin.get(temp, len + 1);
    val.set_number(temp);
    // cout << val.get_number() ;
    return input;
}