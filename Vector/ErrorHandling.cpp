#include "ErrorHandling.h"

int StartParameters() {
    string p;
    while (true) {
        getline(cin, p);
        try {
            if (cin.fail()) {
                ClearCin();
                throw runtime_error(" Įvesties klaida, bandykite dar kartą ");
            }
            if (p.empty() || any_of(p.begin(), p.end(), [](char c) { return !(isdigit(c)) || isspace(c); })) {
                throw invalid_argument("Netinkamas įvesties formatas, bandykite dar kartą (patikrinkite ar nėra tarpų arba raidžių)");
            }
            int num = stoi(p);
            if (num <= 0 || num > 2147483646) {
                throw out_of_range("Netinkamas įvesties formatas, bandykite dar kartą (patikrinkite ar nėra tarpų arba raidžių)");
            }
            return num;
        }
        catch (const runtime_error& e){
            cerr << e.what() << endl;
        }
        catch (const invalid_argument& e) {
            cerr << e.what() << endl;
        }
        catch (const out_of_range& e) {
            cerr << e.what() << endl;
        }
    }
}
string StringParameters(){
    string p;
    while(true){
        getline(cin, p);
        try{
            if (cin.fail()) {
                ClearCin();
                throw runtime_error(" Įvesties klaida, bandykite dar kartą ");
            }
            if(p.empty() || p.size() > 25 || any_of(p.begin(), p.end(), [](char c) { return isdigit(c) || isspace(c); })) {
                throw invalid_argument("Netinkamas įvesties formatas, bandykite dar kartą (patikrinkite ar nėra tarpų arba skaičių)");
            }
        return p;
        }
        catch (const runtime_error& e){
            cerr << e.what() << endl;
        }
        catch (const invalid_argument& e) {
            cerr << e.what() << endl;
        }
    }
}

int GradingParameters(){
    string p;
    while (true) {
        getline(cin, p);
        try {
            if (cin.fail()) {
                ClearCin();
                throw runtime_error(" įvesties klaida, bandykite dar kartą ");
            }
            if (p.empty() || any_of(p.begin(), p.end(), [](char c) { return !(isdigit(c)) || isspace(c); })) {
                throw invalid_argument("Netinkamas įvesties formatas, bandykite dar kartą (patikrinkite ar nėra tarpų arba raidžių)");
            }
            int num = stoi(p);
            if (num < 0 || num > 11) {
                throw out_of_range("Netinkamas įvesties formatas, bandykite dar kartą (patikrinkite ar nėra tarpų arba raidžių)");
            }
            return num;
        }
        catch (const runtime_error& e){
            cerr << e.what() << endl;
        }
        catch (const invalid_argument& e) {
            cerr << e.what() << endl;
        }
        catch (const out_of_range& e) {
            cerr << e.what() << endl;
        }
    }
}
int ExamParameters(){
    string p;
    while (true) {
        getline(cin, p);
        try {
            if (cin.fail()) {
                ClearCin();
                throw runtime_error(" Įvesties klaida, bandykite dar kartą ");
            }
            if (p.empty() || any_of(p.begin(), p.end(), [](char c) { return !(isdigit(c)) || isspace(c); })) {
                throw invalid_argument("Netinkamas įvesties formatas, bandykite dar kartą (patikrinkite ar nėra tarpų arba raidžių)");
            }
            int num = stoi(p);
            if (num < 0 || num > 10) {
                throw out_of_range("Netinkamas įvesties formatas, bandykite dar kartą (patikrinkite ar nėra tarpų arba raidžių)");
            }
            return num;
        }
        catch (const runtime_error& e){
            cerr << e.what() << endl;
        }
        catch (const invalid_argument& e) {
            cerr << e.what() << endl;
        }
        catch (const out_of_range& e) {
            cerr << e.what() << endl;
        }
    }
}

void ClearCin(){

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
