//****************************************************************************************************
//
// File: SportManager.cpp
// Student: Stephen Froeber
// Assignment:
// Course Name: Programming II
// Course Number: COSC 1560
// Due: April 16
//
// This program asks the user to read a file of student data from a disk file and then
// creates an ordered list of students by student id.
//
//
//
//****************************************************************************************************

#include <iostream>
#include <string>
using namespace std;

//data structures and declarations
struct GameDate
{
    int day;
    int month;
    int year;
};

class Sport
{
private:
    string sportName;
    GameDate next;
    int teams;

public:
    void setSportName(string n);
    void setNextGameDate(GameDate d);
    void setTeams(int t);
    void setAllSportData();
    string getSportName() const;
    GameDate getNextGameDate() const;
    int getTeams() const;
    Sport getAllSportData() const;
};

//main program
int main()
{
}

//definitions
void Sport::setSportName(string n)
{
    sportName = n;
}

void Sport::setNextGameDate(GameDate d)
{
    next = d;
}

void Sport::setTeams(int t)
{
    cout << "\nPlease enter the number of teams participating in the sport: ";
    cin >> t;
    while (t < 1)
    {
        cout << "\nYou must enter at least one team: ";
        cin >> t;
    }
    teams = t;
}

void Sport::setAllSportData()
{
    string n;
    GameDate d;

    cout << "Create a Sport Entry" << endl;

    //setSportName()
    cout << "\nPlease enter the name of the sport: ";
    cin >> n;
    //setSportName() validator
    while (n.empty())
    {
        cout << "\nThe name of the sport cannot be blank: ";
        cin >> n;
    }
    setSportName(n);

    //setNextGameDate()
    cout << "\nPlease enter the date of the next game (DD MM YYYY)-";

    cout << "\nDay: ";
    cin >> d.day;
    //setNextGameDate() day validator
    while (d.day > 31 || d.day < 1)
    {
        cout << "\nThe day must be a valid calendar date: ";
        cin >> d.day;
    }
    //setNextGameDate() month validator
    cout << "\nMonth: ";
    cin >> d.month;
    while (d.month > 12 || d.month < 1)
    {
        cout << "\nThe month must be between 1-12: ";
        cin >> d.month;
    }
    //setNextGameDate() year validator
    cout << "\nYear: ";
    cin >> d.year;
    while (d.year < 2021)
    {
        cout << "\nThe year must be this year, or in the future: ";
        cin >> d.year;
    }
}

string Sport::getSportName() const
{
    return sportName;
}

GameDate Sport::getNextGameDate() const
{
    return next;
}

//TODO
int Sport::getTeams() const
{
}

Sport Sport::getAllSportData() const
{
}