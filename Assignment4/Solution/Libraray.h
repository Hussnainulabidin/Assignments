//Name : Hussnain Ul Abidin
//Roll no : 22i-1102
//Section : K

#include <iostream>

using namespace std;

class Librarian;

class ReturnDate
{
private:
    int date;
    int month;

public:
    void set_Return_date(int dd , int mm);
    int get_date();
    int get_month();
};

class IssueDate
{
private:
    int date;
    int month;

public:
    
    void set_Issue_date(int dd , int mm);
    int get_date();
    int get_month();
};

class IssueBook
{
private:
    string std_name;
    string std_id;
    string book_id;
    string book_type;
    string std_type;
    string author;
    int book_editionnumber;
    IssueDate Idate;
    ReturnDate Rdate;

public:
    void set_std_name(string);
    void set_std_id(string);
    void set_book_id(string);
    void set_book_type(string);
    void set_book_editionnumber(int);
    void set_std_type(string);
    void set_issueReturn_date();
    void set_author(string);

    string get_std_name();
    string get_std_id();
    string get_book_id();
    string get_book_type();
    string get_std_type();
    int get_book_editionnumber();
    void show_issueReturn_date();
    void show_return_date();
    ReturnDate& get_return_date();
    string get_author();
};

class Student 
{
private:
    bool member_ship;
    string type;
    string ID;
    string name;
    int phone_no;
    int book_issued;

public:
    Student();
    Student(string n, string id, int no);


    string get_student_id();
    string get_student_name();
    int get_numberofBooks_issued();

    void add_data(string n, string id, int no);
    void issue_book_from(Librarian&);
    void display_return_date(Librarian &);
    void return_book_to(Librarian &);
};

class Faculty
{
private:
    bool member_ship;
    string type;
    string ID;
    string name;
    int phone_no;
    int book_issued;

public:
    Faculty();
    Faculty(string n, string id, int no);

    void get_name();
    void get_id();
    int get_numberofBooks_issued();

    string get_faculty_id();
    string get_faculty_name();

    void add_data(string n, string id, int no);
    void issue_book_from(Librarian&);
    void display_return_date(Librarian &);
    void return_book_to(Librarian &);
};

class Magazine
{
private:
    string ID;
    string name;
    string author;
    int edition_number;
    bool available;

public:
    Magazine();

    void set_ID(string);
    void set_name(string);
    void set_author(string);
    void set_edition_number(int);
    void set_availability(bool);

    string get_ID();
    string get_name();
    string get_author();
    int get_edition_number();
    bool get_availability();
};
class Journels
{
private:
    string ID;
    string name;
    string author;
    int edition_number;
    bool available;

public:
    Journels();

    void set_ID(string);
    void set_name(string);
    void set_author(string);
    void set_edition_number(int);
    void set_availability(bool);

    string get_ID();
    string get_name();
    string get_author();
    int get_edition_number();
    bool get_availability();
};
class Study
{
private:
    string ID;
    string name;
    string author;
    int edition_number;
    bool available;

public:
    Study();

    void set_ID(string);
    void set_name(string);
    void set_author(string);
    void set_edition_number(int);
    void set_availability(bool);

    string get_ID();
    string get_name();
    string get_author();
    int get_edition_number();
    bool get_availability();
};

class Book
{
private:
    Magazine *mag;
    Journels *jour;
    Study *std;
    int mag_amu, jour_amu, std_amu;

public:
    Book();

    Magazine *get_Magazines();
    Journels *get_Journels();
    Study *get_Study();

    int get_mag_amu();
    int get_jour_amu();
    int get_std_amu();

    void add_magazine(Magazine &);
    void add_jour(Journels &);
    void add_std(Study &);
};

class Records : private Book
{
private:
    IssueBook *issuedbook;
    int issue_count;

public:
    Records();
    void add_books(int);
    void show_books();

    int issue_book(string, int& ,string , string);
    void show_return_date(string, string, string);

    void Return_A_Book(string, string, string);
};

class System 
{
private:
    bool check_login;
    Records records;
    string ID;
    string password;

    Student *student_reg;
    Faculty *faculty_reg;

    int fac_amu, std_amu;

public:
    System();
    void create_an_account(string id, string pass);
    void login();
    void add_books();
    void show_books();

    void get_number_of_student_registered();
    void get_number_of_faculty_registered();

    void register_student(Student &);
    void register_faculty(Faculty &);

    void show_amount();
    void issue_book(string , int& , string , string);
    void display_return_dates_of_student(Student&);
    void display_return_dates_of_faculty(Faculty&);

    void Return_book(Student&);
    void Return_book(Faculty&);
};

class Librarian : public System
{
private:
    string name;

public:
    Librarian();
};