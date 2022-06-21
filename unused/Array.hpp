#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Student {
public:
    string name;
    vector<string> courses;
    vector<int> marks;
    unsigned long id;
    Student();
    void printReport();
    void addCourse(string course, int mark);
    void deleteCourse(string course);
    void modifyCourse(string course, string newCourse);
    void modifyMark(string course, int mark);
    void setToNull(unsigned long id);
};

void displayMenu();

int getHashKey(unsigned ID);

void addStudent(unsigned long ID, string n, Student student_list[]);

int searchStudent(unsigned long id, Student student_list[]);

#endif
