#include <iostream>
#include "Record.h"
#include <string>

using namespace std;

Record::Record()
{
    name[0] = '\0';
    address[0] = '\0';
    GPA = 0;
    age = 0;
}

Record::Record(char *str)
{
    ofstream file_write;

    file_write.open(str , ios::app);

    if (!file_write)
    {
        cout << "Cannot Make file : " << str << endl;
    }
    else
    {
        int len = 0;
        for (int i = 0; str[i] != '\0'; ++i)
        {
            len++;
        }
        filename = new char[len + 1];
        for (int i = 0; str[i] != '\0'; ++i)
        {
            filename[i] = str[i];
        }
        filename[len] = '\0';
    }
}

void Record::record_Input()
{
    int num;
    cout << "Enter the Number of students : ";
    cin >> num;

    cout << filename << endl;

    Record *data = new Record[num];
    for (int i = 0; i < num; ++i)
    {
        cin.ignore();
        cout << "Enter Record of Student " << i << endl;
        cout << "Enter Name : ";
        cin.get(data[i].name, 100);
        cin.ignore();
        cout << "Enter Address : ";
        cin.get(data[i].address, 100);
        cin.ignore();
        cout << "Enter Age : ";
        cin >> data[i].age;
        cout << "Enter CGPA : ";
        cin >> data[i].GPA;
        cout << endl;
    }
    ofstream file_write;

    file_write.open(filename);

    for (int i = 0; i < num; ++i)
    {
        file_write << data[i].name << "," << data[i].address << "," << data[i].age << "," << data[i].GPA << endl;
    }

    file_write.close();
}

void Record::record_Dislay()
{
    ifstream file_read;

    file_read.open(filename);
    char data[200];

    int line = 0;

    string str;

    int comma = 0;
    char name[100] = "\0";
    char address[100] = "\0";
    char GPA[10] = "\0";
    char age[10] = "\0";
    int ind = 0;

    while (getline(file_read, str))
    {
        ind = 0;
        name[0] = '\0';
        address[0] = '\0';
        age[0] = '\0';
        GPA[0] = '\0';
        comma = 0;
        for (int i = 0; str[i] != '\0'; ++i)
        {

            if (str[i] == ',')
            {
                comma += 1;
                ind = 0;
                continue;
            }
            if (comma == 0)
            {
                name[ind + 1] = name[ind];
                name[ind] = str[i];
                ind++;
            }
            else if (comma == 1)
            {
                address[ind + 1] = address[ind];
                address[ind] = str[i];
                ind++;
            }
            else if (comma == 2)
            {
                age[ind + 1] = age[ind];
                age[ind] = str[i];
                ind++;
            }
            else if (comma == 3)
            {
                GPA[ind + 1] = GPA[ind];
                GPA[ind] = str[i];
                ind++;
            }
        }
        cout << "Data of Student " << line + 1 << endl;
        cout << "Name    : " << name << endl;
        cout << "Address : " << address << endl;
        cout << "Age     : " << age << endl;
        cout << "CGPA    : " << GPA << endl;
        line += 1;
        cout << endl;
    }

    file_read.close();
}

void Record::delete_Record()
{
    char name[100];
    char name1[100] = "\0";
    int comma = 0;
    bool check = false;

    cout << "Enter the Name of the Student you want to Remove : ";
    cin.get(name, 100);

    ifstream read_file;
    read_file.open(filename);

    string *str;
    int line = 0;
    string data;

    while (getline(read_file, data))
    {
        string *temp = str;
        str = new string[line + 1];

        for (int i = 0; i < line; ++i)
        {
            str[i] = temp[i];
        }
        str[line] = data;
        line++;
    }

    int ind = 0;

    for (int i = 0; i < line; ++i)
    {
        check = false;
        name1[0] = '\0';
        ind = 0;
        for (int j = 0; str[i][j] != ','; ++j)
        {
            name1[ind + 1] = name1[ind];
            name1[ind] = str[i][j];
            ind++;
        }
        check = true;
        for (int i = 0; name[i] != '\0'; ++i)
        {
            if (name[i] != name1[i])
            {
                check = false;
                break;
            }
        }
        if (check)
        {
            ind = i;
            break;
        }
    }

    read_file.close();

    if (check)
    {
        ofstream file_write;
        file_write.open(filename);

        for (int i = 0; i < line; ++i)
        {
            if (i == ind)
            {
                continue;
            }
            file_write << str[i] << endl;
        }

        file_write.close();
    }
}

int Record::record_Count()
{
    ifstream file_read;
    file_read.open(filename);

    int line = 0;
    string data;

    while (getline(file_read, data))
    {
        line++;
    }
    return line;
}

void Record::record_Search()
{
    char name[100];
    char name1[100] = "\0";
    int comma = 0;
    bool check = false;

    cout << "Enter the Name of the Student you want to find : ";
    cin.get(name, 100);

    ifstream read_file;
    read_file.open(filename);

    string *str;
    int line = 0;
    string data;

    while (getline(read_file, data))
    {
        string *temp = str;
        str = new string[line + 1];

        for (int i = 0; i < line; ++i)
        {
            str[i] = temp[i];
        }
        str[line] = data;
        line++;
    }

    int ind = 0;

    for (int i = 0; i < line; ++i)
    {
        check = false;
        name1[0] = '\0';
        ind = 0;
        for (int j = 0; str[i][j] != ','; ++j)
        {
            name1[ind + 1] = name1[ind];
            name1[ind] = str[i][j];
            ind++;
        }
        check = true;
        for (int i = 0; name[i] != '\0'; ++i)
        {
            if (name[i] != name1[i])
            {
                check = false;
                break;
            }
        }
        if (check)
        {
            ind = i;
            break;
        }
    }

    read_file.close();
    cout << "\n"
         << endl;
    if (check)
    {
        cout << "--------------Student Found--------------" << endl;
    }
    else
    {
        cout << "--------------Student Not Found--------------" << endl;
    }
}

void Record::record_Insert()
{
    char name[100];
    char address[100];
    int age;
    float gpa;

    cout << "Enter the Data of Student you want to add" << endl;
    cout << "Enter Name : ";
    cin.get(name, 100);
    cin.ignore();
    cout << "Enter Address : ";
    cin.get(address, 100);
    cin.ignore();
    cout << "Enter Age : ";
    cin >> age;
    cin.ignore();
    cout << "Enter CGPA : ";
    cin >> gpa;
    cin.ignore();
    cout << "\n"
         << endl;
    

    ofstream file_write;
    file_write.open(filename, ios::app);
    file_write << endl;
    file_write << name << "," << address << "," << age << "," << gpa << endl;
}

void Record::record_Replace()
{
    char name[100];
    char name1[100] = "\0";
    int comma = 0;
    bool check = false;

    cout << "Enter the Name of the Student to be replaced : ";
    cin.get(name, 100);

    ifstream read_file;
    read_file.open(filename);

    string *str;
    int line = 0;
    string data;

    while (getline(read_file, data))
    {
        string *temp = str;
        str = new string[line + 1];

        for (int i = 0; i < line; ++i)
        {
            str[i] = temp[i];
        }
        str[line] = data;
        line++;
    }

    int ind = 0;

    for (int i = 0; i < line; ++i)
    {
        check = false;
        name1[0] = '\0';
        ind = 0;
        for (int j = 0; str[i][j] != ','; ++j)
        {
            name1[ind + 1] = name1[ind];
            name1[ind] = str[i][j];
            ind++;
        }
        check = true;
        for (int i = 0; name[i] != '\0'; ++i)
        {
            if (name[i] != name1[i])
            {
                check = false;
                break;
            }
        }
        if (check)
        {
            ind = i;
            break;
        }
    }

    if (check == false)
    {
        cout << "No such Student found" << endl;
    }
    else
    {
        char new_name[100];
        char address[100];
        int age;
        float gpa;

        cin.ignore();
        cout << "\n\nEnter new Student data" << endl;
        cout << "Enter Name : ";
        cin.get(new_name ,100);
        cin.ignore();
        cout << "Enter Address : ";
        cin.get(address ,100);
        cin.ignore();
        cout << "Enter Age : ";
        cin >> age;
        cin.ignore();
        cout << "Enter CGPA : " ;
        cin >> gpa;
        cin.ignore();
        ofstream file_write;

        file_write.open(filename);
        for(int i = 0 ; i < line  ; ++i)
        {   
            if(i == ind)
            {
                file_write << new_name << "," << address  << "," << age << "," << gpa  << endl;
                continue;
            }
            file_write << str[i] << endl;
        }
        file_write.close();
        
    }
}