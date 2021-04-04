//****************************************************************************************************
//
// File: speakersBurear.cpp
// Student: Stephen Froeber
// Assignment: 7.1
// Course Name: Programming II
// Course Number: COSC 1560
// Due: 19 March
//
// Stores arrays of Speakers, and allows the user to enter, display and edit them.
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

void dataEntry(Speaker speakerList[], const int SPEAKERS, int &userSpeakers);           //populate the full array of Speakers
void changeSpeaker(Speaker speakerList[], const int userSpeakers, string userEditName); //Edit details of one speaker

void nameValidator(Speaker speakerList[]); //make sure names are not empty

int main()
{
    cout << "Speaker's Bureau Database" << endl;

    //create the storage mechanism for users to edit speakers
    const int SPEAKERS = 10;       //max Speakers
    Speaker speakerList[SPEAKERS]; //storage array
    int userSpeakers;              //custom number of speakers
    string userEditName;           //for editing a particular speaker

    //get user input and validate that it's not zero
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

    cout << "\nThe database currently has the following speakers:" << endl;
    for (int i = 0; i < userSpeakers; i++)
    {
        cout << speakerList[i].name << endl;
    }
    cout << "Which Speaker would you like to edit? " << endl;
    cin.clear();
    getline(cin, userEditName);

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

        nameValidator(speakerList[], i);

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

Each function shouldaccept an array as the firstargument.  In the first function, the second argument is the current size of the array.  In the other functions, the second argument is the number of speakers currently stored in the array.  Additional arguments may be needed for some functions.

ii)Change the contents fora particular speaker who is already stored in the array.The name of the speaker being updated will be passed as the third argument.
*/

void changeSpeaker(Speaker speakerList[], const int userSpeakers, string userEditName)
{
    int editPosition;

    for (int i = 0; i < userSpeakers; i++)
    {
        if (speakerList[i].name.compare(userEditName) == 0)
        {
            editPosition = i;
        }
    }
    cout << "\nEnter the new name for Speaker " << editPosition + 1 << ": ";
    cin.clear();
    getline(cin, speakerList[editPosition].name);
    cout << "\nEnter the new phone number for Speaker " << editPosition + 1 << ": ";
    cin.clear();
    getline(cin, speakerList[editPosition].phoneNumber);
    cout << "\nEnter the new topic for Speaker " << editPosition + 1 << ": ";
    cin.clear();
    getline(cin, speakerList[editPosition].topic);
    cout << "\nEnter the new fee for Speaker " << editPosition + 1 << ": $";
    cin.clear();
    cin >> speakerList[editPosition].fee;
}

/*
iii)Display a specific speaker’s information.The name of the speaker to be displayed will be passed as the third argument.

iv)Displaythe people speaking about a specific topic.The name of the specific topic should be passed as the third argument.  All speakers whoare speaking about this topicshould be displayed.  If no speakers are speaking about this topic thenan appropriate message should be displayed.

v)Display all the data stored in the array.
*/

//validators
void nameValidator(Speaker speakerList[], int position)
{
    //name validation
    while (speakerList[position].name.length() == 0)
    {
        cout << "\nYou must enter a name: ";
        cin.clear();
        getline(cin, speakerList[position].name);
    }
}