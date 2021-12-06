//
// Created by Alpar on 12/6/2021.
//

#include "Ceg.h"

void Ceg::printManagers() const {
    for (auto m: alkalmazottak) {
        if ((*m).getMunkakor() == "Manager") {
            (*m).print();
        }
    }
}

void Ceg::printEmployees() const {
    for (auto alk: alkalmazottak) {
        (*alk).print();
    }
}

void Ceg::addAlkalmazott(Alkalmazott *a) {
    alkalmazottak.emplace_back(a);
}

void Ceg::addAlkalmManagerhez(int empId, int manId) {
    for (auto man: alkalmazottak) {
        if ((*man).getMunkakor() == "Manager" && (*man).getId() == manId) {
            auto *c = dynamic_cast<Manager *>(man);
            if (c != nullptr)
                c->addAlkalmazott(keresesIdSzerint(empId));
            break;
        }
    }
}

void Ceg::kirugAlkalmoazott(int id) {
    for (auto i = this->alkalmazottak.begin(); i != alkalmazottak.end(); ++i) {
        if ((*i)->getId() == id) {
            this->alkalmazottak.erase(i);
            break;
        }
    }
}

void Ceg::managerEltavAlkalm(int empId, int manId) {
    for (auto a: alkalmazottak)
    {
        if ((*a).getMunkakor()=="Manager" && (*a).getId()==manId)
        {
            auto * c = dynamic_cast<Manager*>(a);
            if (c)
                c->deleteAlkalmazott(empId);
            break;
        }
    }
}

Alkalmazott *Ceg::keresesIdSzerint(int id) {
    for (auto it: alkalmazottak) {
        if ((*it).getId() == id) {
            return it;
        }
    }
    return nullptr;
}
