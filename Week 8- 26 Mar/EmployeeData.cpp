//****************************************************************************************************
//
// File: EmployeeData.cpp
// Student: Stephen Froeber
// Assignment: 8
// Course Name: Programming II
// Course Number: COSC 1560
// Due: 26 Mar 2021
//
// Reads structures from a file and writes them.
//
// Other files required:
// 1. EmployeeData.txt
//
//****************************************************************************************************

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//structure declarations
struct Date
{
    int Day;
    int Month;
    int Year;
};

struct Employee
{
    string Name;
    int Age;
    Date DateEmployed;
};

//function prototypes
Employee *readEmployees(const string &empFile, int &numEmps);
void displayEmployees(const Employee emps[], int numEmps);
void dateFormatter(const Date date);
Employee *inputEmployees(Employee *emps, int &numEmps);
void outputEmployees(const string empFile, Employee *emps, int numEmps);

int main()
{
    //declarations
    Employee *emp = nullptr;          //for dynamic allocation
    string empFile = "Employees.txt"; //filename
    int numEmps;                      //stores how many employess are in the file
    Employee *userEmps = nullptr;

    emp = readEmployees(empFile, numEmps);
    displayEmployees(emp, numEmps);
    userEmps = inputEmployees(emp, numEmps);
    displayEmployees(userEmps, numEmps);
    delete emp;
    delete userEmps;
}

//function definitions

/*
The first argument, ‘empFile’, is the name of the file, passed as an argument when the function is called.  The second argument, ‘numEmps’, should be assigned the number of employees read from the file.  The function should return a pointer to the array allocated to store the employees read from the file.
*/
Employee *readEmployees(const string &empFile, int &numEmps)
{
    //declarations
    fstream f;
    Employee *p;    //dynamic pointer
    string tempNum; //to convert string numbers to ints

    //function start
    f.open(empFile, ios::in);

    //read the number of emps stored in file and dynamically allocate the array
    tempNum = f.get();
    numEmps = stoi(tempNum);

    p = new Employee[numEmps];
    cout << "The current size of employee array is" << sizeof(*p) << endl;
    string tempNums; //temporarily store string numbers for conversion

    //populate the array
    for (int i = 0; i < numEmps; i++)
    {
        getline(f, p[i].Name, ',');
        getline(f, tempNums, ',');
        p[i].Age = stoi(tempNums);
        getline(f, tempNums, '/');
        p[i].DateEmployed.Day = stoi(tempNums);
        getline(f, tempNums, '/');
        p[i].DateEmployed.Month = stoi(tempNums);
        getline(f, tempNums, '\n');
        p[i].DateEmployed.Year = stoi(tempNums);
    }
    f.close();
    return p;
}

/*
Display all employees in the first argument.  The number of employees is passed as the second argument.
*/
void displayEmployees(const Employee emps[], int numEmps)
{
    cout << left << setw(25) << "NAME" << left << setw(10) << "AGE"
         << "DATE EMPLOYED" << endl;
    for (int i = 0; i < numEmps; i++)
    {
        cout << left << setw(25) << emps[i].Name << left << setw(10) << emps[i].Age;
        dateFormatter(emps[i].DateEmployed);
        cout << endl;
    }
}

void dateFormatter(const Date date)
{
    cout << date.Day << "/" << date.Month << "/" << date.Year;
}

/*
Input new employee details from the user.  A pointer to the existing array of employees is passed as the first argument.  The second argument is thenumber of existing employees.  The function should update ‘numEmps’ and return a pointer to the newly-created array storing all employees.
*/
Employee *inputEmployees(Employee *emps, int &numEmps)
{
    Employee *newEmps;
    char userInput;  //For the yes or no choice
    string userDate; //For date entry
    int oldSize;
    cout << "\n Do you need to add more employees to the list (y/n)? ";
    cin >> userInput;
    toupper(userInput);

    //validation
    while (userInput == !'Y' && userInput == !'N')
    {
        cout << "\nPlease enter y or n: ";
        cin >> userInput;
        toupper(userInput);
    }

    if (userInput == 'Y')
    {

        int numEmpAdds;
        cout << "\nHow many additional employees do you need to enter? ";
        cin >> numEmpAdds;

        //validation
        while (numEmpAdds < 1)
        {
            cout << "\nYou must enter a positive number: ";
        }

        //store the old size, and add to the user input for new total size
        oldSize = numEmps;
        numEmps += numEmpAdds;
        newEmps = new Employee[numEmps];

        //enter the current data
        for (int i = 0; i < oldSize; i++)
        {
            emps[i] = newEmps[i];
        }

        //get new user data
        cout << "\nPlease enter the information for new employees. EMPLOYED should be entered in DDMMYYYY format with no slashes." << endl;

        for (int i = oldSize + 1; i < numEmps; i++)
        {
            cout << setw(10) << "\nNAME:";
            getline(cin, newEmps[i].Name);
            cout << setw(10) << "\nAGE:";
            cin >> newEmps[i].Age;
            cout << setw(10) << "\nEMPLOYED:";
            getline(cin, userDate);
            //validation
            while (userDate.length() == !8)
            {
                cout << "\nDate should be entered in DDMMYYYY format with no slashes.";
                getline(cin, userDate);
            }
            string tempNums;

            tempNums = userDate.substr(0, 2);
            newEmps[i]
                .DateEmployed.Day = stoi(tempNums);
            tempNums = userDate.substr(2, 2);
            newEmps[i].DateEmployed.Month = stoi(tempNums);
            tempNums = userDate.substr(4, 4);
            newEmps[i].DateEmployed.Year = stoi(tempNums);
        }
    }
    else
    {
        cout << "Thank you. The file has been saved." << endl;
        newEmps = emps;
    }

    return newEmps;
}

//TODO: write the new data to the file, delete pointers, and close it.
void outputEmployees(const string &empFile, Employee *emps, int &numEmps)
{
    fstream f;
    f.open(empFile, ios::out);

    f.write(reinterpret_cast<char *>(numEmps), sizeof(emps));
    f.write(reinterpret_cast<char *>(&emps[0]), sizeof(emps));
    f.close();
}