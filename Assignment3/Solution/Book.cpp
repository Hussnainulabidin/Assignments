//Name : Hussnain Ul Abidin
//Roll No : 22i-1102_K
#include <iostream>
#include "Book.h"
using namespace std;

Book::Book()
{
    pages = nullptr;
    this->lenpages = 0;
}

Book::Book(int x)
{
    this->pages = new Page[x];
    this->lenpages = x;
}

Book::Book(Book &copy)
{
    copy.lenpages = this->lenpages;
    copy.pages = new Page[copy.lenpages];
    for (int i = 0; i < this->lenpages; ++i)
    {
        copy.pages[i] = this->pages[i];
    }
}

void Book::showData()
{
    bool check = true;
    for (int i = 0; i < lenpages; ++i)
    {
        cout << "Book Page --" << i + 1 << "--" << endl;
        for (int j = 0; j < pages[i].lenlines; ++j)
        {
            if (pages[i].lines[j].data == NULL)
            {
                continue;
                ;
            }
            cout << pages[i].lines[j].data << endl;
        }
        cout << endl;
    }
}

void Book::operator+=(Page &p)
{
    static int ind = 0;
    int len = p.get_lenlines();

    if (pages[ind].lenlines == 0)
    {
        pages[ind].lines = new Line[20];
        for (int i = 0; i < 20; ++i)
        {
            pages[ind].lines[i].data = NULL;
        }
        pages[ind].lenlines = len;
        for (int i = 0; i < len; ++i)
        {
            pages[ind].lines[i].data = new char[40];
            int j = 0;
            pages[ind].lines[i].data = p.lines[i].data;
        }
    }
    else
    {
        int prev_len = pages[ind].lenlines - 1;
        int new_len = prev_len + len;
        if (new_len > 20)
        {
            new_len = 20;
        }
        pages[ind].lenlines = new_len;
        bool next_page = false;

        int c = 0;
        int j = 0;
        int k = 0;
        for (int i = prev_len; i < new_len + 1; ++i)
        {
            if (i > 19)
            {
                new_len = new_len + 2 - i;
                i = 0;
                ind += 1;
                pages[ind].lines = new Line[20];
                pages[ind].lenlines = len - c;
                for (int i = 0; i < 20; ++i)
                {
                    pages[ind].lines[i].data = NULL;
                }
            }
            if (i == prev_len)
                for (j = 0; pages[ind].lines[i].data[j] != '\0'; ++j) // check the length of already existing characters
                {
                }
            else
            {
                pages[ind].lines[i].data = new char[40];
            }
            for (;;)
            {
                int l = k;
                int l1 = k + 1;
                if (p.lines[c].data[k] == ' ' || p.lines[c].data[k] == '.') // check if the coming word exceeds the line by 40 limit
                {

                    for (l = k + 1;; ++l)
                    {
                        if (p.lines[c].data[l] == ' ' || p.lines[c].data[l] == '.' || p.lines[c].data[l] == '\0')
                        {
                            break;
                        }
                    }
                }
                l -= l1 - 1;
                if (j + l >= 40) // if exceed then a word is not added and null is added to terminate line
                {

                    pages[ind].lines[i].data[j] == '\0';
                    k += 1;
                    break;
                }
                if (p.lines[c].data[k] == '\0' && c < len) // if the new para line end then making it to next line and index at 0
                {
                    pages[ind].lines[i].data[j] = ' ';
                    j += 1;
                    k = 0;
                    c++;
                    if (c == len)
                    {
                        break;
                    }
                }
                pages[ind].lines[i].data[j] = p.lines[c].data[k];
                j++;
                k++;
            }
            if (c == len)
            {
                break;
            }
            j = 0;
        }
    }
}

Page &Book::operator[](int i)
{
    return pages[i];
}

ostream& operator <<(ostream& out , Book& b)
{
    bool check = true;
    for (int i = 0; i < b.lenpages; ++i)
    {
        cout << "Book Page --" << i + 1 << "--" << endl;
        for (int j = 0; j < b.pages[i].lenlines; ++j)
        {
            if (b.pages[i].lines[j].data == NULL)
            {
                continue;
                ;
            }
            cout << b.pages[i].lines[j].data << endl;
        }
        cout << endl;
    }
    return out;
}

