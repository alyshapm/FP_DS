#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

void print_map(map<int, map<string, map<string, int> > > m);

map<int, map<string, map<string, int> > > register_student(map<int, map<string, map<string, int> > > m, int ID, string name);

void find_student_by_ID(map<int, map<string, map<string, int> > > m, int ID);

void find_student_by_Name(map<int, map<string, map<string, int> > > m, string name);

map<int, map<string, map<string, int> > > addCourse(map<int, map<string, map<string, int> > > m, int ID, string course, int mark);

map<int, map<string, map<string, int> > > modifyCourse(map<int, map<string, map<string, int> > > m, int ID, string course, string newCourse);

map<int, map<string, map<string, int> > > modifyMarks(map<int, map<string, map<string, int> > > m, int ID, string course, int mark);

map<int, map<string, map<string, int> > > deleteStudent(map<int, map<string, map<string, int> > > m, int ID);

void displayMenu();

#endif