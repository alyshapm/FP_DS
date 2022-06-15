#include "Student.h"

#include <iostream>
#include<vector>
#include <iomanip>

using namespace std;

int getHashKey(unsigned ID) {
    return ID % 30;
}

void addStudent(unsigned long ID, string n, Student student_list[]){
    int hkey;
    hkey = getHashKey(ID);

    for(int i=0; i < 30; i++) {
        if (student_list[hkey].id == ID) {
            cout << "This ID is already assigned" << endl;
            return;
        } else if(student_list[hkey].id == -1){
            student_list[hkey].id = ID;
            student_list[hkey].name = n;
//            cout << "This student has been added" << endl;
            return;
        }
        hkey = (hkey+1) % 30;
    }
    cout << "The table is already full" << endl;
}

int searchStudent(unsigned long id, Student student_list[]) {
    int hkey;
    hkey = getHashKey(id);

    for(int i=0; i < 30; ) {
        if(student_list[hkey].id == -1){
            cout << "This student is not in the list" << endl;
            return -1;
        } else if (student_list[hkey].id == id) {
            return hkey;
        }
        hkey = (hkey+1) % 30;
    }
    cout << "This student is not in the list" << endl;
    return -1;
}




///* ----- MAIN ----- */
//
//int main(){
//    Student student_list[30];
//
//    int choice, hashkey, mark;
//    unsigned long ID;
//    string name, course, newCourse;
//
//
//    while(choice != 6){
//        displayMenu();
//        cout << "Enter your choice: ";
//        cin >> choice;
//
//        switch(choice) {
//        case 1:
//            cout << "Student ID: ";
//            cin >> ID;
//            cout << "Name: ";
//            cin.ignore();
//            getline(cin, name);
//            addStudent(ID, name, student_list);
//            break;
//        case 2:
//            cout << "Student ID: ";
//            cin >> ID;
//            if (searchStudent(ID, student_list) != -1) {
//                int index = searchStudent(ID, student_list);
//                student_list[index].printReport();
//            }
//            break;
//        case 3:
//            cout << "Student ID: ";
//            cin >> ID;
//            cout << "Enter the course name: ";
//            cin >> course;
//            cout << "Enter the mark: ";
//            cin >> mark;
//            if (searchStudent(ID, student_list) != -1) {
//                int index = searchStudent(ID, student_list);
//                student_list[index].addCourse(course, mark);
//            }
//            break;
//        case 4:
//            cout << "1. Course" << endl;
//            cout << "2. Mark" << endl;
//            cout << "Enter your choice: ";
//            cin >> choice;
//
//            switch(choice){
//                case 1:
//                    cout << "Student ID: ";
//                    cin >> ID;
//                    cout << "Course: ";
//                    cin.ignore();
//                    getline(cin, course);
//                    cout << "New name of the course: ";
//                    cin >> newCourse;
//                    if (searchStudent(ID, student_list) != -1) {
//                        int index = searchStudent(ID, student_list);
//                        student_list[index].modifyCourse(course, newCourse);
//                    }
//                    break;
//                case 2:
//                    cout << "Student ID: ";
//                    cin >> ID;
//                    cout << "Course: ";
//                    cin.ignore();
//                    getline(cin, course);
//                    cout << "Mark: ";
//                    cin >> mark;
//                    if (searchStudent(ID, student_list) != -1) {
//                        int index = searchStudent(ID, student_list);
//                        student_list[index].modifyMark(course, mark);
//                    }
//                    break;
//                }
//        case 5:
//            cout << "Student ID: ";
//            cin >> ID;
//            if (searchStudent(ID, student_list) != -1) {
//                int index = searchStudent(ID, student_list);
//                student_list[index].modifyMark(course, mark);
//            }
//            break;
//        case 6:
//            exit(0);
//            break;
//            }
//        }
//        return 0;
//    }
