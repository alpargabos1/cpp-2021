//
// Created by Alpar on 12/7/2021.
//

#ifndef MAIN_CPP_STUDENT_H
#define MAIN_CPP_STUDENT_H

#include <iostream>
#include <map>

using namespace std;

class Student {
private:
    int ID;
    string firstName;
    string lastName;
    map<string, double> grades;
    double average;
    bool passed;
public:
    Student(int, const string &, const string &);

    int getId() const;

    const string &getFirstName() const;

    const string &getLastName() const;

    const map<string, double> &getGrades() const;

    void addGrade(const string &, double);

    bool getPassed() const;

    double getAverage() const;

    void computeAverage();

    friend ostream & operator <<(ostream&, const Student&);
};


#endif //MAIN_CPP_STUDENT_H
