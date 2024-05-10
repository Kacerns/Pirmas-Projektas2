#pragma once

#include "lib.h"
extern bool CountByAvg;

class zmogus{
protected:
  string vard;
  string pav;
public:
  virtual string getName() const = 0; // setters and getters start
  virtual void setName(string str) { vard = str; }

  virtual string getSurname() const = 0;
  virtual void setSurname(string str) { pav = str; } // setters and getters end

  virtual ~zmogus(){}; // destructor
};

class stud : public zmogus {
private:
  float egz;
  vector<int> nd;
  float FinalMark;
public:
  stud() noexcept : zmogus()//constructors start
  { vard = "";
    pav = "";
    egz = 0;
    nd.clear();
    FinalMark=0.0;
  }
  stud(std::istream &is) noexcept;
  stud(string vard_, string pav_, int egz_, vector<int> nd_) noexcept : zmogus()
  {
    vard = vard_;
    pav = pav_;
    egz = egz_;
    nd = nd_;
    int sum = 0;
    for(int i : nd){sum+=i;};
    CalculateFinalMark(sum);
  }  //constructors end

  float getEgzamRez() const { return egz; } // setters and getters start
  void setEgzamRez(int i) { egz = i; }

  string getName() const {return vard;} // setters and getters start
  void setName(string str) { vard = str; }

  string getSurname() const {return pav;}
  void setSurname(string str) { pav = str; } // setters and getters end

  float getFinalMark() const { return FinalMark; }

  vector<int>& getHomeWorkRez() { return nd; }
  int getHomeWorkSize() { return nd.size(); }
  void setHomeWorkRez(vector<int> vec) { nd = vec; } // setters and getters end

  ~stud() {nd.clear();} // destructor

  float CalculateFinalMark(int sum); // Methods start

  std::istream& ReadStudent(std::istream& is);

  void AddMark(int grade){nd.push_back(grade);}

  void GenerateRandomGrades(int Quantity, int counter);
  void GenerateRandomGrades(int Quantity);

  void GenerateRandomName(int counter);
  void GenerateRandomName();

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

    cout << "\nCopy operator called\n";
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
    cout << "\nMove operator called\n";
    return *this;
  }

  stud(const stud& obj):zmogus(){
    vard = obj.vard;
    pav = obj.pav;
    egz = obj.egz;
    nd = obj.nd;
    FinalMark = obj.FinalMark;
    cout << "\nCopy constructor called\n"<<endl;
  }

  stud(stud&& obj) noexcept:zmogus()
  {
    vard = (move(obj.vard));
    pav = (move(obj.pav));
    egz = (move(obj.egz));
    nd = (move(obj.nd));
    FinalMark = (move(obj.FinalMark));
    obj.vard.clear();
    obj.pav.clear();
    obj.egz = 0;
    obj.nd.clear();
    obj.FinalMark = 0.0;
    cout << "\nMove constructor called\n"<<endl;
  }

  friend std::ostream &operator<<(std::ostream &out, const stud &obj){
    out << setw(26) << left << obj.vard << setw(26) << left << obj.pav << setw(15) << setprecision(2) << fixed << left << obj.FinalMark << endl;
    return out;
  }
  friend std::istream &operator>>(std::istream &in, stud &obj){

    bool pass = false;
    char optionForGeneration;
    auto Cinadress = &std::cin;
    if(&in == Cinadress){
      cout<<"Ar norite generuoti random varda ir pavarde? Y/N"<<endl;
      in >> optionForGeneration;
      optionForGeneration == 'Y' ? pass = true : pass = false;
    }
    if(pass){
      obj.GenerateRandomName();
      pass = false;
    }
    else{
      if(&in == Cinadress){cout<<"Iveskite varda ir pavarde atskirta tarpu"<<endl;}
      in >> obj.vard;
      in >> obj.pav;
    }

    int number = 0;
    if(&in == Cinadress){
      cout<<"Ar norite generuoti random pazymius? Y/N"<<endl;
      in >> optionForGeneration;
      optionForGeneration == 'Y' ? pass = true : pass = false;
    }
    if(pass){
      cout<<"Kiek namu darbu pazymiu norite?"<<endl;
      in >> number;
      obj.GenerateRandomGrades(number);
    }
    else{
      if(&in == Cinadress){cout<<"Iveskite visus pazymius (iskaitant egzamino kaip paskutini), norint baigti parasykite raide"<<endl;}
      while(in >> number){
        obj.nd.push_back(number);
      }
      obj.egz = obj.nd.back();
      obj.nd.pop_back();
    }

    if(obj.nd.empty()){
      cerr << "Klaida!  Studento pažymių skaitymo nuo failo klaida "<< endl;
      throw runtime_error("Klaida!  Studento pažymių skaitymo nuo failo klaida ");
    }
    int ndSum = 0;
    for(int i : obj.nd){ndSum+=i;};

    obj.CalculateFinalMark(ndSum);

    return in;
  }
  
};
