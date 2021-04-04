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
    bool isNumber = true;
    int numDigits = 10;
    //populate the structure array with the user selected number of speakers
    for (int i = 0; i < userSpeakers; i++)
    {
        int userDisplay = i + 1;
        cout << "\nPlease enter the data for Speaker " << userDisplay << ": " << endl;

        //name block
        cout << "Speaker " << userDisplay << "'s name: ";
        cin.clear();
        getline(cin, speakerList[i].name);
        cin.ignore();

        //name validation

        if (speakerList[i].name.length() != numDigits)
        {
            while (speakerList[i].name.length() != numDigits)
            {
                cout << "\nYou must enter a name: ";
                cin.clear();
                getline(cin, speakerList[i].name);
                cin.ignore();
            }
        }

        //Phone Number block
        cout << "\nEnter " << speakerList[i].name << "'s phone number (enter 10 digits, with no dashes or hyphens): ";
        cin.clear();
        getline(cin, speakerList[i].phoneNumber);
        cin.ignore();

        //Phone number validation block

        //test for the correct number of digits
        if (speakerList[i].phoneNumber.length() != numDigits)
        {
            while (speakerList[i].phoneNumber.length() != numDigits)
            {
                cout << "\nPlease enter exactly 10 digits, with no spaces, hyphens, or parentheses: ";
                cin.clear();
                getline(cin, speakerList[i].phoneNumber);
                cin.ignore();
            }
        }
        //test to make sure they are numbers
        for (int j = 0; j < speakerList[i].phoneNumber.length(); j++)
        {
            if (!isdigit(speakerList[i].phoneNumber.at(j)))
            {
                int temp;
                while (!isdigit(speakerList[i].phoneNumber.at(j)))
                {
                    cout << "\nCharacter " << j + 1 << " is not a number. Enter the correct number: ";
                    cin.clear();
                    cin >> temp;
                }
                speakerList[i].phoneNumber.replace(j, 1, temp);
            }
        }

        //US phone number formatter
        speakerList[i].phoneNumber.insert(0, "(");
        speakerList[i].phoneNumber.insert(4, ")");
        speakerList[i].phoneNumber.insert(9, "-");
        // Outputs: (314) 308-1307
    }
}
