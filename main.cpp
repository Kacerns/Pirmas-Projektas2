#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct stud{
    string vard, pav;                                                                       // saugom studentu varda ir pavarde
    int* nd = nullptr; 
    int egz = 0;                                                                       // saugom tarpini namu darbu rezultata, egzamino rezultata
    float vidurkis = 0;
    float mediana = 0;
};



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
    for(int i = 0; i<s; i++){
        
        cout << "Iveskite studento varda: " <<endl;
        cin >> obj[i].vard;
        cout << "Iveskite studento pavarde: " <<endl;
        cin >> obj[i].pav;
        cout << "Iveskite " << obj[i].vard << " namu darbu pazymius: "<<endl;
        obj[i].nd = new int[n];
        for(int j = 0; j<n; j++){
            cin >> obj[i].nd[j];
            obj[i].vidurkis += obj[i].nd[j];
        }
        cout << "Iveskite egzamino rezultata"<<endl;
        cin >> obj[i].egz;
        getAverage(obj, n, i);
        getMedian(obj, n, i);   
    }
}

void Print (stud* obj, int s){

    int temp;
    cout << endl << endl << " Pasirinkite galutinio rezultato skaiciavimo buda : " << endl;
    cout << " (1) Namu darbu vidurkis. " << endl; 
    cout << " (2) Namu darbu mediana." << endl;

    cin >> temp;

    switch(temp){
        case (1):
            cout << left << setw(10) << "Vardas"  << setw(15) << "Pavarde" << setw(15) << left << "Galutinis (Vid.)" << endl;
            for (int z = 0; z<50; z++){ cout << '-'; }
            cout << endl;
            for(int i = 0; i<s; i++){
                cout << left << setw(10) << obj[i].vard << setw(15) << obj[i].pav << setw(15) << left << fixed << setprecision(2) << obj[i].vidurkis << endl;
            }
            break;
        case (2):
            cout << left << setw(10) << "Vardas"  << setw(15) << "Pavarde" << setw(15) << left << "Galutinis (Med.)" << endl;
            for (int z = 0; z<50; z++){ cout << '-'; }
            cout << endl;
            for(int i = 0; i<s; i++){
                cout << left << setw(10) << obj[i].vard << setw(15) << obj[i].pav << setw(15) << left << fixed << setprecision(2) << obj[i].mediana << endl;
            }
            break;
        default:
            cout << " Pateikete netinkama simboli, bandykite is naujo" << endl;
            Print(obj, s);
            break;
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
    Assign(obj, n, s);
    Print(obj, s);

    delete[] obj;
    return 0;

}