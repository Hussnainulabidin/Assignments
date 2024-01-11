//Name : Hussnain Ul Abidin
//Roll no : 22i-1102
//Section : K

#include <iostream>
#include "Item.h"

using namespace std;

Item::Item()
{
    this->Name = "";
    this->ItemType = "";
    this->price_per_unit = 0;
}
void Item::setName(string n)
{
    this->Name = n;
}
void Item::setItemType(string i)
{
    this->ItemType = i;
}
void Item::setPricePerUnit(float p)
{
    this->price_per_unit = p;
}

string Item::getName()
{
    return this->Name;
}
string Item::getItemType()
{
    return this->ItemType;
}
float Item::getPricePerUnit()
{
    return this->price_per_unit;
}
