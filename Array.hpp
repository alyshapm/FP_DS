#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Student {
public:
    string name;
    int numOfcourses = 0;
    vector<string> courses;
    vector<int> marks;
    unsigned long id;
    Student();
    void printReport();
    void addCourse(string course, int mark);
    void deleteCourse(string course);
    void modifyCourse(string course, string newCourse);
    void modifyMark(string course, int mark);

};

void Student::printReport();

void Student::addCourse(string course, int mark);

void Student::deleteCourse(string course);

void Student::modifyCourse(string course, string newCourse);

void Student::modifyMark(string course, int mark);

void displayMenu();

int getHashKey(unsigned ID);

void addStudent(unsigned long ID, string n, Student student_list[]);

int searchStudent(unsigned long id, Student student_list[]);

#endif 