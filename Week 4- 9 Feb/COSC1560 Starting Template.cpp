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

int main()
{
    string TA;
    string *T = &TA;

    *T = "What's this all about, eh?";

    cout << TA;
}