//****************************************************************************************************
//
// File: PointPractice.cpp
// Student: Stephen Froeber
// Assignment: 3.2
// Course Name: Programming II
// Course Number: COSC 1560
// Due: 2 Feb 2021
//
// This program declares pointer variables to demonstrate usage
//
//****************************************************************************************************

#include <iostream>

using namespace std;

int n1 = 10,
    n2 = 25,
    n3 = 50;

int *p1 = &n1,
    *p2 = &n2;

int main()
{

    *p1 *= 2;
    cout << "The value stored at n1, multiplied by 2, is: " << n1 << endl;

    cout << "The sum of " << *p1 << " and " << *p2 << " is " << *p1 + *p2 << endl;

    cout << "The memory address stored in p1 is " << &p1 << "." << endl;
    p1 = &n3;
    cout << "That address will now change to " << p1 << endl;

    cout << "The sum of " << *p2 << " and " << *p1 << " is " << *p2 + *p1 << endl;

    return 0;
}
