//****************************************************************************************************
//
// File: EmployeeData.cpp
// Student: Stephen Froeber
// Assignment: 8
// Course Name: Programming II
// Course Number: COSC 1560
// Due: 26 Mar 2021
//
// This program asks the user to read a file of student data from a disk file and then
// creates an ordered list of students by student id.
// Other files required:
// 1. studentFile.txt – text file of Student data
// 2. student.h – definition of the Student struct
//****************************************************************************************************

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//structure declarations
struct Date
{
    int Day;
    int Month;
    int Year;
};

struct Employee
{
    string Name;
    int Age;
    Date DateEmployed;
};

//function prototypes

int main()
{
    //declarations
    Employee *emp = nullptr; //for dynamic allocation
    fstream f;               //file data
    int arraySize;           //stores how many employess are in the file

    f.open("Employees.txt", ios::in | ios::out);
}