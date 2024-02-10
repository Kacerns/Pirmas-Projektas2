#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct stud{
    string vard, pav;                                                                       // saugom studentu varda ir pavarde
    int nd, egz = 0;                                                                       // saugom tarpini namu darbu rezultata, egzamino rezultata
    double vidurkis = 0;
};

void Read (stud* obj, int n, int s){
    for(int i = 0; i<s; i++){
        cout << "Iveskite studento varda: " <<endl;
        cin >> obj[i].vard;
        cout << "Iveskite studento pavarde: " <<endl;
        cin >> obj[i].pav;
        cout << "Iveskite " << n << " studento namu darbu pazymius: "<<endl;
        for(int j = 0; j<n; j++){
            cin >> obj[i].nd;
            obj[i].vidurkis += obj[i].nd;
        }
        obj[i].vidurkis = obj[i].vidurkis/n;
        cout << "Iveskite egzamino pazymi"<<endl;
        cin >> obj[i].egz;
        obj[i].vidurkis = obj[i].vidurkis * 0.4;
        obj[i].vidurkis = (double)obj[i].egz * 0.6 + obj[i].vidurkis;
    }
}

void Print (stud* obj, int s){

    cout << endl << endl;
    cout << left << setw(10) << "Vardas"  << setw(15) << "Pavarde" << setw(15) << left << "Galutinis (Vid.)" << endl;
    for (int z = 0; z<50; z++){ cout << '-'; }
    cout << endl;
        
    for(int i = 0; i<s; i++){
        cout << left << setw(10) << obj[i].vard << setw(15) << obj[i].pav << setw(15) << left << setprecision(3) << obj[i].vidurkis << endl;
    }
}

int main(){
    int s = 0, n = 0;                                                                          //kiek studentu ir namu darbu
    stud *obj = new stud[s];
    delete[] obj;
    cout << "Iveskite studentu skaiciu" <<endl;
    cin >> s;
    cout << "Iveskite namu darbu uzduociu skaiciu: "<<endl;
    cin >> n;
    obj = new stud[s];
    Read(obj, n, s);
    Print(obj, s);

    delete[] obj;
    return 0;

}