#include <iostream>
#include "Point.h"

using namespace std;

int main() {
    Point p1(2, 3);
    cout << "p1( " << p1.getX() << "," << p1.getY() << ")" << endl;
    Point p2(100, 200);
    cout << "p2( " << p2.getX() << "," << p2.getY() << ")" << endl;
    Point *pp1 = new Point(300, 400);
    Point *pp2 = new Point(500, 1000);
    cout << "pp1( " << pp1->getX() << "," << pp1->getY() << ")" << endl;
    cout << "pp2( " << pp2->getX() << "," << pp2->getY() << ")" << endl;

    //4
    cout << endl << "Distance (p1,p2): " << distance(p1, p2) << endl << endl;

    //5
    Point s1(20, 10), s2 = (10, 20),
            s3 = (20, 20), s4 = (10, 10);
    cout << "Is square s1(20, 10), s2 = (10, 20), s3 = (20, 20), s4 = (10, 10)? ===> " << isSquare(s1, s2, s3, s4)
         << endl << endl;

    //6
    cout << "FILE ROWS:" << endl;
    testIsSquare("points.txt");

    //7,8
    int len;
    cout << endl << endl << "Array length: ";
    cin >> len;
    auto pts = createArray(len);
    printArray(pts, len);

    //9
    cout << endl << endl << "Closest points (from array) are: ";
    auto cp = closestPoints(pts, len);
    cp.first.print();
    cout << "and ";
    cp.second.print();

    //10
    cout << endl << endl << "Farthest points (from array) are: ";
    auto fp = farthestPoints(pts, len);
    fp.first.print();
    cout << "and ";
    fp.second.print();
    cout << endl << endl;


    delete pp1;
    delete pp2;
    return 0;
}
