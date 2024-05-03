#pragma once

#include "lib.h"
#include "DataManip.h"
#include "student.hpp"
#include "ErrorHandling.h"

void Assign(vector<stud> &obj, bool countByAvg);
void Print (const vector<stud> &obj);
void readFile(vector<stud>& obj, const string filename, const bool countByAvg);
void PrintFile(const vector<stud> &obj, string filename);
void CreateFile(string& filename);
void OutputTime();