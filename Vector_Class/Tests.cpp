#include "Tests.h"

stud IstreamInputTest(stud& Tester, string filename){
    ifstream file(filename);
    string line;
    getline(file, line);
    istringstream in(line);
    in >> Tester;
    file.close();
    return Tester;
}
stud CinInputTest(stud& Tester){
    cin >> Tester;
    return Tester;
}

void OutputTest(const stud& Tester){
    cout << Tester;
}
void OutputTestFile(const stud& Tester, string filename){
    ostringstream buffer;
    buffer << Tester;
    ofstream file(filename);
    file << buffer.str();
    file.close();
}
void CopyOpConTest(stud &Tester1, stud &Tester2){
    stud TestCopy(Tester1); // Testing Copy Constructor
    cout << "Tester 1: " << endl;
    OutputTest(Tester1);
    cout << "TestCopyConstructor: " << endl;
    OutputTest(TestCopy);

    TestCopy = Tester2; // Testing Copy operator
    cout << "Tester 2: " << endl;
    OutputTest(Tester2);
    cout << "TestCopyConstructor: " << endl;
    OutputTest(TestCopy);
}
void MoveOpConTest(stud &Tester1, stud &Tester2){
    stud TestMove(std::move(Tester1)); // Testing Move Constructor
    cout << "Tester 1: " << endl;
    OutputTest(Tester1);
    cout << "TesterMove: " << endl;
    OutputTest(TestMove);

    TestMove = std::move(Tester2); // Testing Move operator
    cout << "Tester 2: " << endl;
    OutputTest(Tester2);
    cout << "TesterMove: " << endl;
    OutputTest(TestMove);
}