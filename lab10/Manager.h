//
// Created by Alpar on 12/6/2021.
//

#ifndef MAIN_CPP_MANAGER_H
#define MAIN_CPP_MANAGER_H

#include "Alkalmazott.h"
#include <vector>

class Manager : public Alkalmazott{
private:
    vector<Alkalmazott*> beosztottak;
public:
    Manager(const string&, const string&, int, const string&);
    static const string MANAGER_MUNKAKOR;
    void addAlkalmazott(Alkalmazott* alk);
    int beosztottakSzama() {return beosztottak.size();}
    void deleteAlkalmazott(int id);
    virtual void print(ostream& os=cout) const;
};


#endif //MAIN_CPP_MANAGER_H
