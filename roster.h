//Author: kcmodev
//Date of original submission: 5/12/2020
//Class: WGU C867 Scripting and Programming Applications

#ifndef BOOK_REPO_ROSTER_H
#define BOOK_REPO_ROSTER_H

#pragma once

#include <iostream>
#include <string>

using namespace std;

#include "degree.h"
#include "student.h"

class Roster {
private:
    int index;
    int numStudents;
    Student** classRosterArray; // array of pointers of student objects

public:
    Roster();
    Roster(int numStudents);

//    Student* getStudentAt(int index);
    string getStudentAt(int index);
    void parseData(string data);
    void add(string studentID, string firstName, string lastName,
             string emailAddress, int age, int daysInCourse1,
             int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);

    ~Roster(); // deconstructor
};


#endif //BOOK_REPO_ROSTER_H
