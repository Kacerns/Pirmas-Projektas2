#include "DataManip.h"


void sorting(vector<stud>& obj){
    
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
                sort(obj.begin(), obj.end(), stud::compareName);//Galimai klaida??
                auto stoptime = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> diff = stoptime-start;
                Marktime.emplace_back(diff.count());
                end = true;
                break;
            }
            case (2):{
                auto start = std::chrono::high_resolution_clock::now();
                sort(obj.begin(), obj.end(), stud::compareSurname);
                auto stoptime = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> diff = stoptime-start;
                Marktime.emplace_back(diff.count());
                end = true;
                break;
            }
            case (3):{
                auto start = std::chrono::high_resolution_clock::now();
                sort(obj.begin(), obj.end(), stud::compareMark);
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

void SplitVector(vector<stud>& obj, vector<stud> &SAD, vector<stud> &COOL){
    
    auto start = std::chrono::high_resolution_clock::now();
    std::copy_if(obj.begin(), obj.end(), std::back_inserter(SAD), [](const stud& student){return student.getEgzamRez() < 5;});
    obj.erase(std::remove_if(obj.begin(), obj.end(),[](const stud& student){ return student.getEgzamRez() < 5; }), obj.end());
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;
    Marktime.emplace_back(diff.count());
}