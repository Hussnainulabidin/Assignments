#include <iostream>

using namespace std;

class String
{
    char *data;

public:
    // Constructors

    String();
    String(char *str);
    String(int x);
    String(const String &str);


    // Member Functions

    char *getdata();


    char getChar(int i);


    bool isEmpty();
   

    int length();

    String append_string(const String &str);
    String append_string(const char &str);
    String append_string(char *&str);
    String append_string(string &str);
    

    String remove_string(const String &substr);
    String remove_string(string &substr);
    String remove_string(char *&substr);
    String remove_string(const char &a);


    String &assign_string(const String &str);
    String &assign_string(char *str);
    String &assign_string(const string &str);
    

    bool isEqual(const String &str) const;
    bool isEqual(const string& str) const ;
    bool isEqual(char *str) const;
    

    int index_at(char A) const;
    int index_at(const String& str) const;
    int index_at(const string& str) const;
    int index_at(char* str) const;
   

};