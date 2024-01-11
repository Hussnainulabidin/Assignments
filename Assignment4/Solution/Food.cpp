//Name : Hussnain Ul Abidin
//Roll no : 22i-1102
//Section : K
#include <iostream>
#include "Food.h"

using namespace std;

Socks::Socks()
{
}
Socks::Socks(int price, int no)
{
    this->for_sale = false;
    this->gift_card = false;
    this->no_of_unit_purchased = no;
    this->setItemType("clothes");
    this->setName("Sock");
    this->setPricePerUnit(price);
}
Socks::Socks(int price, int no, bool sale)
{
    this->for_sale = sale;
    this->gift_card = false;
    this->no_of_unit_purchased = no;
    this->setItemType("clothes");
    this->setName("Sock");
    this->setPricePerUnit(price);
}
Socks::Socks(int price, int no, bool sale, bool gift)
{
    this->for_sale = sale;
    this->gift_card = gift;
    this->no_of_unit_purchased = no;
    this->setItemType("clothes");
    this->setName("Sock");
    this->setPricePerUnit(price);
}
float Socks::price()
{
    float price = this->getPricePerUnit();
    if (this->for_sale)
    {
        return price * 0.75;
    }
    else
    {
        return price;
    }
}
bool Socks::gift()
{
    return this->for_sale;
}
bool Socks::operator==(Socks &item)
{
    if (this->getName() == item.getName() && this->getPricePerUnit() == item.getPricePerUnit() && this->getItemType() == item.getItemType())
        return true;
    else
        return false;
}
ostream &operator<<(ostream &out, Socks &item)
{
    cout << "<" << item.getName() << "> ";
    cout << "<" << item.getPricePerUnit() << "> ";
    cout << "<" << item.no_of_unit_purchased << "> ";
    if (item.for_sale)
    {
        cout << "<For Sale> ";
    }
    else
    {
        cout << "<Not For Sale> ";
    }
    if (item.gift_card)
    {
        cout << "<Complementary Gift Card>";
    }
    else
    {
        cout << "<No Complementary Gift Card>";
    }
    cout << "Price: <" << item.price() << ">Rs." << endl;
}
bool Socks::getsale()
{
    return this->for_sale;
}


Pens::Pens()
{
}
Pens::Pens(int price, int no)
{
    this->for_sale = false;
    this->gift_card = false;
    this->no_of_unit_purchased = no;
    this->setItemType("supplies");
    this->setName("Pen");
    this->setPricePerUnit(price);
}
Pens::Pens(int price, int no, bool sale)
{
    this->for_sale = sale;
    this->gift_card = false;
    this->no_of_unit_purchased = no;
    this->setItemType("supplies");
    this->setName("Pen");
    this->setPricePerUnit(price);
}
Pens::Pens(int price, int no, bool sale, bool gift)
{
    this->for_sale = sale;
    this->gift_card = gift;
    this->no_of_unit_purchased = no;
    this->setItemType("supplies");
    this->setName("Pen");
    this->setPricePerUnit(price);
}
float Pens::price()
{
    float price = this->getPricePerUnit();
    if (this->for_sale)
    {
        return price * 0.75;
    }
    else
    {
        return price;
    }
}
bool Pens::gift()
{
    return this->for_sale;
}
bool Pens::operator==(Pens &item)
{
    if (this->getName() == item.getName() && this->getPricePerUnit() == item.getPricePerUnit() && this->getItemType() == item.getItemType())
        return true;
    else
        return false;
}
ostream &operator<<(ostream &out, Pens &item)
{
    cout << "<" << item.getName() << "> ";
    cout << "<" << item.getPricePerUnit() << "> ";
    cout << "<" << item.no_of_unit_purchased << "> ";
    if (item.for_sale)
    {
        cout << "<For Sale> ";
    }
    else
    {
        cout << "<Not For Sale> ";
    }
    if (item.gift_card)
    {
        cout << "<Complementary Gift Card>";
    }
    else
    {
        cout << "<No Complementary Gift Card>";
    }
    cout << "Price: <" << item.price() << ">Rs." << endl;
}
bool Pens::getsale()
{
    return this->for_sale;
}

Breads::Breads()
{
}
Breads::Breads(int price, int no)
{
    this->for_sale = false;
    this->gift_card = false;
    this->no_of_unit_purchased = no;
    this->setItemType("Food");
    this->setName("Bread");
    this->setPricePerUnit(price);
}
Breads::Breads(int price, int no, bool sale)
{
    this->for_sale = sale;
    this->gift_card = false;
    this->no_of_unit_purchased = no;
    this->setItemType("Food");
    this->setName("Bread");
    this->setPricePerUnit(price);
}
Breads::Breads(int price, int no, bool sale, bool gift)
{
    this->for_sale = sale;
    this->gift_card = gift;
    this->no_of_unit_purchased = no;
    this->setItemType("Food");
    this->setName("Bread");
    this->setPricePerUnit(price);
}
float Breads::price()
{
    float price = this->getPricePerUnit();
    if (this->for_sale)
    {
        return price * 0.75;
    }
    else
    {
        return price;
    }
}
bool Breads::gift()
{
    return this->for_sale;
}
bool Breads::operator==(Breads &item)
{
    if (this->getName() == item.getName() && this->getPricePerUnit() == item.getPricePerUnit() && this->getItemType() == item.getItemType())
        return true;
    else
        return false;
}
ostream &operator<<(ostream &out, Breads &item)
{
    cout << "<" << item.getName() << "> ";
    cout << "<" << item.getPricePerUnit() << "> ";
    cout << "<" << item.no_of_unit_purchased << "> ";
    if (item.for_sale)
    {
        cout << "<For Sale> ";
    }
    else
    {
        cout << "<Not For Sale> ";
    }
    if (item.gift_card)
    {
        cout << "<Complementary Gift Card>";
    }
    else
    {
        cout << "<No Complementary Gift Card>";
    }
    cout << "Price: <" << item.price() << ">Rs." << endl;
}
bool Breads::getsale()
{
    return this->for_sale;
}

Eggs::Eggs()
{
}
Eggs::Eggs(int price, int no)
{
    this->for_sale = false;
    this->gift_card = false;
    this->no_of_unit_purchased = no;
    this->setItemType("Food");
    this->setName("Egg");
    this->setPricePerUnit(price);
}
Eggs::Eggs(int price, int no, bool sale)
{
    this->for_sale = sale;
    this->gift_card = false;
    this->no_of_unit_purchased = no;
    this->setItemType("Food");
    this->setName("Egg");
    this->setPricePerUnit(price);
}
Eggs::Eggs(int price, int no, bool sale, bool gift)
{
    this->for_sale = sale;
    this->gift_card = gift;
    this->no_of_unit_purchased = no;
    this->setItemType("Food");
    this->setName("Egg");
    this->setPricePerUnit(price);
}
float Eggs::price()
{
    float price = this->getPricePerUnit();
    if (this->for_sale)
    {
        return price * 0.75;
    }
    else
    {
        return price;
    }
}
bool Eggs::gift()
{
    return this->for_sale;
}
bool Eggs::operator==(Eggs &item)
{
    if (this->getName() == item.getName() && this->getPricePerUnit() == item.getPricePerUnit() && this->getItemType() == item.getItemType())
        return true;
    else
        return false;
}
ostream &operator<<(ostream &out, Eggs &item)
{
    cout << "<" << item.getName() << "> ";
    cout << "<" << item.getPricePerUnit() << "> ";
    cout << "<" << item.no_of_unit_purchased << "> ";
    if (item.for_sale)
    {
        cout << "<For Sale> ";
    }
    else
    {
        cout << "<Not For Sale> ";
    }
    if (item.gift_card)
    {
        cout << "<Complementary Gift Card>";
    }
    else
    {
        cout << "<No Complementary Gift Card>";
    }
    cout << "Price: <" << item.price() << ">Rs." << endl;
}
bool Eggs::getsale()
{
    return this->for_sale;
}
