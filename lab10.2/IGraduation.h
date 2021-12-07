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
    virtual Student getStudent(int) const;
    virtual string getFirstName(int) const;
    virtual string getLastName(int) const;
    virtual double getAverage(int) const;
    virtual map<string,double> getResults(int) const;
    virtual void printResults(ostream &);
    virtual void printPassed(ostream &);
    virtual void printFailed(ostream &);
};


#endif //MAIN_CPP_IGRADUATION_H
