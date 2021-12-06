#include <iomanip>
#include "Szemely.h"
#include "Alkalmazott.h"
#include "Manager.h"
#include "Ceg.h"

using namespace std;

int main() {
//    Szemely sz1("Nagy", "Bela", 1977);
//    sz1.print();
//    cout << sz1;
//    Alkalmazott a1("Egy","Ketto",1988,"dev");
//    Alkalmazott a2("Negy","Ot",1998,"dev");
//    Alkalmazott a3("Hat","Het",1928,"test");
//    Alkalmazott a4("Tiz","Husz",1948,"pr");
//    Manager m1("Fonok","Bacsi",1979,"Manager");
//    m1.addAlkalmazott(&a1);
//    m1.addAlkalmazott(&a2);
//    m1.addAlkalmazott(&a3);
//    m1.addAlkalmazott(&a4);
//
//    m1.print();

    Ceg ceg1;
    Alkalmazott a1("A", "B", 1999, "dev");
    Alkalmazott a2("C", "D", 1949, "dev");
    Alkalmazott a3("E", "F", 1923, "pr");
    Alkalmazott a4("G", "H", 1965, "hr");
    Alkalmazott a5("I", "J", 1998, "dev");
    Alkalmazott a6("K", "L", 1976, "pr");
    Alkalmazott a7("M", "N", 1975, "test");
    Manager m1("AA", "BB", 1999, "Manager");
    Manager m2("CC", "DD", 1999, "Manager");
    Manager m3("EE", "FF", 1999, "Manager");

    ceg1.addAlkalmazott(&a1);
    ceg1.addAlkalmazott(&a2);
    ceg1.addAlkalmazott(&a3);
    ceg1.addAlkalmazott(&a4);
    ceg1.addAlkalmazott(&a5);
    ceg1.addAlkalmazott(&a6);
    ceg1.addAlkalmazott(&a7);
    ceg1.addAlkalmazott(&m1);
    ceg1.addAlkalmazott(&m2);
    ceg1.addAlkalmazott(&m3);

    ceg1.addAlkalmManagerhez(1, 8);
    ceg1.addAlkalmManagerhez(2, 8);
    ceg1.addAlkalmManagerhez(3, 8);
    ceg1.addAlkalmManagerhez(4, 9);
    ceg1.addAlkalmManagerhez(5, 9);
    ceg1.addAlkalmManagerhez(6, 10);
    ceg1.addAlkalmManagerhez(7, 10);

    ceg1.printManagers();
    cout << "\nAthelyezzuk az 1-es alkalmazottat a 8-astol a 9-es managerhez...\n" << endl;

    ceg1.managerEltavAlkalm(1, 8);
    ceg1.addAlkalmManagerhez(1, 9);

    ceg1.printManagers();
    return 0;
}
