### Welcome to my first published c++ project on github
## Setup
   1. Download MinGW compiler.
   2. Open cmd
   3. Open the project, then navigate to the folder named vector.
   4. Open the terminal and execute the following commands:
   ```
   mkdir build
   cd build
   cmake ..
   make
   ./my_program
   ```
   5. Enjoy!

This repository contains two *.cpp files
Both C.cpp and vector.cpp achieve the same objective of enabling users to input their students name/surname, along with their homework/exam grades, and subsequently calculate the final grade using either the average or median with a specific formula.:

Finalgrade = 0.4 * average/median + 0.6 * examGrade

vector.cpp uses vectors and C.cpp uses dynamic arrays

vector.cpp has the ability to read data from files as well as output data to a new file. This program also lets you sort data by 1. Student name, 2. Student surname and 3. Final grade.
I have tested 3 data files containing 1. 10000 students 2. 100000 students 3. 1000000 students

Average time spent on Input, Sorting and Output(Data was tested 3 times):
(Keep in mind that time spent on these operations could differ according to the device running the program)

1. "10000.txt":
   Input: 0.36 seconds
   Sorting: 0.09 seconds
   Output: 0.20 seconds
2. "100000.txt":
   Input: 3.76 seconds
   Sorting: 0.88 seconds
   Output:  2.67 seconds
4. "1000000.txt":
   Input: 15.56 seconds
   Sorting: 10.31 seconds
   Output:  17.12 seconds

### V1.1
   ##  Testing Classes vs Structures
   ##   Classes results
   #    100000.txt file: ![image](https://github.com/Kacerns/Pirmas-Projektas2/assets/148889303/5b98d4b6-83d2-43d6-a6d5-cae08abd6c41)
   #    1000000.txt file : ![image](https://github.com/Kacerns/Pirmas-Projektas2/assets/148889303/6df7e2fe-2603-4e0f-b3f8-d3c1c99f0056)
   ##   Struct results
   100000.txt file: ![image](https://github.com/Kacerns/Pirmas-Projektas2/assets/148889303/a7f570ad-2d37-4bca-b0d5-04414385a357)
   1000000.txt file: ![image](https://github.com/Kacerns/Pirmas-Projektas2/assets/148889303/1c0983f7-e273-4f7a-b0ad-4b5758e4e41a)
   ## Testing Optimisation
   #   O1:
   100000.txt file : ![image](https://github.com/Kacerns/Pirmas-Projektas2/assets/148889303/17388fea-eba7-414c-8d49-a8da8b9b7d00)
   1000000.txt file : ![image](https://github.com/Kacerns/Pirmas-Projektas2/assets/148889303/d389843a-8fb2-4c68-8cd1-eb3d77c45542)
   # O2: 
   100000.txt file : ![image](https://github.com/Kacerns/Pirmas-Projektas2/assets/148889303/8dec343e-914f-4b8e-a244-7bd95ca65580)
   1000000.txt file : ![image](https://github.com/Kacerns/Pirmas-Projektas2/assets/148889303/8ffaf25b-fd25-4d47-ac7e-598be36475b3)
   # O3: 
   100000.txt file : ![image](https://github.com/Kacerns/Pirmas-Projektas2/assets/148889303/4e989667-a773-4503-8226-a014b68b8d69)
   1000000.txt file : ![image](https://github.com/Kacerns/Pirmas-Projektas2/assets/148889303/75c71dc8-c0a8-4b19-bac7-ea25283518a5)








      


