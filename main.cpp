//Author: kcmodev
//Date of original submission: 5/12/2020
//Class: WGU C867 Scripting and Programming Applications

#include <iostream>
#include <string>

using namespace std;

#include "degree.h"
#include "roster.h"
#include "student.h"

int main()
{
    // starting set of data prior to parsing and manipulation
    const string studentData[] = {
            "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
            "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
            "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
            "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
            "A5,first,last,email@email.edu,20,14,15,10,SOFTWARE"
    };

    int numStudents = 5; // rows of data in the table = number of students

    cout << "WGU C867 Scripting and Programming Applications" << endl;
    cout << "Programming language used: C++" << endl;
    cout << "Student name: kcmodev" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "Creating an instance of the \"Roster\" class....." << endl;
    Roster * classRoster = new Roster(numStudents);

    // parsing data from studentData and adding each student to their respective
    // instance of the roster class
    for (int i = 0; i < numStudents; i++) {
        classRoster->parseData(studentData[i]);
    }

    // print entire student data table
    classRoster->printAll();
    cout << endl;

    // print invalid emails within student data table
    classRoster->printInvalidEmails();
    cout << endl;

    // print average days for all students in student data table (all added and divided by number of days)
    cout << "Printing each students average days in class..." << endl;
    for (int j = 0; j < numStudents; j++) {
        classRoster->printAverageDaysInCourse(classRoster->getStudentAt(j));
    }
    cout << endl;

    // print student with only a specific degree plan, in this case security
    classRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);
    cout << endl;

    // remove student with ID "A3"
    classRoster->remove("A3");
    classRoster->printAll();
    cout << endl;

    // attempting to remove 'A3' again to produce an error
    classRoster->remove("A3");

    classRoster->~Roster(); // releasing memory from roster instance
    cout << "\nmemory allocated to roster released...\n" << endl;

    return 0;
}