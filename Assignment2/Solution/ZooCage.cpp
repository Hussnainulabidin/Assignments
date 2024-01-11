#include <iostream>
#include "ZooCage.h"

using namespace std;

ZooChain::ZooChain()
{
    start = NULL;
}

void ZooChain::add_Cage(char *name, int cageNumber)
{
    int ind = 0;
    int len = 0;
    int len1 = 0;
    for (int i = 0; name[i] != '\0'; ++i)
    {
        len1++;
    }
    char *Name = new char[len1 + 2];
    for (int i = 0; i < len1 + 2; ++i)
    {
        Name[i] = name[i];
    }
    if (start != NULL)
    {
        for (int i = 0;; ++i)
        {
            len++;
            if (start[i].link == NULL)
            {
                break;
            }
        }
        ind = len;
        ZooCage *temp = start;
        start = new ZooCage[len + 1];
        for (int i = 0; i < len; ++i)
        {
            start[i].name = temp[i].name;
            start[i].cageNumber = temp[i].cageNumber;
            start[i].link = start + (i + 1);
        }
    }
    if (start == NULL)
    {
        ind = 0;
        start = new ZooCage[1];
    }
    start[ind].name = Name;
    start[ind].cageNumber = cageNumber;
    start[ind].link = NULL;
}

void ZooChain::print_Chain()
{
    if (start == NULL)
        return;
    for (int i = 0;; ++i)
    {
        cout << "Chain Number " << i << endl;
        cout << "Animal Name = " << start[i].name << endl;
        cout << "Cage Number = " << start[i].cageNumber << endl;
        cout << endl;

        if (start[i].link == NULL)
        {
            break;
        }
    }
}

void ZooChain::delete_Chain(int cageNumber)
{
    int i = 0;
    bool check = false;
    for (;;)
    {
        if (start[i].cageNumber == cageNumber) // finding the index of Cage to be removed
        {
            check = true;
            break;
        }
        i++;
    }

    int cage = 0;
    for (int i = 0;; ++i) // finding the length of start array
    {
        cage++;
        if (start[i].link == NULL)
        {
            break;
        }
    }
    if (cage - 1 == 0 && check == true)
    {
        start = NULL;
        return;
    }
    else if (cage - 1 == 0 && check == false)
    {
        return;
    }

    ZooCage *temp = start;
    start = new ZooCage[cage - 1];
    int ind = 0;
    for (int j = 0; j < cage; ++j) // copying all the value to except the cage to be deleted
    {
        if (j == i)
        {
            continue;
        }
        else
        {
            int len1 = 0;
            for (int i = 0; temp[j].name[i] != '\0'; ++i)
            {

                len1++;
            }
            char *Name = new char[len1 + 2];
            for (int i = 0; i < len1 + 2; ++i)
            {
                Name[i] = temp[j].name[i];
            }

            start[ind].name = Name;
            start[ind].cageNumber = temp[j].cageNumber;
            ind++;
        }
    }
    if (start[0].name == "\0")
    {
        start = NULL;
        return;
    }
    i = 0;
    for (i = 0; i < cage - 2; ++i) // Making a link between all the cage
    {
        start[i].link = start + (i + 1);
    }
    start[i].link = NULL; // Making the last cage link pointer to Null
}

void ZooChain::Sort_Chain()
{
    int cage = 0;
    for (cage;; ++cage)
    {
        if (start[cage].link == NULL)
        {
            break;
        }
    }
    cage += 1;
    ZooCage *temp = new ZooCage[cage];
    int *ptr = new int[cage];
    int temp1;
    for (int i = 0; i < cage; ++i)
    {
        ptr[i] = start[i].cageNumber;
    }
    
    for (int i = 0; i < cage; ++i)
    {
        for (int j = i + 1; j < cage; ++j)
        {
            if (ptr[i] > ptr[j])
            {
                temp1 = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = temp1;
            }
        }
    }
    for (int i = 0; i < cage; ++i)
    {
        for (int j = 0; j < cage; ++j)
        {
            if (ptr[i] == start[j].cageNumber)
            {
                temp[i] = start[j];
            }
        }
    }
    start = temp;
    int i = 0;
    for (i = 0; i < cage-1; ++i) // Making a link between all the cage
    {
        start[i].link = start + (i + 1);
    }
    start[i].link = NULL; // Making the last cage link pointer to Null
    

}

void ZooChain::update_name_at_cageNumber(int cageNumber, char *name)
{
    int len = 0;
    for (int i = 0; name[i] != '\0'; ++i)
    {
        len++;
    }
    char *animal = new char[len];
    for (int i = 0; name[i] != '\0'; ++i)
    {
        animal[i] = name[i];
    }
    int cage = 0;
    for (int i = 0;; ++i) // finding the length of start array
    {
        cage++;
        if (start[i].link == NULL)
        {
            break;
        }
    }
    for (int i = 0; i < cage; ++i)
    {
        if (start[i].cageNumber == cageNumber)
        {
            start[i].name = animal;
        }
    }
}

void ZooChain::remove_Duplicate()
{
    ZooCage *temp;
    int cage = 0;
    for (int i = 0;; ++i) // finding the length of start array
    {
        cage++;
        if (start[i].link == NULL)
        {
            break;
        }
    }
    bool check = false;
    for (int i = 0; i < cage; ++i)
    {
        for (int j = i + 1; j < cage; ++j)
        {
            if (start[i].cageNumber == start[j].cageNumber)
            {
                check = true;
                for (int k = 0; start[i].name[k] != '\0' || start[j].name[k] != '\0'; ++k)
                {
                    if (start[i].name[k] != start[j].name[k])
                    {
                        check = false;
                        break;
                    }
                }
            }
            if (check == true)
            {
                temp = new ZooCage[cage - 1];
                int ind = 0;
                for (int k = 0; k < cage; ++k)
                {
                    if (k == j)
                    {
                        continue;
                    }
                    temp[ind] = start[k];
                    ind++;
                }
                start = temp;
                cage -= 1;
            }
            check = false;
        }
    }
    int i = 0;
    for (i = 0; i < cage - 1; ++i) // Making a link between all the cage
    {
        start[i].link = start + (i + 1);
    }
    start[i].link = NULL; // Making the last cage link pointer to Null
}

ZooChain::~ZooChain()
{
    delete[] start;
    start = NULL;
}
