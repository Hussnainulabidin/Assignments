//Name : Hussnain Ul Abidin
//Roll no : 22i-1102
//Section : K

#include <iostream>
#include "Libraray.h"
#include <string>

using namespace std;

System::System()
{
    fac_amu = 0;
    std_amu =
        check_login = false;
}

void System::create_an_account(string id, string pass)
{
    ID = id;
    password = pass;
    cout << "\n--Account Created Sucessfully--" << endl;
}

void System::login()
{
    cout << "\n--Enter data to Login--" << endl;
    string id, pass;
    cout << "Enter ID  : ";
    getline(cin, id);
    cout << "Enter Password  : ";
    getline(cin, pass);
    if (ID == id && pass == password)
    {
        check_login = true;
        cout << "\n--Login Sucessfull--" << endl;
    }
    else
    {
        cout << "\n--Login Failed--" << endl;
    }
}

void System::add_books()
{
    if (check_login)
    {
        int num;
        cout << "Enter Number of Books to add : ";
        cin >> num;
        records.add_books(num);
    }
    else
        cout << "\n--You are not Login to Account--" << endl;
}

void System::show_books()
{
    if (check_login)
        records.show_books();
    else
        cout << "\n--You are not Login to Account--" << endl;
}

void System::register_student(Student &s)
{
    if (std_amu == 0)
    {
        std_amu = 1;
        student_reg = new Student[std_amu];
        student_reg[0] = s;
    }
    else
    {
        Student *temp = student_reg;
        std_amu += 1;
        student_reg = new Student[std_amu];
        for (int i = 0; i < std_amu - 1; ++i)
        {
            student_reg[i] = temp[i];
        }
        student_reg[std_amu - 1] = s;
    }
}

void System::register_faculty(Faculty &s)
{
    if (fac_amu == 0)
    {
        fac_amu = 1;
        faculty_reg = new Faculty[fac_amu];
        faculty_reg[0] = s;
    }
    else
    {
        Faculty *temp = faculty_reg;
        fac_amu += 1;
        faculty_reg = new Faculty[fac_amu];
        for (int i = 0; i < fac_amu - 1; ++i)
        {
            faculty_reg[i] = temp[i];
        }
        faculty_reg[fac_amu - 1] = s;
    }
}

void System::show_amount()
{
    cout << "std amu is " << std_amu << endl;
    cout << "fac amu is " << fac_amu << endl;
}

void System::issue_book(string type, int &book_issued, string name, string id)
{
    if (type == "student")
    {
        if (book_issued > 3)
        {
            cout << "\n--" << name << " has already issued 3 Books and reached max limit--" << endl;
        }
        bool check = false;
        for (int i = 0; i < std_amu; ++i)
        {
            if (student_reg[i].get_student_name() == name && student_reg[i].get_student_id() == id)
            {
                check = true;
                break;
            }
        }
        if (check)
        {
            records.issue_book(type, book_issued, name, id);
        }
        else
        {
            cout << "\n--Student is not Registerd in Libraray Data Base--" << endl;
        }
    }
    if (type == "faculty")
    {
        if (book_issued > 5)
        {
            cout << "\n--" << name << "has already issued 5 Books and reached MAX limit--" << endl;
        }
        bool check = false;
        for (int i = 0; i < fac_amu; ++i)
        {
            if (faculty_reg[i].get_faculty_name() == name && faculty_reg[i].get_faculty_id() == id)
            {
                check = true;
                break;
            }
        }
        if (check)
        {
            records.issue_book(type, book_issued, name, id);
        }
        else
        {
            cout << "\n--Faculty is not Registerd in Libraray Data Base--" << endl;
        }
    }
}

void System::display_return_dates_of_student(Student &std)
{
    if (check_login)
    {
        string name = std.get_student_name();
        string id = std.get_student_id();
        string type = "student";
        records.show_return_date(name, id, type);
    }
    else
    {
        cout << "\n--You are not logged in to your account" << endl;
    }
}

void System::Return_book(Student &std)
{
    if (check_login)
    {
        string name = std.get_student_name();
        string id = std.get_student_id();
        string type = "student";
        records.Return_A_Book(name, id, type);
    }
    else
    {
        cout << "\n--You are not logged in to your account" << endl;
    }
}

void System::Return_book(Faculty& fac)
{
    if (check_login)
    {
        string name = fac.get_faculty_name();
        string id = fac.get_faculty_id();
        string type = "faculty";
        records.Return_A_Book(name, id, type);
    }
    else
    {
        cout << "\n--You are not logged in to your account" << endl;
    }
}

Librarian::Librarian()
{
    char choice;
    cout << "Create an account (Y/N): ";
    cin >> choice;
    if (choice == 'Y' || choice == 'y')
    {
        string id, pass, name;
        cin.ignore();
        cout << "Enter yor Name : ";
        getline(cin, name);
        cout << "Enter ID : ";
        getline(cin, id);
        cout << "Enter Password : ";
        getline(cin, pass);
        this->name = name;
        this->create_an_account(id, pass);
    }
}

Records::Records()
{
    issue_count = 0;
}

void Records::add_books(int books_to_add)
{

    int num = books_to_add;

    string name;
    string id;
    string author;
    string genre;
    int edition;
    int choice;
    cout << "Num = " << num << endl;
    cout << "Enter the Following data for Each of the Book : " << endl;
    for (int i = 0; i < num; ++i)
    {

        cout << "\nSelect Book type : " << endl;
        cout << "1.Journel" << endl;
        cout << "2.Magazine" << endl;
        cout << "3.Study" << endl;
        cin >> choice;
        cin.ignore();
        cout << "Enter Name : ";
        getline(cin, name);
        cout << "Enter ID : ";
        getline(cin, id);
        cout << "Enter Author : ";
        getline(cin, author);
        cout << "Enter Edition : ";
        cin >> edition;
        if (choice == 1)
        {
            Journels jour;
            jour.set_author(author);
            jour.set_edition_number(edition);
            jour.set_ID(id);
            jour.set_name(name);
            this->add_jour(jour);
        }
        else if (choice == 2)
        {
            Magazine mag;
            mag.set_author(author);
            mag.set_edition_number(edition);
            mag.set_ID(id);
            mag.set_name(name);
            this->add_magazine(mag);
        }
        else if (choice == 3)
        {
            Study std;
            std.set_author(author);
            std.set_edition_number(edition);
            std.set_ID(id);
            std.set_name(name);
            this->add_std(std);
        }
        else
        {
            cout << "Invalid Choice -- Cannot Add" << endl;
            i -= 1;
        }
    }
}

void Records::show_books()
{
    cout << endl;
    if (get_mag_amu() != 0)
    {
        Magazine *mag = get_Magazines();
        cout << "Magazine in the libraray are : " << endl;
        for (int i = 0; i < get_mag_amu(); ++i)
        {
            cout << "---------" << i + 1 << "---------" << endl;
            cout << "Book Name   : " << mag[i].get_name() << endl;
            cout << "Author name : " << mag[i].get_author() << endl;
            cout << "Book ID     : " << mag[i].get_ID() << endl;
            cout << "Edition No. : " << mag[i].get_edition_number() << endl;
            cout << endl;
        }
    }
    if (get_jour_amu() != 0)
    {
        Journels *mag = get_Journels();
        cout << "Journals in the libraray are : " << endl;
        for (int i = 0; i < get_jour_amu(); ++i)
        {
            cout << "---------" << i + 1 << "---------" << endl;
            cout << "Book Name   : " << mag[i].get_name() << endl;
            cout << "Author name : " << mag[i].get_author() << endl;
            cout << "Book ID     : " << mag[i].get_ID() << endl;
            cout << "Edition No. : " << mag[i].get_edition_number() << endl;
            cout << endl;
        }
    }
    if (get_std_amu() != 0)
    {
        Study *mag = get_Study();
        cout << "Study Books in the libraray are : " << endl;
        for (int i = 0; i < get_std_amu(); ++i)
        {
            cout << "---------" << i + 1 << "---------" << endl;
            cout << "Book Name   : " << mag[i].get_name() << endl;
            cout << "Author name : " << mag[i].get_author() << endl;
            cout << "Book ID     : " << mag[i].get_ID() << endl;
            cout << "Edition No. : " << mag[i].get_edition_number() << endl;
            cout << endl;
        }
    }
}

int Records::issue_book(string type, int &bookissued, string name, string id)
{
    int choice;
    cout << "\n--Enter the Type of Book you want to Issue : " << endl;
    cout << "1.Magazine" << endl;
    cout << "2.Journel" << endl;
    cout << "3.Study" << endl;
    cout << "You choice : ";
    cin >> choice;
    if (choice == 1)
    {
        if (get_mag_amu() != 0)
        {
            Magazine *mag = get_Magazines();
            cout << "Magazine in the libraray are : " << endl;
            for (int i = 0; i < get_mag_amu(); ++i)
            {
                if (mag[i].get_availability() == false)
                    continue;
                cout << "---------" << i + 1 << "---------" << endl;
                cout << "Book Name   : " << mag[i].get_name() << endl;
                cout << "Author name : " << mag[i].get_author() << endl;
                cout << "Book ID     : " << mag[i].get_ID() << endl;
                cout << "Edition No. : " << mag[i].get_edition_number() << endl;
                cout << endl;
            }
            int choice;
            cout << "\n----------------------------------------------------" << endl;
            cout << "--Enter Book Number--" << endl;
            cin >> choice;
            if (choice > get_mag_amu())
            {
                cout << "\n--invalid choice--" << endl;
            }
            else
            {
                if (issue_count == 0)
                {
                    issuedbook = new IssueBook[1];
                }
                else
                {
                    IssueBook *temp = issuedbook;
                    issuedbook = new IssueBook[issue_count + 1];
                    for (int i = 0; i < issue_count; ++i)
                    {
                        issuedbook[i] = temp[i];
                    }
                }
                issuedbook[issue_count].set_book_editionnumber(mag[choice - 1].get_edition_number());
                issuedbook[issue_count].set_book_id(mag[choice - 1].get_ID());
                issuedbook[issue_count].set_book_type("magazine");
                issuedbook[issue_count].set_author(mag[choice - 1].get_author());
                issuedbook[issue_count].set_std_name(name);
                issuedbook[issue_count].set_std_id(id);
                issuedbook[issue_count].set_std_type(type);
                issuedbook[issue_count].set_issueReturn_date();
                issuedbook[issue_count].show_issueReturn_date();
                mag[choice - 1].set_availability(false);
                issue_count += 1;
                bookissued += 1;
                cout << "\n---You book have been sucessfully Issued---" << endl;
            }
        }
        else
        {
            cout << "\n--\"Sorry\"  No book of you choice are present in Libarary" << endl;
        }
    }
    else if (choice == 2)
    {
        cout << "Jour Amount " << get_jour_amu() << endl;
        if (get_jour_amu() != 0)
        {
            Journels *mag = get_Journels();
            cout << "Journals in the libraray are : " << endl;
            for (int i = 0; i < get_jour_amu(); ++i)
            {
                if (mag[i].get_availability() == false)
                    continue;
                cout << "---------" << i + 1 << "---------" << endl;
                cout << "Book Name   : " << mag[i].get_name() << endl;
                cout << "Author name : " << mag[i].get_author() << endl;
                cout << "Book ID     : " << mag[i].get_ID() << endl;
                cout << "Edition No. : " << mag[i].get_edition_number() << endl;
                cout << endl;
            }
            int choice;
            cout << "\n----------------------------------------------------" << endl;
            cout << "--Enter Book Number--" << endl;
            cin >> choice;
            if (choice > get_jour_amu())
            {
                cout << "\n--invalid choice--" << endl;
            }
            else
            {
                if (issue_count == 0)
                {
                    issuedbook = new IssueBook[1];
                }
                else
                {
                    IssueBook *temp = issuedbook;
                    issuedbook = new IssueBook[issue_count + 1];
                    for (int i = 0; i < issue_count; ++i)
                    {
                        issuedbook[i] = temp[i];
                    }
                }
                issuedbook[issue_count].set_book_editionnumber(mag[choice - 1].get_edition_number());
                issuedbook[issue_count].set_book_id(mag[choice - 1].get_ID());
                issuedbook[issue_count].set_book_type("journal");
                issuedbook[issue_count].set_author(mag[choice - 1].get_author());
                issuedbook[issue_count].set_std_name(name);
                issuedbook[issue_count].set_std_id(id);
                issuedbook[issue_count].set_std_type(type);
                issuedbook[issue_count].set_issueReturn_date();
                issuedbook[issue_count].show_issueReturn_date();
                mag[choice - 1].set_availability(false);
                issue_count += 1;
                bookissued += 1;
                cout << "\n---You book have been sucessfully Issued---" << endl;
            }
        }
        else
        {
            cout << "\n--\"Sorry\"  No book of you choice are present in Libarary" << endl;
        }
    }
    else if (choice == 3)
    {
        if (get_std_amu() != 0)
        {
            Study *mag = get_Study();
            cout << "Study Books in the libraray are : " << endl;
            for (int i = 0; i < get_std_amu(); ++i)
            {
                if (mag[i].get_availability() == false)
                    continue;
                cout << "---------" << i + 1 << "---------" << endl;
                cout << "Book Name   : " << mag[i].get_name() << endl;
                cout << "Author name : " << mag[i].get_author() << endl;
                cout << "Book ID     : " << mag[i].get_ID() << endl;
                cout << "Edition No. : " << mag[i].get_edition_number() << endl;
                cout << endl;
            }
            int choice;
            cout << "\n----------------------------------------------------" << endl;
            cout << "--Enter Book Number--" << endl;
            cin >> choice;
            if (choice > get_std_amu())
            {
                cout << "\n--invalid choice--" << endl;
            }
            else
            {
                if (issue_count == 0)
                {
                    issuedbook = new IssueBook[1];
                }
                else
                {
                    IssueBook *temp = issuedbook;
                    issuedbook = new IssueBook[issue_count + 1];
                    for (int i = 0; i < issue_count; ++i)
                    {
                        issuedbook[i] = temp[i];
                    }
                }
                issuedbook[issue_count].set_book_editionnumber(mag[choice - 1].get_edition_number());
                issuedbook[issue_count].set_book_id(mag[choice - 1].get_ID());
                issuedbook[issue_count].set_book_type("studybook");
                issuedbook[issue_count].set_author(mag[choice - 1].get_author());
                issuedbook[issue_count].set_std_name(name);
                issuedbook[issue_count].set_std_id(id);
                issuedbook[issue_count].set_std_type(type);
                issuedbook[issue_count].set_issueReturn_date();
                issuedbook[issue_count].show_issueReturn_date();
                mag[choice - 1].set_availability(false);
                issue_count += 1;
                bookissued += 1;
                cout << "\n---You book have been sucessfully Issued---" << endl;
            }
        }
        else
        {
            cout << "\n--\"Sorry\"  No book of you choice are present in Libarary" << endl;
        }
    }
    else
    {
        cout << "\n--Invalid Choice--" << endl;
    }
}

void Records::show_return_date(string name, string id, string type)
{
    int j = 1;
    for (int i = 0; i < issue_count; ++i)
    {
        string n = issuedbook[i].get_std_name();
        string I = issuedbook[i].get_std_id();
        string t = issuedbook[i].get_std_type();
        if (n == name && I == id && t == type)
        {
            cout << "Book" << j << endl;
            issuedbook[i].show_return_date();
            cout << endl;
            j += 1;
        }
    }
}

void Records::Return_A_Book(string name, string id, string type)
{
    string book_name;
    string book_type;
    int book_edition;
    string book_author;
    string book_id;
    int mm;
    int dd;
    cin.ignore();
    cout << "--Enter the Data of Book to be returned--" << endl;
    cout << "Enter Book Name :";
    getline(cin, book_name);
    cout << "Enter Book Type : ";
    getline(cin, book_type);
    cout << "Enter Edition : ";
    cin >> book_edition;
    cin.ignore();
    cout << "Enter Author Name : ";
    getline(cin, book_author);
    cout << "Enter book Id : ";
    getline(cin, book_id);
    cout << "Enter Date : ";
    cin >> dd;
    cout << "Enter Month : ";
    cin >> mm;
    int check_count = 0;
    int index = 0;
    for (int i = 0; i < this->issue_count; ++i)
    {
        check_count = 0;
        if (issuedbook[i].get_author() == book_author && issuedbook[i].get_book_editionnumber() == book_edition && issuedbook[i].get_book_type() == book_type && issuedbook[i].get_book_id() == book_id)
        {
            cout << "in" << endl;
            check_count += 1;
        }
        if (issuedbook[i].get_std_name() == name && issuedbook[i].get_std_id() == id && issuedbook[i].get_std_type() == type)
        {
            cout << "in" << endl;
            check_count += 1;
        }
        if (check_count == 2)
        {
            index = i;
            break;
        }
    }
    if (check_count == 2)
    {
        if (book_type == "magazine")
        {
            Magazine *jour = this->get_Magazines();
            for (int i = 0; i < this->get_mag_amu(); ++i)
            {
                if (jour[i].get_author() == book_author && jour[i].get_edition_number() == book_edition && jour[i].get_ID() == book_id)
                {
                    jour[i].set_availability(true);
                }
            }
        }
        else if (book_type == "studybook")
        {
            Study *jour = this->get_Study();
            for (int i = 0; i < this->get_std_amu(); ++i)
            {
                if (jour[i].get_author() == book_author && jour[i].get_edition_number() == book_edition && jour[i].get_ID() == book_id)
                {
                    jour[i].set_availability(true);
                }
            }
        }
        else if (book_type == "journal")
        {
            Journels *jour = this->get_Journels();
            for (int i = 0; i < this->get_jour_amu(); ++i)
            {
                if (jour[i].get_author() == book_author && jour[i].get_edition_number() == book_edition && jour[i].get_ID() == book_id)
                {
                    jour[i].set_availability(true);
                }
            }
        }
        ReturnDate R = issuedbook[index].get_return_date();
        if (R.get_month() > mm)
        {
            cout << "\n--Book returned Late--" << endl;
            cout << "Fine == 1000 RS" << endl;
        }
        else if (R.get_date() > dd && R.get_month() == mm)
        {
            cout << "\n--Book returned Late--" << endl;
            cout << "Fine == 1000 RS" << endl;
        }
        else
        {
            cout << "\n--Book Returned Successfully--" << endl;
        }
    }
    else
    {
        cout << "\n--No book of This Data has been found in records--" << endl;
    }
}

Book::Book()
{
    this->jour = nullptr;
    this->mag = nullptr;
    this->std = nullptr;
    this->jour_amu = 0;
    this->mag_amu = 0;
    this->std_amu = 0;
}

void Book::add_magazine(Magazine &m)
{
    if (mag_amu != 0)
    {
        mag_amu += 1;
        Magazine *mag_temp = mag;
        mag = new Magazine[mag_amu];
        for (int i = 0; i < mag_amu - 1; ++i)
        {
            mag[i] = mag_temp[i];
        }
    }
    else
    {
        mag_amu += 1;
        mag = new Magazine[mag_amu];
    }
    mag[mag_amu - 1] = m;
}

void Book::add_jour(Journels &j)
{
    if (jour_amu != 0)
    {
        jour_amu += 1;
        Journels *jour_temp = jour;
        jour = new Journels[jour_amu];
        for (int i = 0; i < jour_amu - 1; ++i)
        {
            jour[i] = jour_temp[i];
        }
    }
    else
    {
        jour_amu += 1;
        jour = new Journels[jour_amu];
    }
    jour[jour_amu - 1] = j;
}

void Book::add_std(Study &s)
{
    if (std_amu != 0)
    {
        std_amu += 1;
        Study *std_temp = std;
        std = new Study[std_amu];
        for (int i = 0; i < std_amu - 1; ++i)
        {
            std[i] = std_temp[i];
        }
    }
    else
    {
        std_amu += 1;
        std = new Study[std_amu];
    }
    std[std_amu - 1] = s;
}

int Book::get_mag_amu()
{
    return mag_amu;
}
int Book::get_jour_amu()
{
    return jour_amu;
}
int Book::get_std_amu()
{
    return std_amu;
}

Magazine *Book::get_Magazines()
{
    return this->mag;
}
Journels *Book::get_Journels()
{
    return jour;
}
Study *Book::get_Study()
{
    return this->std;
}

Magazine::Magazine()
{
    this->available = true;
}
void Magazine::set_ID(string id)
{
    this->ID = id;
}
void Magazine::set_name(string name)
{
    this->name = name;
}
void Magazine::set_author(string author)
{
    this->author = author;
}
void Magazine::set_edition_number(int edition)
{
    this->edition_number = edition;
}
void Magazine::set_availability(bool ava)
{
    this->available = ava;
}

string Magazine::get_ID()
{
    return this->ID;
}
string Magazine::get_name()
{
    return this->name;
}
string Magazine::get_author()
{
    return this->author;
}
int Magazine::get_edition_number()
{
    return this->edition_number;
}
bool Magazine::get_availability()
{
    return this->available;
}

Journels::Journels()
{
    this->available = true;
}
void Journels::set_ID(string id)
{
    this->ID = id;
}
void Journels::set_name(string name)
{
    this->name = name;
}
void Journels::set_author(string author)
{
    this->author = author;
}
void Journels::set_edition_number(int edition)
{
    this->edition_number = edition;
}
void Journels::set_availability(bool ava)
{
    this->available = ava;
}

string Journels::get_ID()
{
    return this->ID;
}
string Journels::get_name()
{
    return this->name;
}
string Journels::get_author()
{
    return this->author;
}
int Journels::get_edition_number()
{
    return this->edition_number;
}
bool Journels::get_availability()
{
    return this->available;
}

Study::Study()
{
    this->available = true;
}
void Study::set_ID(string id)
{
    this->ID = id;
}
void Study::set_name(string name)
{
    this->name = name;
}
void Study::set_author(string author)
{
    this->author = author;
}
void Study::set_edition_number(int edition)
{
    this->edition_number = edition;
}
void Study::set_availability(bool ava)
{
    this->available = ava;
}

string Study::get_ID()
{
    return this->ID;
}
string Study::get_name()
{
    return this->name;
}
string Study::get_author()
{
    return this->author;
}
int Study::get_edition_number()
{
    return this->edition_number;
}
bool Study::get_availability()
{
    return this->available;
}

Student::Student()
{
    name = "\0";
    ID = "\0";
    phone_no = -1;
    book_issued = 0;
    this->type = "student";
}

Student::Student(string n, string id, int no)
{
    this->name = n;
    this->ID = id;
    this->phone_no = no;
    this->member_ship = false;
    book_issued = 0;
    this->type = "student";
}

int Student::get_numberofBooks_issued()
{
    return book_issued;
}

void Student::issue_book_from(Librarian &lib)
{
    lib.issue_book(this->type, this->book_issued, this->name, this->ID);
}

void Student::return_book_to(Librarian &lib)
{
    lib.Return_book(*this);
}

string Student::get_student_id()
{
    return this->ID;
}
string Student::get_student_name()
{
    return this->name;
}

//----------------------------------------------
Faculty::Faculty()
{
    name = "\0";
    ID = "\0";
    phone_no = -1;
    member_ship = false;
    type = "faculty";
    book_issued = 0;
}
Faculty::Faculty(string n, string id, int no)
{
    this->name = n;
    this->ID = id;
    this->phone_no = no;
    this->member_ship = false;
    this->type = "faculty";
    book_issued = 0;
}

int Faculty::get_numberofBooks_issued()
{
    return book_issued;
}


void Faculty::return_book_to(Librarian &Lib)
{
    Lib.Return_book(*this);
}

void Faculty::issue_book_from(Librarian &lib)
{
    lib.issue_book(this->type, this->book_issued, this->name, this->ID);
}
string Faculty::get_faculty_id()
{
    return this->ID;
}
string Faculty::get_faculty_name()
{
    return this->name;
}

void IssueBook::set_std_name(string name)
{
    this->std_name = name;
}
void IssueBook::set_std_id(string id)
{
    this->std_id = id;
}
void IssueBook::set_book_id(string id)
{
    this->book_id = id;
}
void IssueBook::set_book_type(string type)
{
    this->book_type = type;
}
void IssueBook::set_book_editionnumber(int ed)
{
    this->book_editionnumber = ed;
}
void IssueBook::set_std_type(string t)
{
    this->std_type = t;
}
void IssueBook::set_issueReturn_date()
{
    int dd, mm;
    cout << "Enter Todays Date : ";
    cin >> dd;
    cout << "Enter Month : ";
    cin >> mm;
    this->Idate.set_Issue_date(dd, mm);
    if (std_type == "student")
    {
        if (dd + 14 > 30)
        {
            dd += 14;
            dd -= 30;
            mm += 1;
        }
        else
        {
            dd += 14;
        }
    }
    else
    {
        mm += 2;
    }
    Rdate.set_Return_date(dd, mm);
}
void IssueBook::set_author(string a)
{
    this->author = a;
}

string IssueBook::get_std_name()
{
    return this->std_name;
}
string IssueBook::get_std_id()
{
    return this->std_id;
}
string IssueBook::get_book_id()
{
    return this->book_id;
}
string IssueBook::get_book_type()
{
    return this->book_type;
}
int IssueBook::get_book_editionnumber()
{
    return this->book_editionnumber;
}
void IssueBook::show_issueReturn_date()
{
    cout << "\n--Issue Date--" << endl;
    cout << "Date  : " << Idate.get_date() << endl;
    cout << "Month : " << Idate.get_month() << endl;

    cout << "--Return Date--" << endl;
    cout << "Date  : " << Rdate.get_date() << endl;
    cout << "Month : " << Rdate.get_month() << endl;
}
string IssueBook::get_std_type()
{
    return std_type;
}
void IssueBook::show_return_date()
{
    cout << "--Return Date" << endl;
    cout << "Date  : " << Rdate.get_date() << endl;
    cout << "Month : " << Rdate.get_month() << endl;
}
string IssueBook::get_author()
{
    return this->author;
}
ReturnDate &IssueBook::get_return_date()
{
    return this->Rdate;
}

void ReturnDate::set_Return_date(int dd, int mm)
{
    this->date = dd;
    this->month = mm;
}
int ReturnDate::get_date()
{
    return this->date;
}
int ReturnDate::get_month()
{
    return this->month;
}

void IssueDate::set_Issue_date(int dd, int mm)
{
    this->date = dd;
    this->month = mm;
}
int IssueDate::get_date()
{
    return this->date;
}
int IssueDate::get_month()
{
    return this->month;
}