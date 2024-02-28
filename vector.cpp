#include "lib.h"
#include "IOmanip.h"
#include "ErrorHandling.h"
#include "DataManip.h"



int main(){
    vector<stud> obj;
    string filename = "studentai1000000.txt";

    int option = 0;
    bool pass = true;

    while(pass){
    cout << " Pasrinkite programos veikimo eigą: " << endl;
    cout << " (1) Duomenis nuskaityti iš failo. " << endl; 
    cout << " (2) Duomenis suvesti programoje. " << endl;
    cin >> option;
    ClearCin();

    switch (option){
        case 1 :{
            readFile(obj, filename);
            pass = false;
            break;
        }
        case 2 :{
            Assign(obj);
            pass = false;
            break;
        }
        default:{
            cout << " Netinkamas įvesties formatas, bandykite dar kartą :   " << endl;
            break;
        }
    }
    }
    pass = true;
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
    }
    }

    sorting(obj, countByAvg);

    pass = true;
    while(pass){
    cout << " Pasrinkite duomenų spausdinimo būdą: " << endl;
    cout << " (1) Duomenis spausdinti į failą. (Rekomenduojama dideliems kiekiams duomenų) " << endl; 
    cout << " (2) Duomenis spausdinti programoje. " << endl;
    cin >> option;
    ClearCin();

    switch (option){
        case 1 :{
            PrintFile(obj, countByAvg);
            pass = false;
            break;
        }
        case 2 :{
            Print(obj, countByAvg);
            pass = false;
            break;
        }
        default:{
            cout << " Netinkamas įvesties formatas, bandykite dar kartą :   " << endl;
            break;
        }
    }
    }
    return 0;

}