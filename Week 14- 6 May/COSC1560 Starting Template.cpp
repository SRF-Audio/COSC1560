//****************************************************************************************************
//
// File:
// Student: Stephen Froeber
// Assignment:
// Course Name: Programming II
// Course Number: COSC 1560
// Due:
//
// This program asks the user to read a file of student data from a disk file and then
// creates an ordered list of students by student id.
// Other files required:
// 1. studentFile.txt – text file of Student data
// 2. student.h – definition of the Student struct
//****************************************************************************************************

#ifndef AGENT_H //if not defined
#define AGENT_H

class Agent
{
private:
    string agentName;
    int housesSold;
    string addresses[];

public:
    Agent(string agentName);
    ~Agent();
    void setAgentName();
    void setHousesSold();
    void setAddresses();
    string getAgentName();
    int getHousesSold();
    string getAddresses();
    void displayAgent();
    void populate();
}

Agent::Agent(string agentName)
{
    agentName = empty;
    housesSold = 0;
}

void Agent::populate()
{
    setAgentName();
    setHousesSold();
    setAddresses();
}

#endif

int main()
{
    Agent ian;
    ian.populate();
    ian.displayAgent();
}
