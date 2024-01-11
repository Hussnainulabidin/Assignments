//Name : Hussnain Ul Abidin
//Roll no : 22i-1102
//Section : K

#include <iostream>
#include "Cart.cpp"

using namespace std;

int main()
{
    Breads p1(12, 3);
    cout << p1 << endl;
    // example of sale item
    Eggs p2(15, 1, true);
    // example of sale item with gift card
    Socks p3(20, 2.0, true, true);
    cart c1;
    c1 += p1; // add bread to cart
    c1 += p1;
    c1 += p2; // add eggs to cart
    c1 += p3; // add socks to cart
    // cout << c1 << endl;

    c1 = c1 - p1;
    // cout << c1 << endl;

    cart c2;
    c2 = c1 + p2;
    cout << c2 << endl;

    c2 -= p2;
    cout << c2 << endl;
    cout << cart::Total_items() << endl;

    return 0;
}