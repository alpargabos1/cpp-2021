#include <iostream>
#include "function.h"

using namespace std;

int main() {
    ///FUGGVENYEK

    //feladat 1
    cout << countBits(9) << endl;

    //feladat 2
    int x = 8;
    setBit(x, 2);
    cout << x << endl;

    //feladat 3
    double arr[3] = {1, 3, 6};
    cout << mean(arr, 3) << endl;


    //feladat4
    double arr2[4] = {20, 10, 15, 15};
    cout << stddev(arr2, 4) << endl;

    //feladat 5
    double arr3[4] = {20, 10, 85, 15};
    cout << max2(arr3, 4).first << " " << max2(arr3, 4).second << endl;


    ///STRING

    //feladat 1
    string myStr = "1 2 3 alma 4";
    cout << countWords(myStr) << endl;
    return 0;
}
