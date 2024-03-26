#include "lib.h"
#include "IOmanip.h"
#include "ErrorHandling.h"
#include "DataManip.h"

vector<double> Marktime;
vector<double> AverageTime;

int main(){
    list<stud> obj;
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
            Assign(obj);
            pass = false;
            break;
        }
        default:{
            cout << " Netinkamas įvesties formatas, bandykite dar kartą :   " << endl;
            break;
        }
    }}

    list<stud> SAD,COOL;

    sorting(obj, countByAvg);
    SplitList(obj, SAD, COOL, countByAvg);

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
            PrintFile(SAD, countByAvg, filename);
            filename = "Kietiakai.txt";
            PrintFile(COOL, countByAvg, filename);
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
    }}
    OutputTime();

    return 0;

}