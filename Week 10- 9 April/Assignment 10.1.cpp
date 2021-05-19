//****************************************************************************************************
//
// File: ProperEnglish.cpp
// Student: Stephen Froeber
// Assignment: 10.1
// Course Name: Programming II
// Course Number: COSC 1560
// Due: 9 April, 2020
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

using namespace std;

struct Person
{
    string name;
    string nums;
};

int main()
{
    string txt = "Testers.txt",
           dat = "Testers.dat";
    fstream t(txt), d(dat);
    int size;
    Person p[size];
    t.open(txt, ios::in);
    if (t)
    {
        t >> size;
        while (t)
        {
            for (int i = 0; i < size; i++)
            {
                getline(t, p[i].name);
                getline(t, p[i].nums);
            };
        }
    }

    t.close();

    d.open(dat, ios::out | ios::binary);
    d.write(reinterpret_cast<char *>(size), sizeof(size));
    d.write(reinterpret_cast<char *>(p), sizeof(p) * size);
    d.close();
}