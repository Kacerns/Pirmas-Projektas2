#include "DataManip.h"

vector <string> Names {"Audrius", "Edvard", "Ganesh", "Nojus", "Cleophas", "Rodrigo","Jurgita", "Ugne", "Tatiana", "Sarah"};
vector <string> Surnames {"Czerniewicz", "Finch", "Hummel", "McKowen", "Warszawski", "Clery", "Wilbur", "Kennedy", "Nixon", "Obama"};


float getAverage(vector<stud> &obj, int s, int i){
    obj.at(i).FinalAverage = obj.at(i).FinalAverage/s;
    obj.at(i).FinalAverage = obj.at(i).FinalAverage * 0.4;
    obj.at(i).FinalAverage = (float)obj.at(i).egz * 0.6 + obj.at(i).FinalAverage;
    return obj.at(i).FinalAverage;
}

float getMedian(vector<stud> &obj, int s, int i){
    if(s%2==0){
        obj.at(i).median = (float)obj.at(i).nd.at((s/2)-1) + (float)obj.at(i).nd.at((s/2));
        obj.at(i).median = obj.at(i).median/2.0;
        obj.at(i).median = obj.at(i).median*0.4;
    }
    else{
        int temp = ((float)s/2)-0.5;
        obj.at(i).median = obj.at(i).nd.at(temp);
        obj.at(i).median = obj.at(i).median*0.4;
    }
    obj.at(i).median = (float)obj.at(i).egz * 0.6 + obj.at(i).median;
    return obj.at(i).median;
}

void RandomGrades(vector<stud> &obj, int counter, int ndcounter){
    unsigned seed = (std::chrono::high_resolution_clock::now().time_since_epoch().count()) + counter*ndcounter;
    mt19937 rng(seed);
    cout << " Generuojami pažymiai... " << endl;
    std::uniform_int_distribution<int> dist(1, 10);
    obj.at(counter).egz = dist(rng);
    for(int i = 0; i<ndcounter; i++){
        obj.at(counter).nd.push_back(dist(rng));
        obj.at(counter).FinalAverage += obj.at(counter).nd.back();
    }
    cout << " Pažymiai sugeneruoti " << endl;
}

void RandomNames(vector<stud> &obj, int counter){
    unsigned seed = (std::chrono::high_resolution_clock::now().time_since_epoch().count()) + counter;
    mt19937 rng(seed);
    cout << " Generuojami vardai... " << endl;
    std::uniform_int_distribution<int> distNames(0, Names.size()-1);
    std::uniform_int_distribution<int> distSurNames(0, Surnames.size()-1);
    obj.at(counter).vard = Names.at(distNames(rng));
    obj.at(counter).pav = Surnames.at(distSurNames(rng));
    cout << " Vardai sugeneruoti " << endl;
}

//V.0.2



bool compareName(const stud& a, const stud& b){
    return a.vard < b.vard;
}
bool compareSurname(const stud& a, const stud& b){
    return a.pav < b.pav;
}
bool compareMedian(const stud& a, const stud& b){
    return a.median < b.median;
}
bool compareAverage(const stud& a, const stud& b){
    return a.FinalAverage < b.FinalAverage;
}

void sorting(vector<stud>& obj, bool countByAvg){
    
    int option;
    bool end = false;
    while (!end) {
        cout << "Pasirinkite duomenų rikiavimo būdą: "<<endl;
        cout << "(1) rikiuoti pagal vardą." << endl << "(2) rikiuoti pagal pavardę" << endl <<  "(3) rikiuoti pagal pažymį" << endl;
        cin >> option;
        ClearCin();

        switch (option) {
            case (1):{
                auto start = std::chrono::high_resolution_clock::now();
                sort(obj.begin(), obj.end(), compareName);
                auto stoptime = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> diff = stoptime-start;
                cout << " Sorting time:  " << diff.count() << endl;
                end = true;
                break;
            }
            case (2):{
                auto start = std::chrono::high_resolution_clock::now();
                sort(obj.begin(), obj.end(), compareSurname);
                auto stoptime = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> diff = stoptime-start;
                cout << " Sorting time:  " << diff.count() << endl;
                end = true;
                break;
            }
            case (3):{
                auto start = std::chrono::high_resolution_clock::now();
                sort(obj.begin(), obj.end(), countByAvg ? compareAverage : compareMedian);
                auto stoptime = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> diff = stoptime-start;
                cout << " Sorting time:  " << diff.count() << endl;
                end = true;
                break;
            }
            default:{
                cout << " Pateikėte netinkamą simbolį, bandykite iš naujo" << endl;
                break;
            }
        }
    }
}