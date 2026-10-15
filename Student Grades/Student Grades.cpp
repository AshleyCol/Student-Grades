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


int readStudentData(Student data, int header[2]);

int main()
{
    Student studentData;
    int header[2] = {0,0};
    int validation = 1;

    validation = readStudentData(studentData, header);

    if (validation == 0) {

    }
    else {
        return 1;
    }

    return 0;
}

int readStudentData(Student data, int header[2]) {
    ifstream inFile(studentDataFile);

    if (!inFile) {
        cout << "Error occured while opening file for reading!" << endl;

        return 1;
    }




    return 0;
}

