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
    char str1[15] = "mina yang"; //declare char array with 15 elements, and set value to text

    if (islower(str1[0]))
    {

        str1[0] = toupper(str1[0]);

    } //evaluate the first character in the array (m) to see if it's lower case. If it is, change it to upper case.

    cout << strlen(str1) << endl; //outputs the length of str1

    char str2[15]; //declare another c string with 15 elements

    strcpy(str2, str1); //copies the value of str2 into str1.

    cout << str2 << endl; //empty string
}