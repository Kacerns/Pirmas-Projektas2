#include "DataManip.h"

vector <string> Names {"Audrius", "Edvard", "Ganesh", "Nojus", "Cleophas", "Rodrigo","Jurgita", "Ugne", "Tatiana", "Sarah"};
vector <string> Surnames {"Czerniewicz", "Finch", "Hummel", "McKowen", "Warszawski", "Clery", "Wilbur", "Kennedy", "Nixon", "Obama"};


float getAverage(list<stud> &obj, int s, int i){
    auto temp = obj.begin();
    std::advance(temp, i);
    temp->FinalAverage = temp->FinalAverage/s;
    temp->FinalAverage = temp->FinalAverage * 0.4;
    temp->FinalAverage = (float)temp->egz * 0.6 + temp->FinalAverage;
    return temp->FinalAverage;
}

float getMedian(std::list<stud> &obj, int s, int i) {
    auto temp = obj.begin();
    std::advance(temp, i);

    temp->nd.sort();

    if (s % 2 == 0) {
        auto middle1 = std::next(temp->nd.begin(), s / 2 - 1);
        auto middle2 = std::next(temp->nd.begin(), s / 2);
        temp->median = (*middle1 + *middle2) / 2.0f;
    } else {
        auto middle = std::next(temp->nd.begin(), s / 2);
        temp->median = *middle;
    }

    temp->median *= 0.4;
    temp->median += static_cast<float>(temp->egz) * 0.6;

    return temp->median;
}

void RandomGrades(list<stud> &obj, int counter, int ndcounter){
    unsigned seed = (std::chrono::high_resolution_clock::now().time_since_epoch().count()) + counter*ndcounter;
    mt19937 rng(seed);
    cout << " Generuojami pažymiai... " << endl;
    std::uniform_int_distribution<int> dist(1, 10);
    auto it = obj.begin();
    std::advance(it, counter);
    it->egz = dist(rng);
    for(int i = 0; i<ndcounter; i++){
        it->nd.push_back(dist(rng));
        it->FinalAverage += it->nd.back();
    }
    cout << " Pažymiai sugeneruoti " << endl;
}

void RandomNames(list<stud> &obj, int counter){
    unsigned seed = (std::chrono::high_resolution_clock::now().time_since_epoch().count()) + counter;
    mt19937 rng(seed);
    cout << " Generuojami vardai... " << endl;
    std::uniform_int_distribution<int> distNames(0, Names.size()-1);
    std::uniform_int_distribution<int> distSurNames(0, Surnames.size()-1);
    auto it = obj.begin();
    std::advance(it, counter);
    it->vard = Names.at(distNames(rng));
    it->pav = Surnames.at(distSurNames(rng));
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

void sorting(list<stud>& obj, bool countByAvg){
    
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
                obj.sort(compareName);
                auto stoptime = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> diff = stoptime-start;
                Marktime.emplace_back(diff.count());
                end = true;
                break;
            }
            case (2):{
                auto start = std::chrono::high_resolution_clock::now();
                obj.sort(compareSurname);
                auto stoptime = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> diff = stoptime-start;
                Marktime.emplace_back(diff.count());
                end = true;
                break;
            }
            case (3):{
                auto start = std::chrono::high_resolution_clock::now();
                obj.sort(countByAvg ? compareAverage : compareMedian);
                auto stoptime = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> diff = stoptime-start;
                Marktime.emplace_back(diff.count());
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

void SplitList(list<stud>& obj, list<stud> &SAD, list<stud> &COOL, bool countByAvg){

        int temp;
    cout << "Strategija : 1, 2, 3" << endl;
    cin >> temp;
    ClearCin();
    switch (temp)
    {
    case 1:{
        auto start = std::chrono::high_resolution_clock::now();
        if(countByAvg){
            for(auto student : obj){
                if(student.FinalAverage < 5){
                    SAD.push_back(student);
                }
                else{
                    COOL.push_back(student);
                }
            }
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff = end-start;
            Marktime.emplace_back(diff.count());
        }
        else{
            for(auto student : obj){
                if(student.median < 5){
                    SAD.push_back(student);
                }
                else{
                    COOL.push_back(student);
                }
            }
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff = end-start;
            Marktime.emplace_back(diff.count());
        }
        break;
    }
    case 2:{
        auto start = std::chrono::high_resolution_clock::now();
        if (countByAvg) {
            int index = 0;
            auto it_end = obj.end();
            for (auto student = obj.begin(); student != it_end;) {
                if (student->FinalAverage < 5) {
                    SAD.emplace_back(*student);
                    auto it1 = student;
                    auto it2 = std::prev(obj.end(), index);
                    std::iter_swap(it1, it2);
                    it_end = std::prev(it_end);
                    index++;
                } else {
                    ++student;
                }
            }
            auto eraseIndex = std::prev(obj.end(), index+1);
            obj.erase(eraseIndex, obj.end());
            obj.sort(compareAverage);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff = end - start;
            Marktime.emplace_back(diff.count());
        } else {
            int index = 0;
            auto it_end = obj.end();
            for (auto student = obj.begin(); student != it_end;) {
                if (student->median < 5) {
                    SAD.emplace_back(*student);
                    auto it1 = student;
                    auto it2 = std::prev(obj.end(), index+1);
                    std::iter_swap(it1, it2);
                    it_end = std::prev(it_end);
                    index++;
                } else {
                    ++student;
                }
            }
            auto eraseIndex = std::prev(obj.end(), index);
            obj.erase(eraseIndex, obj.end());
            obj.sort(compareMedian);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff = end - start;
            Marktime.emplace_back(diff.count());
        }
        break;
    }
    case 3:{
        auto start = std::chrono::high_resolution_clock::now();
        if(countByAvg){
            std::remove_copy_if(obj.begin(), obj.end(), std::back_inserter(SAD), [](const auto& student){return student.FinalAverage >= 5;});
            obj.erase(std::remove_if(obj.begin(), obj.end(),[](const auto& student){ return student.FinalAverage >= 5; }), obj.end());
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff = end-start;
            Marktime.emplace_back(diff.count());
        }
        else{
            std::remove_copy_if(obj.begin(), obj.end(), std::back_inserter(SAD), [](const auto& student){return student.median >= 5;});
            obj.erase(std::remove_if(obj.begin(), obj.end(),[](const auto& student){ return student.median >= 5;}), obj.end());
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff = end-start;
            Marktime.emplace_back(diff.count());
        }
        break;
    }
    default:{
        break;
    }
    }
}