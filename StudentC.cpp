#include "StudentC.h"

using namespace std;

void Student::printReport() {
    cout << "Name: " << name << "    Student ID: " << id << endl;
    cout << right << setw(18) << "Courses" << setw(13) << "|" << setw(8) << "Marks" << endl;
    cout << "----------------------------------------------" << endl;
    for (int i = 0; i<courses.size(); i++) {
            cout << left << setw(30) << courses[i] << setw(5) << "|" << setw(8) << marks[i] << endl;
    }
}

void Student::addCourse(string course, int mark) {
    for (int i = 0; i < courses.size(); i++) {
        if (courses[i] == course) {
            cout << "This course was already added" << endl;
            return;
        }
    }
    courses.push_back(course);
    marks.push_back(mark);

}

void Student::deleteCourse(string course) {
    bool found = false;
    if (courses.size() == 0) {
        cout << "No courses were added yet" << endl;
        return;
    }

    for (int i = 0; i < courses.size(); i++) {
        if (courses[i] == course) {
            found = true;
            courses.erase(courses.begin() + i);
            marks.erase(marks.begin() + i);
        }
    }

    if(!found) {
        cout << "Course not found" << endl;
    }
}

void Student::modifyCourse(string course, string newCourse) {
    bool found = false;

    if (courses.size() == 0) {
        cout << "No courses were added yet" << endl;
        return;
    }

    for (int i = 0; i < courses.size(); i++) {
        if (courses[i] == course) {
            found = true;
            courses[i] == newCourse;
        }
    }

    if(!found) {
        cout << "Course not found" << endl;
    }
}

void Student::modifyMark(string course, int mark) {
    bool found = false;

    if (courses.size() == 0) {
        cout << "No courses were added yet" << endl;
        return;
    }

    for (int i = 0; i < courses.size(); i++) {
        if (courses[i] == course) {
            found = true;
            marks[i] == mark;
        }
    }

    if(!found) {
        cout << "Course not found" << endl;
    }
}

void Student::setToNull() {
    name = "";
    id = -1;
    courses.clear();
    marks.clear();
    }
