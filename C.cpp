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

void Assign(stud* obj);
float getAverage(stud* obj, int n, int i);
float getMedian(stud* obj, int n, int i);
void Print (stud* obj);
int StartParameters(int p);
string StringParameters(string str);
int GradingParameters(int p);
int ExamParameters(int p);
void ClearCin();

int main(){
    stud *obj = nullptr;

    Assign(obj);
    cout << obj[0].vard;
    Print(obj);
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

void Assign(stud* obj){
    stud* tempstud = nullptr;
    string p;
    bool pass = true;
    int fk = 0;
    obj = nullptr;
    char c = ' ';
    while(pass){
        cout << " Ar norite pridėti studentą? (Y/N) " << endl;
        cin >> c;
        ClearCin();
        switch (c){
            case 'Y':
            {
                tempstud = new stud[fk];
                for(int i = 0; i<fk; i++){
                    tempstud[i]=obj[i];
                }
                delete[] obj;
                obj = new stud[fk+1];
                for(int z = 0; z<fk; z++){
                    obj[z]=tempstud[z];
                }
                delete[] tempstud;

                cout << "Įveskite " << fk+1 << " studento vardą :  ";
                obj[fk].vard = StringParameters(p);
                cout << "Įveskite " << fk+1 << " studento pavardę :  ";
                obj[fk].pav = StringParameters(p);
                cout << "Įveskite " << fk+1 << "-o studento namų darbų pažymius ( Jei norite baigti, įveskite 11) "<<endl;
                bool ndCheck = true;
                int ndcounter = 0;
                int* tempnd = nullptr;
                int* truend = new int[ndcounter];
                int tempint;
                while(ndCheck){
                    ndcounter++;
                    tempnd = new int[ndcounter-1];
                    for(int k = 0; k<ndcounter-1; k++){
                        tempnd[k]=truend[k];
                    }
                    delete[] truend;
                    truend = new int[ndcounter];
                    for(int l = 0; l<ndcounter-1; l++){
                        truend[l]=tempnd[l];
                    }
                    delete[] tempnd;
                    truend[ndcounter-1]= GradingParameters(tempint);
                    if(truend[ndcounter-1] == 11){
                        ndCheck=false;
                        break;
                    }
                    else{ cout << " Pazymys priimtas " << endl;}
                }
                obj[fk].nd = new int [ndcounter];
                for(int j = 0; j<ndcounter-1; j++){
                    obj[fk].nd[j] = truend[j];
                    obj[fk].vidurkis += obj[fk].nd[j];
                }
                delete[] truend;
                cout << "Įveskite " << fk+1 << "-o studento egzamino rezultatą :  ";
                obj[fk].egz = ExamParameters(obj[fk].egz);
                if(ndcounter > 1){
                    getAverage(obj, ndcounter-1, fk);
                    getMedian(obj, ndcounter-1, fk);
                }
                else{
                    obj[fk].vidurkis = 0.6*obj[fk].egz;
                    obj[fk].mediana = 0.6*obj[fk].egz;
                }
                fk++;
                break;
            }
            case 'N':
            {
                cout << " Stabdomas studentų pridėjimas... "<<endl;
                pass = false;
                if(fk == 0){
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
}

void Print (stud* obj){
    int s = (int)(sizeof(*obj)/sizeof(obj[0]));
    cout << " s = " << s << endl;
    cout << " size1 = " << sizeof(*obj) << endl;
    cout << " size2 = " << sizeof(obj[0]) << endl;
    int temp;
    cout << obj[0].vard << endl;
    cout << endl << endl << " Pasirinkite galutinio rezultato pateikimo būdą : " << endl;
    cout << " (1) Namų darbų vidurkis. " << endl; 
    cout << " (2) Namų darbų mediana." << endl;

    cin >> temp;

    switch(temp){
        case (1):
        {
            cout << left << setw(10) << "Vardas"  << setw(15) << "Pavardė" << setw(15) << left << "Galutinis (Vid.)" << endl;
            for (int z = 0; z<50; z++){ cout << '-'; }
            cout << endl;
            for(int i = 0; i<s; i++){
                cout << left << setw(10) << obj[i].vard << setw(15) << obj[i].pav << setw(15) << left << fixed << setprecision(2) << obj[i].vidurkis << endl;
            }
            break;
        }
        case (2):
        {
            cout << left << setw(10) << "Vardas"  << setw(15) << "Pavardė" << setw(15) << left << "Galutinis (Med.)" << endl;
            for (int z = 0; z<50; z++){ cout << '-'; }
            cout << endl;
            for(int i = 0; i<s; i++){
                cout << left << setw(10) << obj[i].vard << setw(15) << obj[i].pav << setw(15) << left << fixed << setprecision(2) << obj[i].mediana << endl;
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

int StartParameters(int p){
    cin >> p;
    string str = to_string(p);
    for(char c : str){
        if(p <=0 || !(isdigit(c)) || cin.fail() || isblank(c)){
            ClearCin();
            cout << " Netinkamas įvesties formatas, bandykite dar kartą :   " << endl;
            return StartParameters(p);
        }
    }
    ClearCin();
    return p;
}

string StringParameters(string p){
    cin >> p;
    for(char c : p){
        if(isdigit(c) || cin.fail() || p.size()>25 || isblank(c)){
            ClearCin();
            cout << " Netinkamas įvesties formatas, bandykite dar kartą :   " << endl;
            return StringParameters(p);
        }
    }
    ClearCin();
    return p;
}


int GradingParameters(int p){
    cin >> p;
    string str = to_string(p);
    for(char c : str){
        if(p < 0 || p > 11 || !(isdigit(c)) || cin.fail() || isblank(c)){
            ClearCin();
            cout << " Netinkamas įvesties formatas, bandykite dar kartą :   " << endl;
            return GradingParameters(p);
        }
    }
    ClearCin();
    return p;
}

int ExamParameters(int p){
    cin >> p;
    string str = to_string(p);
    for(char c : str){
        if(p < 0 || p > 10 || !(isdigit(c)) || cin.fail() || isblank(c)){
            ClearCin();
            cout << " Netinkamas įvesties formatas, bandykite dar kartą :   " << endl;
            return ExamParameters(p);
        }
    }
    ClearCin();
    return p;
}

void ClearCin(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}