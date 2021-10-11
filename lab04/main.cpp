#include <iomanip>
#include "functions.h"
#include "PointSet.h"

using namespace std;

int main() {
///Megoldottak
//    dinamikusTomb();
//    algoritmusok();

///LABOR
    int n = 2;
    cout << "Pontok\tMinTav\t MaxTav\t #tavolsagok\t#kulonbozotavolsagok" << endl;
    cout << fixed;
    for (int i = 0; i < 12; ++i) {
        PointSet pSet(n);
        cout << setw(6) << n << " ";
        cout << setw(8) << setprecision(2) << pSet.minDistance() << " ";
        cout << setw(8) << setprecision(2) << pSet.maxDistance() << " ";
        cout << setw(10) << pSet.numDistances() << " ";
        cout << setw(16) << pSet.numDistinctDistances() << endl;
        n = n << 1;
    }
    return 0;
}
