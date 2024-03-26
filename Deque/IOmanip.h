#pragma once

#include "lib.h"
#include "DataManip.h"
#include "ErrorHandling.h"

void Assign(vector<stud> &obj);
void Print (vector<stud> &obj, bool countByAvg);
void readFile(vector<stud>& obj, const string filename, const bool countByAvg);
void PrintFile(vector<stud> &obj, bool countByAvg, string filename);
void CreateFile(string& filename);
void OutputTime();