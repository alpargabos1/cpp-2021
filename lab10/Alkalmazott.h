//
// Created by Alpar on 12/6/2021.
//

#ifndef MAIN_CPP_ALKALMAZOTT_H
#define MAIN_CPP_ALKALMAZOTT_H

#include "Szemely.h"

class Alkalmazott : public Szemely {
private:
    string munkakor;
    int id;
public:
    int getId() const;

    const string &getMunkakor() const;

    Alkalmazott(const string &vNev, const string &kNev, int szulEv, const string &munkakor);
    virtual void print(ostream & = cout) const override;
};


#endif //MAIN_CPP_ALKALMAZOTT_H
