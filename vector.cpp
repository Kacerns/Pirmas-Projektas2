#include <iostream>
#include <iomanip>
#include <string>
#include <ios>
#include <limits>
#include <vector>

using namespace std;

struct stud{
    string vard, pav;
    vector<int> nd; 
    int egz = 0;
    float vidurkis = 0;
    float mediana = 0;
};

void Assign(vector<stud> &obj);
float getAverage(vector<stud> &obj, int n, int i);
float getMedian(vector<stud> &obj, int n, int i);
void RandomGrades(vector<stud> &obj, int counter);
void RandomNames(vector<stud> &obj, int counter);
void Print (vector<stud> &obj);
int StartParameters(int p);
string StringParameters(string str);
int GradingParameters(int p);
int ExamParameters(int p);
void ClearCin();

vector <string> Names {"Audrius", "Edvard", "Ganesh", "Nojus", "Cleophas", "Rodrigo","Jurgita", "Ugne", "Tatiana", "Sarah"};
vector <string> Surnames{"Czerniewicz", "Finch", "Hummel", "McKowen", "Warszawski", "Clery", "Wilbur", "Kennedy", "Nixon", "Obama"};

int main(){
    vector<stud> obj;
    Assign(obj);
    Print(obj);
    return 0;

}

float getAverage(vector<stud> &obj, int s, int i){
    obj.at(i).vidurkis = obj.at(i).vidurkis/s;
    obj.at(i).vidurkis = obj.at(i).vidurkis * 0.4;
    obj.at(i).vidurkis = (float)obj.at(i).egz * 0.6 + obj.at(i).vidurkis;
    return obj.at(i).vidurkis;
}

float getMedian(vector<stud> &obj, int s, int i){
    if(s%2==0){
        for(int med = (s/2)-1; med<=(s/2); med++){
            obj.at(i).mediana+= obj.at(i).nd.at(med);
        }
        obj.at(i).mediana = obj.at(i).mediana/2;
        obj.at(i).mediana = obj.at(i).mediana*0.4;
    }
    else{
        int temp = ((float)s/2)+0.5;
        obj.at(i).mediana = obj.at(i).nd.at(temp);
        obj.at(i).mediana = obj.at(i).mediana*0.4;
    }
    obj.at(i).mediana = (float)obj.at(i).egz * 0.6 + obj.at(i).mediana;
    return obj.at(i).mediana;
}

void RandomGrades(vector<stud> &obj, int counter){
    cout << " Generuojami pažymiai... " << endl;
    int ndcounter = rand() % 100 + 1;
    obj.at(counter).egz = rand() % 10;
    for(int i = 0; i<ndcounter; i++){
        obj.at(counter).nd.push_back(rand() % 10);
        obj.at(counter).vidurkis += obj.at(counter).nd.back();
    }
    cout << " Pažymiai sugeneruoti " << endl;
}

void RandomNames(vector<stud> &obj, int counter){
    cout << " Generuojami vardai... " << endl;
    obj.at(counter).vard = Names.at(rand() % Names.size());
    obj.at(counter).pav = Surnames.at(rand() % Surnames.size());
    cout << " Vardai sugeneruoti " << endl;
}

void Assign(vector<stud> &obj){
    bool pass = true;
    char c = ' ';
    int counter = 0;
    int option = 0;
    while(pass){
        cout << " Ar norite pridėti studentą? (Y/N) " << endl;
        cin >> c;
        ClearCin();
        switch (c){
            case 'Y':
            {
                cout << " Pasrinkite studento pridėjimo eigą: " << endl;
                cout << " (1) Duomenis suvesti ranka. " << endl; 
                cout << " (2) Atsitiktinai generuoti tik studento pažymius" << endl;
                cout << " (3) Atsitiktinai generuoti visus studento duomenis" << endl;
                cout << " (4) Uždaryti programą (Atsargiai!! Pasirinkus šį nustatymą dingsta visi jūsų įvesti duomenys ir programa užsidaro)" << endl;

                cin >> option;
                ClearCin();

                switch (option){
                    case (1):{
                        obj.resize(counter+1);
                        cout << "Įveskite " << counter+1 << " studento vardą :  ";
                        obj.at(counter).vard = StringParameters(obj.at(counter).vard);
                        cout << "Įveskite " << counter+1 << " studento pavardę :  ";
                        obj.at(counter).pav = StringParameters(obj.at(counter).pav);
                        cout << "Įveskite " << counter+1 << "-o studento namų darbų pažymius ( Jei norite baigti, įveskite 11) "<<endl;
                        bool ndCheck = true;
                        int tempgrade = 0;
                        while(ndCheck){
                            tempgrade = GradingParameters(tempgrade);
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
                            obj.at(counter).vidurkis += i;
                        }
                        cout << "Įveskite " << counter+1 << "-o studento egzamino rezultatą :  ";
                        obj.at(counter).egz = ExamParameters(obj.at(counter).egz);
                        if(s > 1){
                            getAverage(obj, s, counter);
                            getMedian(obj, s, counter);
                        }
                        else{
                            obj.at(counter).vidurkis = 0.6*obj.at(counter).egz;
                            obj.at(counter).mediana = 0.6*obj.at(counter).egz;
                        }
                        counter++;
                        break;
                    }
                    case (2):{
                        obj.resize(counter+1);
                        cout << "Įveskite " << counter+1 << " studento vardą :  ";
                        obj.at(counter).vard = StringParameters(obj.at(counter).vard);
                        cout << "Įveskite " << counter+1 << " studento pavardę :  ";
                        obj.at(counter).pav = StringParameters(obj.at(counter).pav);
                        RandomGrades(obj, counter);
                        int s = obj.at(counter).nd.size();
                        getAverage(obj, s, counter);
                        getMedian(obj, s, counter);
                        counter++;
                        break;

                    }
                    case (3):{
                        obj.resize(counter+1);
                        RandomNames(obj, counter);
                        RandomGrades(obj, counter);
                        int s = obj.at(counter).nd.size();
                        getAverage(obj, s, counter);
                        getMedian(obj, s, counter);
                        counter++;
                        break;
                    }
                    case (4):
                    {
                        cout << " Programos darbas baigiamas " << endl;
                        exit(0);
                        break;
                    }
                    default:
                    {
                        cout << " Netinkamas įvesties formatas, bandykite dar kartą :   " << endl;
                        break;
                    }
                }
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
}

void Print (vector<stud> &obj){
    int temp;
    int s = obj.size();
    cout << endl << endl << " Pasirinkite galutinio rezultato pateikimo būdą : " << endl;
    cout << " (1) Namų darbų vidurkis. " << endl; 
    cout << " (2) Namų darbų mediana." << endl;

    cin >> temp;

    switch(temp){
        case (1):
        {
            cout << left << setw(26) << "Vardas"  << setw(26) << "Pavardė" << setw(15) << left << "Galutinis (Vid.)" << endl;
            for (int z = 0; z<70; z++){ cout << '-'; }
            cout << endl;
            for(int i = 0; i<s; i++){
                cout << left << setw(26) << obj.at(i).vard << setw(26) << obj.at(i).pav << setw(15) << left << fixed << setprecision(2) << obj.at(i).vidurkis << endl;
            }
            break;
        }
        case (2):
        {
            cout << left << setw(10) << "Vardas"  << setw(15) << "Pavardė" << setw(15) << left << "Galutinis (Med.)" << endl;
            for (int z = 0; z<50; z++){ cout << '-'; }
            cout << endl;
            for(int i = 0; i<s; i++){
                cout << left << setw(26) << obj.at(i).vard << setw(26) << obj.at(i).pav << setw(15) << left << fixed << setprecision(2) << obj.at(i).mediana << endl;
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