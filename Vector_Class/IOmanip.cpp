#include "IOmanip.h"

void Assign(vector<stud> &obj, bool countByAvg){

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
                        obj.resize(counter+1);
                        cout << "Įveskite " << counter+1 << " studento vardą :  ";
                        obj.at(counter).setName(StringParameters());
                        cout << "Įveskite " << counter+1 << " studento pavardę :  ";
                        obj.at(counter).setSurname(StringParameters());
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
                                obj.at(counter).AddMark(tempgrade);
                            }
                        }
                        int s = obj.at(counter).getHomeWorkSize();
                        int sum = 0;
                        for(const int& i : obj.at(counter).getHomeWorkRez()){
                            sum += i;
                        }
                        cout << "Įveskite " << counter+1 << "-o studento egzamino rezultatą :  ";
                        obj.at(counter).setEgzamRez(ExamParameters());
                        obj.at(counter).CalculateFinalMark(countByAvg, sum);
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
                        obj.resize(counter+1);
                        cout << "Įveskite " << counter+1 << " studento vardą :  ";
                        obj.at(counter).setName(StringParameters());
                        cout << "Įveskite " << counter+1 << " studento pavardę :  ";
                        obj.at(counter).setSurname(StringParameters());
                        obj.at(counter).GenerateRandomGrades(numberOfHw, counter, countByAvg);
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
                obj.resize(counter+1);
                obj.at(counter).GenerateRandomName(counter);
                obj.at(counter).GenerateRandomGrades(numberOfHw, counter, countByAvg);
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

void Print (const vector<stud> &obj){
    int s = obj.size();

    cout << left << setw(26) << "Vardas"  << setw(26) << "Pavardė" << setw(15) << left << "Galutinis" << endl;
    for (int z = 0; z<70; z++){ cout << '-'; }
    cout << endl;
    for(int i = 0; i<s; i++){
        cout << left << setw(26) << obj.at(i).getName() << setw(26) << obj.at(i).getSurname() << setw(15) << left << fixed << setprecision(2) << obj.at(i).getEgzamRez() << endl;
    }
}

void readFile(vector<stud> &obj, const string filename, const bool countByAvg){

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
            istringstream is(line);
            try{stud temp(is, countByAvg); obj.emplace_back(temp);}
            catch(const runtime_error& e){continue;}
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

void PrintFile(const vector<stud> &obj, string filename){

    // auto start = std::chrono::high_resolution_clock::now();
    ofstream PrintOut(filename);
    if (!PrintOut.is_open()){
        cerr << "Klaida!  Failo atidarymo klaida." << endl;
        return;
    }

    try{
        ostringstream buffer;
        int s = obj.size();

        buffer << left << setw(26) << "Vardas"  << setw(26) << "Pavardė" << setw(15) << left << "Galutinis" << endl;
        for (int z = 0; z<70; z++){ buffer << '-'; }
        buffer << endl;
        for(int i = 0; i<s; i++){
            buffer << left << setw(26) << obj.at(i).getName() << setw(26) << obj.at(i).getSurname() << setw(15) << left << fixed << setprecision(2) << obj.at(i).getEgzamRez() << endl;
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
    int temp = 0;
    cin >> temp;
    ClearCin();
    switch(temp){
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
                break;
            }
            catch (const exception& e){
                cerr << " Klaida!  Įrašymo į failą klaida " << endl;
            }
        }
    }
}

void OutputTime(){
    cout<<endl<<endl;
    cout<<" Reading data from file took: " << Marktime.at(0)<<endl;
    cout<<" Sorting took: " << Marktime.at(1)<<endl;
    cout<<" Making new containers took: " << Marktime.at(2)<<endl;

    double temp = 0.0;
    for(int i = 0; i<3; i++){
        temp += Marktime.at(i);
    }
    cout<<" Average time:  "<<temp<<endl;
    // AverageTime.emplace_back(temp);
    // cout<<" Program time:  " <<AverageTime.at(0)<<endl;
}