#include <iostream>

using namespace std;

class BinaryStore
{
private:
    char **Address;
    char **Byte;
    int length;

public:
    BinaryStore();
    BinaryStore(int len);

    void showdata();
    char *Get(char *address);
    char *ToString();
    void add_Address(char *s);
    void set_Byte(char *address , char *value);
    char* Add(char *a , char *b);
    bool  comp_EQUAL(char *a , char *b);
    char* comp_AND(char *a , char *b);
    char* comp_OR(char *a , char *b);
    char* comp_NOT(char *a );
    ~BinaryStore();

};
