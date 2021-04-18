
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
#include <fstream>
using namespace std;

class House
{
private:
    int houseNumber;
    string streetName;
    string streetType;

public:
    void populate()
    {
        cout << "Please enter the house number: ";
        cin >> houseNumber;
        cout << "\nPlease enter the street name: ";
        getline(cin, streetName);
    }
    void display()
    {
    }
};

int main()
{
}

/*
a)  Open a file named “Sport.dat” as a binary file, for writing.

b)  Write ‘NUM_SPORTS’ as the first value in the file.

c)  Write the array ‘events’ to the file.
*/