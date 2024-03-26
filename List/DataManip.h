#pragma once

#include "lib.h"
#include "ErrorHandling.h"

float getAverage(list<stud> &obj, int n, int i);
float getMedian(list<stud> &obj, int n, int i);
void RandomGrades(list<stud> &obj, int counter, int ndcounter);
void RandomNames(list<stud> &obj, int counter);

void sorting(list<stud>& obj, bool option);
bool compareName(const stud& a, const stud& b);
bool compareSurname(const stud& a, const stud& b);
bool compareMedian(const stud& a, const stud& b);
bool compareAverage(const stud& a, const stud& b);

void SplitList(list<stud>& obj, list<stud> &SAD, list<stud> &COOL, bool countByAvg);