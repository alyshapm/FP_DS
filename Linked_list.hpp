#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

struct Student{ // change to class
    // int rollNo;
    char Name[20];
    char Phone[100];
    float Marks[2];
    char noStudents[100];
    struct Student *next;
} *head;

void addStudent(char* Name, char* Phone, char* noStudents, float marks[]);

void addMark(char* Name, int courseNo, float mark);

void printStudentReport(char* Name, struct Student* temp);

void studentsReport(struct Student *temp);

#endif