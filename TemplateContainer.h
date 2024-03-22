#pragma once

#include "lib.h"
#include "ErrorHandling.h"
#include "DataManip.h"
#include "IOmanip.h"


template<typename Container>
void process(Container& obj, bool countByAvg) {
    std::string filename;
    int option = 0;
    CreateFile(filename);

    bool pass = true;

    while (pass) {
        std::cout << " Pasrinkite galutinio balo skaičiavimo būdą: " << std::endl;
        std::cout << " (1) Pagal vidurkį " << std::endl;
        std::cout << " (2) Pagal medianą " << std::endl;
        std::cin >> option;
        ClearCin();

        switch (option) {
            case 1: {
                countByAvg = true;
                pass = false;
                break;
            }
            case 2: {
                countByAvg = false;
                pass = false;
                break;
            }
            default: {
                std::cout << " Netinkamas įvesties formatas, bandykite dar kartą :   " << std::endl;
                break;
            }
        }
    }

    pass = true;

    while (pass) {
        std::cout << " Pasrinkite programos veikimo eigą: " << std::endl;
        std::cout << " (1) Duomenis nuskaityti iš failo. " << std::endl;
        std::cout << " (2) Duomenis suvesti programoje. " << std::endl;
        std::cin >> option;
        ClearCin();

        switch (option) {
            case 1: {
                readFile(obj, filename, countByAvg);
                pass = false;
                break;
            }
            case 2: {
                Assign(obj);
                pass = false;
                break;
            }
            default: {
                std::cout << " Netinkamas įvesties formatas, bandykite dar kartą :   " << std::endl;
                break;
            }
        }
    }

    sorting(obj, countByAvg);

    Container SAD, COOL;

    SplitVector(obj, SAD, COOL, countByAvg);

    pass = true;
    while (pass) {
        std::cout << " Pasrinkite duomenų spausdinimo būdą: " << std::endl;
        std::cout << " (1) Duomenis spausdinti į failą. (Rekomenduojama dideliems kiekiams duomenų) " << std::endl;
        std::cout << " (2) Duomenis spausdinti programoje. " << std::endl;
        std::cin >> option;
        ClearCin();

        switch (option) {
            case 1: {
                filename = "Liūdesiukai.txt";
                PrintFile(SAD, countByAvg, filename);
                filename = "Kietiakai.txt";
                PrintFile(COOL, countByAvg, filename);
                pass = false;
                break;
            }
            case 2: {
                Print(obj, countByAvg);
                pass = false;
                break;
            }
            default: {
                std::cout << " Netinkamas įvesties formatas, bandykite dar kartą :   " << std::endl;
                break;
            }
        }
    }
}
