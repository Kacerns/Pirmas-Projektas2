#include "student.hpp"

stud::stud(std::istream &is, bool CountByAvg){
    ReadStudent(is, CountByAvg);
};

std::istream& stud::ReadStudent(std::istream& is, bool CountByAvg){

    if(!(is >> vard >> pav)){
        cerr << "Klaida!  Studento vardo ir pavardės skaitymo nuo failo klaida "<< endl;
        throw runtime_error("Klaida!  Studento vardo ir pavardės skaitymo nuo failo klaida ");
    }

    int number;
    int sum;

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
    sum -= egz;

    CalculateFinalMark(CountByAvg, sum);

}

double stud::CalculateFinalMark(bool CountByAvg, int sum){
    int s = nd.size();

    if(s==0){
        FinalMark = egz*0.6;
        return FinalMark;
    }
    if(CountByAvg){
        FinalMark = (FinalMark/s)*0.4 + 0.6*egz;
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
    FinalMark = (float)egz * 0.6 + FinalMark;
    return FinalMark;
    
}

void stud::GenerateRandomGrades(int Quantity, int counter, bool CountByAvg){
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
    CalculateFinalMark(CountByAvg, sum);
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