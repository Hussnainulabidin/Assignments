#include <iostream>
#include "String.h"

String::String()
{
    data = NULL;
}

String::String(char *str)
{
    int len = 0;
    for (int i = 0; str[i] != '\0'; ++i)
    {
        len++;
    }
    data = new char[len + 1];
    for (int i = 0; str[i] != '\0'; ++i)
    {
        data[i] = str[i];
    }
    data[len] = '\0';
}

String::String(int x)
{
    data = new char[x];
    data[0] = '\0';
}

String::String(const String &str)
{
    int len = 0;
    for (int i = 0; str.data[i] != '\0'; ++i)
    {
        len++;
    }

    data = new char[len + 1];
    for (int i = 0; str.data[i] != '\0'; ++i)
    {
        data[i] = str.data[i];
    }
    data[len] = '\0';
}

// Member Functions

char* String::getdata()
{
    return data;
}

char String::getChar(int i)
{
    return data[i];
}

bool String::isEmpty()
{
    if (data == NULL)
        return true;
    if (data[0] == '\0')
        return true;
    else
        return false;
}

int String::length()
{
    int len = 0;
    for (int i = 0; data[i] != '\0'; ++i)
    {
        len++;
    }
    return len;
}

String String::append_string(const String &str)
{
    int len = 0;
    int len1 = 0;
    for (int i = 0; data[i] != '\0'; ++i)
    {
        len++;
    }
    for (int i = 0; str.data[i] != '\0'; ++i)
    {
        len1++;
    }

    String temp;
    temp.data = new char[len + len1 + 1];
    int ind = 0;
    for (int i = 0; i < len + len1; ++i)
    {
        if (i < len)
        {
            temp.data[i] = data[i];
        }
        if (i >= len)
        {
            temp.data[i] = str.data[ind];
            ind++;
        }
    }
    temp.data[len + len1] = '\0';
    data = new char[len + len1 + 1];
    int length = len1 + len + 1;

    for (int i = 0; i < length; ++i)
    {
        data[i] = temp.data[i];
    }
    return temp;
}

String String::append_string(const char &str)
{
    int len = 0;
    for (int i = 0; data[i] != '\0'; ++i)
    {
        len++;
    }
    String temp;
    temp.data = new char[len + 2];
    for (int i = 0; i < len + 1; ++i)
    {
        if (i < len)
        {
            temp.data[i] = data[i];
        }
        if (i >= len)
        {
            temp.data[i] = str;
        }
    }
    temp.data[len + 1] = '\0';

    data = new char[len + 2];
    int length = len + 2;

    for (int i = 0; i < length; ++i)
    {
        data[i] = temp.data[i];
    }
    return temp;
}

String String::append_string(char *&str)
{
    int len = 0;
    int len1 = 0;
    for (int i = 0; data[i] != '\0'; ++i)
    {
        len++;
    }
    for (int i = 0; str[i] != '\0'; ++i)
    {
        len1++;
    }
    String temp;
    temp.data = new char[len + len1 + 1];
    int ind = 0;
    for (int i = 0; i < len + len1; ++i)
    {
        if (i < len)
        {
            temp.data[i] = data[i];
        }
        if (i >= len)
        {
            temp.data[i] = str[ind];
            ind++;
        }
    }
    temp.data[len + len1] = '\0';

    data = new char[len + len1 + 1];
    int length = len + len + 1;

    for (int i = 0; i < length; ++i)
    {
        data[i] = temp.data[i];
    }
    return temp;
}

String String::append_string(string &str)
{
    int len = 0;
    int len1 = 0;
    for (int i = 0; data[i] != '\0'; ++i)
    {
        len++;
    }
    for (int i = 0; str[i] != '\0'; ++i)
    {
        len1++;
    }
    String temp;
    temp.data = new char[len + len1 + 1];
    int ind = 0;
    for (int i = 0; i < len + len1; ++i)
    {
        if (i < len)
        {
            temp.data[i] = data[i];
        }
        if (i >= len)
        {
            temp.data[i] = str[ind];
            ind++;
        }
    }
    temp.data[len + len1] = '\0';

    data = new char[len + len1 + 1];
    int length = len1 + len + 1;

    for (int i = 0; i < length; ++i)
    {
        data[i] = temp.data[i];
    }
    return temp;
}

String String::remove_string(const String &substr)
{
    int start = 0, end = 0;
    bool check = false;
    int len = 0;
    for (int i = 0; data[i] != '\0'; ++i)
    {
        if (data[i] == substr.data[0])
        {
            check = true;
            int ind = i + 1;
            start = i;
            for (int j = 1; substr.data[j] != '\0'; ++j)
            {
                if (substr.data[j] != data[ind])
                {
                    check = false;
                    break;
                }
                ind++;
            }
            if (check == true)
            {
                end = ind;
                break;
            }
        }
        
    }
    for(int i = 0 ; data[i] != '\0' ; ++i)
        len++;
    int len1 = len - (end - start);
    int ind = 0;
    String temp;
    temp.data = new char[len + 1];
    {
        for (int i = 0; data[i] != '\0'; ++i)
        {
            if (i >= start && i < end)
            {
                continue;
            }
            temp.data[ind] = data[i];
            ind++;
        }
    }
    temp.data[ind] = '\0';
    data = new char[len1 + 1];
    int length = len1 + 1;
    for (int i = 0; i < length; ++i)
    {
        data[i] = temp.data[i];
    }
    return temp;
}

String String::remove_string(string &substr)
{
    int start, end;
    bool check = false;
    int len = 0;
    for (int i = 0; data[i] != '\0'; ++i)
    {
        if (data[i] == substr[0])
        {
            check = true;
            int ind = i + 1;
            start = i;
            for (int j = 1; substr[j] != '\0'; ++j)
            {
                if (substr[j] != data[ind])
                {
                    check = false;
                    break;
                }
                ind++;
            }
            if (check == true)
            {
                end = ind;
            }
        }
       
    }
    for(int i = 0 ; data[i] != '\0' ; ++i)
        len++;
    int len1 = len - (end - start);
    int ind = 0;
    String temp;
    temp.data = new char[len + 1];
    {
        for (int i = 0; data[i] != '\0'; ++i)
        {
            if (i >= start && i < end)
            {
                continue;
            }
            temp.data[ind] = data[i];
            ind++;
        }
    }
    temp.data[ind] = '\0';
    data = new char[len1 + 1];
    int length = len1 + 1;

    for (int i = 0; i < length; ++i)
    {
        data[i] = temp.data[i];
    }
    return temp;
}

String String::remove_string(char *&substr)
{
    int start = 0, end = 0;
    bool check = false;
    int len = 0;
    for (int i = 0; data[i] != '\0'; ++i)
    {
        if (data[i] == substr[0])
        {
            check = true;
            int ind = i + 1;
            start = i;
            for (int j = 1; substr[j] != '\0'; ++j)
            {
                if (substr[j] != data[ind])
                {
                    check = false;
                    break;
                }
                ind++;
            }
            if (check == true)
            {
                end = ind;
            }
        }
    }
    for(int i = 0 ; data[i] != '\0' ; ++i)
        len++;
    int len1 = (end - start) - len;
    int ind = 0;
    String temp;
    temp.data = new char[len + 1];
    {
        for (int i = 0; data[i] != '\0'; ++i)
        {
            if (i >= start && i < end)
            {
                continue;
            }
            temp.data[ind] = data[i];
            ind++;
        }
    }
    temp.data[ind] = '\0';
    return temp;
}

String String::remove_string(const char &a)
{
    int start = 0, end = 0;
    for (int i = 0; data[i] != '\0'; ++i)
    {
        if (data[i] == a)
        {
            start = i;
            break;
        }
    }
    int len = 0;
    for (int i = 0; data[i] != '\0'; ++i)
    {
        len++;
    }
    end = start + 1;
    int len1 = len - (end - start);
    int ind = 0;
    String temp;
    temp.data = new char[len + 1];
    {
        for (int i = 0; data[i] != '\0'; ++i)
        {
            if (i >= start && i < end)
            {
                continue;
            }
            temp.data[ind] = data[i];
            ind++;
        }
    }
    temp.data[ind] = '\0';
    data = new char[len1 + 1];
    int length = len1 + len + 1;

    for (int i = 0; i < length; ++i)
    {
        data[i] = temp.data[i];
    }
    return temp;
}

String& String::assign_string(const String &str)
{
    int len = 0;
    for (int i = 0; str.data[i] != '\0'; ++i)
    {
        len++;
    }
    String *temp = new String;
    temp->data = new char[len + 1];

    for (int i = 0; i < len + 1; ++i)
    {
        temp->data[i] = str.data[i];
    }
    temp->data[len] = '\0';
    data = new char[len + 1];
    int length = len + 1;

    for (int i = 0; i < length; ++i)
    {
        data[i] = temp->data[i];
    }
    return *(temp);
}

String& String::assign_string(char *str)
{
    int len = 0;
    for (int i = 0; str[i] != '\0'; ++i)
    {
        len++;
    }
    String *temp = new String;
    temp->data = new char[len + 1];

    for (int i = 0; i < len + 1; ++i)
    {
        temp->data[i] = str[i];
    }
    temp->data[len] = '\0';
    data = new char[len + 1];
    int length = len + 1;

    for (int i = 0; i < length; ++i)
    {
        data[i] = temp->data[i];
    }
    return *(temp);
}

String& String::assign_string(const string &str)
{
    int len = 0;
    for (int i = 0; str[i] != '\0'; ++i)
    {
        len++;
    }
    String *temp = new String;
    temp->data = new char[len + 1];

    for (int i = 0; i < len + 1; ++i)
    {
        temp->data[i] = str[i];
    }
    temp->data[len] = '\0';
    data = new char[len + 1];
    int length = len + 1;

    for (int i = 0; i < length; ++i)
    {
        data[i] = temp->data[i];
    }
    return *(temp);
}

bool String::isEqual(const String &str) const
{
    bool check = true;
    int len = 0;
    int len1 = 0;
    for (int i = 0; data[i] != '\0'; ++i)
    {
        len++;
    }
    for (int i = 0; str.data[i] != '\0'; ++i)
    {
        len1++;
    }
    if (len != len1)
        return false;
    else
        for (int i = 0; str.data[i] != '\0' && data[i] != '\0'; ++i)
        {
            if (str.data[i] != data[i])
            {
                check = false;
            }
        }
    return check;
}

bool String::isEqual(const string &str) const
{
    bool check = true;
    int len = 0;
    int len1 = 0;
    for (int i = 0; data[i] != '\0'; ++i)
    {
        len++;
    }
    for (int i = 0; str[i] != '\0'; ++i)
    {
        len1++;
    }
    if (len != len1)
        return false;
    else
        for (int i = 0; str[i] != '\0' && data[i] != '\0'; ++i)
        {
            if (str[i] != data[i])
            {
                check = false;
            }
        }
    return check;
}

bool String::isEqual(char *str) const
{
    bool check = true;
    int len = 0;
    int len1 = 0;
    for (int i = 0; data[i] != '\0'; ++i)
    {
        len++;
    }
    for (int i = 0; str[i] != '\0'; ++i)
    {
        len1++;
    }
    if (len != len1)
        return false;
    else
        for (int i = 0; str[i] != '\0' && data[i] != '\0'; ++i)
        {
            if (str[i] != data[i])
            {
                check = false;
            }
        }
    return check;
}

int String::index_at(char A) const
{
    int index = -1;
    for (int i = 0; data[i] != '\0'; ++i)
    {
        if (data[i] == A)
        {
            index = i;
            break;
        }
    }
    return index;
}

int String::index_at(const String &str) const
{
    int start = 0, end = 0;
    bool check = false;
    int len = 0;
    for (int i = 0; data[i] != '\0'; ++i)
    {
        if (data[i] == str.data[0])
        {
            check = true;
            int ind = i + 1;
            start = i;
            for (int j = 1; str.data[j] != '\0'; ++j)
            {
                if (str.data[j] != data[ind])
                {
                    check = false;
                    break;
                }
                ind++;
            }
            if (check == true)
            {
                end = ind;
                break;
            }
        }
        len++;
    }
    return start;
}

int String::index_at(const string &str) const
{
    int start = 0, end = 0;
    bool check = false;
    int len = 0;
    for (int i = 0; data[i] != '\0'; ++i)
    {
        if (data[i] == str[0])
        {
            check = true;
            int ind = i + 1;
            start = i;
            for (int j = 1; str[j] != '\0'; ++j)
            {
                if (str[j] != data[ind])
                {
                    check = false;
                    break;
                }
                ind++;
            }
            if (check == true)
            {
                end = ind;
                break;
            }
        }
        len++;
    }
    return start;
}

int String::index_at(char *str) const
{
    int start = 0, end = 0;
    bool check = false;
    int len = 0;
    for (int i = 0; data[i] != '\0'; ++i)
    {
        if (data[i] == str[0])
        {
            check = true;
            int ind = i + 1;
            start = i;
            for (int j = 1; str[j] != '\0'; ++j)
            {
                if (str[j] != data[ind])
                {
                    check = false;
                    break;
                }
                ind++;
            }
            if (check == true)
            {
                end = ind;
                break;
            }
        }
        len++;
    }
    return start;
}