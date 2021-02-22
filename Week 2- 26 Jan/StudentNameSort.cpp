//****************************************************************************************************
//
// File: StudentNameSort.cpp
// Student: Stephen Froeber
// Assignment: 2.2
// Course Name: Programming II
// Course Number: COSC 1560
// Due: 26 Jan 2021
//
// This program reads names from a file and searches and sorts them
//
// Other files required:
// 1. StudentNames.txt – text file of Student data
//
//****************************************************************************************************

#include <iostream>
#include <iomanip>
#include <fstream>
#include <ios>
#include <string>
using namespace std;

//function prototypes
int mainMenu();
void readNames(ifstream &, string[], int);
void displayNames(const string[], int);
int searchNames(const string[], int, const string &);
void bubbleSort(string[], int);
void bubbleSortDescending(string[], int);

//global declarations
const int ARR_SIZE = 10;

//program start
int main()
{
    //declarations
    ifstream inputFile;                         //Stores link to StudentNames.txt
    string names[ARR_SIZE];                     //store names from the file
    string searchName;                          //store the name, input by user
    string namesBubbleSort[ARR_SIZE];           //stores the ascending sort names
    string namesBubbleSortDescending[ARR_SIZE]; //stores the descending sort
    int arrayIndex = -1;                        //store the index position of the found name, default "false"

    //User communication
    cout << "Welcome to the Name Search Application" << endl;

    inputFile.open("StudentNames.txt");

    readNames(inputFile, names, ARR_SIZE);
    inputFile.close();

    displayNames(names, ARR_SIZE);

    cout << "\nPlease enter a name: ";
    cin >> searchName;

    searchNames(names, ARR_SIZE, searchName);

    bubbleSort(names, ARR_SIZE);
    bubbleSortDescending(names, ARR_SIZE);

    return 0;
}

void readNames(ifstream &inputFile, string names[], int numNames)
{
    for (int i = 0; i < numNames; i++)
    {
        getline(inputFile, names[i]);
    }

} //read all names from the file

void displayNames(const string names[], int numNames)
{
    cout << endl;
    cout << "The current names in the database are: " << endl;

    //output loop
    for (int i = 0; i < numNames; i++)
    {
        cout << names[i] << endl;
    }

} //display the names

int searchNames(const string names[], int numNames, const string &name)
{
    bool found = false;
    int index = -1;
    for (int i = 0; i < numNames; i++)
    {
        if (name == names[i])
        {
            found = true;
            index = i;
        }
    }
    return index;
} //if 3rd argument name is found, return the index of the name. Otherwise, return -1.

void bubbleSort(string names[], int numNames)
{
    string maxElement = names[numNames - 1];
    string temp;

    for (int i = numNames - 1; i < numNames; i--)
    {
        if (names[i] > names[i + 1])
        {
            swap(names[i], names[i + 1]);
        }
    }
    displayNames(names, numNames);

} //bubble sort ascending

void bubbleSortDescending(string names[], int numNames)
{
    string maxElement = names[0];
    string temp;

    for (int i = 0; i < numNames; i++)
    {
        if (names[i] < names[i + 1])
        {
            swap(names[i + 1], names[i]);
        }
    }
    displayNames(names, numNames);
} //bubble sort descending