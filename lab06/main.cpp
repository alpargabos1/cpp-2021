#include <iomanip>
#include "Polynomial.h"

using namespace std;

int main() {
    double co[] = {4, 3, 2};
    Polynomial p1(2, co);
    cout << p1;
    Polynomial p2(p1);
    cout << p2;
    Polynomial p3 = move(p1);
    cout << p3;
    try {
        cout << p1;
    } catch (out_of_range &e) {
        cout << e.what() << endl;
    }

    cout << p2.degree() << endl;
    cout << p2.evaluate(3) << endl;

    Polynomial p4 = p2.derivative();
    cout << "Derivalt: " << p4 << endl;

    try {
        cout << "Pleas type an index: ";
        int index;
        cin >> index;
        cout << "X coefficient at index[p2] from 0: " << p2[index];
    } catch (out_of_range &e) {
        cout << e.what() << endl;
    }

    cout << endl << "- operator: " << -p2;

    cout << "p4 + p2: " << (p4 + p2);
    cout << "p4 - p2: " << (p4 - p2);
    cout << "p2 * p4: " << (p2 * p4);

    return 0;
}
