# Welcome to my first published c++ project on github

This repository contains two *.cpp files
Both C.cpp and vector.cpp achieve the same objective of enabling users to input their students name/surname, along with their homework/exam grades, and subsequently calculate the final grade using either the average or median with a specific formula.:

Finalgrade = 0.4 * average/median + 0.6 * examGrade

vector.cpp uses vectors and C.cpp uses dynamic arrays

vector.cpp has the ability to read data from files aswell as output data to a new file. This program also lets you sort data by 1. Student name, 2. Student surname and 3. Final grade.
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

