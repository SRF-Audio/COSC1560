#ifndef SPORT_H
#define SPORT_H

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
    if (d.day > 31 || d.day < 1)
    {
        d.day = 1;
    }

    //setNextGameDate() month
    cout << "\nMonth: ";
    cin >> d.month;
    //setNextGameDate() month validator
    if (d.month > 12 || d.month < 1)
    {
        d.month = 1;
    }

    //setNextGameDate() year
    cout << "\nYear: ";
    cin >> d.year;
    //setNextGameDate() year validator
    if (d.year < 2021)
    {
        d.year = 2000;
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
    if (t < 1)
    {
        t = 5;
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

#endif
