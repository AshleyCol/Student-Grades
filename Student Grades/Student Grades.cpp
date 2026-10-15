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


int readStudentData(Student*& data, double header[2]);
void calculateAverages(Student*& data, double header[2]);

int main()
{
    double header[2] = {0,0};
    int validation = 1;
    Student* studentData;

    validation = readStudentData(studentData, header);

    if (validation == 0) {
        calculateAverages(studentData, header);
        
    }
    else {
        return 1;
    }

    return 0;
}

int readStudentData(Student*& data, double header[2]) {
    ifstream inFile(studentDataFile);

    if (!inFile) {
        cout << "Error occured while opening file for reading!" << endl;

        return 1;
    }

    inFile >> header[0];
    inFile >> header[1];

    if (header[0] <= 0 || header[1] <= 0) {
        cout << "Invalid data in file!" << endl;

        return 1;
    }

    data = new Student[header[0]];

    for (int i = 0; i < header[0]; i++) {
        data[i].allScores = new double[header[1]];
        inFile >> data[i].name;
        inFile >> data[i].studentID;

        for (int x = 0; x < header[1]; x++) {
            inFile >> data[i].allScores[x];
        }
    }

    return 0;
}

void calculateAverages(Student*& data, double header[2]) {
    for (int i = 0; i < header[0]; i++) {
        double totalScore = 0;
        
        for (int x = 0; x < header[1]; x++) {
            totalScore = totalScore + data[i].allScores[x];
        }

        data[i].average = totalScore / header[1];
    }
}