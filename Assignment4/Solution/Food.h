//Name : Hussnain Ul Abidin
//Roll no : 22i-1102
//Section : K

#include <iostream>
#include "Item.cpp"

using namespace std;

class Socks : public Item
{
private:
    int no_of_unit_purchased;
    bool for_sale;
    bool gift_card;
public:
    Socks();
    Socks(int,int);
    Socks(int,int,bool);
    Socks(int,int,bool,bool);
    bool getsale();

    float price();
    bool gift();
    bool operator==(Socks &);

    friend ostream &operator<<(ostream & , Socks& );
};

class Pens : public Item
{
private:
    int no_of_unit_purchased;
    bool for_sale;
    bool gift_card;
public:
    Pens();
    Pens(int,int);
    Pens(int,int,bool);
    Pens(int,int,bool,bool);
    bool getsale();

    float price();
    bool gift();
    bool operator==(Pens &);

    friend ostream &operator<<(ostream & , Pens& );
};

class Breads : public Item
{
private:
    int no_of_unit_purchased;
    bool for_sale;
    bool gift_card;
public:
    Breads();
    Breads(int,int);
    Breads(int,int,bool);
    Breads(int,int,bool,bool);
    bool getsale();

    float price();
    bool gift();
    bool operator==(Breads &);

    friend ostream &operator<<(ostream & , Breads& );
};


class Eggs : public Item
{
private:
    int no_of_unit_purchased;
    bool for_sale;
    bool gift_card;
public:
    Eggs();
    Eggs(int,int);
    Eggs(int,int,bool);
    Eggs(int,int,bool,bool);
    bool getsale();

    float price();
    bool gift();
    bool operator==(Eggs &);

    friend ostream &operator<<(ostream & , Eggs& );
};
