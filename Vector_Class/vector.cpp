#include "lib.h"
#include "IOmanip.h"
#include "ErrorHandling.h"
#include "DataManip.h"
#include "student.hpp"

vector<double> Marktime;
vector<double> AverageTime;

int main(){
    vector<stud> obj;
    string filename;

    int option = 0;
    CreateFile(filename);

    bool pass = true;
    bool countByAvg;
    while(pass){
    cout << " Pasrinkite galutinio balo skaičiavimo būdą: " << endl;
    cout << " (1) Pagal vidurkį " << endl; 
    cout << " (2) Pagal medianą " << endl;
    cin >> option;
    ClearCin();
    switch (option){
        case 1 :{
            countByAvg = true;
            pass = false;
            break;
        }
        case 2 :{
            countByAvg = false;
            pass = false;
            break;
        }
        default:{
            cout << " Netinkamas įvesties formatas, bandykite dar kartą :   " << endl;
            break;
        }
    }}

    pass=true;

    while(pass){
    cout << " Pasrinkite programos veikimo eigą: " << endl;
    cout << " (1) Duomenis nuskaityti iš failo. " << endl; 
    cout << " (2) Duomenis suvesti programoje. " << endl;
    cin >> option;
    ClearCin();

    switch (option){
        case 1 :{
            readFile(obj, filename, countByAvg);
            pass = false;
            break;
        }
        case 2 :{
            Assign(obj, countByAvg);
            pass = false;
            break;
        }
        default:{
            cout << " Netinkamas įvesties formatas, bandykite dar kartą :   " << endl;
            break;
        }
    }}

    vector<stud> SAD,COOL;

    SplitVector(obj, SAD, COOL);
    if(obj.size() != 0){sorting(obj);};
    if(SAD.size() != 0){sorting(SAD);};
    if(COOL.size() != 0){sorting(COOL);};

    pass = true;
    while(pass){
    cout << " Pasrinkite duomenų spausdinimo būdą: " << endl;
    cout << " (1) Duomenis spausdinti į failą. (Rekomenduojama dideliems kiekiams duomenų) " << endl; 
    cout << " (2) Duomenis spausdinti programoje. " << endl;
    cin >> option;
    ClearCin();

    switch (option){
        case 1 :{
            filename = "Liūdesiukai.txt";
            if(SAD.size() !=0){ PrintFile(SAD, filename);} else{PrintFile(obj, filename);};
            filename = "Kietiakai.txt";
            if(COOL.size() !=0){ PrintFile(COOL, filename);} else{PrintFile(obj, filename);};
            pass = false;
            break;
        }
        case 2 :{
            cout << "Liudesiukai: " << endl;
            if(SAD.size() !=0){ Print(SAD);} else{Print(obj);};
            cout << "Kietiakai: " << endl;
            if(COOL.size() !=0){ Print(COOL);} else{Print(obj);};
            pass = false;
            break;
        }
        default:{
            cout << " Netinkamas įvesties formatas, bandykite dar kartą :   " << endl;
            break;
        }
    }}
    OutputTime();

    return 0;

}