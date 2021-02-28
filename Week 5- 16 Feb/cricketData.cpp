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

    mostMatches(sNamesPtr, iMatchesPtr, numStudents);

    return 0;
}

//Function definitions
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

void display(const string names[], const int matches[], int size)
{
    cout << "You entered:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << names[i] << " played " << matches[i] << " matches." << endl;
    }
}

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
double mean(const int matches[], int num)
{
    static int sum;
    double mean = static_cast<double>(sum) / num;

    for (int i = 0; i < num; i++)
    {
        sum += matches[i];
    }

    return mean;
}

void sortStudents(string names[], int matches[], int size)
{
}