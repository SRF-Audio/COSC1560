//****************************************************************************************************
//
// File: cricketData.cpp
// Student: Stephen Froeber
// Assignment: 5.1
// Course Name: Programming II
// Course Number: COSC 1560
// Due: 16 Feb, 2021
//
//
//
//
//
//
//****************************************************************************************************

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//declarations
void input(string[], int[], int);
void display(const string[], const int[], int);
void mostMatches(const string[], const int[], int);
double mean(const int[], int);
void sortStudents(string[], int[], int);

//program start
int main()
{
    int numStudents; //Dynamic value from user
    string *sNamesPtr = nullptr;
    int *iMatchesPtr = nullptr;
    double average;

    //program title
    cout << "Cricket Matches in a Year" << endl;
    cout << "Please enter how many students were surveyed on their cricket activities." << endl;
    cout << "(Note- you will be asked to enter a name, and number of cricket matches for each student): ";
    cin >> numStudents;
    cin.get();
    //data validation
    while (numStudents < 1)
    {
        cout << "\nPlease enter a positive number of students: ";
        cin >> numStudents;
    }

    //Dynamic memory allocation
    sNamesPtr = new string[numStudents]; //holds user inputted names
    iMatchesPtr = new int[numStudents];  //holds user inputted matches

    input(sNamesPtr, iMatchesPtr, numStudents); //pass the DMA ptr's to be filled

    display(sNamesPtr, iMatchesPtr, numStudents); //display what the user just entered

    mostMatches(sNamesPtr, iMatchesPtr, numStudents); //calculate and display most matches

    average = mean(iMatchesPtr, numStudents);
    cout << "\nThe mean number of matches played by all students is " << average << " matches." << endl;

    sortStudents(sNamesPtr, iMatchesPtr, numStudents); //sort the names and matches

    display(sNamesPtr, iMatchesPtr, numStudents); //display the sorted array

    return 0;
}

//Function definitions
// Allow the user to enter the nameof each student and number of cricket matches played by thatstudentand store this information in the twoarrays.
void input(string names[], int matches[], int size)
{
    //function intro
    cout << "\nYou entered " << size << " students. Let's gather their data." << endl;

    //input loop
    for (int i = 0; i < size; i++)
    {
        //name input
        cout << "\nPlease enter the name of student " << i + 1 << ": ";
        getline(cin, names[i]);

        //matches input
        cout << "\nPlease enter the number of matches that " << names[i] << " played: ";
        cin >> matches[i];

        //data validation
        while (matches[i] < 0)
        {
            cout << "\nPlease enter a positive number of matches: ";
            cin >> matches[i];
        }
        cin.get();
    }
}

//display names of students and number of matches each has played
void display(const string names[], const int matches[], int size)
{
    cout << "\nCurrent List:" << endl;
    //display loop
    for (int i = 0; i < size; i++)
    {
        cout << names[i] << " played " << matches[i] << " matches." << endl;
    }
}

//Display the name of the student who played the most cricket matches in the year, and the number of matches they played.
void mostMatches(const string names[], const int matches[], int size)
{
    int most = 0,
        index;
    for (int i = 0; i < size; i++)
    {
        if (matches[i] > most)
        {
            most = matches[i];
            index = i;
        }
    }
    cout << "Of the students you entered, " << names[index] << " played the most matches, with " << most << " total matches.";
}

//The function should determine the meanof the array, and return this valueas type double.
double mean(const int matches[], int num)
{
    static int sum = 0;

    for (int i = 0; i < num; i++)
    {
        sum += matches[i];
    }

    double mean = static_cast<double>(sum) / num;
    return mean;
}

void sortStudents(string names[], int matches[], int size)
{
    int minIndex, minValue; //will store array index, and the value of matches
    string minName;         //stores the names

    for (int start = 0; start < size - 1; start++)
    {
        minIndex = start;
        minValue = matches[start];
        minName = names[start];
        for (int index = start + 1; index < size; index++)
        {
            if (names[index] < minName)
            {
                minName = names[index];
                minValue = matches[index];
                minIndex = index;
            }
        }
        swap(names[minIndex], names[start]);
        swap(matches[minIndex], matches[start]);
    }
}