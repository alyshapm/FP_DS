#include <iostream>
#include <map>
#include<vector>
#include<string>
#include "Map.hpp"

using namespace std;

void print_map(map<unsigned long, map<string, map<string, int> > > m)
{
    map<unsigned long, map<string, map<string, int> > >::iterator itr;
    map<string, map<string, int> >::iterator ptr;
    map<string, int>::iterator rtr;

    for (itr = m.begin(); itr != m.end(); itr++) {

        for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {

                cout << "Student ID is " << itr->first
                    << " and name is " << ptr->first << endl;

                for (rtr = ptr->second.begin(); rtr != ptr->second.end(); rtr++){
                    cout << " Course: " << rtr->first << "  |  ";
                    cout << " Grade: " << rtr->second << endl;
                }
        }
    }
}

map<unsigned long, map<string, map<string, int> > > register_student(map<unsigned long, map<string, map<string, int> > > m, unsigned long ID, string name) {
        m.insert(pair<unsigned long, map<string, map<string, int> > >(ID, map<string, map<string, int> >()));
        m[ID].insert(pair<string, map<string, int> >(name, map<string, int>()));
        m[ID][name].insert(pair<string, int>("none", 0));
        return m;
}

void find_student_by_ID(map<unsigned long, map<string, map<string, int> > > m, unsigned long ID) {
    map<unsigned long, map<string, map<string, int> > >::iterator itr = m.find(ID);
    map<string, map<string, int> >::iterator ptr;
    map<string, int>::iterator rtr;

    if (itr != m.end()){
        cout << "Student ID is " << ID << " and name is " << m.find(ID)->second.begin()->first << endl;
                for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
                    for (rtr = ptr->second.begin(); rtr != ptr->second.end(); rtr++){
                        cout << " Course: " << rtr->first << "  |  ";
                        cout << " Grade: " << rtr->second << endl;
                }
            }
    } else {
         cout << "Student not found" << endl;
     }
}

void find_student_by_Name(map<unsigned long, map<string, map<string, int> > > m, string name) {
    bool found;
    map<string, map<string, int> >::iterator ptr;
    map<string, int>::iterator rtr;


     for (auto& it : m) {
        if (it.second.begin()->first == name) {
            found = true;
            cout << "Student ID is " << it.first << " and name is " << it.second.begin()->first << endl;
                for (ptr = it.second.begin(); ptr != it.second.end(); ptr++) {
                    for (rtr = ptr->second.begin(); rtr != ptr->second.end(); rtr++){
                        cout << " Course: " << rtr->first << "      |      ";
                        cout << " Grade: " << rtr->second << endl;
                }
            }
        }
    }
    if (!found) {
        cout << "Student not found" << endl;
    }
}

map<unsigned long, map<string, map<string, int> > > addCourse(map<unsigned long, map<string, map<string, int> > > m, unsigned long ID, string course, int mark) {
    map<unsigned long, map<string, map<string, int> > >::iterator itr = m.find(ID);
    map<string, map<string, int> >::iterator ptr;
    map<string, int>::iterator rtr;

    if (itr != m.end()){
        for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
            for (rtr = ptr->second.begin(); rtr != ptr->second.end(); rtr++){
                if (rtr->first == "none") {
                    itr->second.begin()->second.erase(rtr);
                    m[ID][m.find(ID)->second.begin()->first].insert(pair<string, int>(course, mark));
                    return m;
                } else if (rtr->first == course) {
                    cout << "This course was already added" << endl;
                    return m;
                } else {
                   m[ID][m.find(ID)->second.begin()->first].insert(pair<string, int>(course, mark));
                   return m;
                   }
                }
            }
        }
}

map<unsigned long, map<string, map<string, int> > > modifyCourse(map<unsigned long, map<string, map<string, int> > > m, unsigned long ID, string course, string newCourse) {
    map<unsigned long, map<string, map<string, int> > >::iterator itr = m.find(ID);
    map<string, map<string, int> >::iterator ptr;
    map<string, int>::iterator rtr;
    int temp;

    if (itr != m.end()){
        for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
            for (rtr = ptr->second.begin(); rtr != ptr->second.end(); rtr++){
                if (rtr->first == course) {
                    temp = rtr->second;
                    itr->second.begin()->second.erase(rtr);
                    m[ID][m.find(ID)->second.begin()->first].insert(pair<string, int>(newCourse, temp));
                    return m;
                } else {
                   cout << "course not found" << endl;
                   return m;
                   }
                }
            }
        }
}

map<unsigned long, map<string, map<string, int> > > modifyMarks(map<unsigned long, map<string, map<string, int> > > m, unsigned long ID, string course, int mark) {
    map<unsigned long, map<string, map<string, int> > >::iterator itr = m.find(ID);
    map<string, map<string, int> >::iterator ptr;
    map<string, int>::iterator rtr;

    if (itr != m.end()){
        for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
            for (rtr = ptr->second.begin(); rtr != ptr->second.end(); rtr++){
                if (rtr->first == course) {
                    rtr->second = mark;
                    return m;
                } else {
                   cout << "course not found" << endl;
                   return m;
                   }
                }
            }
        }
}

map<unsigned long, map<string, map<string, int> > > deleteStudent(map<unsigned long, map<string, map<string, int> > > m, unsigned long ID) {
    if (m.find(ID) != m.end()) {
        m.erase(ID);
    }
    return m;
}

void displayMenu(){
    printf("ATTENDANCE SYSTEM");
    printf("\n1. Add student");
    printf("\n2. Display student report");
    printf("\n3. Add course");
    printf("\n4. Modify");
    printf("\n5. Delete");
    printf("\n6. Exit \n");
}

int main()
{
    map<unsigned long, map<string, map<string, int> > > m;
    int choice, mark;
    unsigned long ID;
    string name, course, newCourse;

    while(choice != 6){
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
        case 1:
            cout << "Student ID: ";
            cin >> ID;
            cout << "Name: ";
            cin.ignore();
            getline(cin, name);
            m = register_student(m, ID, name);
            break;
        case 2:
            cout << "1. Search by ID" << endl;
            cout << "2. Search by name" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            switch(choice) {
            case 1:
                cout << "Student ID: ";
                cin >> ID;
                find_student_by_ID(m, ID);
                break;
            case 2:
                cout << "Name: ";
                cin.ignore();
                getline(cin, name);
                find_student_by_Name(m, name);
                break;
            }
            break;
        case 3:
            cout << "Student ID: ";
            cin >> ID;
            cout << "Course: ";
            cin.ignore();
            getline(cin, course);
            cout << "Mark: ";
            cin >> mark;
            m = addCourse(m, ID, course, mark);
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
                    m = modifyCourse(m, ID, course, newCourse);
                    break;
                case 2:
                    cout << "Student ID: ";
                    cin >> ID;
                    cout << "Course: ";
                    cin.ignore();
                    getline(cin, course);
                    cout << "Mark: ";
                    cin >> mark;
                    m = modifyMarks(m, ID, course, mark);
                    break;
            }
            break;
        case 5:
            cout << "1. Student" << endl;
            cout << "2. Course" << endl;
            cout << "Enter your choice";
            cin >> choice;
            switch(choice) {
            case 1:
                cout << "Student ID: ";
                cin >> ID;
                m = deleteStudent(m, ID);
                break;
            case 2:
                cout << "Name: ";
                cin.ignore();
                getline(cin, name);
                find_student_by_Name(m, name);
                break;
            }
            break;
        case 6:
            exit(0);
            break;
        }
    }

    return 0;
}

