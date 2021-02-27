//****************************************************************************************************
//
// File: arrayTester.cpp
// Student: Stephen Froeber
// Assignment: 4.1
// Course Name: Programming II
// Course Number: COSC 1560
// Due: 9 February
//
// This program gets values from the user via pointers, and tests those values against array elements
//
//
// ****************************************************************************************************

#include <iostream>
#include <string>
using namespace std;

void singleIndexPrint(int[], int);
void addElements(int[], int);
int askUser(int, int);               //asks user for a number, and validates if it's in the correct range passed in the 1st arg. Second arg is a counter that changes the message based on how many times they've been asked.
void displayResult(int, int[], int); //displays validated user results. Takes arg of ptr, the array, and the size
void displayArray(int[], int);       //loop to display values and addresses

int main()
{
    const int SIZE = 5;
    int numbers[SIZE] = {10, 22, 34, 48, 59};
    int *ptr = numbers;

    cout << "This program will ask you for an element number in a stored array, and return results." << endl;

    singleIndexPrint(numbers, SIZE); //get user inputs and  them

    addElements(numbers, SIZE); //get two user inputs and sum them

    //Sanity checks for debugging
    /*
    cout << "\nDebug outputs for pointers:" << endl;
    cout << "Value stored at location that ptr points: " << *ptr << endl;
    cout << "Value of ptr: " << ptr << endl;
    cout << "Address of numbers: " << numbers << endl;
    cout << "Address of ptr: " << &ptr << endl;
    cout << "Address of second element: " << &ptr[1] << endl;
    cout << "Value of second element: " << ptr[1] << endl;
    */

    return 0;
}

void singleIndexPrint(int nums[], int size)
{
    int userInput;
    int *ptr1 = &userInput;
    int count = 1; //counter to change user message in the askUser function

    //First round
    *ptr1 = askUser(size, count);
    displayResult(*ptr1, nums, size);
    count++;

    //second round
    *ptr1 = askUser(size, count);
    displayResult(*ptr1, nums, size);
    count++;

    //third round
    *ptr1 = askUser(size, count);
    displayResult(*ptr1, nums, size);

    displayArray(nums, size);
}

void addElements(int nums[], int size)
{
    int u1,
        u2,
        count = 1; //changes message in askUser()
    int *ptr1 = &u1,
        *ptr2 = &u2;

    cout << "\nNext, let's add some stored values together." << endl;
    *ptr1 = askUser(size, count); //get the user input for u1
    count++;
    *ptr2 = askUser(size, count); //get the user input for u2

    displayResult(*ptr1, nums, size);
    displayResult(*ptr2, nums, size);

    ptr1 = &nums[u1 - 1]; //set ptr1 address to array element
    ptr2 = &nums[u2 - 1]; //set ptr2 address to array element

    cout << "\nThe sum of the values stored in elements " << u1 << " and " << u2 << " is " << *ptr1 + *ptr2 << endl;

    displayArray(nums, size);
}

int askUser(int size, int count)
{
    int userNum; //stores user entry

    //Asks the user for a number, and changes message based on count
    switch (count)
    {
    case 1:
        cout << "\nPlease enter a number between 1-" << size << ": ";
        break;
    case 2:
        cout << "\nPlease enter another number between 1-" << size << ": ";
        break;
    case 3:
        cout << "\nPlease enter one more number between 1-" << size << ": ";
        break;
    }

    cin >> userNum;

    //data validation
    while (userNum < 1 || userNum > size)
    {
        cout << "\nPlease try again. The number should be between 1-" << size << ": ";
        cin >> userNum;
    }
    return userNum;
}

void displayResult(int userValue, int nums[], int size)
{
    int index = userValue - 1; //convert element to index
    cout << "Element " << userValue << " is at index " << index << "." << endl;
    cout
        << "That index's address is " << &nums[index] << endl;
    cout << "The value stored there is " << nums[index] << endl;
}

void displayArray(int nums[], int size)
{
    cout << "The array's values and addresses: " << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << "Element " << i + 1 << " holds a value of " << nums[i] << " at memory address " << &nums[i] << "." << endl;
    }
}