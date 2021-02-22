//****************************************************************************************************
//
// File: StudentScoresPt2.cpp
// Student: Stephen Froeber
// Assignment: Practice Quiz
// Course Name: Programming II
// Course Number: COSC 1560
// Due: 26 Jan 2021
//
// This program reads scores from a file and runs calculations on them.
// Other files required:
//
//
//****************************************************************************************************

#include <iostream>

using namespace std;

int main()
{
    int arraySize = 5, values[arraySize], sum;
    double average = static_cast<double>(sum) / arraySize;

    for (int i = 0; i < arraySize; i++)

    {
        cout << "Enter a number: ";
        cin >> values[i];
        sum += values[i];
    }

    cout << "The average of what you entered is: " << average;
}