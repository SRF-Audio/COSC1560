//****************************************************************************************************
//
// File: ProperEnglish.cpp
// Student: Stephen Froeber
// Assignment: 9
// Course Name: Programming II
// Course Number: COSC 1560
// Due: 2 April, 2020
//
// British to American English translator
//
// Other files required:
// 1.
//
//****************************************************************************************************

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

//structure declarations
struct Translation
{
    string american;
    string english;
};
struct Date
{
    int day;
    int month;
    int year;
};
struct Person
{
    char name[20];
    double score;
    Date testTaken;
};

//function prototypes
Translation *readTranslation(const string &filename, int &num);
Person *readTesters(const string &filename, int &num);
void takeTest(const Translation t[], int numT, Person &p);
void testingOptions(const Translation t[], int numT, Person people[], int numP);
void displayTesters(const Person p[], int numP);
void writeTesters(const string &filename, const Person p[], int numP);

int main()
{
    //file data

    string translateName = "Translation.txt";
    string testersName = "Testers.txt";
    int translateNum;
    int testerNum;
    Translation *translatePtr;
    Person *testersPtr;

    translatePtr = readTranslation(translateName, translateNum);
    testersPtr = readTesters(testersName, testerNum);

    return 0;
}

//function definitions

/*
The ‘Translation.txt’ filenameis passed as an argument, and is openedin the function.The first line of the file is read and a dynamically allocatedarray is created.The information in the file is read, and stored in the array.The array is then returned from the function.The number of translations is passed back as the second argument.
*/
Translation *readTranslation(const string &filename, int &num)
{
    //open the file, get the number from the first line, and dynamically allocate the size of the array
    fstream translation;
    translation.open(filename, ios::in);
    translation >> num;
    Translation *ptr = nullptr;
    ptr = new Translation[num];

    for (int i = 0; i < num; i++)
    {
        getline(translation, ptr[i].american, ',');
        getline(translation, ptr[i].english, '\n');
    }
    translation.close();
    return ptr;
}

/*
The ‘Testers.txt’ filenameis passed as an argument, and is openedin the function.The first line of the file is read and a dynamically allocatedarray is created.The information in the file is read, and stored in the array.The array is then returned from the function.The number of testers is passed back as the second argument.
*/
Person *readTesters(const string &filename, int &num)
{

    //open the file, get the number from the first line, and dynamically allocate the size of the array
    fstream testers;
    Person *testPtr = nullptr;
    string tempName;
    testers.open(filename, ios::in);
    testers >> num;

    //checkpoint
    cout << num << endl;

    testPtr = new Person[num];

    // for (int i = 0; i < num; i++)
    // {
    //Get the name as a string, and convert to characters

    getline(testers, tempName);
    cout << tempName << endl;

    // char charName[tempName.length() + 1];
    // strcpy(charName, tempName.c_str());

    // for (int i = 0; i < sizeof(charName); i++)
    // {
    //     cout << charName[i];
    // }

    // strcpy(charName, testPtr[0].name);

    // testers >> testPtr[0].score;
    // cout << testPtr[0].score;
    // testers >> testPtr[0].testTaken.day;
    // testers >> testPtr[0].testTaken.month;
    // testers >> testPtr[0].testTaken.year;
    // // }
    // testers.close();
    return testPtr;
}

/*
The Translation array, the number of translations, and a specific person, are passed as arguments.The person should be asked 5, randomly selected translation questions, chosen from the Translation array.The same question could be asked more than once.The average score achieved by the person will thenbe updatedin ‘p’.
*/
void takeTest(const Translation t[], int numT, Person &p)
{
}

/*
The two arrays, created in the previous two functions,are passed as arguments, along with the numbers in each array.  Prompt the user to enter the current Date, so that it can be usedfor any updates.  Generate three random numbers, in the range 0 to ‘numP-1’.  For each of these numbers, the ‘takeTest’ function should be called for that person.  Their score will then be updatedin the ‘takeTest’ function.  Then their‘testTaken’ datecan be updated.
*/
void testingOptions(const Translation t[], int numT, Person people[], int numP)
{
}

/*
The current information in the Person array should be displayed in a well - designedformat.
*/
void displayTesters(const Person p[], int numP)
{
}

/*
The ‘Testers.txt’ filenameis passed as the firstargument, and is openedfor writingwithin the function.The updated Person array is then written to the file.
*/
void writeTesters(const string &filename, const Person p[], int numP)
{
}
