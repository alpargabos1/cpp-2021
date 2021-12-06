//
// Created by Alpar on 12/6/2021.
//

#include "Szemely.h"

Szemely::Szemely(const string &vNev, const string &kNev, int szulEv) {
    this->keresztNev = kNev;
    this->vezetekNev = vNev;
    this->szuletesiEv = szulEv;
}

void Szemely::print(ostream &os) const {
    os << "\nVezeteknev: " << vezetekNev << "\nKeresztNev: " << keresztNev << "\nSzuletesiEv: " << szuletesiEv << endl;
}

ostream &operator<<(ostream &os, const Szemely &szemely) {
    os << "\nVezeteknev: " << szemely.vezetekNev << "\nKeresztNev: " << szemely.keresztNev << "\nSzuletesiEv: " << szemely.szuletesiEv << endl;
    return os;
}

const string &Szemely::getVezetekNev() const {
    return vezetekNev;
}

const string &Szemely::getKeresztNev() const {
    return keresztNev;
}

int Szemely::getSzuletesiEv() const {
    return szuletesiEv;
}
