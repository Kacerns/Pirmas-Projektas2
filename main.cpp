#include <iostream>
#include <string>

using namespace std;

struct stud{
    string vard, pav;                                                                // saugom studentu varda ir pavarde
    int nd, egz;                                                                       // saugom tarpini namu darbu rezultata, egzamino rezultata
    float vidurkis;
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
        cout << "Iveskite " << n << " studento pazymiu"<<endl;
        for(int j = 0; j<n; j++){
            cin >> obj[i].nd;
            obj[i].vidurkis += (float)obj[i].nd;
        }
        obj[i].vidurkis = obj[i].vidurkis/n;
    }
        for(int i = 0; i<s; i++){
        cout << "Studento vardas" <<endl;
        cout << obj[i].vard<<endl;
        cout << "Studento pa" <<endl;
        cin >> obj[i].pav;
        cout << endl;

        obj[i].vidurkis = obj[i].vidurkis/n;
    }
    delete[] obj;
    return 0;

}