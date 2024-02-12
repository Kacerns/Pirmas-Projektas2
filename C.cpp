#include <iostream>
#include <iomanip>
#include <string>
#include <ios>
#include <limits>

using namespace std;

struct stud{
    string vard, pav;
    int* nd = nullptr; 
    int egz = 0;
    float vidurkis = 0;
    float mediana = 0;
};

void Assign(stud* obj, int n, int s);
float getAverage(stud* obj, int n, int i);
float getMedian(stud* obj, int n, int i);
void Print (stud* obj, int s);
int StartParameters(int p);
string StringParameters(string str);
int GradingParameters(int p);
void Clear ();

int main(){
    int s = 0, n = 0;
    stud *obj = nullptr;
    cout << "Iveskite studentų skaičių :    ";
    s = StartParameters(s);
    cout << "Įveskite namų darbų užduočių skaičių :     ";
    n = StartParameters(n);
    obj = new stud[s];
    Assign(obj, n, s);
    Print(obj, s);
    delete[] obj;
    return 0;

}

float getAverage(stud* obj, int n, int i){
    obj[i].vidurkis = obj[i].vidurkis/n;
    obj[i].vidurkis = obj[i].vidurkis * 0.4;
    obj[i].vidurkis = (float)obj[i].egz * 0.6 + obj[i].vidurkis;
    return obj[i].vidurkis;
}

float getMedian(stud* obj, int n, int i){
    if(n%2==0){
        for(int med = (n/2)-1; med<=(n/2); med++){
            obj[i].mediana+= obj[i].nd[med];
        }
        obj[i].mediana = obj[i].mediana/2;
        obj[i].mediana = obj[i].mediana*0.4;
    }
    else{
        int temp = ((float)n/2)-0.5;
        obj[i].mediana = obj[i].nd[temp];
        obj[i].mediana = obj[i].mediana*0.4;
    }
    obj[i].mediana = (float)obj[i].egz * 0.6 + obj[i].mediana;
    return obj[i].mediana;
}

void Assign(stud* obj, int n, int s){
    stud* temp = nullptr;
    bool Continue = true;
    while()
        cout << "Įveskite " << i+1 << " studento vardą :  ";
        obj[i].vard = StringParameters(obj[i].vard);
        cout << "Įveskite " << i+1 << " studento pavardę :  ";
        obj[i].pav = StringParameters(obj[i].pav);
        cout << "Įveskite " << i+1 << "-o studento namų darbų pažymius: "<<endl;
        obj[i].nd = new int[n];
        for(int j = 0; j<n; j++){
            obj[i].nd[j] = GradingParameters(obj[i].nd[j]);
            obj[i].vidurkis += obj[i].nd[j];
        }
        cout << "Įveskite " << i+1 << "-o studento egzamino rezultatą :  ";
        obj[i].egz = GradingParameters(obj[i].egz);
        getAverage(obj, n, i);
        getMedian(obj, n, i);   
}

void Print (stud* obj, int s){

    int temp;
    cout << endl << endl << " Pasirinkite galutinio rezultato pateikimo būdą : " << endl;
    cout << " (1) Namų darbų vidurkis. " << endl; 
    cout << " (2) Namų darbų mediana." << endl;

    cin >> temp;

    switch(temp){
        case (1):
            cout << left << setw(10) << "Vardas"  << setw(15) << "Pavardė" << setw(15) << left << "Galutinis (Vid.)" << endl;
            for (int z = 0; z<50; z++){ cout << '-'; }
            cout << endl;
            for(int i = 0; i<s; i++){
                cout << left << setw(10) << obj[i].vard << setw(15) << obj[i].pav << setw(15) << left << fixed << setprecision(2) << obj[i].vidurkis << endl;
            }
            break;
        case (2):
            cout << left << setw(10) << "Vardas"  << setw(15) << "Pavardė" << setw(15) << left << "Galutinis (Med.)" << endl;
            for (int z = 0; z<50; z++){ cout << '-'; }
            cout << endl;
            for(int i = 0; i<s; i++){
                cout << left << setw(10) << obj[i].vard << setw(15) << obj[i].pav << setw(15) << left << fixed << setprecision(2) << obj[i].mediana << endl;
            }
            break;
        default:
            cout << " Pateikėte netinkamą simbolį, bandykite iš naujo" << endl;
            Print(obj, s);
            break;
    }
    
}

int StartParameters(int p){
    cin >> p;
    string str = to_string(p);
    for(char c : str){
        if(p <=0 || !(isdigit(c)) || cin.fail() || isblank(c)){
            Clear();
            cout << " Netinkamas įvesties formatas, bandykite dar kartą :   " << endl;
            return StartParameters(p);
        }
    }
    return p;
}

string StringParameters(string p){
    cin >> p;
    for(char c : p){
        if(isdigit(c) || cin.fail() || p.size()>25 || isblank(c)){
            Clear();
            cout << " Netinkamas įvesties formatas, bandykite dar kartą :   " << endl;
            return StringParameters(p);
        }
    }
    return p;
}

int GradingParameters(int p){
    cin >> p;
    string str = to_string(p);
    for(char c : str){
        if(p < 0 || p > 10 || !(isdigit(c)) || cin.fail() || isblank(c)){
            Clear();
            cout << " Netinkamas įvesties formatas, bandykite dar kartą :   " << endl;
            return GradingParameters(p);
        }
    }
    return p;
}

void Clear (){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}