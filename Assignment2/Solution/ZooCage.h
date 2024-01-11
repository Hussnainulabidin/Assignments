#include <iostream>

using namespace std;

struct ZooCage
{
    char *name;
    int cageNumber;
    ZooCage *link;
};

class ZooChain
{

public:
    ZooCage *start;

    ZooChain();

    void add_Cage(char *name, int cageNumber);

    void print_Chain();

    void delete_Chain(int cageNumber);

    void Sort_Chain();

    void update_name_at_cageNumber(int cageNumber, char *name);

    void remove_Duplicate();

    ~ZooChain();

};
