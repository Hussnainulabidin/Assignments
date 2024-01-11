//Name : Hussnain Ul Abidin
//Roll no : 22i-1102
//Section : K
#include <iostream>
#include "Food.cpp"

using namespace std;

class cart
{
private:
    Breads *bread;
    Pens *pen;
    Socks *sock;
    Eggs *egg;

    int no_egg = 0;
    int no_pen = 0;
    int no_bread = 0;
    int no_sock = 0;

    static int total_items;
public:
    static int Total_items();
    Breads *getbread();
    Eggs *getegg();
    Socks *getsock();
    Pens *getpen();
    int getNobread();
    int getNoegg();
    int getNosock();
    int getNopen();
    bool Discount();

    // void operator=(cart &);
    void operator+=(Breads &);
    void operator+=(Eggs &);
    void operator+=(Socks &);
    void operator+=(Pens &);

    cart& operator-(Breads &);
    cart& operator-(Eggs &);
    cart& operator-(Socks &);
    cart& operator-(Pens &);

    cart& operator+(Breads &);
    cart& operator+(Eggs &);
    cart& operator+(Socks &);
    cart& operator+(Pens &);

    void operator-=(Breads &);
    void operator-=(Eggs &);
    void operator-=(Socks &);
    void operator-=(Pens &);

    friend ostream &operator<<(ostream & , cart& C);
};

int cart::total_items = 0;