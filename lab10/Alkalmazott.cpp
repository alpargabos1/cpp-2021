//
// Created by Alpar on 12/6/2021.
//

#include "Alkalmazott.h"

static int ID = 0;

Alkalmazott::Alkalmazott(const string &vNev, const string &kNev, int szulEv, const string &munkakor) : Szemely(vNev,
                                                                                                               kNev,
                                                                                                               szulEv) {
    this->munkakor = munkakor;
    this->id = ++ID;
}

void Alkalmazott::print(ostream &os) const {
    os << "\nALKALMAZOTT";
    Szemely::print();
    os << "Munkakor: " << munkakor << endl;
    os << "ID: " << id << endl;
}

int Alkalmazott::getId() const {
    return id;
}

const string &Alkalmazott::getMunkakor() const {
    return munkakor;
}


