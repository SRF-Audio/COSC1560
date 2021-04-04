//****************************************************************************************************
//
// File: speakersBurearDMA.cpp
// Student: Stephen Froeber
// Assignment: 7.2
// Course Name: Programming II
// Course Number: COSC 1560
// Due: 19 March 2021
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

//Function prototypes
void dataEntry(Speaker speakerList[], const int &userSpeakers);                                         //populate the full array of Speakers
void nameDisplay(Speaker speakerList[], const int &userSpeakers);                                       //display current names in the array
void topicDisplay(Speaker speakerList[], const int &userSpeakers);                                      //display current topics in the array
void changeSpeakerInfo(Speaker speakerList[], const int &userSpeakers, const string &userEditName);     //Edit details of one speaker
void displaySpeakerInfo(Speaker speakerList[], const int &userSpeakers, const string &userSpeakerInfo); //display details of one speaker
void displayTopicInfo(Speaker speakerList[], const int &userSpeakers, const string &userTopicInfo);     //display all speakers with the same topic

//validator functions
void nameValidator(Speaker speakerList[], const int &position);          //Validate names are not empty
void phoneNumberValidator(Speaker speakerList[], const int &position);   //Validate number of digits
void phoneNumberFormatterUS(Speaker speakerList[], const int &position); //convert string to US phone number format
void topicValidator(Speaker speakerList[], const int &position);         //validate topic isn't empty
void feeValidator(Speaker speakerList[], const int &position);           //validate fee isn't negative

int main()
{
    cout << "Speaker's Bureau Database" << endl;

    //create the storage mechanism for users to edit speakers
    Speaker *speakerList = nullptr; //pointer for DAM
    int userSpeakers;               //custom number of speakers
    string userEditName;            //for editing a particular speaker
    string userSpeakerInfo;         //for displaying a particular speaker
    string userTopicInfo;           //for displaying all speakers with a particular topic

    //get user input and validate that it's not zero
    cout
        << "\nHow many speakers do you have? ";
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

    speakerList = new Speaker[userSpeakers];

    dataEntry(speakerList, userSpeakers);

    nameDisplay(speakerList, userSpeakers);

    cout << "Which Speaker would you like to edit? ";
    cin.clear();
    getline(cin, userEditName);
    cin.ignore();

    changeSpeakerInfo(speakerList, userSpeakers, userEditName);

    nameDisplay(speakerList, userSpeakers);

    cout << "Which Speaker would you like to display information for? ";
    cin.clear();
    getline(cin, userSpeakerInfo);

    displaySpeakerInfo(speakerList, userSpeakers, userSpeakerInfo);

    topicDisplay(speakerList, userSpeakers);

    cout
        << "Which topic would you like to display names for? ";
    cin.clear();
    getline(cin, userTopicInfo);

    displayTopicInfo(speakerList, userSpeakers, userTopicInfo);

    delete speakerList;

    return 0;
}

/* 
Each function should accept an array as the first argument.  In the first function, the second argument is the current size of the array.  In the other functions, the second argument is the number of speakers currently stored in the array.  Additional arguments may be needed for some functions.
*/

void dataEntry(Speaker speakerList[], const int &userSpeakers)
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
        cin.ignore();

        nameValidator(speakerList, i);

        //Phone Number block
        cout << "\nEnter " << speakerList[i].name << "'s phone number (enter 10 digits, with no dashes or hyphens): ";
        cin.clear();
        getline(cin, speakerList[i].phoneNumber);
        cin.ignore();

        phoneNumberValidator(speakerList, i);

        phoneNumberFormatterUS(speakerList, i);

        //Topic block
        cout << "\nEnter " << speakerList[i].name << "'s speaking topic(s): ";
        cin.clear();
        getline(cin, speakerList[i].topic);
        cin.ignore();

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

//Custom function to show a list of topics for users to pick
void topicDisplay(Speaker speakerList[], const int &userSpeakers)
{
    cout << "\nThe database currently has the following topics:" << endl;
    for (int i = 0; i < userSpeakers; i++)
    {
        cout << speakerList[i].topic << endl;
    }
}

/*
ii)Change the contents fora particular speaker who is already stored in the array.The name of the speaker being updated will be passed as the third argument.
*/

void changeSpeakerInfo(Speaker speakerList[], const int &userSpeakers, const string &userEditName)
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
    cin.ignore();
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

void displaySpeakerInfo(Speaker speakerList[], const int &userSpeakers, const string &userSpeakerInfo)
{
    bool found = false;
    int position;
    for (int i = 0; i < userSpeakers; i++)
    {
        if (speakerList[i].name.compare(userSpeakerInfo) == 0)
        {
            found = true;
            position = i;
        }
    }
    if (found)
    {
        cout << userSpeakerInfo << "'s information is:" << endl;
        cout << "Phone Number: " << speakerList[position].phoneNumber << endl;
        cout << "Topic: " << speakerList[position].topic << endl;
        cout << setprecision(2) << fixed << "Fee: $" << speakerList[position].fee << endl;
    }
    else
    {
        cout << userSpeakerInfo << " is not in the array. Please check the spelling and try again." << endl;
    }
}

/* 
iv) Display the people speaking about a specific topic.The name of the specific topic should be passed as the third argument.  All speakers whoare speaking about this topicshould be displayed.  If no speakers are speaking about this topic thenan appropriate message should be displayed.
*/

void displayTopicInfo(Speaker speakerList[], const int &userSpeakers, const string &userTopicInfo)
{
    bool found = false;
    cout << "The speakers talking about " << userTopicInfo << " are:" << endl;
    for (int i = 0; i < userSpeakers; i++)
    {
        if (speakerList[i].topic.compare(userTopicInfo) == 0)
        {
            cout << speakerList[i].name << endl;
            if (!found)
            {
                found = true;
            }
        }
    }

    if (!found)
    {
        cout << "No speakers are currently talking about the topic you entered." << endl;
    }
}

/* 
v)Display all the data stored in the array.
*/

void displayAllInfo(Speaker speakerList[], const int &userSpeakers)
{
    cout << endl;
    cout << "Your entire speaker list is as follows:" << endl;
    for (int i = 0; i < userSpeakers; i++)
    {
        cout << "Speaker "
             << i + 1 << "'s information is:" << endl;
        cout << "Name: " << speakerList[i].name << endl;
        cout << "Phone Number: " << speakerList[i].phoneNumber << endl;
        cout << "Topic: " << speakerList[i].topic << endl;
        cout << setprecision(2) << fixed << "Fee: $" << speakerList[i].fee << endl;
    }
}

//validators
void nameValidator(Speaker speakerList[], const int &position)
{
    while (speakerList[position].name.length() == 0)
    {
        cout << "\nYou must enter a name: ";
        cin.clear();
        getline(cin, speakerList[position].name);
    }
}

void phoneNumberValidator(Speaker speakerList[], const int &position)
{
    while (speakerList[position].phoneNumber.length() != numDigits)
    {
        cout << "\nPlease enter exactly 10 digits, with no spaces, hyphens, or parentheses: ";
        cin.clear();
        getline(cin, speakerList[position].phoneNumber);
    }
}

void phoneNumberFormatterUS(Speaker speakerList[], const int &position)
{
    speakerList[position].phoneNumber.insert(0, "(");
    speakerList[position].phoneNumber.insert(4, ")");
    speakerList[position].phoneNumber.insert(9, "-");
    // Outputs: (314)308-1307
}

void topicValidator(Speaker speakerList[], const int &position)
{
    while (speakerList[position].topic.length() == 0)
    {
        cout << "\nYou must enter a topic: ";
        cin.clear();
        getline(cin, speakerList[position].topic);
    }
}

void feeValidator(Speaker speakerList[], const int &position)
{
    //fee validation
    while (speakerList[position].fee < 0)
    {
        cout << "\nThe fee must be a positive dollar amount: $";
        cin >> speakerList[position].fee;
    }
}