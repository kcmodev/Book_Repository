//Author: kcmodev
//Date of original submission: 5/12/2020
//Class: WGU C867 Scripting and Programming Applications


#include <iostream>
#include <string>
using namespace std;

#include "roster.h"
#include "student.h"
#include "degree.h"

Roster::Roster() {
    this->index = -1;
    this->numStudents = -1; // needs to be -1, 0 can be confused for empty (array index of 0)
    this->classRosterArray = nullptr;
}

Roster::Roster(int numStudents) { // dynamically sets capacity for data rows (students)
    this->numStudents = numStudents;
    this->index = -1; //still needs to be empty so it will start at the beginning of the array of data
    this->classRosterArray = new Student*[numStudents]; // sets array of student objects to size of data array
}

void Roster::parseData(string data) {

    if (index < numStudents) {
        this->index++;
        cout << "parsing data set #" << (index + 1) << "..." << endl;
        // instantiate a set of DegreeProram variables
        DegreeProgram degree;

        int lpos = 0;
        int rpos = 0;

        // find first comma in data
        rpos = data.find(",");
        // data between 0 and first comma is student ID
        string studentID = data.substr(lpos, rpos);
        cout << "ID #: " << studentID;

        // new left position is 1 space after the current right position
        // so your new left position is the start of the next word
        // info between first comma and second comma is first name
        lpos = rpos + 1;
        rpos = data.find(",", lpos);
        string firstName = data.substr(lpos, (rpos - lpos));

        // new left position is 1 space after the current right position
        // so your new left position is the start of the next word
        // info between 2nd comma and 3rd is last name
        lpos = rpos + 1;
        rpos = data.find(",", lpos);
        string lastName = data.substr(lpos, (rpos - lpos));
        cout << "\t Name: " << firstName << " " << lastName << endl;

        // new left position is 1 space after the current right position
        // so your new left position is the start of the next word
        // info between 3rd and 4th comma is email
        lpos = rpos + 1;
        rpos = data.find(",", lpos);
        string emailAddress = data.substr(lpos, (rpos - lpos));

        // new left position is 1 space after the current right position
        // so your new left position is the start of the next word
        // then comes age
        lpos = rpos + 1;
        rpos = data.find(",", lpos);
        // converts the numbers from the parsed string to an integer
        int age = stoi(data.substr(lpos, (rpos - lpos)));

        //new left position is 2 spaces after the previous, to account for spaces
        //next is days in which will nbeed to be added to all 3 parts of the array
        int numDays[3] = { 0,0,0 };
        //day 1
        lpos = rpos + 1;
        rpos = data.find(",", lpos);
        // converts the numbers from the parsed string to an integer
        numDays[0] = stoi(data.substr(lpos, (rpos - lpos)));

        // day 2
        lpos = rpos + 1;
        rpos = data.find(",", lpos);
        // converts the numbers from the parsed string to an integer
        numDays[1] = stoi(data.substr(lpos, (rpos - lpos)));

        // day 3
        lpos = rpos + 1;
        rpos = data.find(",", lpos);
        // converts the numbers from the parsed string to an integer
        numDays[2] = stoi(data.substr(lpos, (rpos - lpos)));

        // everything beyond this comma is the string stating the degree for the student
        lpos = rpos + 1;
        rpos = data.find(",", lpos);
        string selectedDegree = data.substr(lpos, (rpos - lpos));

        // uses string containing name of degree and associated it with the enumerated value for degree
        if (selectedDegree == "NETWORK") {
            degree = DegreeProgram::NETWORK;
        }
        else if (selectedDegree == "SOFTWARE") {
            degree = DegreeProgram::SOFTWARE;
        }
        else if (selectedDegree == "SECURITY") {
            degree = DegreeProgram::SECURITY;
        }

        cout << "end of parsing data set #" << (index + 1) << "...\n" << endl;

        // adds all current information in this data set (student) to the current instantiation
        // of a specific student within an instance of the roster class through the add function
        Roster::add(studentID, firstName, lastName, emailAddress,
                    age, numDays[0], numDays[1], numDays[2], degree);
    }

}

void Roster::add(string studentID, string firstName,
                 string lastName, string emailAddress, int age, int daysInCourse1,
                 int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {

    // could loop since but since the data set size is fixed this will suffice
    // adds each individual in to a new array for the current student class so
    // the numbers can be manipulated to determine averages
    int daysToArray[Student::totalDays];
    daysToArray[0] = daysInCourse1;
    daysToArray[1] = daysInCourse2;
    daysToArray[2] = daysInCourse3;

    // calls a subclass of student and it's respective constructor depending on the degree selection
    // found with the parsingDara function and passed here (network/security/software)
    if (degreeProgram == DegreeProgram::NETWORK) {
        classRosterArray[index] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, daysToArray, degreeProgram);
    }
    else if (degreeProgram == DegreeProgram::SOFTWARE) {
        classRosterArray[index] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, daysToArray, degreeProgram);
    }
    else if (degreeProgram == DegreeProgram::SECURITY) {
        classRosterArray[index] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, daysToArray, degreeProgram);
    }
}

void Roster::remove(string studentID) {
    // remove a student based on ID number

    cout << "Attempting to remove student with ID \'" << studentID << "\'" << endl;

    // loops through class roster array until a match for the student ID is found
    for (int i = 0; i < numStudents; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            // match is found and corresponding object is deleted
            delete this->classRosterArray[i];
            cout << "Student removed...\n" << endl;
            // index is reduced by 1 since said object no longer exists
            this->index--;

            for (int j = i; j <= this->index; j++) {
                // moves anything remaining in the array down 1 space to fill the void caused
                // by the removal of the selected object
                classRosterArray[j] = classRosterArray[j + 1];
            }
            return; // returns so the loop doesn't needlessly perform any further iterations
        }
    }

    // only prints if no matching student id is found
    cout << "Student with ID \'" << studentID << "\' could not be found...\n" << endl;
}

void Roster::printAll() {
    // prints entire data set

    cout << "printing data currently in the roster..." << endl;

    for (int i = 0; i <= this->index; i++) {
        (this->classRosterArray)[i]->print();
    }
}

void Roster::printAverageDaysInCourse(string studentID) {
    // takes all 3 values from days to complete array and averages them

    for (int i = 0; i <= index; i++) {
        // loops through the objects (students) until it finds the correct ID and prints only that
        // specific object's average
        if (this->classRosterArray[i]->getStudentID() == studentID) {
            cout << this->classRosterArray[i]->getFirstName() << " " << this->classRosterArray[i]->getLastName()
                 << "\'s average days in class (rounded): ";
            classRosterArray[i]->getDaysToComplete();
        }
    }
}

void Roster::printInvalidEmails() {
    // searches for and prints all invalid emails

    cout << "Printing all invalid emails...." << endl;

    for (int i = 0; i <= this->index; i++) {
        string invEmailCheck = classRosterArray[i]->getEmailAddress();

        // checks to see if the email contains an '@' symbol
        if (invEmailCheck.find('@') == string::npos) {
            cout << invEmailCheck << "\t-- flagged as invalid for not having an \'@\' sign." << endl;
            continue;
        }
            // checks to see if the email contains a '.'
        else if (invEmailCheck.find('.') == string::npos) {
            cout << invEmailCheck << "\t-- flagged for not having a period." << endl;
            continue;
        }
            // checks for spaces in the email address
        else if (invEmailCheck.find(' ') != string::npos) {
            cout << invEmailCheck << "\t-- flagged as invalid for having a space." << endl;
            continue;
        }

    }
}

string Roster::getStudentAt(int index) {
    // returns student ID based on index

    return this->classRosterArray[index]->getStudentID();
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    // prints all student that have the selected degree program

    cout << "Printing only students with ";

    if (degreeProgram == DegreeProgram::SECURITY) {
        cout << "\'Security\'";
    }
    if (degreeProgram == DegreeProgram::NETWORK) {
        cout << "\'Network\'";
    }
    if (degreeProgram == DegreeProgram::SOFTWARE) {
        cout << "\'Software\'";
    }
    cout << " as their selected degree...." << endl;

    // loops through student objects until it find a match and prints the corresponding student data
    for (int i = 0; i < this->numStudents; i++) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            this->classRosterArray[i]->print();
        }
    }
}

Roster::~Roster() {

}