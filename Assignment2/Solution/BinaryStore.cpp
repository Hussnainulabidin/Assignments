#include <iostream>
#include "BinaryStore.h"

using namespace std;

BinaryStore::BinaryStore()
{
    Address = nullptr;
    Byte = nullptr;
}

BinaryStore::BinaryStore(int len)
{
    length = len;
    Address = new char *[len];
    for (int i = 0; i < len; ++i)
    {
        Address[i] = new char[5]{"\0"};
    }
    Byte = new char *[len];
    for (int i = 0; i < len; ++i)
    {
        Byte[i] = nullptr;
    }
}

void BinaryStore::showdata()
{
    for(int i = 0 ; i < length ; ++i)
    {
        cout << Address[i] ;
        if(Byte[i] != nullptr)
        {
            cout << "          " << Byte[i];
        }
        cout << endl;
    }
}

void BinaryStore::add_Address(char *s)
{
    int len = 0;
    int len1 = 1;
    for (int i = 0; s[i] != '\0'; ++i)
    {
        len++;
    }
    for (int i = 0; Address[i][0] != '\0'; ++i)
    {
        len1++;
    }
    len1 = len1 - 1;
    char *add = new char[len + 1];
    for (int i = 0; s[i] != '\0'; ++i)
    {
        add[i] = s[i];
    }
    add[len] = '\0';
    for (int i = 0; i < len + 1; ++i)
    {
        Address[len1][i] = add[i];
    }
}

void BinaryStore::set_Byte(char *address, char *value)
{
    bool check = false;
    int index = -1;
    for (int i = 0; i < length; ++i)
    {
        check = false;
        for (int j = 0; address[j] != '\0'; ++j)
        {
            check = true;
            if (address[j] != Address[i][j])
            {
                check = false;
                break;
            }
        }
        if (check == true)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        char **temp = Address;
        char **temp1 = Byte;
        length += 1;
        Address = new char *[length];
        Byte = new char *[length];
        for (int i = 0; i < length; ++i)
        {
            Address[i] = new char[5];
        }
        for (int i = 0; i < length; ++i)
        {
            Byte[i] = nullptr;
        }
        for (int i = 0; i < length - 1; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                Address[i][j] = temp[i][j];
            }
            if(temp1[i] != nullptr)
            {
                Byte[i] = new char[9];
                for (int j = 0; j < 9; ++j)
                {
                    Byte[i][j] = temp1[i][j];
                }
            }
        }
        Byte[length-1] = new char[9];
        char *temp3 = new char[9];
        for (int i = 0; i < 9; ++i)
        {
            temp3[i] = value[i];
        }
        char *temp4 = new char[5];
        for (int i = 0; i < 5; ++i)
        {
            temp4[i] = address[i];
        }
        Address[length - 1] = temp4;
        Byte[length - 1] = temp3;
    }
    else
    {
        Byte[index] = new char[9];
        char *temp3 = new char[9];
        for (int i = 0; i < 9; ++i)
        {
            temp3[i] = value[i];
        }
        Byte[index] = temp3;
    }
}

char* BinaryStore::Get(char *address)
{
    int index = -1;
    bool check = false;
    for (int i = 0; i < length; ++i)
    {
        check = false;
        for (int j = 0; address[j] != '\0'; ++j)
        {
            check = true;
            if (address[j] != Address[i][j])
            {
                check = false;
                break;
            }
        }
        if (check == true)
        {
            index = i;
            break;
        }
    }
    if (check == true)
    {
        return Byte[index];
    }
    else 
    {
        return NULL;
    }
}

char *BinaryStore::ToString()
{
    int len = length * 4 + length * 9;
    char *store = new char[len];
    int ind = 0;
    for(int i = 0 ; i < length ; ++i)
    {

        for(int j = 0 ; j < 4  ;++j )
        {

            store[ind] = Address[i][j];
            ind++;
        }
        if(Byte[i] != nullptr)
        {
            for(int j = 0 ; j < 8; ++j)
            {
                store[ind] = Byte[i][j];
                ind++;
            }
        }
    }
    store[ind] = '\0';
    return store;
}

char *BinaryStore::Add(char *a , char *b)
{
    int len1 = 0 , len2 = 0;
    for(int i  = 0 ; a[i] != '\0' ; ++i)
        len1++;
    for(int i  = 0 ; a[i] != '\0' ; ++i)
        len2++; 
    
    char* num1 = new char[len1+1];
    char* num2 = new char[len2+1];   
    char* ans  = new char[len1+1]; 

    for(int i = 0 ; i < len1+1 ; ++i)
    {
        num1[i] = a[i];
        num2[i] = b[i];   
    }
    char carry = '0';
    for(int i = len1-1 ; i >= 0 ; --i)
    {
        if(num1[i] == '0' && num2[i] == '0' && carry == '0') // 0 , 0 , 0
        {
            ans[i] = '0';
            carry = '0';
        }
        else if(num1[i] == '0' && num2[i] == '1' && carry == '0') // 0 , 1 ,0
        {
            ans [i] = '1';
            carry = '0';
        }
        else if(num1[i] == '1' && num2[i] == '0' && carry == '0') // 1, 0 ,0
        {
            ans [i] = '1';
            carry = '0';
        }
        else if(num1[i] == '1' && num2[i] == '1' && carry == '0') // 1 , 1, 0
        {
            ans [i] = '0';
            carry = '1';
        }
        else if(num1[i] == '1' && num2[i] == '1' && carry == '1') // 1, ,1, 1
        {
            ans [i] = '1';
            carry = '1';
        }
        else if(num1[i] == '1' && num2[i] == '0' && carry == '1') // 1 , 0 , 1
        {
            ans [i] = '0';
            carry = '1';
        }
        else if(num1[i] == '0' && num2[i] == '1' && carry == '1') // 0 , 1 , 1
        {
            ans [i] = '0';
            carry = '1';
        }
        else if(num1[i] == '0' && num2[i] == '0' && carry == '1') // 0 , 0 , 1
        {
            ans [i] = '1';
            carry = '0';
        }
    }
    ans[len1] = '\0';
    return ans;
}

bool BinaryStore::comp_EQUAL(char *a , char *b)
{
    bool check = false;
    int len = 0;
    for(int i = 0 ; a[i] != '\0' ; ++i)
    {
        len++;
    }
    len +=1;
    char* num1 = new char[len];
    char* num2 = new char[len];
    for(int i = 0 ; a[i] != '\0' ; ++i)
    {
        num1[i] = a[i];
        num2[i] = b[i];
    } 
    num1[len-1] = '\0';
    num2[len-1] = '\0'; 
    for(int i = 0 ; num1[i] != '\0' ; ++i)
    {
        if(num1[i] != num2[i])
        {
            return false;
        }
    }
    return true;
}

char* BinaryStore::comp_AND(char *a , char *b)
{
    int len1 = 0 , len2 = 0;
    for(int i  = 0 ; a[i] != '\0' ; ++i)
        len1++;
    for(int i  = 0 ; a[i] != '\0' ; ++i)
        len2++; 
    
    char* num1 = new char[len1+1];
    char* num2 = new char[len2+1];   
    char* ans  = new char[len1+1]; 

    for(int i = 0 ; i < len1+1 ; ++i)
    {
        num1[i] = a[i];
        num2[i] = b[i];   
    }
    for(int i = len1-1 ; i >= 0 ; --i)
    {
        if(num1[i] == '0' && num2[i] == '0')
        {
            ans[i] = '0';
        }
        else if(num1[i] == '0' && num2[i] == '1' || num1[i] == '1' && num2[i] == '0')
        {
            ans[i] = '0';
        }
        else if(num1[i] == '1' && num2[i] == '1')
        {
            ans[i] = '1'; 
        }
    }
    ans[len1] = '\0';
    return ans; 
}

char* BinaryStore::comp_OR(char *a , char *b)
{
    int len1 = 0 , len2 = 0;
    for(int i  = 0 ; a[i] != '\0' ; ++i)
        len1++;
    for(int i  = 0 ; a[i] != '\0' ; ++i)
        len2++; 
    
    char* num1 = new char[len1+1];
    char* num2 = new char[len2+1];   
    char* ans  = new char[len1+1]; 

    for(int i = 0 ; i < len1+1 ; ++i)
    {
        num1[i] = a[i];
        num2[i] = b[i];   
    }
    for(int i = len1-1 ; i >= 0 ; --i)
    {
        if(num1[i] == '0' && num2[i] == '0')
        {
            ans[i] = '0';
        }
        else if(num1[i] == '0' && num2[i] == '1' || num1[i] == '1' && num2[i] == '0')
        {
            ans[i] = '1';
        }
        else if(num1[i] == '1' && num2[i] == '1')
        {
            ans[i] = '1'; 
        }
    }
    ans[len1] = '\0';
    return ans; 
}

char* BinaryStore::comp_NOT(char *a)
{
    int len1 = 0 , len2 = 0;
    for(int i  = 0 ; a[i] != '\0' ; ++i)
        len1++;
    
    char* num1 = new char[len1+1]; 
    char* ans  = new char[len1+1]; 

    for(int i = 0 ; i < len1+1 ; ++i)
    {
        num1[i] = a[i];
    }
    for(int i = len1-1 ; i >= 0 ; --i)
    {
        if(num1[i] == '0')
        {
            ans[i] = '1';
        }
        else if(num1[i] == '1')
        {
            ans[i] = '0';
        }
    }
    ans[len1] = '\0';
    return ans; 
}

BinaryStore::~BinaryStore()
{
    delete[] Byte;
    delete [] Address;
    
}
