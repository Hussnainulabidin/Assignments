//Name : Hussnain Ul Abidin
//Roll No : 22i-1102_K
#include <iostream>
#include "Page.h"

using namespace std;

Page::Page()
{
    this->lenlines = 0;
    this->lines = nullptr;
}

Page::Page(int x)
{
    this->lenlines = x;
    this->lines = new Line[x];
}

Page::Page(Page &copy)
{
    this->lenlines = copy.lenlines;
    this->lines = new Line[this->lenlines];
    for (int i = 0; i < this->lenlines; ++i)
    {
        this->lines[i] = copy.lines[i];
    }
}

int Page::get_lenlines()
{
    return lenlines;
}

void Page::operator+=(char *l)
{
    int len = 0;
    for (int i = 0; l[i] != '\0'; ++i) // finding the length of the paragraph recives
    {
        len += 1;
    }
    int line = 0;
    int c = 0;
    if (lenlines == 0)
    {

        for (int i = 0; l[i] != '\0'; ++i) // finding the number of line in paragraph with max length 40
        {
            if (c > 40)
            {
                line += 1;
                c = 0;
                if (l[i] != ' ' || l[i] != '.') // making the all words fit in length 40;
                {                               // if length exceed
                    for (i;; --i)               // then decreasing length to number of words which fit
                    {
                        if (l[i] == ' ' || l[i] == '.')
                        {
                            break;
                        }
                    }
                }
            }
            c++;
        }
        line = line + 1;
        this->lines = new Line[line]; // created an array of lines to store data from para in eash line
        for (int i = 0; i < line; ++i)
        {
            lines[i] = Line(40);
        }

        char *templines = new char[40];
        c = 0;
        int ind = 0;
        for (int i = 0; l[i] != '\0'; ++i)
        {
            if (c >= 40)
            {
                int j = i;
                c = 0;
                if (l[i] != ' ' || l[i] != '.') // making the all words fit in length 40;
                {                               // if length exceed
                    for (i;; --i)               // then decreasing length to number of words which fit
                    {
                        if (l[i] == ' ' || l[i] == '.')
                        {
                            break;
                        }
                    }
                }
                j -= i;
                templines[40 - j] = '\0';
                lines[ind].set_data(templines);
                ind++;
                continue;
            }
            templines[c] = l[i];
            c++;
        }
        templines[c] = '\0';
        lines[ind].set_data(templines);
        lenlines = line;
    }
    else
    {
        for (int i = 0; l[i] != '\0'; ++i) // finding the number of line in paragraph with max length 40
        {
            if (c > 40)
            {
                line += 1;
                c = 0;
                if (l[i] != ' ' || l[i] != '.') // making the all words fit in length 40;
                {                               // if length exceed
                    for (i;; --i)               // then decreasing length to number of words which fit
                    {
                        if (l[i] == ' ' || l[i] == '.')
                        {
                            break;
                        }
                    }
                }
            }
            c++;
        }
        line += 1;
        int prev_len = lenlines - 1;
        int new_len = line + prev_len + 1;
        this->lenlines = new_len;
        int c = 0;
        int j = 0;
        int k = 0;
        for (int i = prev_len; i < new_len + 1; ++i)
        {
            if (i == prev_len)
                for (j = 0; lines[i].data[j] != '\0'; ++j) // check the length of already existing characters
                {
                }
            else
            {
                lines[i].data = new char[40];
            }
            for (;;)
            {
                int l1 = k;
                int l2 = k + 1;
                if (l[k] == ' ' || l[k] == '.') // check if the coming word exceeds the line by 40 limit
                {
                    for (l1 = k + 1;; ++l1)
                    {
                        if (l[l1] == ' ' || l[l1] == '.' || l[l1] == '\0')
                        {
                            break;
                        }
                    }
                }
                l1 -= l2 - 1;
                if (j + l1 >= 40) // if exceed then a word is not added and null is added to terminate line
                {
                    lines[i].data[j] == '\0';
                    k += 1;
                    break;
                }
                if (l[k] == '\0')
                {
                    break;
                }
                lines[i].data[j] = l[k];
                j++;
                k++;
            }

            j = 0;
            if (l[k] == '\0')
            {
                break;
            }
        }
    }
}

void Page::operator+=(Page &p)
{
    int len = 0;
    int len2 = p.get_lenlines();
    if (lines == NULL || this->lenlines == 0)
    {
        lines = new Line[20];
        for (int i = 0; i < 20; ++i)
        {
            lines[i].data = NULL;
        }
        this->lenlines = len2;
        for (int i = 0; i < len2; ++i)
        {
            lines[i].data = new char[40];
            lines[i].data = p.lines[i].data;
        }
    }
    else
    {
        int prev_len = this->lenlines - 1;
        int new_len = prev_len + p.lenlines + 1;
        this->lenlines = new_len;

        int c = 0;
        int j = 0;
        int k = 0;
        for (int i = prev_len; i < new_len + 1; ++i)
        {
            if (i == prev_len)
            {
                for (j = 0; lines[i].data[j] != '\0'; ++j) // check the length of already existing characters
                {
                }
            }
            else
            {
                lines[i].data = new char[40];
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

                    lines[i].data[j] == '\0';
                    k += 1;
                    break;
                }
                if (p.lines[c].data[k] == '\0' && c < len2) // if the new para line end then making it to next line and index at 0
                {
                    lines[i].data[j] = ' ';
                    j += 1;
                    k = 0;
                    c++;
                    if (c == len2)
                    {
                        break;
                    }
                }
                lines[i].data[j] = p.lines[c].data[k];
                j++;
                k++;
            }
            if (c == len2)
            {
                break;
            }
            j = 0;
        }
    }
}

void Page::operator+=(Line &l)
{
    int len1 = lenlines;
    if (lines == NULL || this->lenlines == 0)
    {
        lines = new Line[20];
        for (int i = 0; i < 20; ++i)
        {
            lines[i].data = NULL;
        }
        this->lenlines += 1;
        lines[0].data = l.data;
    }
    else
    {
        int prev_len = this->lenlines-1;
        int new_len = prev_len + 1;
        this->lenlines = new_len;
        int c = 0;
        int j = 0;
        int k = 0;
        for (int i = prev_len; i < new_len; ++i)
        {
            if (i == prev_len)
            {
                for (j = 0; lines[i].data[j] != '\0'; ++j) // check the length of already existing characters
                {
                }
            }
            else
            {
                lines[i].data = new char[40];
            }
            
            for (;;)
            {
                int l1 = k;
                int l2 = k + 1;
                if (l.data[k] == ' ' || l.data[k] == '.') // check if the coming word exceeds the line by 40 limit
                {
                    for (l1 = k + 1;; ++l1)
                    {
                        if (l.data[l1] == ' ' || l.data[l1] == '.' || l.data[l1] == '\0')
                        {
                            break;
                        }
                    }
                }
                l1 -= l2 - 1;
                if (j + l1 >= 40) // if exceed then a word is not added and null is added to terminate line
                {
                    this->lenlines+=1;
                    new_len+=1;
                    lines[i].data[j] == '\0';
                    k += 1;
                    break;
                }
                if (l.data[k] == '\0')
                {
                    break;
                }
                lines[i].data[j] = l.data[k];
                j++;
                k++;
            }
            j = 0;
            if(i == new_len)
            {
                break;
            }
        }
    }
}

Line &Page::operator[](int i)
{
    return lines[i];
}
