//****************************************************************************************************
//
// File: stringDisplay.cpp
// Student: Stephen Froeber
// Assignment: 6.2
// Course Name: Programming II
// Course Number: COSC 1560
// Due: 23 Feb
//
// This program asks the user for 3 sentences, and then counts up the words in each sentence.
//****************************************************************************************************

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

//declarations
void stringManip(string sentence);

int main()
{
    string sentence = "This is a 101 SAMPLE to demonstrate string processing";

    stringManip(sentence);
}

void stringManip(string sentence)
{
    //a) The size of the string.
    cout << "The length of this sentence is " << sentence.length() << endl;

    //b)The number of letters in the string
    int letterCount;
    for (int i = 0; i < sentence.length(); i++)
    {
        if (isalpha(sentence[i]))
        {
            letterCount++;
        }
    }

    cout << "\nThis sentence has " << letterCount << " letters." << endl;

    //c)The number of digits in the string.
    int digitCount;
    for (int i = 0; i < sentence.length(); i++)
    {
        if (isdigit(sentence[i]))
        {
            digitCount++;
        }
    }

    cout << "\nThis sentence has " << digitCount << " numbers." << endl;

    //d) The number of lower case letters in the string.
    int lowerCaseCount;
    for (int i = 0; i < sentence.length(); i++)
    {
        if (islower(sentence[i]))
        {
            lowerCaseCount++;
        }
    }

    cout << "\nThis sentence has " << lowerCaseCount << " lower case letters." << endl;

    //e) The number of upper case letters in the string
    int upperCaseCount;
    for (int i = 0; i < sentence.length(); i++)
    {
        if (isupper(sentence[i]))
        {
            upperCaseCount++;
        }
    }

    cout << "\nThis sentence has " << upperCaseCount << " upper case letters." << endl;

    //f) The character that is at index 12 of the string

    cout << "\nThe 13th character in this string is " << sentence.at(12) << endl;

    //g) The last character of the string.

    cout << "\nThe last character of the sentence is " << sentence.back() << endl;

    //h) The index of the first ‘s’ in the string

    int sPosition = sentence.find('s', 0);
    cout << "\nThe first instance of the letter 's' in this sentence occurs at index " << sPosition << "." << endl;

    //i) The index of the second ‘s’ in the string.

    cout << "\nThe second instance of the letter 's' in this sentence occurs at index " << sentence.find('s', sPosition + 1) << "." << endl;
}