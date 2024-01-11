#include <iostream>
#include "Book.cpp"

using namespace std;

int main()
{
    Page p, p2, p3, p4;
    p += "I think having someone in your life to look up to is one of the most important things. We all admire people like Linus Torvalds and Bill Gates but trying to make them your role models can be demotivating.Bill Gates began coding at age 13 and formed his first venture at age 17. ";
    p2 += "Having a local hero or mentor is more helpful. Because you're both living in the same community, there 's a greater chance there won' t be such a large gap to discourage you.A local mentor probably started coding around the age you did and was unlikely to start a big venture.";
    p3 += "First, because their stories seemed like fantasy to me, and second, I couldn't reach them. I chose my mentors and role models to be those near my reach.Choosing a role model doesn't mean you just want to get to where they are and stop.Success is step by step.";
    p4 += "You probably can't get one-on-one advice from someone like Bill Gates. You can get the advice they're giving to the public at conferences, which is great, too. I always follow smart people.";
    Book b(3);
    b += p2;
    b += p;
    b += p3;
    b[2] += p4;
    b[2][2] = "I am editing this line using subscripts.";
    b[2] += "Adding this text to existing line of page number 3 and overflowed text must go to next line ";
    Line l("Adding a new line to an existing page.");
    Line l2("This is line 2.");
    b[1] += l;
    b[1] += l2;
    b[1] += l;
    cout << b;
    return 0;
}