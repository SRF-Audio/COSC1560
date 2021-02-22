//****************************************************************************************************
//
// File:
// Student: Stephen Froeber
// Assignment: 2D Array Concept Practice
// Course Name: Programming II
// Course Number: COSC 1560
// Due: 26 Jan 2021
//
// This program asks the user to read a file of student data from a disk file and then
// creates an ordered list of students by student id.
// Other files required:
// 1. studentFile.txt – text file of Student data
// 2. student.h – definition of the Student struct
//****************************************************************************************************

#include <iostream>
#include <iomanip>

using namespace std;

const int ROWS = 5;
const int COLS = 4;

void displayArray(const int[][COLS], int);
void displayArray(int[][COLS], int);
void addValuesToArray(int[][COLS], int);

int main()
{
    const int myArray[ROWS][COLS] = {{13, 17, 15, 22},
                                     {65, 34, 25, 56},
                                     {3, 10, 250, 6},
                                     {1, 5, 11, 7},
                                     {10, 11, 12, 13}}; //each set of brackets is a row, each set of comma numbers is a column

    displayArray(myArray, ROWS);

    //initialized empty
    int changeThisArray[ROWS][COLS];

    //display the array, empty
    cout << "Here's before: " << endl;
    displayArray(changeThisArray, ROWS);

    //make the array values the product of the row and column index
    addValuesToArray(changeThisArray, ROWS);

    //display the array full
    cout << "Here's after: " << endl;
    displayArray(changeThisArray, ROWS);

    return 0;
}

void displayArray(const int testArray[][COLS], int numRows)
{
    //Displays the value stored at <row>, <column>, with a break between rows
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << "The value stored at position " << i << ", " << j << " is " << setw(4) << testArray[i][j] << endl; //nested for loop requires row and column variable
        }
        cout << endl;
    }
}

void addValuesToArray(int changedArray[][COLS], int numRows)
{
    int storeArray[ROWS][COLS];
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            changedArray[i][j] = i * j;
        }
    }
}