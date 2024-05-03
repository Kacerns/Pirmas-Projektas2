#pragma once

#include "lib.h"
#include "student.hpp"

void CopyOpConTest(stud &Tester1, stud &Tester2);
void MoveOpConTest(stud &Tester1, stud &Tester2);
void OutputTest(const stud& Tester);
void OutputTestFile(const stud& Tester, string filename);
stud IstreamInputTest(stud& Tester, string filename);
stud CinInputTest(stud& Tester);
