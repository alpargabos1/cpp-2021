//
// Created by Alpar on 12/7/2021.
//

#include "GraduationInfo.h"

void GraduationInfo::printResults(ostream &os) const {
    os << "Year:" << graduationExam.year << endl;
    os << "Num enrolled:" << getNumEnrolled() << endl;
    os << "Num passed:" << getNumPassed() << endl;
    os << "Num failed:" << getNumFailed() << endl;
}

void GraduationInfo::printPassed(ostream &os) const {
    for (const auto &a: graduationExam.students) {
        if (a.second.getPassed())
            os << a.second;
    }
}

void GraduationInfo::printFailed(ostream &os) const {
    for (const auto &a: graduationExam.students) {
        if (!a.second.getPassed())
            os << a.second;
    }
}
