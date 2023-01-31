#include "Blog.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <ostream>
using namespace std;

Blog::Blog()
{
    authorFirst = "Anonymus";
    authorLast = "Uknown";
    content = " ";
    month = 0;
    day = 0;
    year = 0;
}

Blog::Blog(string firstName, string LastName, string content, int monthOfPublish, int dayOfPublish, int yearOfPublish)
{
    authorFirst = firstName;
    authorLast = LastName;
    content = content;
    month = monthOfPublish;
    day = dayOfPublish;
    year = yearOfPublish;
}

void Blog ::setBlog(string firstName, string LastName, string content, int monthOfPublish, int dayOfPublish, int yearOfPublish)
{
    this->authorFirst = firstName;
    this->authorLast = LastName;
    this->content = content;
    this->month = monthOfPublish;
    this->day = dayOfPublish;
    this->year = yearOfPublish;
}

/**************Getters***************/

string Blog::getAuthorFirst() const
{
    return authorFirst;
} 
string Blog::getAuthorLast() const
{
    return authorLast;
}
string Blog::getAuthorContent() const
{
    return content;
}
int Blog::getMonth() const
{
    return month;
}
int Blog::getDay() const
{
    return day;
}
int Blog::getYear() const
{
    return year;
}

/*************Time elapsed function************/

int Blog::timeElapsed()const {
   time_t now = time(NULL);
   tm *ltm = localtime(&now);
   int currentYear = ltm->tm_year + 1900;
   int currMonth = ltm->tm_mon + 1;
   int currDay = ltm->tm_mday;

   const int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

   int num2 = (currentYear - 1) * 365 + currDay;
   for (int i = 0; i < currMonth - 1; i++) {
  	 num2 += month_days[i];
   }

   if (currMonth <= 2) {
    	currentYear--;
   }

   int numOfElapse = currentYear / 4 - currentYear / 100 + currentYear / 400;
   num2 += numOfElapse;


   int month1 = this->month;
   int day1 = this->day;
   int year1 = this->year;
   int num1 = (year1)*365 + day1;
   for (int i = 0; i < month1 - 1; i++) {
    	  num1 += month_days[i];
   }

  if (month1 <= 2)
       year1--;

  int numOfElapse1 = year1 / 4 - year1 / 100 + year1 / 400;
  num1 += numOfElapse1;

  return num2 - num1;
}

/********operator overloading************/

bool Blog::operator<(const Blog &right) const {
   if (this->timeElapsed() < right.timeElapsed()) {
     return true;
   }
  else
     return false;
}



