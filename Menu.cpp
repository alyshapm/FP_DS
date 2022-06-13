#include <iomanip>
#include <iostream>

#include "Array.hpp"
#include "Queue.hpp"
#include "Map.hpp"
#include "Linked_list.hpp"
#include "Menu.hpp"

using namespace std;

void menu(){
    printf("\t\t\t  **************************************************************************************\n ");
    printf("\t\t\t  **                            ADVANCE STUDENT MANAGEMENT SYSTEM                     **\n ");
    printf("\t\t\t  **                                                                                  **\n ");
    printf("\t\t\t  **      To Introduce New Student             ---->          choose  option '1'      **\n ");
    printf("\t\t\t  **      To display student report            ---->          choose  option '2'      **\n ");
    printf("\t\t\t  **      To add course                        ---->          choose  option '3'      **\n ");
    printf("\t\t\t  **      To update student info               ---->          choose  option '4'      **\n ");
    printf("\t\t\t  **      To delete student info               ---->          choose  option '5'      **\n ");
    printf("\t\t\t  **      *To Save to a FILE                   ---->         choose  option 'n/a'     **\n ");
    printf("\t\t\t  **      *To Retrieve from a FILE             ---->         choose  option 'n/a'     **\n ");
    printf("\t\t\t  **      To EXIT                              ---->          choose  option '6'      **\n ");
    printf("\t\t\t  **                                                                                  **\n ");
    printf("\t\t\t  **************************************************************************************\n ");
}

void menuLinkedList(int option){

}

void menuArray(int option){
    Student student_list[30];

    int choice, hashkey, mark;
    unsigned long ID;
    string name, course, newCourse;

    switch(option){
        case 1:
            cout << "Student ID: ";
            cin >> ID;
            cout << "Name: ";
            cin.ignore();
            getline(cin, name);
            addStudent(ID, name, student_list);
            break;
        case 2:
            cout << "Student ID: ";
            cin >> ID;
            if (searchStudent(ID, student_list) != -1) {
                int index = searchStudent(ID, student_list);
                student_list[index].printReport();
            }
            break;
        case 3:
            cout << "Student ID: ";
            cin >> ID;
            cout << "Enter the course name: ";
            cin >> course;
            cout << "Enter the mark: ";
            cin >> mark;
            if (searchStudent(ID, student_list) != -1) {
                int index = searchStudent(ID, student_list);
                student_list[index].addCourse(course, mark);
            }
            break;
        case 4:
            cout << "1. Course" << endl;
            cout << "2. Mark" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch(choice){
                case 1:
                    cout << "Student ID: ";
                    cin >> ID;
                    cout << "Course: ";
                    cin.ignore();
                    getline(cin, course);
                    cout << "New name of the course: ";
                    cin >> newCourse;
                    if (searchStudent(ID, student_list) != -1) {
                        int index = searchStudent(ID, student_list);
                        student_list[index].modifyCourse(course, newCourse);
                    }
                    break;
                case 2:
                    cout << "Student ID: ";
                    cin >> ID;
                    cout << "Course: ";
                    cin.ignore();
                    getline(cin, course);
                    cout << "Mark: ";
                    cin >> mark;
                    if (searchStudent(ID, student_list) != -1) {
                        int index = searchStudent(ID, student_list);
                        student_list[index].modifyMark(course, mark);
                    }
                    break;
                }
        case 5:
            cout << "Student ID: ";
            cin >> ID;
            if (searchStudent(ID, student_list) != -1) {
                int index = searchStudent(ID, student_list);
                student_list[index].modifyMark(course, mark);
            }
            break;
        case 6:
            exit(0);
            break;
            }
    }

}

void menuMap(int option){

}

void menuQueue(int option){

}

void menuLinkedList(int option){

}