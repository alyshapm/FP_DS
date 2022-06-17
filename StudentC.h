#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

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
    Student(){
        id = -1;
    };
    void printReport();
    void addCourse(string course, int mark);
    void deleteCourse(string course);
    void modifyCourse(string course, string newCourse);
    void modifyMark(string course, int mark);
    void setToNull();
};

#endif // STUDENT_H_INCLUDED
