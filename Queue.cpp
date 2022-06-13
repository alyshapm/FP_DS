#include <iostream>
#include <queue>
#include "Queue.hpp"

using namespace std;

template <typename T>
void printQueueElements(queue<T> Q)
{
	//printing content of queue
	while (!Q.empty()){
		cout<<Q.front()<<" ";
		Q.pop();
	}
	cout << endl;
}

void printQueueInfo(int t, queue<string> Q1, queue<string> Q2, queue<string> Q3) {
    for (int i = 0; i < t; i++) {
        Q1.pop();
        Q2.pop();
        Q3.pop();
    }
    cout<<"Name: " << Q1.front() << " " << Q2.front() << " " << "Attendance: " << Q3.front() << endl;
}

int searchEl(string fname, string lname, queue<string> Q1, queue<string> Q2) {
    bool found = false;
    if (Q1.empty() || Q2.empty()) {
        return -1;
    } else {
        int i = 0;
        while (i < Q1.size() && fname != Q1.front() && lname != Q2.front()) {
            Q1.pop();
            Q2.pop();
            i++;
        }
        if (fname == Q1.front() && lname == Q2.front()) {
            found == true;
            return i;
        } else {
             return -1;
            }
    }
}

void checkIn(int t, queue<string> Q1){
    for (int i = 0; i < t; i++) {
        Q1.pop();
    }
    Q1.front() = "Present";
}

int main() {
    queue<string> student_first_name;
    queue<string> student_last_name;
    queue<string> student_attendance;
    queue<string> teacher_first_name;
    queue<string> teacher_last_name;
    queue<string> temp_queue;
    int choice;
    do {

        cout<<"1.Student" << endl;
        cout<<"2.Lecturer" << endl;
        cout<<"3.Staff" << endl;
        cout<<"0.Exit"<< endl;;

        cout<<"Enter you choice: ";
        cin>>choice;
        cout << endl;

        switch(choice) {
            case 1:
                {cout<<"1.Register" << endl;
                cout<<"2.Check attendance" << endl;
                cout<<"3.Check in" << endl;
                cout<<"0.Go back <-"<< endl;;
                cout<<"Enter you choice: ";
                cin>>choice;
                cout << endl;

                switch(choice) {
                    case 1:
                        {
                        cout<<"----- Form to Register Student ---- \n";
                        string firstName, lastName;
                        string attendance = "Absent";

                        cout<<"Enter first name: ";
                        cin>>firstName;
                        cout<<"Enter your last name: ";
                        cin>>lastName;

                        student_first_name.push(firstName);
                        student_last_name.push(lastName);
                        student_attendance.push(attendance);
                        break;
                        }
                    case 2:
                        {
                        string firstName, lastName;
                        cout<<"Enter first name: ";
                        cin>>firstName;
                        cout<<"Enter your last name: ";
                        cin>>lastName;

                        if (searchEl(firstName, lastName, student_first_name, student_last_name)!= -1){
                            int time = searchEl(firstName, lastName, student_first_name, student_last_name);
                            printQueueInfo(time, student_first_name, student_last_name, student_attendance);
                        } else {
                            cout << "Student not found" << endl;
                        }
                        break;
                        }
                    case 3:
                        {
                        string firstName, lastName;
                        string change;
                        cout<<"Enter first name: ";
                        cin>>firstName;
                        cout<<"Enter your last name: ";
                        cin>>lastName;

                        if (searchEl(firstName, lastName, student_first_name, student_last_name)!= -1){
                            int time = searchEl(firstName, lastName, student_first_name, student_last_name);
                            for (int i = 0; i < time; i++) {
                                change = student_attendance.front();
                                temp_queue.push(change);
                                student_attendance.pop();
                            }
                            student_attendance.front() = "Present";

                            for(int i = 0; i < temp_queue.size(); i++) {
                                student_attendance.push(temp_queue.front());
                                temp_queue.pop();
                            }
                        } else {
                            cout << "Student not found" << endl;
                        }
                        break;
                        }
                }
                break;

            case 2:
                cout<<"hey"<<endl;
                break;
            case 3:
                cout<<"heyyy"<<endl;
                break;
            case 0:
                break;
        }

    }
    }
    while (choice!=0);
}

