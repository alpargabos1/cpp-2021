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
    GraduationInfo(GraduationExam &graduationExam);

    int getNumEnrolled() const override;

    int getNumPassed() const override;

    int getNumFailed() const override;

    Student getStudent(int i) const override;

    string getFirstName(int i) const override;

    string getLastName(int i) const override;

    double getAverage(int i) const override;

    map<string, double> getResults(int i) const override;

    void printResults(ostream &ostream1) override;

    void printPassed(ostream &ostream1) override;

    void printFailed(ostream &ostream1) override;
};




#endif //MAIN_CPP_GRADUATIONINFO_H
