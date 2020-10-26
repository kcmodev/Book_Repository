//Author: kcmodev
//Date of original submission: 5/12/2020
//Class: WGU C867 Scripting and Programming Applications

#ifndef BOOK_REPO_STUDENT_H
#define BOOK_REPO_STUDENT_H

#pragma once

#include <string>
#include "degree.h"
using namespace std;

class Student
{
public:
    const static int numStudents = 5; // number of students in data set
    const static int totalDays = 3; // number of days to be averaged in data set
    int removed = 0;

protected:
    string studentID = "";
    string firstName = "";
    string lastName = "";
    string emailAddress = "";
    int age = 0;
    int numDays[totalDays];
    DegreeProgram degreeProgram;

public:
    Student(); // constructor
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numDays[]); // overloaded constructor

    //setters
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string email);
    void setAge(int age);
    void setDaysToComplete(int numDays[]);
    void printStudentData();

    //getters
    string getStudentID() const;
    string getFirstName() const;
    string getLastName() const;
    string getEmailAddress() const;
    int getAge() const;
    void getDaysToComplete() const;
    virtual DegreeProgram getDegreeProgram() = 0;
    virtual void print() {};

    ~Student(); // deconstructor
};

// security student class
class SecurityStudent : public Student {

// calls constructors from Student class
public:
    SecurityStudent();
    SecurityStudent(string studentID, string firstName, string lastName, string emailAddress,
                    int age, int numDays[], DegreeProgram degreeProgram);

    DegreeProgram getDegreeProgram();
    void print();

    ~SecurityStudent();
};

// networking student class
class NetworkStudent : public Student {

public:
    NetworkStudent();
    NetworkStudent(string studentID, string firstName, string lastName, string emailAddress,
                   int age, int numDays[], DegreeProgram degreeProgram);

    DegreeProgram getDegreeProgram();
    void print();

    ~NetworkStudent();
};

// software student class
class SoftwareStudent : public Student {

public:
    SoftwareStudent();
    SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress,
                    int age, int numDays[], DegreeProgram degreeProgram);

    DegreeProgram getDegreeProgram();
    void print();

    ~SoftwareStudent();
};

#endif //BOOK_REPO_STUDENT_H
