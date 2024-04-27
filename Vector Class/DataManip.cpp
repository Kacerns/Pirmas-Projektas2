#include "DataManip.h"

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
                Marktime.emplace_back(diff.count());
                end = true;
                break;
            }
            case (2):{
                auto start = std::chrono::high_resolution_clock::now();
                sort(obj.begin(), obj.end(), compareSurname);
                auto stoptime = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> diff = stoptime-start;
                Marktime.emplace_back(diff.count());
                end = true;
                break;
            }
            case (3):{
                auto start = std::chrono::high_resolution_clock::now();
                sort(obj.begin(), obj.end(), countByAvg ? compareAverage : compareMedian);
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

void SplitVector(vector<stud>& obj, vector<stud> &SAD, vector<stud> &COOL, bool countByAvg){

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
        sort(obj.begin(), obj.end(), countByAvg ? compareAverage : compareMedian);
        auto start = std::chrono::high_resolution_clock::now();
        if (countByAvg) {
        //     int index = 0;
        //     auto it_end = obj.end();
        //     for (auto student = obj.begin(); student != it_end;) {
        //         if (student->FinalAverage < 5) {
        //             SAD.emplace_back(*student);
        //             auto it1 = student;
        //             auto it2 = std::prev(obj.end(), index);
        //             std::iter_swap(it1, it2);
        //             it_end = std::prev(it_end);
        //             index++;
        //         } else {
        //             ++student;
        //         }
        //     }
        //     auto eraseIndex = std::prev(obj.end(), index+1);
        //     obj.erase(eraseIndex, obj.end());
        while(obj.back().FinalAverage >= 5){
            COOL.push_back(obj.back());
            obj.pop_back();
        }
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff = end - start;
            Marktime.emplace_back(diff.count());
        } else {
            // int index = 0;
            // auto it_end = obj.end();
            // for (auto student = obj.begin(); student != it_end;) {
            //     if (student->median < 5) {
            //         SAD.emplace_back(*student);
            //         auto it1 = student;
            //         auto it2 = std::prev(obj.end(), index+1);
            //         std::iter_swap(it1, it2);
            //         it_end = std::prev(it_end);
            //         index++;
            //     } else {
            //         ++student;
            //     }
            // }
            // auto eraseIndex = std::prev(obj.end(), index);
            // obj.erase(eraseIndex, obj.end());
            while(obj.back().median >= 5){
                COOL.emplace_back(obj.back());
                obj.pop_back();
            }
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff = end - start;
            Marktime.emplace_back(diff.count());
        }
        break;
    }
    case 3:{
        auto start = std::chrono::high_resolution_clock::now();
        if(countByAvg){
            std::copy_if(obj.begin(), obj.end(), std::back_inserter(SAD), [](const auto& student){return student.FinalAverage < 5;});
            obj.erase(std::remove_if(obj.begin(), obj.end(),[](const auto& student){ return student.FinalAverage < 5; }), obj.end());
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff = end-start;
            Marktime.emplace_back(diff.count());
        }
        else{
            std::copy_if(obj.begin(), obj.end(), std::back_inserter(SAD), [](const auto& student){return student.median < 5;});
            obj.erase(std::remove_if(obj.begin(), obj.end(),[](const auto& student){ return student.median < 5; }), obj.end());
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