//
// Created by Alpar on 12/7/2021.
//

#include "GraduationExam.h"

string tempFirstName, tempLastName;
int tempId;
double tempGrade;
map<int, Student>::iterator it;

void GraduationExam::enrollment(const string &filename) {
    ifstream fNames("names.txt");
    if (!fNames) {
        exit(11);
    }

    while (!fNames.eof()) {
        fNames >> tempId;
        fNames >> tempFirstName;
        fNames >> tempLastName;
        const Student tempStudent(tempId, tempFirstName, tempLastName);
        students.insert(pair<int, Student>(tempId, tempStudent));
    }
//    for (const auto& s : students){
//        cout << s.first << " " << s.second.getFirstName() << " " << s.second.getLastName() << endl;
//    }
}

void GraduationExam::readGradesOfSubject(const string &subject, const string &filename) {
    ifstream fGrades(filename);
    if (!fGrades) {
        exit(22);
    }
    while (!fGrades.eof()) {
        fGrades >> tempId >> tempGrade;
        students.find(tempId)->second.addGrade(subject,tempGrade);
    }
}

void GraduationExam::computeFinalGrades() {
    for(auto s : students){
        s.second.computeAverage();
        cout << s.second.getId() << " " << s.second.getAverage() << endl;
    }

}

map<string, double> GraduationExam::getGrades(int studentID) const {
    map<string, double> grade;

    return grade;
}

int GraduationExam::numPassed() const {
    return 0;
}