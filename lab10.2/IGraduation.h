//
// Created by Alpar on 12/7/2021.
//

#ifndef MAIN_CPP_IGRADUATION_H
#define MAIN_CPP_IGRADUATION_H

#include "Student.h"

class IGraduation {
public:
    virtual int getNumEnrolled() const = 0;

    virtual int getNumPassed() const = 0;

    virtual int getNumFailed() const = 0;

    virtual Student getStudent(int) const = 0;

    virtual string getFirstName(int) const = 0;

    virtual string getLastName(int) const = 0;

    virtual double getAverage(int) const = 0;

    virtual map<string, double> getResults(int) const = 0;

    virtual void printResults(ostream &) const = 0;

    virtual void printPassed(ostream &) const = 0;

    virtual void printFailed(ostream &) const = 0;
};


#endif //MAIN_CPP_IGRADUATION_H
