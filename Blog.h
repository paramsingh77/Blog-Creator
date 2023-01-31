#ifndef _BLOG_H
#define _BLOG_H
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;



class Blog
{
private:
    string authorFirst;
    string authorLast;
    string content;
    int month;
    int day;
    int year;

public:
    // constructors
    Blog();
    Blog(string, string, string, int, int, int);

    // methods
    void setBlog(string, string, string, int, int, int);
    string getAuthorFirst() const;
    string getAuthorLast() const;
    string getAuthorContent() const;
    int getMonth() const;
    int getDay() const;
    int getYear() const;
    int timeElapsed()const;
    bool operator<(const Blog& right)const;
};

#endif
