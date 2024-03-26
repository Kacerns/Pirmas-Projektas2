#pragma once

#include "lib.h"
#include "DataManip.h"
#include "ErrorHandling.h"

void Assign(list<stud> &obj);
void Print (list<stud> &obj, bool countByAvg);
void readFile(list<stud>& obj, const string filename, const bool countByAvg);
void PrintFile(list<stud> &obj, bool countByAvg, string filename);
void CreateFile(string& filename);
void OutputTime();