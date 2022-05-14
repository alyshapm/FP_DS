/* 
    STUDENT ATTENDANCE SYSTEM USING LINKED LIST (test 1)
    to fix: input validation/exceptions, add other functions
*/ 

#include <iostream>
#include <cstdio>
using namespace std;

// --- METHODS --- 
struct Student{
    // int rollNo;
    char Name[20];
    char Phone[100];
    float Marks[2];
    char noStudents[100];
    struct Student *next;
} *head;

void addStudent(char* Name, char* Phone, char* noStudents, float marks[]){
    struct Student *student = (struct Student*) malloc(sizeof(struct Student)); // allocates memory to a new node
    // student->rollNo = rollNo;
    strcpy(student->Name, Name);
    strcpy(student->Phone, Phone);
    strcpy(student->noStudents, noStudents);
    student->next = NULL;
    int j;  for (j = 0; j < 2; j++) {
        student->Marks[j] = marks[j];}

    //checks if list is empty
    if(head==NULL){
        head = student;
    } else {
        student->next = head;
        head = student;
    }
}

void addMark(char* Name, int courseNo, float mark){
    struct Student *temp = head;
    while (temp != NULL){
        if(strcmp(temp->Name, Name) == 0){ // if name is the same as the name entred add mark
            temp->Marks[courseNo - 1] = mark; // mark added
            return;
        }
        else{
            temp = temp->next;
        }
    }
}

void printStudentReport(char* Name, struct Student *temp){
    int j;
    if(strcmp(Name, temp->Name) == 0){ // Compares Names in database with the name inputed
        printf("%s \t\t%s \n", temp->Name, temp->noStudents);
        for (j = 0; j < 2; j++){
            printf("\t\t\t\t\tMarks[%d] = %.2f %%\n\n", j+1, temp->Marks[j]);
        }
        printf("\n");
        return;
    } else{
        printStudentReport(Name, temp->next); // recursively recall function
    }
}

// --- MENU --- 
void displayMenu(){
    printf("ATTENDANCE SYSTEM (LINKED LIST). Enter:");
    printf("\n1. Add student");
    printf("\n2. Display a student report");
    printf("\n3. Add marks");
    printf("\n4. Exit");
}

void menu(int option){
    int exit = 0;
    int i, n;
    char Name[20], Phone[100], noStudents[100];
    float Marks[2], Mark;
    struct Student *head = NULL;

    switch(option){
        case 1:
            printf("Enter student name: ");
            scanf("%s", Name);

            printf("Enter student phone number: ");
            scanf("%s", Phone);
            printf("Enter student number: ");
            scanf("%s", noStudents);
            for (i = 0; i < 2; i++){
                Marks[i] = 0;
            }
            addStudent(Name, Phone, noStudents, Marks);
            break;
        case 2:
            printf("Enter name to print: ");
            scanf("%s", Name);
            printf("Name \tStudent Number \tStudent Marks\n\n");
            printStudentReport(Name, head);
            break;
        case 3:
            printf("Enter student name: ");
            scanf("%s", Name);
            printf("Enter course ID: ");
            scanf("%d", &n);
            printf("Enter the mark: ");
            scanf("%f", &Mark);
            addMark(Name, n, Mark);
            break;
        case 4:
            exit = 1;
            break;
    }
}


// --- DRIVER ---
int main(){
    int option = 0;
    int exit = 0;

    while(exit == 0) {
        displayMenu();
        printf("\nOption: ");
        scanf("%d", &option);
        menu(option);
    }
}