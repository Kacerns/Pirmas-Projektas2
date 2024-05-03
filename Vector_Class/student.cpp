#include "student.hpp"

vector <string> Names {"Audrius", "Edvard", "Ganesh", "Nojus", "Cleophas", "Rodrigo","Jurgita", "Ugne", "Tatiana", "Sarah"};  // Names and Surnames for random generation
vector <string> Surnames {"Czerniewicz", "Finch", "Hummel", "McKowen", "Warszawski", "Clery", "Wilbur", "Kennedy", "Nixon", "Obama"};

stud::stud(std::istream &is) noexcept {
    ReadStudent(is);
};

std::istream& stud::ReadStudent(std::istream& is){

    if(!(is >> vard >> pav)){
        cerr << "Klaida!  Studento vardo ir pavardės skaitymo nuo failo klaida "<< endl;
        throw runtime_error("Klaida!  Studento vardo ir pavardės skaitymo nuo failo klaida ");
    }
    int number = 0;
    int sum = 0;

    while(is >> number){
        nd.push_back(number);
        sum += number;
    }

    if(nd.empty()){
        cerr << "Klaida!  Studento pažymių skaitymo nuo failo klaida "<< endl;
        throw runtime_error("Klaida!  Studento pažymių skaitymo nuo failo klaida ");
    }

    egz = nd.back();
    nd.pop_back();
    sum -=egz;

    CalculateFinalMark(sum);
    return is;

}

float stud::CalculateFinalMark(int sum){
    FinalMark = 0.0;
    int s = nd.size();

    if(s==0){
        FinalMark = egz*0.6;
        return FinalMark;
    }
    if(CountByAvg){
        FinalMark = sum/(float)s*0.4 + 0.6*egz;
        return FinalMark;
    }

    sort(nd.begin(), nd.end()); 
    
    if(s%2!=0){
        FinalMark = nd.at(((float)s/2)-0.5);
        FinalMark = FinalMark*0.4;
    }
    else{
        FinalMark = (float)nd.at((s/2)-1) + nd.at((s/2));
        FinalMark = (FinalMark/2.0)*0.4;
    }
    FinalMark = ((float)egz * 0.6) + FinalMark;
    return FinalMark;
    
}

void stud::GenerateRandomGrades(int Quantity, int counter){
    unsigned seed = (std::chrono::high_resolution_clock::now().time_since_epoch().count()) + counter*Quantity;
    mt19937 rng(seed);
    cout << " Generuojami pažymiai... " << endl;
    std::uniform_int_distribution<int> dist(1, 10);
    egz = dist(rng);
    int sum = 0;
    for(int i = 0; i<Quantity; i++){
        nd.push_back(dist(rng));
        sum += nd.back();
    }
    CalculateFinalMark(sum);
    cout << " Pažymiai sugeneruoti " << endl;
}
void stud::GenerateRandomGrades(int Quantity){
    unsigned seed = (std::chrono::high_resolution_clock::now().time_since_epoch().count()) + Quantity;
    mt19937 rng(seed);
    cout << " Generuojami pažymiai... " << endl;
    std::uniform_int_distribution<int> dist(1, 10);
    egz = dist(rng);
    for(int i = 0; i<Quantity; i++){
        nd.push_back(dist(rng));
    }
    cout << " Pažymiai sugeneruoti " << endl;
}

void stud::GenerateRandomName(int counter){
    unsigned seed = (std::chrono::high_resolution_clock::now().time_since_epoch().count()) + counter;
    mt19937 rng(seed);
    cout << " Generuojami vardai... " << endl;
    std::uniform_int_distribution<int> distNames(0, Names.size()-1);
    std::uniform_int_distribution<int> distSurNames(0, Surnames.size()-1);
    vard = Names.at(distNames(rng));
    pav = Surnames.at(distSurNames(rng));
    cout << " Vardai sugeneruoti " << endl;
}
void stud::GenerateRandomName(){
    unsigned seed = (std::chrono::high_resolution_clock::now().time_since_epoch().count());
    mt19937 rng(seed);
    cout << " Generuojami vardai... " << endl;
    std::uniform_int_distribution<int> distNames(0, Names.size()-1);
    std::uniform_int_distribution<int> distSurNames(0, Surnames.size()-1);
    vard = Names.at(distNames(rng));
    pav = Surnames.at(distSurNames(rng));
    cout << " Vardai sugeneruoti " << endl;
}