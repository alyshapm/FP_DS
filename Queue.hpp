#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <queue>
#include <string>

using namespace std;

template <typename T>
void printQueueElements(queue<T> Q);

void printQueueInfo(int t, queue<string> Q1, queue<string> Q2, queue<string> Q3);

int searchEl(string fname, string lname, queue<string> Q1, queue<string> Q2);

void checkIn(int t, queue<string> Q1);

#endif