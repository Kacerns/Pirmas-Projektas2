#pragma once

#include "lib.h"

// struct stud{
//     string vard, pav;
//     vector<int> nd;
//     int egz = 0;
//     float FinalAverage = 0.0;
//     float median = 0.0;
// };

class stud {
private:
  string vard;
  string pav;
  int egz;
  vector<int> nd;
  float FinalAverage;
  float median;
public:
  Studentas() : egz(0), FinalAverage(0.0), median(0.0)  { }  // default konstruktorius
  Studentas(std::istream& is);
  inline string vardas() const { return vard; }    // get'eriai, inline
  inline string pavarde() const { return pav; }  // get'eriai, inline
  double galBalas(double (*) (vector<double>) = mediana) const;  // get'eriai
  std::istream& readStudent(std::istream&);  // set'eriai
};
