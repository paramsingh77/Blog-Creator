/**************************************************************************************************************************************
Name - Parminder Singh
Course - 355
Assingment - 2
Date - January 17th 2023
Program Description - In this program/assingment we need to create the Blog Creator. For this we will create the blog class which will take the private
members first name , last name , content of the blog and what date it was published in form of mm-dd-yyyy. In this we will have getters for each private
members in the class. Then we will have a BLOG array  which will get all the entries of the blog coming in it. And the integer number for tracking the number
of blogs initiated with zero i.e numberOfBlogs. Then we will have two funciton named addBlog and displayBlogs. These both  function will have blog array and
reference to the number of blogs as a parameter. addBlog will call the setBlog function and will put a entery into the blog array and incremneting the index and pointer to next index. displayblog will display all the blogs using maniuplators (setw,setfill,left,right). And menu function will display the
operations user can perform. This assignment has 3 new function. Save Blogs will save the blogs into the data file using file handling. loadBlogs
will read the data into file in array of blogs. And we will have a sort function. Sort function overload it's less then operator and will compare the time
of both indexes,
****************************************************************************************************************************************/


#include "Blog.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include<ctime>

const int MAX = 100;
using namespace std;


/********************************************************************
***********************function declaration*************************/
/*******************************************************************/
int menu();
int getOption();
void addBlog(Blog blog[], int &numBlogs);
void displayBlogs(Blog blog[], int &noOfBlogs);
void createHtml(Blog blog[] , int &noOfBlogs);
void saveBlogs(Blog blog[], int &noOfBlogs);
void loadBlogs(Blog blog[], int &noOfBlogs);
void createLogFiles(Blog blog[], int numOfBlogs);
void sortBlogs(Blog blog[] , int noOfBlogs);





/***************************************/
/**************MAIN FUNCTION************/
/***************************************/

int main()
{
    cout << "*****************************BLOG EDITOR***************************"
         << endl
         << endl;
    Blog blog[MAX];
    Blog b;              // initaite the object.
    int noOfBlogs = 0;   // track for the count of blogs in array.
                           // will get the operation to performed.
   
    int opt = menu();
    while(opt!=0){
    addBlog(blog,noOfBlogs);
    displayBlogs(blog,noOfBlogs);
    loadBlogs(blog,noOfBlogs);
    createLogFiles(blog,noOfBlogs);
    opt = menu();
      if (opt == 0) {
        cout << endl;
        cout << "Goodbye!" << endl;
        break;
      }
   }
   createHtml(blog,noOfBlogs);
    return 0;
}



/******************************************/
/***********Function Definitions***********/
/******************************************/






//*************************************************************************************************************************
// function name - menu
// function description - This function will print the options to the user, what
// operations they want to use. 1 option will be for publishing a blog and third option is 0 to quit.
// incoming parameters - None 
// outgoing - None 
// return - None
//****************************************************************************************************************************

int menu()
{
    cout << endl
         << endl;
    cout << "**********OPTIONS************" << endl
         << endl;
    cout << "Press 1 for publishing a blog" << endl;
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



//***************************************************************************************************************************************************************
// function name - addBlog
// function description - This function will take the array of blogs and reference of number of blogs which are being passed into blog array. This function will store all the blog information that is 6 paramters into the local variables then method set blog will be called which will put entry into the blog array and it will be incremented to next index and number of blogs will be incremented. 
// incoming parameters -  blog array and reference of number of blogs in a blog array. 
// outgoing - numBlogs which will track the number of blogs.
// return - None
//**************************************************************************************************************************************************************


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



/**************************************************************************************************************************/
// function name - displayBlog
// function description - This function will take the array of blogs and reference of number of blogs which are being 
//    passed into blog array.This  function will using the function setw ,  setfill , left and right for maniuplating output.
//    Firstly, the headings will be displayed on top. Then using for loop and getters we will print the blog enteries.
// incoming parameters -  blog array and reference of number of blogs in a blog array. 
// outgoing - numBlogs which will track the number of  blogs. 
// return - None
//*****************************************************************************************************************************



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


/*****************************************************************************************************************************************************
function name - saveBlog
function Description - This function will save a data into a data file. This funciton will create the file named rooms1.txt and will load data into it.
this function will be called at the starting of the main function.
incoming parameters - blog array and the reference to the number of blogs.
outgoing parameter - noOfBlogs
return-none
******************************************************************************************************************************************************/

void saveBlogs(Blog blog[], int &noOfBlogs)
{
    cout << endl;
    //creating file
    ofstream outfile("rooms1.txt");

    for (int i = 0; i < noOfBlogs; i++)
    {
	//putting the content into file
        outfile << blog[i].getMonth() << "-" << blog[i].getDay() << "-"
                << blog[i].getYear() << " " << blog[i].getAuthorFirst() << " "
                << blog[i].getAuthorLast() << " " << blog[i].getAuthorContent()
                << endl;
    }
    cout << endl;
    outfile.close();
}


/****************************************************************************************************************************************************
* function name - createLogFiles
* function description - This function will create the log file with the html extension. Then file will be open and content of author will be opened.
* incoming parameters -  blog array and reference of number of blogs in a blog array.
* outgoing parameters - None
* return - None
***************************************************************************************************************************************************/


void createLogFiles(Blog blog[], int numOfBlogs)
{
    ofstream outfile;
    string fileName;
    for (int i = 0; i < numOfBlogs; i++)
    {
	 //creating the file path
        string filePath = "website/website/" + blog[i].getAuthorFirst() + to_string(blog[i].getMonth())+"-"+ to_string(blog[i].getDay()) +"-" + to_string(blog[i].getYear()) +".html";
        outfile.open(filePath.c_str());
        outfile << blog[i].getAuthorContent() << endl;
        outfile.close();
    }
}


/*****************************************************************************************************************************************************
 * function name - loadBlogs
 * function description - This function will load the dara file into the array of blogs.And it will call the setBlog function to set the data.
 * incoming parameters - blog array and the reference to the number of class rooms.
 * outgoing parameters - None
 * return - None
*****************************************************************************************************************************************************/


void loadBlogs(Blog blog[], int &numClassrooms)
{
    //create file
    ifstream infile("rooms1.txt");
    int month = 0, year = 0, day = 0;
    string firstName = " ", lastName = " ";
    string content;
    getline(infile, content);
    //loading the data
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


/**************************************************************************************************************************************************
 * function name - createHtml
 * function description - This funciton will create a index.html file. In this function we will put the html code into the html file. This will print
 * a header on the top. Then the list of all the blogs in the sorted manner. All the new blogs will be on the top and in rest of all in order. The 
 * name of the author will be as a hypertext to all of their blogs.
 * incoming parameter - array of blog type and the reference to the number of blogs.
 * outgoing parameter - reference to the number of blogs.
 * return -  none
***************************************************************************************************************************************************/

void createHtml(Blog blog[] ,int &noOfBlogs){

	ofstream outfile;
	string fileName = "website/index.html";
	outfile.open(fileName.c_str());

         outfile<< "<!DOCTYPE html>"<<endl;
	 outfile<< "<head>"<<endl;
	 outfile<< " <meta charset=\"UTF-8\">" <<endl;
	 outfile<< "<title> Param's Blog </title>" <<endl;
	 outfile<< "</head>"<<endl;
	 outfile<< "<body style=\" text-align: center \";>" <<endl;
	 outfile<< "<h1\">The CS355 Super Blog</h1>"<<endl;
       	 for(int i = 0 ; i < noOfBlogs ; i++){
         	sortBlogs(blog,noOfBlogs); //will sort the array
 outfile<<"<p>Blog Written by <a href="<< "website/" + blog[i].getAuthorFirst() + to_string(blog[i].getMonth())+"-"+ to_string(blog[i].getDay()) +"-" + to_string(blog[i].getYear()) +".html" <<">"<<blog[i].getAuthorFirst()<<" "<<blog[i].getAuthorLast()<<"</a>"<<" Date : " << blog[i].getMonth() <<"-"<< blog[i].getDay()<<"-"<<blog[i].getYear()<<"</p>"<<endl;
	}

	 outfile<< "</body>"<<endl;
	 outfile<< "</html>"<<endl;

	outfile.close();
}

/************************************************************************************************************************************************
 * function name - sortBlogs
 * function description - this function will sort the blogs array with bubble sort for organizing the blogs into descending order which is new on the top and old
 * ones at bottom. This function will have the overloaded greater then operator which will compare the time of publishing a blog and sort according to it.
 * incoming parameter - array of blog and number of blog
 * outgoing parameter - None
 * return - None
***********************************************************************************************************************************************/


void sortBlogs(Blog blog[] , int noOfBlogs){

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
