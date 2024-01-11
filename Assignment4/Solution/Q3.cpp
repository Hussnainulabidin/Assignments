//Name : Hussnain Ul Abidin
//Roll no : 22i-1102
//Section : K

#include <iostream>
#include "Libraray.cpp"
#include <string>

using namespace std;

int main()
{
    Librarian lib;
    lib.login();
    lib.add_books();
    

    Student s1("Hussnain", "hu", 90);
    Student s2("Hamza", "ha", 91);
    Student s3("Zain", "za", 92);
    Student s4("Hamdan", "ha", 93);

    Faculty f1("Asif", "as", 01);
    Faculty f2("Naheeda", "na", 02);

    lib.register_student(s1);
    lib.register_student(s2);
    lib.register_student(s3);

    lib.register_faculty(f1);
    lib.register_faculty(f2);


    // lib.

    lib.show_books();
    s2.issue_book_from(lib);

    lib.display_return_dates_of_student(s2);

    s2.return_book_to(lib);
    s2.issue_book_from(lib);

    // lib.show_amount();
}