#pragma once

#include "lib.h"
#include "DataManip.h"
#include "ErrorHandling.h"

void Assign(vector<stud> &obj);
void Print (vector<stud> &obj, bool countByAvg);
void readFile(vector<stud> &obj, const string filename);
void PrintFile(vector<stud> &obj, bool countByAvg);
void CreateFile(string& filename);