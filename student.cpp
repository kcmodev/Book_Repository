//Author: kcmodev
//Date of original submission: 5/12/2020
//Class: WGU C867 Scripting and Programming Applications

#include <iostream>
#include <string>
using namespace std;

#include "student.h"
#include "degree.h"

Student::Student() { // sets default values
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = -1;

    for (int i = 0; i < totalDays; i++) {
        this->numDays[i] = 0;
    }
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numDays[]) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;

    for (int i = 0; i < totalDays; i++) {
        this->numDays[i] = numDays[i];
    }
}

// setters
void Student::setStudentID(string studentID) {
    this->studentID = studentID;
}
void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}
void Student::setLastName(string lastName) {
    this->lastName = lastName;
}
void Student::setEmailAddress(string email) {
    this->emailAddress = email;
}
void Student::setAge(int age) {
    this->age = age;
}
void Student::setDaysToComplete(int numDays[]) {
    // loops through array to set this student object with the correct dates in course

    for (int i = 0; i < totalDays; i++) {
        this->numDays[i] = numDays[i];
    }
}

// getters
string Student::getStudentID() const {
    return this->studentID;
}
string Student::getFirstName() const {
    return this->firstName;
}
string Student::getLastName() const {
    return this->lastName;
}
string Student::getEmailAddress() const {
    return this->emailAddress;
}
int Student::getAge() const {
    return this->age;
}
void Student::getDaysToComplete() const { // prints avg numbers of days for courses
    // performs arithmetic to average the 3 days in course

    double avg = 0;

    for (int i = 0; i < this->totalDays; i++) {
        avg += static_cast<double>(numDays[i]);
    }

//    avg = round(avg / this->totalDays);
    avg = avg / this->totalDays;
    cout << avg << endl;
}

void Student::printStudentData() {
    // prints all student data tab separated
    cout << "Student ID: " << this->studentID << "\t" << "First Name: " << this->firstName << "\t"
         << "Last Name: " << this->lastName << "\t" << "Age: " << this->age << "\t  "
         << "Days in course: {" << this->numDays[0] << ", " << this->numDays[1] << ", " << this->numDays[2] << "}\t"
         << " Degree Program: ";
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// SECURITY student subclass & functions
SecurityStudent::SecurityStudent() :Student() {

    // establishes a subclass for security students with a constructor
    degreeProgram = DegreeProgram::SECURITY;
}


SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName,
                                 string emailAddress, int age, int numDays[], DegreeProgram degreeProgram)
        : Student(studentID, firstName, lastName, emailAddress, age, numDays) {
    // and an overloaded constructor

    // instatnciates a DegreeProgram enum for this subclass
    degreeProgram = DegreeProgram::SECURITY;
}

DegreeProgram SecurityStudent::getDegreeProgram() {

    // sets enum value
    return DegreeProgram::SECURITY;
}

void SecurityStudent::print() {

    // prints enum value as a string based on enum value
    this->Student::printStudentData();
    cout << "SECURITY" << endl;
}

SecurityStudent::~SecurityStudent() {
    Student::~Student(); // calls super destructor
}


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// NETWORKING student subclass & functions
NetworkStudent::NetworkStudent() :Student() {
    // establishes a subclass for networking students with a constructor

    degreeProgram = DegreeProgram::NETWORK;
}

NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName,
                               string emailAddress, int age, int numDays[], DegreeProgram degreeProgram)
        : Student(studentID, firstName, lastName, emailAddress, age, numDays) {
    // and an overloaded constructor

    // instantiates a DegreeProgram enum for this subclass
    degreeProgram = DegreeProgram::NETWORK;
}

DegreeProgram NetworkStudent::getDegreeProgram() {

    // sets enum value
    return DegreeProgram::NETWORK;
}

void NetworkStudent::print() {

    // prints enum value as a string based on enum value
    this->Student::printStudentData();
    cout << "NETWORK" << endl;
}

NetworkStudent::~NetworkStudent() {
    Student::~Student(); // calls super destructor
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// SOFTWARE student subclass & functions
SoftwareStudent::SoftwareStudent() :Student() {
    // establishes a subclass for software  students with a constructor
    degreeProgram = DegreeProgram::SOFTWARE;
}

SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName,
                                 string emailAddress, int age, int numDays[], DegreeProgram degreeProgram)
        : Student(studentID, firstName, lastName, emailAddress, age, numDays) {
    // and an overloaded constructor

    // instantiates a DegreeProgram enum for this subclass
    degreeProgram = DegreeProgram::SOFTWARE;
}

DegreeProgram SoftwareStudent::getDegreeProgram() {
    // sets enum value
    return DegreeProgram::SOFTWARE;
}

void SoftwareStudent::print() {

    // prints enum value as a string based on enum value
    this->Student::printStudentData();
    cout << "SOFTWARE" << endl;
}

SoftwareStudent::~SoftwareStudent() {
    Student::~Student(); // calls super destructor
}

Student::~Student() {
}