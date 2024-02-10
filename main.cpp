#include <iostream>
#include <string>

using namespace std;

struct stud{
    string vard, pav;                                                                // saugom studentu varda ir pavarde
    int nd, egz = 0;                                                                       // saugom tarpini namu darbu rezultata, egzamino rezultata
    double vidurkis = 0;
};

int main(){
    int s = 0, n = 0;                                                                          //kiek studentu ir namu darbu
    stud *obj = new stud[s];
    delete[] obj;
    cout << "Iveskite studentu kieki" <<endl;
    cin >> s;
    cout << "Iveskite namu darbu uzduociu kieki"<<endl;
    cin >> n;
    obj = new stud[s];
    for(int i = 0; i<s; i++){
        cout << "Iveskite studento varda" <<endl;
        cin >> obj[i].vard;
        cout << endl;
        cout << "Iveskite studento pavarde" <<endl;
        cin >> obj[i].pav;
        cout << endl;
        cout << "Iveskite " << n << " studento namu darbu pazymiu"<<endl;
        for(int j = 0; j<n; j++){
            cin >> obj[i].nd;
            obj[i].vidurkis += obj[i].nd;
        }
        obj[i].vidurkis = obj[i].vidurkis/n;
        cout << "Iveskite egzamino pazymi"<<endl;
        cin >> obj[i].egz;
        obj[i].vidurkis = obj[i].vidurkis * 0.4;
        cout << obj[i].vidurkis <<endl;
        obj[i].vidurkis = (double)obj[i].egz * 0.6 + obj[i].vidurkis;
    }
        for(int i = 0; i<s; i++){
        cout << "Studento vardas" <<endl;
        cout << obj[i].vard<<endl;
        cout << "Studento pavarde" <<endl;
        cout << obj[i].pav;
        cout << endl;
        cout << "Studento vidurkis"<<endl;
        cout << obj[i].vidurkis;
    }
    delete[] obj;
    return 0;

}