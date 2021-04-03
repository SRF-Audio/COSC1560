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
    double feeRequired;
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
    cin >> userSpeakers;

    while (userSpeakers < 1)
    {
        cout << "\nYou must enter at least one speaker: ";
        cin >> userSpeakers;
    }

    dataEntry(speakerList, SPEAKERS, userSpeakers);

    return 0;
}

void dataEntry(Speaker speakerList[], const int SPEAKERS, int &userSpeakers)
{

    //populate the structure array with the user selected number of speakers
    for (int i = 0; i < userSpeakers; i++)
    {
        int userDisplay = i + 1;
        cout << "\nPlease enter the data for Speaker " << userDisplay << ": " << endl;

        //name block
        cout << "Speaker " << userDisplay << "'s name: ";
        getline(cin, speakerList[i].name);

        //name validation
        while (sizeof(speakerList[i].name) == 0)
        {
            cout << "\nYou must enter a name: ";
            getline(cin, speakerList[i].name);
        }

        //Phone Number block
        cout << "Speaker " << userDisplay << "'s phone number (enter 10 digits, no dashes or hyphens): ";
        getline(cin, speakerList[i].phoneNumber);

        //Phone number validation block
        bool numTest = true;
        do
        {
            //test for the correct number of digits
            while (sizeof(speakerList[i].phoneNumber) != 10)
            {
                cout << "\nPlease enter exactly 10 digits, with no spaces, hyphens, or parentheses: ";
                getline(cin, speakerList[i].phoneNumber);
            }
            //test to make sure they are numbers
            while (numTest == false)
            {
                numTest = true;
                for (int j = 0; j <= sizeof(speakerList[i].phoneNumber); j++)
                {
                    if (isdigit(speakerList[i].phoneNumber.at(j) == false))
                    {
                        numTest = false;
                        break;
                    }
                }
                cout << "\nPlease enter exactly 10 digits, with no spaces, hyphens, or parentheses: ";
                getline(cin, speakerList[i].phoneNumber);
            }

        } while (sizeof(speakerList[i].phoneNumber) != 10 || numTest == false);

        //US phone number formatter
        speakerList[i].phoneNumber.insert(0, "(");
        speakerList[i].phoneNumber.insert(3, ") ");
        speakerList[i].phoneNumber.insert(8, "-");
        // Outputs: (314) 308-1307
        cout << speakerList[i].phoneNumber;
    }
}