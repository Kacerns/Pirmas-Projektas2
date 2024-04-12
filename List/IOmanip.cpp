#include "IOmanip.h"

void Assign(list<stud> &obj){

    bool pass = true;
    bool program = true;
    int counter = 0;
    char c = ' ';
    int option = 0;

    while(program){
    
    cout << " Pasrinkite studento pridėjimo eigą: " << endl;
    cout << " (1) Duomenis suvesti ranka. " << endl; 
    cout << " (2) Atsitiktinai generuoti tik studentų pažymius" << endl;
    cout << " (3) Atsitiktinai generuoti visus studentų duomenis" << endl;
    cout << " (4) Uždaryti programą "<< endl;

    cin >> option;
    ClearCin();

    switch (option){
        case (1):{
            program = false;
            while(pass){
                cout << " Ar norite pridėti studentą? (Y/N) " << endl;
                cin >> c;
                ClearCin();
                switch (c){
                    case 'Y':
                    {
                        obj.push_back(stud());
                        cout << "Įveskite " << counter+1 << " studento vardą :  ";
                        obj.back().vard = StringParameters();
                        cout << "Įveskite " << counter+1 << " studento pavardę :  ";
                        obj.back().pav = StringParameters();
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
                                obj.back().nd.push_back(tempgrade);
                            }
                        }
                        int s = obj.back().nd.size();
                        for(const int& i : obj.back().nd){
                            obj.back().FinalAverage += i;
                        }
                        cout << "Įveskite " << counter+1 << "-o studento egzamino rezultatą :  ";
                        obj.back().egz = ExamParameters();
                        if(s >= 1){
                            getAverage(obj, s, counter);
                            getMedian(obj, s, counter);
                        }
                        else{
                            obj.back().FinalAverage = 0.6*obj.back().egz;
                            obj.back().median = 0.6*obj.back().egz;
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
        case (2):
        {
            program = false;
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
                        obj.push_back(stud());
                        cout << "Įveskite " << counter+1 << " studento vardą :  ";
                        obj.back().vard = StringParameters();
                        cout << "Įveskite " << counter+1 << " studento pavardę :  ";
                        obj.back().pav = StringParameters();
                        RandomGrades(obj, counter, numberOfHw);
                        int s = obj.back().nd.size();
                        if(s >= 1){
                            getAverage(obj, s, counter);
                            getMedian(obj, s, counter);
                        }
                        else{
                            obj.back().FinalAverage = 0.6*obj.back().egz;
                            obj.back().median = 0.6*obj.back().egz;
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
        case (3):
        {
            program = false;
            cout << " Įveskite studentų skaičių:  " << endl;
            int numberOfSt = 0;
            numberOfSt = StartParameters();
            cout << " Įveskite namų darbų skaičių:  " << endl;
            int numberOfHw = 0;
            numberOfHw = StartParameters();
            for(counter; counter < numberOfSt; counter++){
                obj.push_back(stud());
                RandomNames(obj, counter);
                RandomGrades(obj, counter, numberOfHw);
                int s = obj.back().nd.size();
                if(s >= 1){
                    getAverage(obj, s, counter);
                    getMedian(obj, s, counter);
                }
                else{
                    obj.back().FinalAverage = 0.6*obj.back().egz;
                    obj.back().median = 0.6*obj.back().egz;
                }
            }
            break;
        }
        case (4):
        {
            program = false;
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
}

void Print(list<stud>& obj, bool countByAvg) {
    if (countByAvg) {
        cout << left << setw(26) << "Vardas" << setw(26) << "Pavardė" << setw(15) << left << "Galutinis (Vid.)" << endl;
    } else {
        cout << left << setw(26) << "Vardas" << setw(26) << "Pavardė" << setw(15) << left << "Galutinis (Med.)" << endl;
    }
    for (int z = 0; z<70; z++){ cout << '-'; }
    for (const auto& student : obj) {
        cout << left << setw(26) << student.vard << setw(26) << student.pav << setw(15) << left << fixed << setprecision(2);
        if (countByAvg) {
            cout << student.FinalAverage;
        } else {
            cout << student.median;
        }
        cout << endl;
    }
}
void readFile(list<stud> &obj, const string filename, const bool countByAvg){

    int s = 0;
    int counter = 0;
    auto start = std::chrono::high_resolution_clock::now();
    ifstream file(filename);
    if (!file.is_open()){
        cerr << "Klaida!  Failo atidarymo klaida " << filename << endl;
        exit(0);
    }
    try{
        string line;
        getline(file, line);

        while (getline(file, line)){
            stud* temp = new stud;
            istringstream iss(line);
            if (!(iss >> temp->vard >> temp->pav)){
                cerr << "Klaida!  Studento vardo ir pavardės skaitymo nuo failo klaida " << filename << endl;
                continue;
            }

            int number;

            while (iss >> number){

                temp->nd.push_back(number);
                temp->FinalAverage += number;
            }

            if (temp->nd.empty()){

                cerr << "Klaida!  Studento pažymių skaitymo nuo failo klaida " << filename << endl;
                continue;
            }

            temp->egz = temp->nd.back();
            temp->nd.pop_back();
            temp->FinalAverage -= temp->egz;
            s = temp->nd.size();

            if(s >= 1){
                if(countByAvg){
                    temp->FinalAverage = ((temp->FinalAverage/s)*0.4) + 0.6*temp->egz;
                }
                else{
                    temp->nd.sort();
                    if(s%2==0){
                        auto middle1 = std::next(temp->nd.begin(), s / 2 - 1);
                        auto middle2 = std::next(temp->nd.begin(), s / 2);
                        temp->median = (*middle1 + *middle2) / 2.0f;
                        temp->median = temp->median*0.4;
                    }
                    else{
                        auto middle = std::next(temp->nd.begin(), s / 2);
                        temp->median = *middle;
                        temp->median = temp->median*0.4;
                    }
                        temp->median = (float)temp->egz * 0.6 + temp->median;
                }
            }
            else{

                temp->FinalAverage = 0.6*temp->egz;
                temp->median = 0.6*temp->egz;

            }
            obj.emplace_back(*temp);
            delete temp;
            counter++;
        }
    }
    catch(const exception& e){
        cerr << " Klaida!  Skaitymo nuo failo klaida " << endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;
    Marktime.emplace_back(diff.count());
    ifstream fclose(filename);
}

void PrintFile(list<stud> &obj, bool countByAvg, string filename){

    // auto start = std::chrono::high_resolution_clock::now();
    ofstream PrintOut(filename);
    if (!PrintOut.is_open()){
        cerr << "Klaida!  Failo atidarymo klaida." << endl;
        return;
    }
    try{
        ostringstream buffer;
        int s = obj.size();

        if (countByAvg) {
            buffer << left << setw(26) << "Vardas" << setw(26) << "Pavardė" << setw(15) << left << "Galutinis (Vid.)" << endl;
        } else {
            buffer << left << setw(26) << "Vardas" << setw(26) << "Pavardė" << setw(15) << left << "Galutinis (Med.)" << endl;
        }
        for (int z = 0; z<70; z++){ buffer << '-'; }
        buffer<<endl;
        for (const auto& student : obj) {
            buffer << left << setw(26) << student.vard << setw(26) << student.pav << setw(15) << left << fixed << setprecision(2);
            if (countByAvg) {
                buffer << student.FinalAverage;
            } else {
                buffer << student.median;
            }
            buffer <<endl;
        }
        PrintOut << buffer.str();
        // auto end = std::chrono::high_resolution_clock::now();
        // std::chrono::duration<double> diff = end-start;
        // Marktime.emplace_back(diff.count());
        PrintOut.close();
    }
    catch (const exception& e){
        cerr << " Klaida!  Įrašymo į failą klaida " << endl;
    }
}

void CreateFile(string& filename){

    int option = 0;
    bool pass = true;

    while(pass){
    cout << " Pasirinkite studentų failo dydį: " << endl;
    cout << " (1) 1000 " << endl; 
    cout << " (2) 10000 " << endl;
    cout << " (3) 100000 " << endl; 
    cout << " (4) 1000000 " << endl;
    cout << " (5) 10000000 " << endl;
    cin >> option;
    ClearCin();

    switch (option){
        case 1 : { option = 1000; filename = "1000.txt"; pass = false; break;}
        case 2 : { option = 10000; filename = "10000.txt"; pass = false; break;}
        case 3 : { option = 100000; filename = "100000.txt"; pass = false; break;}
        case 4 : { option = 1000000; filename = "1000000.txt"; pass = false; break;}
        case 5 : { option = 10000000; filename = "10000000.txt"; pass = false; break;}
        default:{
            cout << " Netinkamas įvesties formatas, bandykite dar kartą :   " << endl;
            break;
        }

    }
    }
    cout << "(1) Naudoti esantį " << filename << " failą. (2) Sugeneruoti naują " << filename << " failą ";
    cin >> option;
    ClearCin();
    switch(option){
        case 1:{
            break;
        }
        case 2:{
            auto start = std::chrono::high_resolution_clock::now();
            ofstream PrintOut(filename);
            if (!PrintOut.is_open()){
                cerr << "Klaida!  Failo atidarymo klaida." << endl;
                return;
            }
            try{
                ostringstream buffer;
                int s = option;
                int ndsize = 5;
                string ND;
                string Vardas;
                string Pavarde;
            
                buffer << left << setw(26) << "Vardas"  << setw(26) << "Pavardė";
                for(int i = 0; i<ndsize; i++){ ND = "ND" + std::to_string(i+1); buffer << setw(6) << left << ND;}
                buffer << setw(6) << left << "Egz" << endl;
                unsigned seed = (std::chrono::high_resolution_clock::now().time_since_epoch().count());
                mt19937 rng(seed);
                for(int i = 0; i<s; i++){
                    Vardas = "Vardas" + std::to_string(i+1);
                    Pavarde = "Pavarde" + std::to_string(i+1);
                    buffer << left << setw(26) << Vardas << setw(26) << Pavarde;

                    std::uniform_int_distribution<int> dist(1, 10);
                    for(int j = 0; j<ndsize; j++){
                        buffer << setw(6) << left << dist(rng);
                    }
                    buffer << setw(6) << left << dist(rng) << endl;
                }
                
                PrintOut << buffer.str();
                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> diff = end-start;
                cout << "Generavimas truko: " << diff.count() << endl;
                PrintOut.close();
            }
            catch (const exception& e){
                cerr << " Klaida!  Įrašymo į failą klaida " << endl;
            }
            break;
        }
    }
}

void OutputTime(){
    cout<<endl<<endl;
    cout<<" Reading data from file took: " << Marktime.at(0)<<endl;
    cout<<" Sorting took: " << Marktime.at(1)<<endl;
    cout<<" Making new containers took: " << Marktime.at(2)<<endl;

    double temp = 0.0;
    for(double i : Marktime){
        temp += i;
    }
    cout<<" Average time:  "<<temp<<endl;
}