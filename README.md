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

### Version 1.2 (Rule of Five)
## Constructors, Destructors & Operators

# Copy and Move Constructors ![image](https://github.com/Kacerns/Pirmas-Projektas2/assets/148889303/049f9f67-6e85-4e17-b521-16db16f836f9)
# Destructor ![image](https://github.com/Kacerns/Pirmas-Projektas2/assets/148889303/2ea16229-ac34-4303-ae2e-811bfdd22364)
# Copy and Move Operators ![image](https://github.com/Kacerns/Pirmas-Projektas2/assets/148889303/4e96d9fa-3915-47ef-a579-6dc8331d090e)
# Input and Output Operators ![image](https://github.com/Kacerns/Pirmas-Projektas2/assets/148889303/424a467d-37f7-41c7-b009-2d34084e169f) _Output Operator takes any ostream and prints out default parameters and the final grade_   ![image](https://github.com/Kacerns/Pirmas-Projektas2/assets/148889303/2b0d559a-70cf-4eec-992f-eb728d901985) _The input operator checks for input method and can be used to input by file or by hand in the console_
## Testing

# Testing Copy Constructors and operators ![image](https://github.com/Kacerns/Pirmas-Projektas2/assets/148889303/80e8140d-0f5b-4bd4-a30d-d1c9313f2e65) ![image](https://github.com/Kacerns/Pirmas-Projektas2/assets/148889303/e7d09b2d-cb20-4bd7-afee-31a093c6a2a0) ![image](https://github.com/Kacerns/Pirmas-Projektas2/assets/148889303/342ba9bd-710d-44d3-86d1-7b3724709aae)
# Testing Move Constructors and operators ![image](https://github.com/Kacerns/Pirmas-Projektas2/assets/148889303/90a43282-a3ee-41df-8491-964690349011) ![image](https://github.com/Kacerns/Pirmas-Projektas2/assets/148889303/8c7dfdff-34ce-463b-a2eb-006b6223418d) ![image](https://github.com/Kacerns/Pirmas-Projektas2/assets/148889303/3a76cc90-0b77-4904-bcbe-e83c1b48785b)

### Version 1.5 (Abstract Class)
## Constructing abstract class












