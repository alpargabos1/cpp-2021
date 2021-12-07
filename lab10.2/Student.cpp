//
// Created by Alpar on 12/7/2021.
//

#include "Student.h"

Student::Student(int id, const string &firstName, const string &lastName) : ID(id),
                                                                            firstName(firstName),
                                                                            lastName(lastName) {
}

int Student::getId() const {
    return ID;
}

const string &Student::getFirstName() const {
    return firstName;
}

const string &Student::getLastName() const {
    return lastName;
}

const map<string, double> &Student::getGrades() const {
    return grades;
}

double Student::getAverage() {
    return average;
}

void Student::addGrade(const string &subject, double grade) {
    this->grades.insert(pair<string, double>(subject, grade));
}

void Student::computeAverage() {
    if (grades.size() != 3) {
        exit(33);
    }
    for (const auto &g: grades) {
        average += g.second;
    }
    average /= 3;
}

