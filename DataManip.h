#pragma once

#include "lib.h"
#include "ErrorHandling.h"

float getAverage(vector<stud> &obj, int n, int i);
float getMedian(vector<stud> &obj, int n, int i);
void RandomGrades(vector<stud> &obj, int counter, int ndcounter);
void RandomNames(vector<stud> &obj, int counter);

void sorting(vector<stud>& obj, bool option);
bool compareName(const stud& a, const stud& b);
bool compareSurname(const stud& a, const stud& b);
bool compareMedian(const stud& a, const stud& b);
bool compareAverage(const stud& a, const stud& b);