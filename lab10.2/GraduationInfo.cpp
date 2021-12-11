//
// Created by Alpar on 12/7/2021.
//

#include "GraduationInfo.h"

GraduationInfo::GraduationInfo(GraduationExam &graduationExam) : graduationExam(graduationExam) {

}

int GraduationInfo::getNumEnrolled() const {
    return graduationExam.numStudents();
}

int GraduationInfo::getNumPassed() const {
    return graduationExam.numPassed();
}

int GraduationInfo::getNumFailed() const {
    return graduationExam.numStudents() - graduationExam.numPassed();
}

Student GraduationInfo::getStudent(int i) const {
    return this->graduationExam.students.find(i)->second;
}

string GraduationInfo::getFirstName(int i) const {
    return this->graduationExam.students.find(i)->second.getFirstName();
}

string GraduationInfo::getLastName(int i) const {
    return this->graduationExam.students.find(i)->second.getLastName();;
}

double GraduationInfo::getAverage(int i) const {
    return this->graduationExam.students.find(i)->second.getAverage();
}

map<string, double> GraduationInfo::getResults(int i) const {
    return this->graduationExam.students.find(i)->second.getGrades();
}

void GraduationInfo::printResults(ostream &os) {
    for (auto s: graduationExam.students) {
        os << s.second.getId() << " " << s.second.getAverage() << endl;
    }
}

void GraduationInfo::printPassed(ostream &os) {
    for (auto s: graduationExam.students) {
        bool passed = true;
        for (const auto &g: s.second.getGrades()) {
            if (g.second < 5) {
                passed = false;
            }
        }
        if (s.second.getAverage() >= 6 && passed) {
            os << s.second.getId() << " " << s.second.getAverage() << endl;
        }
    }
}

void GraduationInfo::printFailed(ostream &os) {
    for (auto s: graduationExam.students) {
        bool passed = true;
        for(const auto& g: s.second.getGrades()){
            if(g.second < 5) {
                passed = false;
            }
        }
        if (!passed) {
            os << s.second.getId() << " " << s.second.getAverage() << endl;
        }
    }
}
