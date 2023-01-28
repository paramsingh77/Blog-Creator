#include "Blog.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include<ctime>

const int MAX = 100;
using namespace std;
/*****function declaration******/
int menu();
int getOption();
void addBlog(Blog blog[], int &numBlogs);
void displayBlogs(Blog blog[], int &noOfBlogs);
void createHtml(Blog blog[] , int &noOfBlogs);
void saveBlogs(Blog blog[], int &noOfBlogs);
void loadBlogs(Blog blog[], int &noOfBlogs);
void createLogFiles(Blog blog[], int numOfBlogs);
void sortBlogs(Blog blog[] , int &noOfBlogs);


int main()
{
    cout << "*****************************BLOG EDITOR***************************"
         << endl
         << endl;
    Blog blog[MAX];
    Blog b;              // initaite the object.
    int noOfBlogs = 0;   // track for the count of blogs in array.
                           // will get the operation to performed.
   
   int q;
   cout<<"Enter the value of q:  ";
   cin>>q;
   while(q!=0){

    addBlog(blog,noOfBlogs);
    displayBlogs(blog,noOfBlogs);
    loadBlogs(blog,noOfBlogs);
    createLogFiles(blog,noOfBlogs);
    // sortBlogs(blog,noOfBlogs);
    cout<<"Enter the next value : ";
    cin>>q;
   }
   createHtml(blog,noOfBlogs);
    return 0;
}

/***********Function Definitions***********/

int menu()
{
    cout << endl
         << endl;
    cout << "**********OPTIONS************" << endl
         << endl;
    cout << "Press 1 for publishing a blog" << endl;
    cout << "Press 2 for Displaying a blog" << endl;
    cout << "Press 3 for savingDisplaying a blog" << endl;
    cout << "Press 4 for loadDisplaying a blog" << endl;
    cout << "Press 5 for CreateLog a blog" << endl;
    cout << "Press 0 for quit" << endl
         << endl;
    cout << "*****************************" << endl
         << endl;
    int val = getOption();
    return val;
}

int getOption()
{
    int num;
    cout << "Enter the option you want to choose: ";
    cin >> num;
    cout << endl;
    return num;
}

void addBlog(Blog blog[], int &numBlogs)
{

    string authorFirstName;
    string authorLastName;
    string contentName;
    int month;
    int day;
    int year;
    cout << "Enter the firstName of author: ";
    cin >> authorFirstName;
    cout << "Enter the Last Name of author: ";
    cin >> authorLastName;
    cout << "Enter the Content: ";
    cin.ignore();
    getline(cin, contentName);
    cout << "Enter the Month of Publish: ";
    cin >> month;
    cout << "Enter the day of publish: ";
    cin >> day;
    cout << "Enter the year of publish: ";
    cin >> year;
    blog[numBlogs].setBlog(authorFirstName, authorLastName, contentName, month,
                           day, year); // it will set the entries into the blog
                                       // array whenever it will be called.
    numBlogs++;                        // increment the index and the value of the numBlod.
}

void displayBlogs(Blog blog[], int &noOfBlogs)
{
    cout << endl;
    cout << setw(7) << "Date" << setw(7);
    cout << setw(20) << "Author" << setw(20);
    cout << setw(18) << "Content" << setw(18) << endl;
    for (int i = 0; i < noOfBlogs; i++)
    {
        cout << right << setw(2) << setfill('0') << blog[i].getMonth() << "-";
        cout << right << setw(2) << setfill('0') << blog[i].getDay() << "-";
        cout << left << setw(7) << setfill(' ') << blog[i].getYear();
        cout << setw(14) << left << blog[i].getAuthorFirst();
        cout << left << setw(10) << blog[i].getAuthorLast();
         cout << right << blog[i].getAuthorContent() << endl;
    }
    cout << endl;
}

void saveBlogs(Blog blog[], int &noOfBlogs)
{
    cout << endl;
    ofstream outfile("rooms1.txt");

    for (int i = 0; i < noOfBlogs; i++)
    {
        outfile << blog[i].getMonth() << "-" << blog[i].getDay() << "-"
                << blog[i].getYear() << " " << blog[i].getAuthorFirst() << " "
                << blog[i].getAuthorLast() << " " << blog[i].getAuthorContent()
                << endl;
    }
    cout << endl;
    outfile.close();
}


void createLogFiles(Blog blog[], int numOfBlogs)
{
    ofstream outfile;
    string fileName;
    for (int i = 0; i < numOfBlogs; i++)
    {
        string filePath = "Website/" + blog[i].getAuthorFirst() + to_string(blog[i].getMonth())+"-"+ to_string(blog[i].getDay()) +"-" + to_string(blog[i].getYear()) +".html";
	    //fileName = "logs/" + blog[i].getAuthorFirst() + ".txt";
        outfile.open(filePath.c_str());
        outfile << blog[i].getAuthorFirst()
                << blog[i].getAuthorLast()
                << blog[i].getAuthorContent() << endl;
        outfile.close();
    }
}

void loadBlogs(Blog blog[], int &numClassrooms)
{
    ifstream infile("rooms1.txt");
    int month = 0, year = 0, day = 0;
    string firstName = " ", lastName = " ";
    string content;
    getline(infile, content);
    while (!infile.eof())
    {
        infile >> month;
        infile >> day;
        infile >> year;
        infile >> firstName;
        infile >> lastName;
        infile >> ws;
        getline(infile, content);
        blog[numClassrooms].setBlog(firstName, lastName, content, month, day, year);
    }

    infile.close();
}


void createHtml(Blog blog[] ,int &noOfBlogs){

	ofstream outfile;
	string fileName = "Website/index.html";
	outfile.open(fileName.c_str());

         outfile<< "<!DOCTYPE html>"<<endl;
	 outfile<< "<head>"<<endl;
	 outfile<< " <meta charset=\"UTF-8\">" <<endl;
	 outfile<< "<title> Param's Blog </title>" <<endl;
	 outfile<< "</head>"<<endl;
	 outfile<< "<body style=\" text-align: center \";>" <<endl;
	 outfile<< "<h1 style=\"color:blue;\">The CS355 Super Blog</h1>"<<endl;
       	 for(int i = 0 ; i < noOfBlogs ; i++){
         	sortBlogs(blog,noOfBlogs);
 outfile<<"<p>Blog Written by <a href="<< "Website/" + blog[i].getAuthorFirst()+ to_string(blog[i].getMonth())+ "-" + to_string(blog[i].getDay()) +"-" + to_string(blog[i].getYear())+".html\"" <<">"<<blog[i].getAuthorFirst()<<" "<<blog[i].getAuthorLast()<<"</a>"<<" Date : " << blog[i].getMonth() <<"-"<< blog[i].getDay()<<"-"<<blog[i].getYear()<<"</p>"<<endl;
	}

	 outfile<< "</body>"<<endl;
	 outfile<< "</html>"<<endl;

	outfile.close();
}

void sortBlogs(Blog blog[] , int &noOfBlogs){

	for(int top = 0 ; top  < noOfBlogs ; top++){
		bool sorted = true;
		for(int i = noOfBlogs-1 ; i > top ; i--){
			if(blog[i] < blog[i-1]){
				Blog temp = blog[i];
			        blog[i] = blog[i-1];
				blog[i-1] = temp;
				sorted = false;
			}
		}
		if(sorted)
			return;
	}
			        	
}
