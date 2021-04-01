//****************************************************************************************************
//
// File:
// Student: Stephen Froeber
// Assignment:
// Course Name: Programming II
// Course Number: COSC 1560
// Due:
//
// This program asks the user to read a file of student data from a disk file and then
// creates an ordered list of students by student id.
// Other files required:
// 1. studentFile.txt – text file of Student data
// 2. student.h – definition of the Student struct
//****************************************************************************************************

#include <iostream>
#include <string>
using namespace std;

struct Date

{

    int day;

    int month;

    int year;
};

struct Exam

{

    string name;

    Date dateScheduled;

    int numStudents;
};

/*
a)  Create a dynamically allocated array of 10 Exams.

b)  Assign “Chemistry” as the name of the 2nd element of the array.

c)  Set a pointer to the 3rd element of the array, and assign “1/2/2021” as the date of that exam by using the pointer.
*/

int main()
{
    Exam *e;
    e = new Exam[10];
    e[1].name = "Chemistry";
    Exam *three = &e[2];
    three->dateScheduled.day = 1;
    three->dateScheduled.month = 2;
    three->dateScheduled.year = 2021;
}