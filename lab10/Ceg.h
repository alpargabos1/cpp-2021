//
// Created by Alpar on 12/6/2021.
//

#ifndef MAIN_CPP_CEG_H
#define MAIN_CPP_CEG_H

#include "Alkalmazott.h"
#include "Manager.h"
#include <vector>


class Ceg {
private:
    vector<Alkalmazott*> alkalmazottak;
public:
    void printManagers() const;
    void printEmployees() const;
    void addAlkalmazott(Alkalmazott* a);
    void addAlkalmManagerhez(int empId, int manId);
    void kirugAlkalmoazott(int id);
    void managerEltavAlkalm(int empId, int manId);
    Alkalmazott* keresesIdSzerint(int id);
};


#endif //MAIN_CPP_CEG_H
