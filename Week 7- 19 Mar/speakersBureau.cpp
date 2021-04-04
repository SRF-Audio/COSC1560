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
#include <iomanip>

using namespace std;

//Structures
struct Speaker
{
    string name;
    string phoneNumber;
    string topic;
    double fee;
};

//Global Variables
const int numDigits = 10; //phone number length for US numbers
const int SPEAKERS = 10;  //max Speakers

//Function prototypes
void dataEntry(Speaker speakerList[], const int SPEAKERS, int &userSpeakers);                  //populate the full array of Speakers
void nameDisplay(Speaker speakerList[], const int &userSpeakers);                              //display current names in the array
void changeSpeaker(Speaker speakerList[], const int userSpeakers, string userEditName);        //Edit details of one speaker
void displaySpeaker(Speaker speakerList[], const int userSpeakers, string displaySpeakerInfo); //display details of one speaker

//validator functions
void nameValidator(Speaker speakerList[], int position);          //Validate names are not empty
void phoneNumberValidator(Speaker speakerList[], int position);   //Validate number of digits
void phoneNumberFormatterUS(Speaker speakerList[], int position); //convert string to US phone number format
void topicValidator(Speaker speakerList[], int position);         //validate topic isn't empty
void feeValidator(Speaker speakerList[], int position);           //validate fee isn't negative

int main()
{
    cout << "Speaker's Bureau Database" << endl;

    //create the storage mechanism for users to edit speakers

    Speaker speakerList[SPEAKERS]; //storage array
    int userSpeakers;              //custom number of speakers
    string userEditName;           //for editing a particular speaker
    string userSpeakerInfo;        //for displaying a particular speaker

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

    nameDisplay(speakerList, userSpeakers);

    cout << "Which Speaker would you like to edit? ";
    cin.clear();
    getline(cin, userEditName);

    changeSpeaker(speakerList, userSpeakers, userEditName);

    nameDisplay(speakerList, userSpeakers);

    cout << "Which Speaker would you like to display information for? ";
    cin.clear();
    getline(cin, userSpeakerInfo);

    displaySpeaker(speakerList, userSpeakers, userSpeakerInfo);

    return 0;
}

/* 
Each function should accept an array as the first argument.  In the first function, the second argument is the current size of the array.  In the other functions, the second argument is the number of speakers currently stored in the array.  Additional arguments may be needed for some functions.
*/

void dataEntry(Speaker speakerList[], const int SPEAKERS, int &userSpeakers)
{

    //populate the structure array with the user selected number of speakers
    for (int i = 0; i < userSpeakers; i++)
    {
        int userDisplay = i + 1;
        cout << "\nPlease enter the data for Speaker " << userDisplay << "- " << endl;

        //name block
        cout << "Speaker " << userDisplay << "'s name: ";
        cin.clear();
        getline(cin, speakerList[i].name);

        nameValidator(speakerList, i);

        //Phone Number block
        cout << "\nEnter " << speakerList[i].name << "'s phone number (enter 10 digits, with no dashes or hyphens): ";
        cin.clear();
        getline(cin, speakerList[i].phoneNumber);

        phoneNumberValidator(speakerList, i);

        phoneNumberFormatterUS(speakerList, i);

        //Topic block
        cout << "\nEnter " << speakerList[i].name << "'s speaking topic(s): ";
        cin.clear();
        getline(cin, speakerList[i].topic);

        topicValidator(speakerList, i);

        //Fee block
        cout << "\nEnter " << speakerList[i].name << "'s speaking fee: $";
        cin.clear();
        cin >> speakerList[i].fee;

        feeValidator(speakerList, i);
    }
}

//Custom function to show a list of names for users to pick
void nameDisplay(Speaker speakerList[], const int &userSpeakers)
{
    cout << "\nThe database currently has the following speakers:" << endl;
    for (int i = 0; i < userSpeakers; i++)
    {
        cout << speakerList[i].name << endl;
    }
}

/*
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
    nameValidator(speakerList, editPosition);

    cout << "\nEnter the new phone number for " << speakerList[editPosition].name << ": ";
    cin.clear();
    getline(cin, speakerList[editPosition].phoneNumber);
    phoneNumberValidator(speakerList, editPosition);

    cout << "\nEnter the new topic for " << speakerList[editPosition].name << ": ";
    cin.clear();
    getline(cin, speakerList[editPosition].topic);
    topicValidator(speakerList, editPosition);

    cout << "\nEnter the new fee for " << speakerList[editPosition].name << ": $";
    cin.clear();
    cin >> speakerList[editPosition].fee;
    feeValidator(speakerList, editPosition);
}

/*
iii)Display a specific speaker’s information.The name of the speaker to be displayed will be passed as the third argument.
*/

void displaySpeaker(Speaker speakerList[], const int userSpeakers, string displaySpeakerInfo)
{
    bool found = false;
    int position;
    for (int i = 0; i < userSpeakers; i++)
    {
        if (speakerList[i].name.compare(displaySpeakerInfo) == 0)
        {
            found = true;
            position = i;
        }
    }
    if (found)
    {
        cout << displaySpeakerInfo << "'s information is:" << endl;
        cout << "Phone Number: " << speakerList[position].phoneNumber << endl;
        cout << "Topic: " << speakerList[position].topic << endl;
        cout << setprecision(2) << fixed << "Fee: $" << speakerList[position].fee << endl;
    }
    else
    {
        cout << displaySpeakerInfo << " is not in the array. Please check the spelling and try again." << endl;
    }
}

/*
iv)Displaythe people speaking about a specific topic.The name of the specific topic should be passed as the third argument.  All speakers whoare speaking about this topicshould be displayed.  If no speakers are speaking about this topic thenan appropriate message should be displayed.

v)Display all the data stored in the array.
*/

//validators
void nameValidator(Speaker speakerList[], int position)
{
    while (speakerList[position].name.length() == 0)
    {
        cout << "\nYou must enter a name: ";
        cin.clear();
        getline(cin, speakerList[position].name);
    }
}

void phoneNumberValidator(Speaker speakerList[], int position)
{
    while (speakerList[position].phoneNumber.length() != numDigits)
    {
        cout << "\nPlease enter exactly 10 digits, with no spaces, hyphens, or parentheses: ";
        cin.clear();
        getline(cin, speakerList[position].phoneNumber);
    }
}

void phoneNumberFormatterUS(Speaker speakerList[], int position)
{
    speakerList[position].phoneNumber.insert(0, "(");
    speakerList[position].phoneNumber.insert(4, ")");
    speakerList[position].phoneNumber.insert(9, "-");
    // Outputs: (314)308-1307
}

void topicValidator(Speaker speakerList[], int position)
{
    while (speakerList[position].topic.length() == 0)
    {
        cout << "\nYou must enter a topic: ";
        cin.clear();
        getline(cin, speakerList[position].topic);
    }
}

void feeValidator(Speaker speakerList[], int position)
{
    //fee validation
    while (speakerList[position].fee < 0)
    {
        cout << "\nThe fee must be a positive dollar amount: $";
        cin >> speakerList[position].fee;
    }
}