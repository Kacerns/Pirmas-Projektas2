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
  float FinalMark;
public:
  vector <string> Names {"Audrius", "Edvard", "Ganesh", "Nojus", "Cleophas", "Rodrigo","Jurgita", "Ugne", "Tatiana", "Sarah"};  // Names and Surnames for random generation
  vector <string> Surnames {"Czerniewicz", "Finch", "Hummel", "McKowen", "Warszawski", "Clery", "Wilbur", "Kennedy", "Nixon", "Obama"};

  stud() noexcept : //constructors start
    vard(""),
    pav(""),
    egz(0),
    nd(0),
    FinalMark(0)
  {}
  stud(std::istream &is, bool CountByAvg) noexcept;
  stud(string vard_, string pav_, int egz_, vector<int> nd_) noexcept :
    vard(vard_),
    pav(pav_),
    egz(egz_),
    nd(nd_),
    FinalMark(0)
  {}  //constructors end

  string getName() const { return vard; } //setters and getters start
  void setName(string str) { vard = str; }

  string getSurname() const { return pav; }
  void setSurname(string str) { pav = str; }

  int getEgzamRez() const { return egz; }
  void setEgzamRez(int i) { egz = i; }

  vector<int>& getHomeWorkRez() { return nd; }
  int getHomeWorkSize() { return nd.size(); }
  void setHomeWorkRez(vector<int> vec) { nd = vec; } //setters and getters end

  ~stud() {nd.clear();} //destructor

  double CalculateFinalMark(bool CountByAvg, int sum); //Methods start

  std::istream& ReadStudent(std::istream& is, bool CountByAvg);

  void AddMark(int grade){nd.push_back(grade);}

  void GenerateRandomGrades(int Quantity, int counter, bool CountByAvg);

  void GenerateRandomName(int counter);
};
