//Name : Hussnain Ul Abidin
//Roll no : 22i-1102
//Section : K

#include <iostream>

using namespace std;

class Item
{
private:
    string Name;
    string ItemType;
    float price_per_unit;
public:
    Item();

    void setName(string n);
    void setItemType(string i);
    void setPricePerUnit(float p);
    string getName();
    string getItemType();
    float getPricePerUnit();
};
