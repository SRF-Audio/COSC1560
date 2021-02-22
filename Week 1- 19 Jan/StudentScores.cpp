//****************************************************************************************************
//
// File: StudentScores.cpp
// Student: Stephen Froeber
// Assignment: 1
// Course Name: Programming II
// Course Number: COSC 1560
// Due: 19 Jan 2021
//
// This program reads scores from a file and runs calculations on them.
// Other files required:
// 1. Assignment1Data.txt – text file of Student data
//
//****************************************************************************************************

#include <iostream>
#include <iomanip>
#include <fstream>
#include <ios>
using namespace std;

//array size
const int NUM_STUDENTS = 10; //Rows of students
const int NUM_TESTS = 8;     //columns of tests

//function prototypes
void readTestScores(ifstream &, int[][NUM_TESTS], const int);
void displayTestScores(const int[][NUM_TESTS], const int);
int totalOneTest(const int[][NUM_TESTS], int, int);
int totalOneStudent(const int[][NUM_TESTS], int, int);
double averageOneTest(const int[][NUM_TESTS], int, int);
double averageOneStudent(const int[][NUM_TESTS], int, int);
int highestOneStudent(const int[][NUM_TESTS], int, int);
int topStudent(const int[][NUM_TESTS], int);
void pressEnter();

int main()
{

    //declarations
    ifstream inputFile;
    int testScores[NUM_STUDENTS][NUM_TESTS];

    //program start

    inputFile.open("Assignment1Data.txt");

    readTestScores(inputFile, testScores, NUM_STUDENTS);

    displayTestScores(testScores, NUM_STUDENTS);
    inputFile.close();
    pressEnter();

    totalOneTest(testScores, NUM_STUDENTS, 1);
    pressEnter();

    totalOneTest(testScores, NUM_STUDENTS, 5);
    pressEnter();

    totalOneStudent(testScores, NUM_STUDENTS, 3);
    pressEnter();

    totalOneStudent(testScores, NUM_STUDENTS, 8);
    pressEnter();

    averageOneTest(testScores, NUM_STUDENTS, 5);
    pressEnter();

    averageOneTest(testScores, NUM_STUDENTS, 8);
    pressEnter();

    averageOneStudent(testScores, NUM_STUDENTS, 5);
    pressEnter();

    averageOneStudent(testScores, NUM_STUDENTS, 9);
    pressEnter();

    highestOneStudent(testScores, NUM_STUDENTS, 2);

    return 0;
}

//function defintions

void readTestScores(ifstream &f, int scores[][NUM_TESTS], int numStds)
{
    for (int i = 0; i < numStds; i++)
    {
        for (int j = 0; j < NUM_TESTS; j++)
        {
            f >> scores[i][j];
        }
    }

} //read scores from file and store in array

void displayTestScores(const int scores[][NUM_TESTS], int numStds)
{
    cout << "All Test Scores:" << endl;
    for (int i = 0; i < numStds; i++)
    {
        for (int j = 0; j < NUM_TESTS; j++)
        {
            cout << setw(4) << scores[i][j];
        }
        cout << endl;
    }

} //display all scores in the array

int totalOneTest(const int scores[][NUM_TESTS], int numStds, int testNumber)
{
    int total;
    for (int row = 0; row < numStds; row++)
    {
        total += scores[row][testNumber];
    }

    cout << "Total for Test #" << testNumber << " is: " << total << endl;

    return total;
} //Return the total for the test specified in the third argument

int totalOneStudent(const int scores[][NUM_TESTS], int numStds, int studentNumber)
{
    int total;
    for (int col = 0; col < NUM_TESTS; col++)
    {
        total += scores[studentNumber][col];
    }

    cout << "Total for Student #" << studentNumber << " is: " << total << endl;

    return total;

} //Return the total for the student specified in the third argument

double averageOneTest(const int scores[][NUM_TESTS], int numStds, int testNumber)
{
    double total = (totalOneTest(scores, numStds, testNumber)) / static_cast<double>(numStds);

    cout << "Average for Test #" << testNumber << " is: " << fixed << setprecision(2) << total << endl;

    return total;
} //Return the average for the test specified in the third argument

double averageOneStudent(const int scores[][NUM_TESTS], int numStds, int studentNumber)
{
    double total = (totalOneStudent(scores, numStds, studentNumber)) / static_cast<double>(numStds);

    cout << "Average for Student #" << studentNumber << " is: " << fixed << setprecision(2) << total << endl;

    return total;
} //Return the average for the student specified in the third argument

int highestOneStudent(const int scores[][NUM_TESTS], int numStds, int studentNumber)
{
    int highest = 0;
    for (int i = 0; i < NUM_TESTS; i++)
    {
        if (scores[studentNumber][i] > highest)
        {
            highest = scores[studentNumber][i];
        }
    }
    cout << "Highest test score for Student #" << studentNumber << ": " << highest << endl;
    return highest;
} //Return highest result for the student specified in the third argument

int topStudent(const int scores[][NUM_TESTS], int numStds)
{
    int studentAverage;
    int topStudent = 0;
    for (int rows = 0; rows < numStds; rows++)
    {
        studentAverage = averageOneStudent(scores, numStds, rows);
        if (studentAverage > topStudent)
        {
            topStudent = rows + 1;
        }
    }
    cout << "The top Student: " << topStudent << endl;

    return topStudent;
} //Return the Student number with the highest average test score

void pressEnter()
{
    cout << "Press Enter to Continue" << endl;
    cin.get();
}
