//****************************************************************************************************
//
// File: wordCounter.cpp
// Student: Stephen Froeber
// Assignment: 6.1
// Course Name: Programming II
// Course Number: COSC 1560
// Due: 23 Feb
//
// This program asks the user for 3 sentences, and then counts up the words in each sentence.
//****************************************************************************************************

#include <iostream>
#include <string>
using namespace std;

//declarations
int numberWords(const char *words, int size);
void periodValidator(char *userSentence, int &length, int ARRAY_SIZE);
void displayWords(int numWords);

int main()
{
    //memory location for dynamic allocation
    char *ptr = nullptr;
    int length, numWords;      //stores array size, and the number of words
    const int ARRAY_SIZE = 50; //max length

    //first round
    cout << "Please enter a sentence, less than " << ARRAY_SIZE - 1 << " characters, and end it with a period: ";
    ptr = new char[ARRAY_SIZE];               //Dynamically create C string
    cin.getline(ptr, ARRAY_SIZE);             //user input
    length = strlen(ptr);                     //get the length that they just entered.
    periodValidator(ptr, length, ARRAY_SIZE); //make sure they followed directions
    numWords = numberWords(ptr, length);      //count them up
    displayWords(numWords);                   //spit them out
    delete ptr;                               //No memory leakage allowed

    //second round
    cout << "\nPlease enter another sentence, less than " << ARRAY_SIZE - 1 << " characters, and end it with a period: ";
    ptr = new char[ARRAY_SIZE];               //Dynamically create C string
    cin.getline(ptr, ARRAY_SIZE);             //user input
    length = strlen(ptr);                     //get the length that they just entered.
    periodValidator(ptr, length, ARRAY_SIZE); //make sure they followed directions
    numWords = numberWords(ptr, length);      //count them up
    displayWords(numWords);                   //spit them out
    delete ptr;                               //No memory leakage allowed

    //Third round
    cout << "\nPlease enter one more sentence, less than " << ARRAY_SIZE - 1 << " characters, and end it with a period: ";
    ptr = new char[ARRAY_SIZE];               //Dynamically create C string
    cin.getline(ptr, ARRAY_SIZE);             //user input
    length = strlen(ptr);                     //get the length that they just entered.
    periodValidator(ptr, length, ARRAY_SIZE); //make sure they followed directions
    numWords = numberWords(ptr, length);      //count them up
    displayWords(numWords);                   //spit them out
    delete ptr;                               //No memory leakage allowed

    return 0;
}

void periodValidator(char *ptr, int &length, int ARRAY_SIZE)
{
    //make sure there's a period at the end.
    while (ptr[length - 1] != '.')
    {
        cout << "\nYou must end the sentence with a period. Try again: ";
        cin.getline(ptr, ARRAY_SIZE);
        length = strlen(ptr);
    }
}

int numberWords(const char *words, int size)
{
    int wordCount = 0;
    for (int i = 0; i < size; i++)
    {
        if (isspace(words[i]) || words[i] == '.')
        {
            wordCount++;
        }
    }
    return wordCount;
}

void displayWords(int numWords)
{
    cout << "\nThe sentence you entered has " << numWords << " words.";
}