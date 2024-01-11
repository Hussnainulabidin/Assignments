//Name : Hussnain Ul Abidin
//Roll no : 22i-1102
//Section : K

#include <iostream>
#include "Cart.h"

using namespace std;

int cart::Total_items()
{
    return total_items;
}
bool cart::Discount()
{
    int count = 0;
    for (int i = 0; i < this->no_bread; ++i)
    {
        if(bread[i].getsale())
        {
            count += 1;
        }
    }
    for (int i = 0; i < this->no_pen; ++i)
    {
        if(pen[i].getsale())
        {
            count += 1;
        }
    }
    for (int i = 0; i < this->no_sock; ++i)
    {
        if(sock[i].getsale())
        {
            count += 1;
        }
    }
    for (int i = 0; i < this->no_egg; ++i)
    {
        if(egg[i].getsale())
        {
            count += 1;
        }
    }
    if(count >= 3)
        return true;
    else
        return false;
}
Breads *cart::getbread()
{
    return this->bread;
}
Eggs *cart::getegg()
{
    return this->egg;
}
Socks *cart::getsock()
{
    return this->sock;
}
Pens *cart::getpen()
{
    return this->pen;
}
int cart::getNobread()
{
    return this->no_bread;
}
int cart::getNoegg()
{
    return this->no_egg;
}
int cart::getNosock()
{
    return this->no_sock;
}
int cart::getNopen()
{
    return this->no_pen;
}

void cart::operator+=(Breads &b)
{
    total_items += 1;
    no_bread += 1;
    Breads *temp = bread;
    bread = new Breads[no_bread];
    for (int i = 0; i < no_bread - 1; ++i)
    {
        bread[i] = temp[i];
    }
    bread[no_bread - 1] = b;
}
void cart::operator+=(Eggs &e)
{
    total_items += 1;
    no_egg += 1;
    Eggs *temp = egg;
    egg = new Eggs[no_egg];
    for (int i = 0; i < no_egg - 1; ++i)
    {
        egg[i] = temp[i];
    }
    egg[no_egg - 1] = e;
}
void cart::operator+=(Socks &s)
{
    total_items += 1;
    no_sock += 1;
    Socks *temp = sock;
    sock = new Socks[no_sock];
    for (int i = 0; i < no_sock - 1; ++i)
    {
        sock[i] = temp[i];
    }
    sock[no_sock - 1] = s;
}
void cart::operator+=(Pens &p)
{
    total_items += 1;
    this->no_pen += 1;
    Pens *temp = this->pen;
    this->pen = new Pens[no_pen];
    for (int i = 0; i < no_pen - 1; ++i)
    {
        pen[i] = temp[i];
    }
    pen[no_pen - 1] = p;
}
cart& cart::operator+(Breads &b)
{
    total_items += 1;
    no_bread += 1;
    Breads *temp = bread;
    bread = new Breads[no_bread];
    for (int i = 0; i < no_bread - 1; ++i)
    {
        bread[i] = temp[i];
    }
    bread[no_bread - 1] = b;
    return *this;
}
cart& cart::operator+(Eggs &e)
{
    total_items += 1;
    no_egg += 1;
    Eggs *temp = egg;
    egg = new Eggs[no_egg];
    for (int i = 0; i < no_egg - 1; ++i)
    {
        egg[i] = temp[i];
    }
    egg[no_egg - 1] = e;
    return *this;
}
cart& cart::operator+(Socks &s)
{
    total_items += 1;
    no_sock += 1;
    Socks *temp = sock;
    sock = new Socks[no_sock];
    for (int i = 0; i < no_sock - 1; ++i)
    {
        sock[i] = temp[i];
    }
    sock[no_sock - 1] = s;
    return *this;
}
cart& cart::operator+(Pens &p)
{
    total_items += 1;
    this->no_pen += 1;
    Pens *temp = this->pen;
    this->pen = new Pens[no_pen];
    for (int i = 0; i < no_pen - 1; ++i)
    {
        pen[i] = temp[i];
    }
    pen[no_pen - 1] = p;
    return *this;
}

void cart::operator-=(Breads &b)
{
    if(no_bread != 0)
        delete[] this->bread;
    if(no_egg != 0)
        delete[] this->egg;

    total_items -= no_egg;
    total_items -= no_bread;
    this->no_bread = 0;
    this->no_egg = 0;
}
void cart::operator-=(Eggs &e)
{

    if(no_bread != 0)
        delete[] this->bread;
    if(no_egg != 0)
        delete[] this->egg;

    total_items -= no_egg;
    total_items -= no_bread;
    this->no_bread = 0;
    this->no_egg = 0;
    
}
void cart::operator-=(Socks &s)
{
    if(no_sock  != 0)
     delete[] this->sock;
    total_items -= no_sock;
    this->no_sock = 0;
    
}
void cart::operator-=(Pens &p)
{
    if(no_pen != 0)
        delete[] this->pen;
    total_items -= no_pen;
    this->no_pen = 0;
}


cart& cart::operator-(Breads &b)
{
    if(no_bread!= 0)
        delete[] this->bread;
    total_items -= no_bread;
    this->no_bread = 0;
    return *this;
}
cart& cart::operator-(Eggs &e)
{
    if(this->no_egg != 0)
        delete[] this->egg;
    total_items -= no_egg;
    this->no_egg = 0;
    return *this;
}
cart& cart::operator-(Socks &s)
{
    if(this->no_sock != 0)
        delete[] this->sock;
    total_items -= no_sock;
    this->no_sock = 0;
    return *this;
}
cart& cart::operator-(Pens &p)
{
    if(this->no_pen != 0)
        delete[] this->pen;
    total_items -= no_pen;
    this->no_pen = 0;
    return *this;
}

ostream &operator<<(ostream &out, cart &C)
{
    float price = 0;
    if (cart::total_items == 0)
    {
        cout << "Still no item in the Cary" << endl;
    }
    int no = 1;
    Eggs *temp_egg = C.getegg();
    for (int i = 0; i < C.getNoegg(); ++i)
    {
        price += temp_egg[i].price();
        cout << "Item<" << no << "> ";
        cout << temp_egg[i] << endl;
        no += 1;
    }
    Socks *temp_sock = C.getsock();
    for (int i = 0; i < C.getNosock(); ++i)
    {
        price += temp_sock[i].price();
        cout << "Item<" << no << "> ";
        cout << temp_sock[i] << endl;
        no += 1;
    }
    Pens *temp_pen = C.getpen();
    for (int i = 0; i < C.getNopen(); ++i)
    {
        price += temp_pen[i].price();
        cout << "Item<" << no << "> ";
        cout << temp_pen[i] << endl;
        no += 1;
    }
    Breads *temp_bread = C.getbread();
    for (int i = 0; i < C.getNobread(); ++i)
    {
        price += temp_bread[i].price();
        cout << "Item<" << no << "> ";
        cout << temp_bread[i] << endl;
        no += 1;
    }
    cout << "Cart is Discounted : ";
    if(C.Discount())
    {
        cout << "yes";
        price -= price * (12.5 / 100);
    }
    else
        cout << "No";
    cout << endl;
    cout << price << endl;
    cout << "Total Price = <" << price << ">Rs." << endl;
    return out;
}
