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
// 1.Testers.txt
// 2.Translation.txt
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

    takeTest(translatePtr, translateNum, testersPtr[3]);

    testingOptions(translatePtr, translateNum, testersPtr, testerNum);
    displayTesters(testersPtr, testerNum);
    writeTesters(testersName, testersPtr, testerNum);
    /*TODO




    */

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
The ‘Testers.txt’ filenameis passed as an argument, and is opened in the function. The first line of the file is read and a dynamically allocated array is created. The information in the file is read, and stored in the array. The array is then returned from the function.The number of testers is passed back as the second argument.
*/
Person *readTesters(const string &filename, int &num)
{

    //open the file, get the number from the first line, and dynamically allocate the size of the array
    fstream testers;
    Person *testPtr = nullptr;
    testers.open(filename, ios::in);
    testers >> num;
    testers.get();

    //checkpoint
    cout << num << endl;

    testPtr = new Person[num];

    //loop through text file data
    for (int i = 0; i < num; i++)
    {
        testers.getline(testPtr[i].name, 20);
        testers >> testPtr[i].score;
        testers.get();
        testers >> testPtr[i].testTaken.day;
        testers.get();
        testers >> testPtr[i].testTaken.month;
        testers.get();
        testers >> testPtr[i].testTaken.year;
    }

    testers.close();
    return testPtr;
}

/*
The Translation array, the number of translations, and a specific person, are passed as arguments.The person should be asked 5, randomly selected translation questions, chosen from the Translation array. The same question could be asked more than once. The average score achieved by the person will then be updatedin ‘p’.
*/
void takeTest(const Translation t[], int numT, Person &p)
{
    int userAnswer[5]; //store user answers
    bool correct[5];   //keep track of right/wrong answers
    int correctCount = 0;
    double average; //stores percentage correct

    srand(time(0));

    //Question loop
    for (int i = 0; i < 5; i++)
    {
        int randomNum = rand() % numT + 1;
        cout << "\nWhich is the British word? (Enter the number of your choice)" << endl;
        cout << "1) " << t[randomNum].american << endl;
        cout << "2) " << t[randomNum].english << endl;
        cout << ": ";
        cin >> userAnswer[i];

        while (userAnswer[i] > 2 || userAnswer[i] < 1)
        {
            cout << "\nThat's an invalid choice. Please enter 1 or 2: ";
            cin >> userAnswer[i];
        }
    }

    //Answer loop
    for (int i = 0; i < 5; i++)
    {
        if (userAnswer[i] == 2)
        {
            correct[i] = true;
            correctCount++;
        }

        else
        {
            correct[i] = false;
        }
    }

    //score update
    average = correctCount / static_cast<double>(5);
    p.score = average;
}

/*
The two arrays, created in the previous two functions,are passed as arguments, along with the numbers in each array.  Prompt the user to enter the current Date, so that it can be usedfor any updates.  Generate three random numbers, in the range 0 to ‘numP-1’.  For each of these numbers, the ‘takeTest’ function should be called for that person.  Their score will then be updatedin the ‘takeTest’ function.  Then their‘testTaken’ datecan be updated.
*/
void testingOptions(const Translation t[], int numT, Person people[], int numP)
{
    //get the current date from the user
    Date currentDate;
    cout << "Please enter the current date:" << endl;
    cout << "Day (DD): ";
    cin >> currentDate.day;
    cout << "\nMonth (MM): ";
    cin >> currentDate.month;
    cout << "\nYear (YYYY): ";
    cin >> currentDate.year;

    srand(time(0));
    for (int i = 0; i < 3; i++)
    {
        int randomNum = rand() % numP - 1;
        cout << "\nNow please have person " << randomNum << " take the test:" << endl;
        takeTest(t, numT, people[randomNum]);
        people[randomNum].testTaken.day = currentDate.day;
        people[randomNum].testTaken.month = currentDate.month;
        people[randomNum].testTaken.year = currentDate.year;
    }
}

/*
The current information in the Person array should be displayed in a well - designedformat.
*/
void displayTesters(const Person p[], int numP)
{
    cout << "The testers in the database have the following information:" << endl;
    for (int i = 0; i < numP; i++)
    {
        cout << "\nPerson " << i + 1 << " name: " << p->name << endl;
        cout << "Most recent test score: " << p->score << endl;
        cout << "Test date: " << p->testTaken.day << "/" << p->testTaken.month << "/" << p->testTaken.year;
    }
}

/*
The ‘Testers.txt’ filenameis passed as the firstargument, and is openedfor writingwithin the function.The updated Person array is then written to the file.
*/
void writeTesters(const string &filename, const Person p[], int numP)
{
    //open the file, get the number from the first line, and dynamically allocate the size of the array
    fstream testers;

    testers.open(filename, ios::out);
    testers << numP;
    testers.get();

    //checkpoint
    cout << numP << endl;

    //loop through text file data
    for (int i = 0; i < numP; i++)
    {
        testers << sizeof(p[i].name) << endl;
        testers << p[i].score << ",";
        testers << p[i].testTaken.day << "/";
        testers << p[i].testTaken.month << "/";
        testers << p[i].testTaken.year << endl;
    }

    testers.close();
}