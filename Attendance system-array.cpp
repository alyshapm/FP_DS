#include <iostream>
#include<vector>
#include <iomanip>

using namespace std;

class Student {
public:
    string name;
    int numOfcourses = 0;
    vector<string> courses;
    vector<int> marks;
    unsigned long id;
    Student() {
        id = -1;
    }
    void printReport();
    void addCourse(string course, int mark);
    void deleteCourse(string course);
    void modifyCourse(string course, string newCourse);
    void modifyMark(string course, int mark);

};

void Student::printReport() {
    cout << "Name: " << name << "    Student ID: " << id << endl;
    cout << right << setw(18) << "Courses" << setw(13) << "|" << setw(8) << "Marks" << endl;
    cout << "----------------------------------------------" << endl;
    for (int i = 0; i<numOfcourses; i++) {
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
    numOfcourses++;
    courses.push_back(course);
    marks.push_back(mark);

}

void Student::deleteCourse(string course) {
    bool found = false;

    for (int i = 0; i < courses.size(); i++) {
        if (courses[i] == course) {
            found = true;
            courses.erase(courses.begin() + i - 1);
            marks.erase(marks.begin() + i - 1);
        }
    }

    if(!found) {
        cout << "Course not found" << endl;
    }
}

void Student::modifyCourse(string course, string newCourse) {
    bool found = false;

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


void displayMenu(){
    printf("ATTENDANCE SYSTEM");
    printf("\n1. Add student");
    printf("\n2. Display student report");
    printf("\n3. Add course");
    printf("\n4. Modify");
    printf("\n5. Delete");
    printf("\n6. Exit \n");
}

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
            cout << "This student has been added" << endl;
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



int main(){
    Student student_list[30];

    int choice, hashkey, mark;
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
        return 0;
    }


