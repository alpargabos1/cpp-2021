//
// Created by Alpar on 12/7/2021.
//

#ifndef MAIN_CPP_GRADUATIONINFO_H
#define MAIN_CPP_GRADUATIONINFO_H


#include "GraduationExam.h"
#include "IGraduation.h"

class GraduationInfo : public IGraduation {
private:
    GraduationExam &graduationExam;
public:
    GraduationInfo(GraduationExam &g) : graduationExam(g) {};

    virtual int getNumEnrolled() const { return graduationExam.numStudents(); };

    virtual int getNumPassed() const { return graduationExam.numPassed(); };

    virtual int getNumFailed() const { return getNumEnrolled() - getNumPassed(); };

    virtual Student getStudent(int id) const { return graduationExam.students.find(id)->second; };

    virtual string getFirstName(int id) const { return graduationExam.students.find(id)->second.getFirstName(); };

    virtual string getLastName(int id) const { return graduationExam.students.find(id)->second.getLastName(); };

    virtual double getAverage(int id) const { return graduationExam.students.find(id)->second.getAverage(); };

    virtual map<string, double> getResults(int id) const {
        return graduationExam.students.find(id)->second.getGrades();
    };

    virtual void printResults(ostream &) const;

    virtual void printPassed(ostream &) const;

    virtual void printFailed(ostream &) const;
};

#endif //MAIN_CPP_GRADUATIONINFO_H
