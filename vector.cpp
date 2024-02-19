#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

struct stud{
    string vard, pav;
    vector<int> nd;
    int egz = 0;
    float FinalAverage = 0.0;
    float median = 0.0;
};

void Assign(vector<stud> &obj);
float getAverage(vector<stud> &obj, int n, int i);
float getMedian(vector<stud> &obj, int n, int i);
void RandomGrades(vector<stud> &obj, int counter, int ndcounter);
void RandomNames(vector<stud> &obj, int counter);
void Print (vector<stud> &obj);
int StartParameters();
string StringParameters();
int GradingParameters();
int ExamParameters();
void ClearCin();

vector <string> Names {"Audrius", "Edvard", "Ganesh", "Nojus", "Cleophas", "Rodrigo","Jurgita", "Ugne", "Tatiana", "Sarah"};
vector <string> Surnames {"Czerniewicz", "Finch", "Hummel", "McKowen", "Warszawski", "Clery", "Wilbur", "Kennedy", "Nixon", "Obama"};

int main(){
    vector<stud> obj;

    Assign(obj);
    Print(obj);
    return 0;

}

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
    unsigned seed = (chrono::high_resolution_clock::now().time_since_epoch().count()) + counter*ndcounter;
    mt19937 rng(seed);
    cout << " Generuojami pažymiai... " << endl;
    uniform_int_distribution<int> dist(1, 10);
    obj.at(counter).egz = dist(rng);
    for(int i = 0; i<ndcounter; i++){
        obj.at(counter).nd.push_back(dist(rng));
        obj.at(counter).FinalAverage += obj.at(counter).nd.back();
    }
    cout << " Pažymiai sugeneruoti " << endl;
}

void RandomNames(vector<stud> &obj, int counter){
    unsigned seed = (chrono::high_resolution_clock::now().time_since_epoch().count()) + counter;
    mt19937 rng(seed);
    cout << " Generuojami vardai... " << endl;
    uniform_int_distribution<int> distNames(0, Names.size()-1);
    uniform_int_distribution<int> distSurNames(0, Surnames.size()-1);
    obj.at(counter).vard = Names.at(distNames(rng));
    obj.at(counter).pav = Surnames.at(distSurNames(rng));
    cout << " Vardai sugeneruoti " << endl;
}

void Assign(vector<stud> &obj){

    bool pass = true;
    int counter = 0;
    char c = ' ';
    int option = 0;

    cout << " Pasrinkite studento pridėjimo eigą: " << endl;
    cout << " (1) Duomenis suvesti ranka. " << endl; 
    cout << " (2) Atsitiktinai generuoti tik studentų pažymius" << endl;
    cout << " (3) Atsitiktinai generuoti visus studentų duomenis" << endl;
    cout << " (4) Uždaryti programą "<< endl;

    cin >> option;
    ClearCin();

    switch (option){
        case (1):{
            while(pass){
                cout << " Ar norite pridėti studentą? (Y/N) " << endl;
                cin >> c;
                ClearCin();
                switch (c){
                    case 'Y':
                    {
                        obj.resize(counter+1);
                        cout << "Įveskite " << counter+1 << " studento vardą :  ";
                        obj.at(counter).vard = StringParameters();
                        cout << "Įveskite " << counter+1 << " studento pavardę :  ";
                        obj.at(counter).pav = StringParameters();
                        cout << "Įveskite " << counter+1 << "-o studento namų darbų pažymius ( Jei norite baigti, įveskite 11) "<<endl;
                        bool ndCheck = true;
                        int tempgrade = 0;
                        while(ndCheck){
                            tempgrade = GradingParameters();
                            if(tempgrade == 11){
                                ndCheck=false;
                                break;
                            }
                            else{
                                obj.at(counter).nd.push_back(tempgrade);
                            }
                        }
                        int s = obj.at(counter).nd.size();
                        for(const int& i : obj.at(counter).nd){
                            obj.at(counter).FinalAverage += i;
                        }
                        cout << "Įveskite " << counter+1 << "-o studento egzamino rezultatą :  ";
                        obj.at(counter).egz = ExamParameters();
                        if(s >= 1){
                            getAverage(obj, s, counter);
                            getMedian(obj, s, counter);
                        }
                        else{
                            obj.at(counter).FinalAverage = 0.6*obj.at(counter).egz;
                            obj.at(counter).median = 0.6*obj.at(counter).egz;
                        }
                        counter++;
                        break;
                    }
                    case 'N':
                    {
                        cout << " Stabdomas studentų pridėjimas... "<<endl;
                        pass = false;
                        if(counter == 0){
                            cout << " Studentų informacijos nėra " << endl;
                            cout << " Programa stabdoma "<< endl;
                            exit(0);
                        }
                        break;
                    }
                    default:
                    {
                        cout << " Netinkamas įvesties formatas, bandykite dar kartą :   " << endl;
                        break;
                    }
                }
            }
            break;
        }
        case (2):{
            cout << " Įveskite namų darbų skaičių:  " << endl;
            int numberOfHw = 0;
            numberOfHw = StartParameters();
            while(pass){
                cout << " Ar norite pridėti studentą? (Y/N) " << endl;
                cin >> c;
                ClearCin();
                switch (c){
                    case 'Y':
                    {
                        obj.resize(counter+1);
                        cout << "Įveskite " << counter+1 << " studento vardą :  ";
                        obj.at(counter).vard = StringParameters();
                        cout << "Įveskite " << counter+1 << " studento pavardę :  ";
                        obj.at(counter).pav = StringParameters();
                        RandomGrades(obj, counter, numberOfHw);
                        int s = obj.at(counter).nd.size();
                        if(s >= 1){
                            getAverage(obj, s, counter);
                            getMedian(obj, s, counter);
                        }
                        else{
                            obj.at(counter).FinalAverage = 0.6*obj.at(counter).egz;
                            obj.at(counter).median = 0.6*obj.at(counter).egz;
                        }
                        counter++;
                        break;
                    }
                    case 'N':
                    {
                        cout << " Stabdomas studentų pridėjimas... "<<endl;
                        pass = false;
                        if(counter == 0){
                            cout << " Studentų informacijos nėra " << endl;
                            cout << " Programa stabdoma "<< endl;
                            exit(0);
                        }
                        break;
                    }
                    default:
                    {
                        cout << " Netinkamas įvesties formatas, bandykite dar kartą :   " << endl;
                        break;
                    }
                }
            }
            break;
        }
        case (3):{
            cout << " Įveskite studentų skaičių:  " << endl;
            int numberOfSt = 0;
            numberOfSt = StartParameters();
            cout << " Įveskite namų darbų skaičių:  " << endl;
            int numberOfHw = 0;
            numberOfHw = StartParameters();
            for(counter; counter < numberOfSt; counter++){
                obj.resize(counter+1);
                RandomNames(obj, counter);
                RandomGrades(obj, counter, numberOfHw);
                int s = obj.at(counter).nd.size();
                if(s >= 1){
                    getAverage(obj, s, counter);
                    getMedian(obj, s, counter);
                }
                else{
                    obj.at(counter).FinalAverage = 0.6*obj.at(counter).egz;
                    obj.at(counter).median = 0.6*obj.at(counter).egz;
                }
            }
            break;
        }
        case (4):{
            cout << " Programos darbas baigiamas " << endl;
            exit(0);
            break;
        }
        default:{
            cout << " Netinkamas įvesties formatas, bandykite dar kartą :   " << endl;
            break;
        }
    }
}


void Print (vector<stud> &obj){
    int temp;
    int s = obj.size();
    cout << endl << endl << " Pasirinkite galutinio rezultato pateikimo būdą : " << endl;
    cout << " (1) Namų darbų vidurkis. " << endl; 
    cout << " (2) Namų darbų mediana." << endl;

    cin >> temp;
    ClearCin();

    switch(temp){
        case (1):
        {
            cout << left << setw(26) << "Vardas"  << setw(26) << "Pavardė" << setw(15) << left << "Galutinis (Vid.)" << endl;
            for (int z = 0; z<70; z++){ cout << '-'; }
            cout << endl;
            for(int i = 0; i<s; i++){
                cout << left << setw(26) << obj.at(i).vard << setw(26) << obj.at(i).pav << setw(15) << left << fixed << setprecision(2) << obj.at(i).FinalAverage << endl;
            }
            break;
        }
        case (2):
        {
            cout << left << setw(26) << "Vardas"  << setw(26) << "Pavardė" << setw(15) << left << "Galutinis (Med.)" << endl;
            for (int z = 0; z<70; z++){ cout << '-'; }
            cout << endl;
            for(int i = 0; i<s; i++){
                cout << left << setw(26) << obj.at(i).vard << setw(26) << obj.at(i).pav << setw(15) << left << fixed << setprecision(2) << obj.at(i).median << endl;
            }
            break;
        }
        default:
        {
            cout << " Pateikėte netinkamą simbolį, bandykite iš naujo" << endl;
            Print(obj);
            break;
        }
    }
    
}

int StartParameters(){
     string p;
    getline(cin,p);
    if (cin.fail()) {
        ClearCin();
        return StartParameters();
    }
    while(p.empty(),any_of(p.begin(), p.end(), [](char c) { return !(isdigit(c)) || isspace(c); })){
        cout << " Netinkamas įvesties formatas, bandykite dar kartą(patikrinkite ar nėra tarpų arba raidžių) :   ";
        getline(cin, p);
    }
    int num = stoi(p);
    if(num <= 0 || num > 2147483646){
        cout << " Netinkamas įvesties formatas, bandykite dar kartą(patikrinkite ar nėra tarpų arba raidžių) :   ";
        return StartParameters();
    }
    return num;
}

string StringParameters(){
    string p;
    getline(cin, p);
    if (cin.fail()) {
        ClearCin();
        return StringParameters();
    }
    while (p.empty() || p.size() > 25 || any_of(p.begin(), p.end(), [](char c) { return isdigit(c) || isspace(c); })) {
        cout << " Netinkamas įvesties formatas, bandykite dar kartą(patikrinkite ar nėra tarpų arba skaičių) :   ";
        getline(cin, p);
    }
    return p;
}


int GradingParameters(){
    string p;
    getline(cin,p);
    if (cin.fail()) {
        ClearCin();
        return GradingParameters();
    }
    while(p.empty(),any_of(p.begin(), p.end(), [](char c) { return !(isdigit(c)) || isspace(c); })){
        cout << " Netinkamas įvesties formatas, bandykite dar kartą(patikrinkite ar nėra tarpų arba raidžių) :   ";
        getline(cin, p);
    }
    int num = stoi(p);
    if(num < 0 || num > 11){
        cout << " Netinkamas įvesties formatas, bandykite dar kartą(patikrinkite ar nėra tarpų arba raidžių) :   ";
        return GradingParameters();
    }
    return num;
}

int ExamParameters(){
    string p;
    getline(cin,p);
    if (cin.fail()) {
        ClearCin();
        return ExamParameters();
    }
    while(p.empty(),any_of(p.begin(), p.end(), [](char c) { return !(isdigit(c)) || isspace(c); })){
        cout << " Netinkamas įvesties formatas, bandykite dar kartą(patikrinkite ar nėra tarpų arba raidžių) :   ";
        getline(cin, p);
    }
    int num = stoi(p);
    if(num < 0 || num > 10){
        cout << " Netinkamas įvesties formatas, bandykite dar kartą(patikrinkite ar nėra tarpų arba raidžių) :   ";
        return ExamParameters();
    }
    return num;
}

void ClearCin(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}