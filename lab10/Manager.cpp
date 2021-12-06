//
// Created by Alpar on 12/6/2021.
//

#include "Manager.h"

Manager::Manager(const string &kNev, const string &vNev, int szulEv, const string &munkakor) : Alkalmazott(vNev,kNev,szulEv,munkakor){

}
const string Manager::MANAGER_MUNKAKOR = "manager";

void Manager::addAlkalmazott(Alkalmazott* alk) {
    this->beosztottak.emplace_back(alk);
}

void Manager::deleteAlkalmazott(int id) {

    for (auto it=this->beosztottak.begin();  it!=beosztottak.end();++it)
    {
        if ( (*it)->getId() == id )
        {
            this->beosztottak.erase(it);
            break;
        }
    }
}

void Manager::print(ostream &os) const {
    os<<"Manager <"<<this->getId()<<"> <"<<this->getVezetekNev()<<"> <"<<this->getKeresztNev()<<"> beosztottjai:"<<endl;

    for (auto a:beosztottak)
    {
        cout<<"\t"<<"Alkalmazott <"<<(*a).getId()<<"> <"<<(*a).getVezetekNev()<<"> <"<<(*a).getKeresztNev()<<"> <"<<(*a).getMunkakor()<<">\n";
    }
}
