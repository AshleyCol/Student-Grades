#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const string studentDataFile = "student_data.txt";
struct Student {
    string name;
    int studentID;
    double* allScores;
    double average;
    char letterGrade;
};


int readStudentData(int header[2]);

int main()
{
    int header[2] = {0,0};
    int validation = 1;

    validation = readStudentData(header);

    if (validation == 0) {
    
    }
    else {
        return 1;
    }

    return 0;
}

int readStudentData(int header[2]) {
    ifstream inFile(studentDataFile);

    if (!inFile) {
        cout << "Error occured while opening file for reading!" << endl;

        return 1;
    }

    inFile >> header[0];
    inFile >> header[1];

    while (inFile) {
        static Student* data = new Student[header[0]];

        for (int i = 0; i < header[0]; i++) {
            data[i].allScores = new double[header[1]];
            inFile >> data[i].name;
            inFile >> data[i].studentID;

            for (int x = 0; x < header[1]; x++) {
                inFile >> data[i].allScores[x];
            }
        }
    }
    return 0;
}

