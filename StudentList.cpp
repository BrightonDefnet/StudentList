/*
 StudentList, Brighton Defnet 2021
 - add a student's information
 - delete a student's information
 - print all students' information
*/
#include <iostream>
#include <vector>
#include <iterator>
#include<bits/stdc++.h>
using namespace std;

//struct for student info
struct student
{
    string firstName;
    string lastName;
    int id;
    float gpa;
};

//add a new student
void addStudent(vector<student*> &reg)
{
    student* newStudent;
    newStudent = new student();
    cout << "enter first name" << endl;
    cin >> newStudent->firstName;
    cout << "enter last name" << endl;
    cin >> newStudent->lastName;
    cout << "enter student ID" << endl;
    cin >> newStudent->id;
    cout << "enter student GPA" << endl;
    cin >> newStudent->gpa;
    reg.push_back(newStudent);
}

//print student info
void printStudent(vector<student*> reg)
{
    vector<student*> profile;
    vector<student*>::iterator itr = reg.begin();
    for(itr = reg.begin(); itr < reg.end(); itr++)
    {
        cout << "student: " << (*itr)->firstName << " " << (*itr)->lastName << endl;
        cout << "ID: " << (*itr)->id << endl;
        cout << "GPA: " << (*itr)->gpa << endl;
        cout << '\n' << endl;
    }
}

//remove a student from the list
void deleteStudent(vector<student*> reg, string studentID)
{
    vector<student*> profile;
    vector<student*>::iterator itr = reg.begin();
    string referenceID;
    int position;
    for(itr = reg.begin(); itr < reg.end(); itr++)
    {
        referenceID = (*itr)->id;
        if(referenceID == studentID)
        {
            position = distance(reg.begin(), itr);
            reg.erase(position); //don't know how to actually delete stuff
        }
    }
}

//main loop
int main()
{
    bool running = true;
    vector<student*> reg;
    string enterID;
    while(running)
    { 
        string action;
        cout << "what would you like do to? (ADD, PRINT, DELETE, QUIT)" << endl;
        cin >> action;
        //actions
        if(action == "ADD") //add student
        {
            cout << '\n' << endl;
            addStudent(reg);
        }
        if(action == "PRINT") //print student information
        {
            cout << '\n' << endl;
            printStudent(reg);
        }
        if(action == "DELETE")
        {
            cout << "enter ID of student to remove" << endl;
            cin >> enterID;
            int studentPosition;
            deleteStudent(reg, enterID);
        }
        if(action == "QUIT") //quit the program
        {
            running = false;
        }
    }
}