//Name : Hussnain Ul Abidin
//Roll No : 22i-1102_K
#include <iostream>
#include <string>

using namespace std;

class BigInt
{
private:
    char *number;
    int len = 0;
public:
    BigInt(int);
    BigInt(const string&);
    BigInt(const BigInt&);
    char* get_number();
    int get_length();
    void set_number(char *);
    void set_length(int);
    BigInt operator +(int) const;
    BigInt operator +(const BigInt&) const;
    BigInt operator+=(const BigInt& rhs);
    BigInt operator -(int) const;
    BigInt operator -(const BigInt&) const;
    BigInt operator -=(const BigInt&);
    BigInt operator *(const BigInt&) const;
    BigInt operator *=(const BigInt&);
    bool operator ==(const BigInt&) const;
    bool operator ==(const char* ) const;
    bool operator !=(const BigInt&) const;
    bool operator <(const BigInt& ) const;
    bool operator >(const BigInt& ) const;
    bool operator >=(const BigInt& ) const;
    bool operator <=(const BigInt& ) const;
    BigInt& operator ++();
    BigInt& operator ++(int);
    BigInt& operator --();
    BigInt& operator --(int);
    string toString();

    friend ostream& operator<<(ostream& output, const BigInt& val);
    
    

    


    operator string();
};