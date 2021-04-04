//****************************************************************************************************
//
// File: speakersBurear.cpp
// Student: Stephen Froeber
// Assignment: 7.1
// Course Name: Programming II
// Course Number: COSC 1560
// Due: 19 March
//
// This program asks the user to read a file of student data from a disk file and then
//
//
//
//
//****************************************************************************************************

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct Speaker
{
    string name;
    string phoneNumber;
    string topic;
    double fee;
};

void dataEntry(Speaker speakerList[], const int SPEAKERS, int &userSpeakers);

int main()
{
    cout << "Speaker's Bureau Database" << endl;

    //create the storage mechanism for users to edit speakers
    const int SPEAKERS = 10;
    Speaker speakerList[SPEAKERS];
    int userSpeakers;

    //get user input and validate it
    cout << "\nHow many speakers do you have? ";
    cin.clear();
    cin >> userSpeakers;
    cin.ignore();

    while (userSpeakers < 1)
    {
        cout << "\nYou must enter at least one speaker: ";
        cin.clear();
        cin >> userSpeakers;
        cin.ignore();
    }

    dataEntry(speakerList, SPEAKERS, userSpeakers);

    return 0;
}

void dataEntry(Speaker speakerList[], const int SPEAKERS, int &userSpeakers)
{
    int numDigits = 10;
    //populate the structure array with the user selected number of speakers
    for (int i = 0; i < userSpeakers; i++)
    {
        int userDisplay = i + 1;
        cout << "\nPlease enter the data for Speaker " << userDisplay << "- " << endl;

        //name block
        cout << "Speaker " << userDisplay << "'s name: ";
        cin.clear();
        getline(cin, speakerList[i].name);

        //name validation
        while (speakerList[i].name.length() == 0)
        {
            cout << "\nYou must enter a name: ";
            cin.clear();
            getline(cin, speakerList[i].name);
        }

        //Phone Number block
        cout << "\nEnter " << speakerList[i].name << "'s phone number (enter 10 digits, with no dashes or hyphens): ";
        cin.clear();
        getline(cin, speakerList[i].phoneNumber);

        //Phone number validation block
        while (speakerList[i].phoneNumber.length() != numDigits)
        {
            cout << "\nPlease enter exactly 10 digits, with no spaces, hyphens, or parentheses: ";
            cin.clear();
            getline(cin, speakerList[i].phoneNumber);
        }

        //US phone number formatter
        speakerList[i].phoneNumber.insert(0, "(");
        speakerList[i].phoneNumber.insert(4, ")");
        speakerList[i].phoneNumber.insert(9, "-");
        // Outputs: (314)308-1307

        //Topic block
        cout << "\nEnter " << speakerList[i].name << "'s speaking topic(s): ";
        cin.clear();
        getline(cin, speakerList[i].topic);

        //Topic validation
        while (speakerList[i].topic.length() == 0)
        {
            cout << "\nYou must enter a topic: ";
            cin.clear();
            getline(cin, speakerList[i].topic);
        }

        //Fee block
        cout << "\nEnter " << speakerList[i].name << "'s speaking fee: $";
        cin.clear();
        cin >> speakerList[i].fee;

        //fee validation
        while (speakerList[i].fee < 0)
        {
            cout << "\nThe fee must be a positive dollar amount: $";
            cin >> speakerList[i].fee;
        }
    }
}

/* 
To do list:
ii)Change the contents fora particular speaker who is already stored in the array.The name of the speaker being updated will be passed as the third argument.

iii)Display a specific speaker’s information.The name of the speaker to be displayed will be passed as the third argument.

iv)Displaythe people speaking about a specific topic.The name of the specific topic should be passed as the third argument.  All speakers whoare speaking about this topicshould be displayed.  If no speakers are speaking about this topic thenan appropriate message should be displayed.

v)Display all the data stored in the array.
*/