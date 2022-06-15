#include "Student.cpp"
#include "ArrayC.cpp"
#include "MapC.cpp"

#include <iostream>
#include <map>
#include<vector>
#include <map>
#include <string>

using namespace std;

void getTime(clock_t start, clock_t endt) {
    double time_taken = double(endt - start) / double(CLOCKS_PER_SEC);
    cout << "Time: " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
}

int main()
{
    vector<vector<string>> student_info1
    {
        {"2502049706", "Arish Madataly", "Math", "45", "OOP", "85", "Data Structure", "89", "Physics", "98", "Chemestry", "78"},
        {"2000868293", "Ywain Lucas", "Math", "28", "OOP", "87", "Data Structure", "96", "Physics", "58", "Chemestry", "88"},
        {"2084106604", "Natalie Sourd", "Math", "48", "OOP", "55", "Data Structure", "99", "Physics", "28", "Chemestry", "48"},
        {"2263115684", "Markus Evelyn", "Math", "95", "OOP", "85", "Data Structure", "79", "Physics", "18", "Chemestry", "18"},
        {"2533157213", "Mina Jeppesen", "Math", "75", "OOP", "88", "Data Structure", "56", "Physics", "71", "Chemestry", "40"},
        {"2425489624", "Hana Conner", "Math", "82", "OOP", "85", "Data Structure", "88", "Physics", "99", "Chemestry", "55"},
        {"2526431179", "Embla Dallas", "Math", "46", "OOP", "5", "Data Structure", "9", "Physics", "8", "Chemestry", "99"},
        {"2241952647", "Priyanka Enns", "Math", "33", "OOP", "87", "Data Structure", "80", "Physics", "98", "Chemestry", "11"},
        {"2194341552", "Torsten Andrews", "Math", "44", "OOP", "25", "Data Structure", "49", "Physics", "10", "Chemestry", "56"},
        {"2531824458", "Draco Paris", "Math", "75", "OOP", "75", "Data Structure", "23", "Physics", "63", "Chemestry", "66"},
        {"2305971183", "Bret Petersson", "Math", "20", "OOP", "80", "Data Structure", "70", "Physics", "90", "Chemestry", "10"},
        {"2393473251", "Alkibiades Wild", "Math", "99", "OOP", "100", "Data Structure", "100", "Physics", "100", "Chemestry", "100"},
        {"2233667131", "Domitia Paddon", "Math", "23", "OOP", "22", "Data Structure", "29", "Physics", "27", "Chemestry", "15"},
        {"2060799803", "Amar Addison", "Math", "85", "OOP", "55", "Data Structure", "74", "Physics", "45", "Chemestry", "26"},
        {"2393700208", "Perdita Penders", "Math", "15", "OOP", "86", "Data Structure", "91", "Physics", "47", "Chemestry", "19"},
        {"2510316472", "Medousa Mertens", "Math", "24", "OOP", "75", "Data Structure", "56", "Physics", "43", "Chemestry", "65"},
        {"2528310820", "Miroslava MacDermott", "Math", "52", "OOP", "12", "Data Structure", "75", "Physics", "47", "Chemestry", "54"},
        {"2489701836", "Flora Janson", "Math", "60", "OOP", "70", "Data Structure", "41", "Physics", "82", "Chemestry", "75"},
        {"2320898036", "Marie-Françoise Beck", "Math", "12", "OOP", "14", "Data Structure", "5", "Physics", "8", "Chemestry", "25"},
        {"2515900124", "Benigno Mancuso", "Math", "17", "OOP", "26", "Data Structure", "39", "Physics", "69", "Chemestry", "100"},
        {"2243624098", "Sara Gustafsson", "Math", "14", "OOP", "56", "Data Structure", "23", "Physics", "79", "Chemestry", "94"},
        {"2376356683", "Cyrus Chancellor", "Math", "74", "OOP", "85", "Data Structure", "83", "Physics", "39", "Chemestry", "31"},
        {"2250401101", "Alexandra North", "Math", "54", "OOP", "66", "Data Structure", "83", "Physics", "69", "Chemestry", "31"},
        {"2564508815", "Francis Borgogni", "Math", "44", "OOP", "46", "Data Structure", "43", "Physics", "49", "Chemestry", "51"},
        {"2515900124", "Feriha Hart", "Math", "24", "OOP", "26", "Data Structure", "23", "Physics", "29", "Chemestry", "21"}, //already assigned id
        {"2130116012", "Idrissa Dunn", "Math", "24", "OOP", "26", "Data Structure", "23", "Physics", "29", "Chemestry", "21"},
        {"2240240857", "Bojan Kranz", "Math", "24", "OOP", "26", "Data Structure", "23", "Physics", "29", "Chemestry", "21"},
        {"2225416823", "Soline Aarse", "Math", "14", "Math", "56", "Data Structure", "83", "Physics", "74", "Chemestry", "12"}, //twice assigned subject
        {"2583648703", "Arif Dobson", "Math", "99", "OOP", "94", "Data Structure", "93", "Physics", "99", "Chemestry", "32"},
        {"2583648703", "Arif Dobson", "Math", "97", "OOP", "94", "Data Structure", "93", "Physics", "99", "Chemestry", "32"},
        {"2583648703", "Arif Dobson", "Math", "97", "OOP", "94", "Data Structure", "93", "Physics", "99", "Chemestry", "32"}
    };

    Student student_list[30];
    map<unsigned long, map<string, map<string, int>>> m;
    unsigned long ID;
    string name, course1, course2, course3, course4, course5;
    int mark1, mark2, mark3, mark4, mark5;
    clock_t start1, endt1, start2, endt2, start3, endt3, start4, endt4, start5, endt5, start6, endt6;

    for (int i = 0; i < 30; i++){
        ID = stoul(student_info1[i][0], nullptr, 0);
        name = student_info1[i][1];

        m = register_student(m, ID, name);
        addStudent(ID, name, student_list);
    }

    // ------------MAP------------
    cout << "Map: " << endl;
    start1 = clock();
    for (int i = 0; i < 10; i++) {
        ID = stoul(student_info1[i][0], nullptr, 0);

        course1 = student_info1[i][2];
        mark1 = stoi(student_info1[i][3]);
        course2 = student_info1[i][4];
        mark2 = stoi(student_info1[i][5]);
        course3 = student_info1[i][6];
        mark3 = stoi(student_info1[i][7]);
        course4 = student_info1[i][8];
        mark4 = stoi(student_info1[i][9]);
        course5 = student_info1[i][10];
        mark5 = stoi(student_info1[i][11]);

        m = addCourse(m, ID, course1, mark1);
        m = addCourse(m, ID, course2, mark2);
        m = addCourse(m, ID, course3, mark3);
        m = addCourse(m, ID, course4, mark4);
        m = addCourse(m, ID, course5, mark5);


        find_student_by_ID(m, ID);

        cout << endl;
    }
    endt1  = clock();

    start2 = clock();
    for (int i = 0; i < 20; i++) {
        ID = stoul(student_info1[i][0], nullptr, 0);

        course1 = student_info1[i][2];
        mark1 = stoi(student_info1[i][3]);
        course2 = student_info1[i][4];
        mark2 = stoi(student_info1[i][5]);
        course3 = student_info1[i][6];
        mark3 = stoi(student_info1[i][7]);
        course4 = student_info1[i][8];
        mark4 = stoi(student_info1[i][9]);
        course5 = student_info1[i][10];
        mark5 = stoi(student_info1[i][11]);

        m = addCourse(m, ID, course1, mark1);
        m = addCourse(m, ID, course2, mark2);
        m = addCourse(m, ID, course3, mark3);
        m = addCourse(m, ID, course4, mark4);
        m = addCourse(m, ID, course5, mark5);


        find_student_by_ID(m, ID);

        cout << endl;
    }
    endt2 = clock();

    start3 = clock();
    for (int i = 0; i < 30; i++) {
        ID = stoul(student_info1[i][0], nullptr, 0);

        course1 = student_info1[i][2];
        mark1 = stoi(student_info1[i][3]);
        course2 = student_info1[i][4];
        mark2 = stoi(student_info1[i][5]);
        course3 = student_info1[i][6];
        mark3 = stoi(student_info1[i][7]);
        course4 = student_info1[i][8];
        mark4 = stoi(student_info1[i][9]);
        course5 = student_info1[i][10];
        mark5 = stoi(student_info1[i][11]);

        m = addCourse(m, ID, course1, mark1);
        m = addCourse(m, ID, course2, mark2);
        m = addCourse(m, ID, course3, mark3);
        m = addCourse(m, ID, course4, mark4);
        m = addCourse(m, ID, course5, mark5);


        find_student_by_ID(m, ID);

        cout << endl;
    }
    endt3 = clock();


     cout << endl;
     cout << endl;

     //------------Array------------
     cout << "Array: " << endl;
     start4 = clock();
     for (int i = 0; i < 10; i++) {
        ID = stoul(student_info1[i][0], nullptr, 0);

        course1 = student_info1[i][2];
        mark1 = stoi(student_info1[i][3]);
        course2 = student_info1[i][4];
        mark2 = stoi(student_info1[i][5]);
        course3 = student_info1[i][6];
        mark3 = stoi(student_info1[i][7]);
        course4 = student_info1[i][8];
        mark4 = stoi(student_info1[i][9]);
        course5 = student_info1[i][10];
        mark5 = stoi(student_info1[i][11]);


        if (searchStudent(ID, student_list) != -1) {
            int index = searchStudent(ID, student_list);
            student_list[index].addCourse(course1, mark1);
            student_list[index].addCourse(course2, mark2);
            student_list[index].addCourse(course3, mark3);
            student_list[index].addCourse(course4, mark4);
            student_list[index].addCourse(course5, mark5);
            student_list[index].printReport();
        }
    }
    endt4 = clock();


     start5 = clock();
     for (int i = 0; i < 20; i++) {
        ID = stoul(student_info1[i][0], nullptr, 0);

        course1 = student_info1[i][2];
        mark1 = stoi(student_info1[i][3]);
        course2 = student_info1[i][4];
        mark2 = stoi(student_info1[i][5]);
        course3 = student_info1[i][6];
        mark3 = stoi(student_info1[i][7]);
        course4 = student_info1[i][8];
        mark4 = stoi(student_info1[i][9]);
        course5 = student_info1[i][10];
        mark5 = stoi(student_info1[i][11]);


        if (searchStudent(ID, student_list) != -1) {
            int index = searchStudent(ID, student_list);
            student_list[index].addCourse(course1, mark1);
            student_list[index].addCourse(course2, mark2);
            student_list[index].addCourse(course3, mark3);
            student_list[index].addCourse(course4, mark4);
            student_list[index].addCourse(course5, mark5);
            student_list[index].printReport();
        }
    }
    endt5 = clock();

    start6 = clock();
     for (int i = 0; i < 30; i++) {
        ID = stoul(student_info1[i][0], nullptr, 0);

        course1 = student_info1[i][2];
        mark1 = stoi(student_info1[i][3]);
        course2 = student_info1[i][4];
        mark2 = stoi(student_info1[i][5]);
        course3 = student_info1[i][6];
        mark3 = stoi(student_info1[i][7]);
        course4 = student_info1[i][8];
        mark4 = stoi(student_info1[i][9]);
        course5 = student_info1[i][10];
        mark5 = stoi(student_info1[i][11]);


        if (searchStudent(ID, student_list) != -1) {
            int index = searchStudent(ID, student_list);
            student_list[index].addCourse(course1, mark1);
            student_list[index].addCourse(course2, mark2);
            student_list[index].addCourse(course3, mark3);
            student_list[index].addCourse(course4, mark4);
            student_list[index].addCourse(course5, mark5);
            student_list[index].printReport();
        }
    }
    endt6 = clock();

    cout << "Map:" << endl;
    cout << "For 10 students: ";
    getTime(start1, endt1);
    cout << "For 20 students: ";
    getTime(start2, endt2);
    cout << "For 30 students: ";
    getTime(start3, endt3);

    cout << "Array:" << endl;
    cout << "For 10 students: ";
    getTime(start4, endt4);
    cout << "For 20 students: ";
    getTime(start5, endt5);
    cout << "For 30 students: ";
    getTime(start6, endt6);
}
