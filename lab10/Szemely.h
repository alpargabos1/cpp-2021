//
// Created by Alpar on 12/6/2021.
//

#ifndef MAIN_CPP_SZEMELY_H
#define MAIN_CPP_SZEMELY_H

#include <iostream>

using namespace std;

class Szemely {
private:
    string vezetekNev;
    string keresztNev;
    int szuletesiEv;
public:
    Szemely(const string&, const string&, int);

    virtual void print(ostream & = cout) const;

    virtual const string &getVezetekNev() const;

    virtual const string &getKeresztNev() const;

    virtual int getSzuletesiEv() const;

    friend ostream &operator<<(ostream &os, const Szemely &szemely);
};

ostream &operator<<(ostream &os, const Szemely &szemely);


#endif //MAIN_CPP_SZEMELY_H
