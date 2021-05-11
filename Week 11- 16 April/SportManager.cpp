//****************************************************************************************************
//
// File: SportManager.cpp
// Student: Stephen Froeber
// Assignment: 11
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
#include <string>
using namespace std;

//data structures
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
    Sport();
    void setSportName();
    void setNextGameDate();
    void setTeams();
    void setAllSportData();
    string getSportName() const;
    GameDate getNextGameDate() const;
    int getTeams() const;
    void displaySport() const;
};

//definitions

//constructors
Sport::Sport()
{
    sportName = "<empty>";
    next.day = 0;
    next.month = 0;
    next.year = 0;
    teams = 0;
}

void Sport::setSportName()
{
    string n;

    if (sportName.empty())
    {
        cout << "\nPlease enter the name of the sport: ";
        cin >> n;
    }
    else
    {
        cout << "\nPlease update the name of the sport: ";
        cin >> n;
    }
    //setSportName() validator
    while (n.empty())
    {
        cout << "\nThe name of the sport cannot be blank: ";
        cin >> n;
    }

    sportName = n;
}

void Sport::setNextGameDate()
{
    GameDate d;

    cout << "\nPlease enter the date of the next game (DD MM YYYY)-";
    cout << "\nDay: ";
    cin >> d.day;
    //setNextGameDate() day validator
    while (d.day > 31 || d.day < 1)
    {
        cout << "\nThe day must be a valid calendar date: ";
        cin >> d.day;
    }

    //setNextGameDate() month
    cout << "\nMonth: ";
    cin >> d.month;
    //setNextGameDate() month validator
    while (d.month > 12 || d.month < 1)
    {
        cout << "\nThe month must be between 1-12: ";
        cin >> d.month;
    }

    //setNextGameDate() year
    cout << "\nYear: ";
    cin >> d.year;
    //setNextGameDate() year validator
    while (d.year < 2021)
    {
        cout << "\nThe year must be this year, or in the future: ";
        cin >> d.year;
    }
    next = d;
}

void Sport::setTeams()
{
    int t;
    //setTeams()
    cout << "\nPlease enter the number of teams participating in the sport: ";
    cin >> t;
    //setTeams() validator
    while (t < 1)
    {
        cout << "\nYou must enter at least one team: ";
        cin >> t;
    }
    teams = t;
}

void Sport::setAllSportData()
{

    cout << "\nCreate a New Sport Entry" << endl;

    setSportName();

    setNextGameDate();

    setTeams();
}

string Sport::getSportName() const
{
    return sportName;
}

GameDate Sport::getNextGameDate() const
{
    return next;
}

int Sport::getTeams() const
{
    return teams;
}

void Sport::displaySport() const
{
    //Sport Name block

    cout << "Sport Name: " << sportName << endl;

    //GameDate Block
    if (next.day == 0 && next.month == 0 && next.year == 0)
    {
        cout << "Date of next game: <empty>" << endl;
    }
    else
    {
        cout << "Date of next game: " << next.day << "/" << next.month << "/" << next.year << endl;
    }

    //Teams Block
    if (teams == 0)
    {
        cout << "Number of Teams: <empty>" << endl;
    }
    else
    {
        cout << "Number of Teams: " << teams << endl;
    }
}

/*
declarations
*/

void sportOperations(Sport sports[], const int size);

//main program
int main()
{
    const int SPORT_SIZE = 3;
    Sport sports[SPORT_SIZE];
    cout << "Welcome to Sport Database" << endl;
    sportOperations(sports, SPORT_SIZE);
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

//TODO

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
        cout << "7) Exit the Program" << endl;
        cout << "Enter your choice (1-7): ";
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
