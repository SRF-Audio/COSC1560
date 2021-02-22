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
    int menuState;                              //stores the user selection for the menu

    //User communication
    cout << "Welcome to the Name Search Application" << endl;

    inputFile.open("StudentNames.txt");

    readNames(inputFile, names, ARR_SIZE);
    inputFile.close();
    menuState = mainMenu();

    //Main Menu Loop
    while (menuState > 1 && menuState < 6)
    {
        switch (menuState)
        {
        case 1:
            displayNames(names, ARR_SIZE);
            menuState = mainMenu();
            break;
        case 2:
            cout << "Please enter a name: ";
            getline(cin, searchName);
            searchNames(names, ARR_SIZE, searchName);
            menuState = mainMenu();
            break;
        case 3:
            bubbleSort(names, ARR_SIZE);
            menuState = mainMenu();
            break;
        case 4:
            bubbleSortDescending(names, ARR_SIZE);
            menuState = mainMenu();
            break;
        case 5:
            cout << "See you later!" << endl;
            break;
        }
    }

    return 0;
}

//function definitions
int mainMenu()
{
    int userChoice; //holds the user's entry
    cout << endl;
    cout << "Main Menu" << endl;
    cout << "Please select from the following:" << endl;
    cout << "1- Display all names currently in the database" << endl;
    cout << "2- Search for a name in the database" << endl;
    cout << "3- Display all names: Ascending" << endl;
    cout << "4- Display all names: Descending" << endl;
    cout << "5- Exit" << endl;
    cout << "Enter your selection: ";
    cin >> userChoice;

    //validate selection
    while (userChoice < 1 || userChoice > 5)
    {
        cout << endl;
        cout << "Please pick a menu option between 1-5: ";
        cin >> userChoice;
        cout << endl;
    }

    return userChoice;
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