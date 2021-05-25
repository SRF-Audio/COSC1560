//****************************************************************************************************
//
// File: Sport.cpp
// Student: Stephen Froeber
// Assignment: 12
// Course Name: Programming II
// Course Number: COSC 1560
// Due: April 16
//
//
// This program manages data for a Sport, using classes and structures
//
//
//
//****************************************************************************************************

#include <iostream>

#include "Sport.h"

void moveOn();

void displaySports(Sport sports[], const int size);
void sportOperations(Sport sports[], const int size);
void averageNumTeams(Sport sports[], const int size);
void orderSports(Sport sports[], const int size);
void swap(Sport &a, Sport &b);

//main program
int main()
{
    int size;

    cout << "Welcome to the Sport Database" << endl;
    cout << "How many sports do you need to enter? ";
    cin >> size;
    Sport sports[size];
    sportOperations(sports, size);
}

/*
definitions
*/

void moveOn()
{
    string pause;
    cout << "\nPress Enter to Continue." << endl;
    getline(cin, pause);
}

void averageNumTeams(Sport sports[], const int size)
{
    static int numTeams, average;
    for (int i = 0; i < size; i++)
    {
        numTeams += sports[i].getTeams();
    }
    average = numTeams / size;
    cout << "The average number of teams in the database is " << average << ".";
}

void displaySports(Sport sports[], const int size)
{
    Sport *p = sports;
    for (int i = 0; i < size; i++)
    {
        (p + i)->displaySport();
    }
}

void orderSports(Sport sports[], const int size)
{
    GameDate recentDate = sports[0].getNextGameDate();

    int index;

    for (int i = 1; i < size; i++)
    {
        if (recentDate.year >= sports[i].getNextGameDate().year)
        {
            if (recentDate.month >= sports[i].getNextGameDate().month)
            {
                if (recentDate.day > sports[i].getNextGameDate().month)
                {
                    swap(sports[i - 1], sports[i]);
                }
            }
        }
    }
}

void swap(Sport &a, Sport &b)
{
    Sport temp = a;
    a = b;
    b = temp;
}

void sportOperations(Sport sports[], const int size)
{
    bool exit = false;
    int menuChoice;

    //menu loop
    while (!exit)
    {
        //menu text
        cout << endl;
        cout << "Please choose from the following:" << endl;
        cout << "1) Enter all data for a new group of sports." << endl;
        cout << "2) See all current sports data." << endl;
        cout << "3) Edit data for a single sport." << endl;
        cout << "4) See data for a single sport." << endl;
        cout << "5) See the average number of teams for all sports." << endl;
        cout << "6) See the next scheduled sport." << endl;
        cout << "7) See sport info for every sport." << endl;
        cout << "8) Exit the Program" << endl;
        cout << "Enter your choice (1-8): ";
        cin >> menuChoice;
        cout << endl;

        switch (menuChoice)
        {
        case 1:
        {
            for (int i = 0; i < size; i++)
            {
                sports[i].setAllSportData();
            }
            moveOn();
            break;
        }

        case 2:
        {
            for (int i = 0; i < size; i++)
            {
                sports[i].displaySport();
            }
            moveOn();
            break;
        }

        case 3:
        {
            int sportNum = 0; //stores the user's choice

            cout << "Which sport do you want to edit?" << endl;
            for (int i = 0; i < size; i++)
            {
                cout << i + 1 << ") " << sports[i].getSportName() << endl;
            }
            cin >> sportNum;

            //validate the choice
            while (sportNum > size || sportNum < size)
            {
                cout << "That's not a valid choice. Please pick a sport from the list: ";
                cin >> sportNum;
            }

            //edit the sport
            sports[sportNum - 1].setAllSportData();
            moveOn();
            break;
        }

        case 4:
        {
            int sportNum = 0; //stores the user's choice

            cout << "Which sport do you want to see?" << endl;
            for (int i = 0; i < size; i++)
            {
                cout << i + 1 << ") " << sports[i].getSportName() << endl;
            }
            cin >> sportNum;

            //validate the choice
            while (sportNum > size || sportNum < size)
            {
                cout << "That's not a valid choice. Please pick a sport from the list: ";
                cin >> sportNum;
            }

            //edit the sport
            sports[sportNum - 1].displaySport();
            moveOn();
            break;
        }

        case 5:
        {

            int sum = 0;

            for (int i = 0; i < size; i++)
            {
                sum += sports[i].getTeams();
            }

            double average = static_cast<double>(sum) / size;
            cout << "\nThe average number of teams for each sport is " << average << endl;
            moveOn();
            break;
        }

        case 6:
        {
            int lowestYear = sports[0].getNextGameDate().year, lowestYearIndex = 0, lowestMonth = 0, lowestMonthIndex = sports[0].getNextGameDate().month, lowestDay = sports[0].getNextGameDate().day, lowestDayIndex = 0;

            for (int i = 1; i < size; i++)
            {
                if (sports[i].getNextGameDate().year < lowestYear)
                {
                    lowestYear = sports[i].getNextGameDate().year;
                    lowestYearIndex = i;
                }
            }
            for (int i = lowestYearIndex; i < size; i++)
            {
                if (sports[i].getNextGameDate().month < lowestMonth)
                {
                    lowestMonth = sports[i].getNextGameDate().month;
                    lowestMonthIndex = i;
                }
            }
            for (int i = lowestMonthIndex; i < size; i++)
            {
                if (sports[i].getNextGameDate().day < lowestDay)
                {
                    lowestDay = sports[i].getNextGameDate().day;
                    lowestDayIndex = i;
                }
            }
            cout << "The sport with the next scheduled game date is " << sports[lowestDayIndex].getSportName();
            moveOn();
            break;
        }

        case 7:
        {
            displaySports(sports, size);
            break;
        }

        case 8:
        {
            exit = true;
            break;
        }

        default:
        {
            cout << "\nThat's not a valid choice.";
            break;
        }
        }
    }
}
