#pragma once

#include "lib.h"

class stud {
private:
  string vard;
  string pav;
  float egz;
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
    FinalMark(0.0)
  {}
  stud(std::istream &is, bool CountByAvg) noexcept;
  stud(string vard_, string pav_, int egz_, vector<int> nd_) noexcept :
    vard(vard_),
    pav(pav_),
    egz(egz_),
    nd(nd_),
    FinalMark(0.0)
  {}  //constructors end

  string getName() const { return vard; } //setters and getters start
  void setName(string str) { vard = str; }

  string getSurname() const { return pav; }
  void setSurname(string str) { pav = str; }

  float getEgzamRez() const { return egz; }
  void setEgzamRez(int i) { egz = i; }

  float getFinalMark() const { return FinalMark; }

  vector<int>& getHomeWorkRez() { return nd; }
  int getHomeWorkSize() { return nd.size(); }
  void setHomeWorkRez(vector<int> vec) { nd = vec; } //setters and getters end

  ~stud() {nd.clear();} //destructor

  float CalculateFinalMark(bool CountByAvg, int sum); //Methods start

  std::istream& ReadStudent(std::istream& is, bool CountByAvg);

  void AddMark(int grade){nd.push_back(grade);}

  void GenerateRandomGrades(int Quantity, int counter, bool CountByAvg);

  void GenerateRandomName(int counter);

  bool static compareName(const stud& a, const stud& b){return a.vard < b.vard;}
  bool static compareSurname(const stud& a, const stud& b){return a.pav < b.pav;}
  bool static compareMark(const stud& a, const stud& b){return a.FinalMark < b.FinalMark;} // Methods end

  stud& operator=(const stud& obj) { // Rule of five
    if(this != &obj){
      vard = obj.vard;
      pav = obj.pav;
      egz = obj.egz;
      nd = obj.nd;
      FinalMark = obj.FinalMark;
    }
    return *this;
  }

  stud& operator=(stud&& obj) noexcept {
    if(this != &obj){
      vard = move(obj.vard);
      pav = move(obj.pav);
      egz = move(obj.egz);
      nd = move(obj.nd);
      FinalMark = move(obj.FinalMark);
      obj.vard.clear();
      obj.pav.clear();
      obj.egz = 0;
      obj.nd.clear();
      obj.FinalMark = 0.0;
    }
    return *this;
  }

  stud(const stud& obj){
    vard = obj.vard;
    pav = obj.pav;
    egz = obj.egz;
    nd = obj.nd;
    FinalMark = obj.FinalMark;
  }

  stud(stud&& obj) noexcept : 
    vard(move(obj.vard)),
    pav(move(obj.pav)),
    egz(move(obj.egz)),
    nd(move(obj.nd)),
    FinalMark(move(obj.FinalMark))
  {
    obj.vard.clear();
    obj.pav.clear();
    obj.egz = 0;
    obj.nd.clear();
    obj.FinalMark = 0.0;
  }

  friend std::ostream &operator<<(std::ostream &out, const stud &obj){
    out << setw(26) << left << obj.vard << setw(26) << left << obj.pav << setw(15) << setprecision(2) << fixed << left << obj.FinalMark << endl;
    return out;
  }
  friend std::istream &operator>>(std::istream &in, stud &obj){
    in >> obj.vard >> obj.pav;
    int sum = 0;
    int number = 0;

    while(in >> number){
        obj.nd.push_back(number);
        sum += number;
    }

    if(obj.nd.empty()){
      cerr << "Klaida!  Studento pažymių skaitymo nuo failo klaida "<< endl;
      throw runtime_error("Klaida!  Studento pažymių skaitymo nuo failo klaida ");
    }

    obj.egz = obj.nd.back();
    obj.nd.pop_back();
    sum -= obj.egz;

    obj.FinalMark = 0.0;
    int s = obj.nd.size();

    if(s==0){
      obj.FinalMark = obj.egz*0.6;
    }
    obj.FinalMark = sum/(float)s*0.4 + 0.6*obj.egz;

    return in;
  }
  
};
