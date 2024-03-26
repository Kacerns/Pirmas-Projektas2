#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <fstream>
#include <deque>
#include <list>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::deque;
using std::list;
using std::endl;
using std::mt19937;
using std::setw;
using std::setprecision;
using std::left;
using std::fixed;
using std::cerr;
using std::out_of_range;
using std::invalid_argument;
using std::runtime_error;
using std::getline;
using std::numeric_limits;
using std::streamsize;
using std::ifstream;
using std::exception;
using std::istringstream;
using std::ofstream;
using std::ostringstream;

struct stud{
    string vard, pav;
    vector<int> nd;
    int egz = 0;
    float FinalAverage = 0.0;
    float median = 0.0;
};

extern vector<double> Marktime;
extern vector<double> AverageTime;