//****************************************************************************************************
//
// File: Midterm2.cpp
// Student: Stephen Froeber
// Assignment: Midterm 2
// Course Name: Programming II
// Course Number: COSC 1560
// Due: 23 Feb
//
// This program asks the user for 3 sentences, and then counts up the words in each sentence.
//****************************************************************************************************

#include <iostream>
#include <string>
#include <ctype.h>
#include <stdio.h>
using namespace std;

//Q1
// int main()
// {
//     int array[3] = {5, 2, 6};
//     int *ptr = array;
//     for (int i = 0; i < 3; i++)
//     {
//         cout << "\nElement " << i << " is: " << ptr[i] << endl;
//         cout << "That value is stored at memory address: " << &ptr[i] << endl;
//     }

//     return 0;
// }

// //Q2
// int main()
// {
//     const int numbers[5] = {3, 5, 1, 2, 8};
//     const int *ptr = &numbers[2];
//     cout << *ptr << endl;

//     const int *const ptr2 = &numbers[2];

//     return 0;
// }

//Q3

// void f(int *p1, int *p2, int *&p3)
// {
//     *p2 = *p1 + 3;
//     *p3 = *p1 + 5;
//     p2 = p1;
//     p3 = p1;
//     *p2 = *p1 + 3;
//     *p3 = *p1 + 5;
// }

// int main()
// {
//     int num1 = 10;
//     int num2 = 15;
//     int num3 = 20;

//     int *ptr1 = &num1;
//     int *ptr2 = &num2;
//     int *ptr3 = &num3;

//     f(ptr1, ptr2, ptr3);

//     cout << num1 << endl;
//     cout << num2 << endl;
//     cout << num3 << endl;
//     cout << *ptr1 << endl;
//     cout << *ptr2 << endl;
//     cout << *ptr3 << endl;
//     return 0;
// }

//Q4

// int main()
// {
//     char str[20] = "Num 202";
//     cout << str << endl;
//     cout << strlen(str) << endl;
//     cout << isalnum(str[1]) << endl;
//     cout << isdigit(str[5]) << endl;
//     cout << toupper(str[2]) << endl;
//     cout << str << endl;
//     cout << strcpy(str, "Testing") << endl;
//     cout << str;

//     if (isalpha(str[5]))
//     {
//         cout << "Definitely a letter";
//     }

//     char str1[10] = "A";
//     char str2[10] = "B";

//     if (strcmp(str1, str2) == -1)
//     {
//         cout << "Alphabetical";
//     }

//     return 0;
// }

// //Q5
// int main()
// {
//     string str("COSC 3100");
//     cout << str.size() << endl;

//     cout << str.at(2) << endl;

//     cout << str.back() << endl;

//     cout << str.find('C', 1) << endl;

//     str.append(str, 4, 5);

//     cout << str << endl;

//     return 0;
// }

//Q6

// struct Date
// {
//     int day;
//     int month;
//     int year;
// };

// struct Employee
// {
//     string name;
//     int age;
//     string projects[3];
//     Date joinDate;
// };

// int main()
// {
//     Employee worker;

//     for (int i = 0; i < 3; i++)
//     {
//         cout << "Please enter a project name: " << endl;
//         cin >> worker.projects[i];
//     }

//     cout << worker.joinDate.year;

// }

//Q7

struct Date
{
    int day;
    int month;
    int year;
};

struct Employee
{
    string name;
    int age;
    string projects[3];
    Date joinDate;
};

int main()
{
    Employee worker;

    for (int i = 0; i < 3; i++)
    {
        cout << "Please enter a project name: " << endl;
        cin >> worker.projects[i];
    }

    cout << worker.joinDate.year;

    Employee employees[5];
    cin >> employees[0].name;
}