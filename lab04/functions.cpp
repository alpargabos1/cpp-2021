//
// Created by Alpar on 10/11/2021.
//

#include "functions.h"

void dinamikusTomb() {
    //Definíció - üres dinamikus tömb
    vector<int> v;
    //Feltöltés: új elem hozzáadása: push_back VAGY emplace_back
    for (int i = 0; i < 10; ++i) {
        v.push_back(i * 10);
    }
    //Kiíratás
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void algoritmusok() {
    int x[100];
    int n = 10;
    cout << "x = [";
    for (int i = 0; i < n; ++i) {
        x[i] = rand() % MAX;
        cout << x[i] << " ";
    }
    cout << "]" << endl;
    cout << "Legkisebb : " << *min_element(x, x + n) << endl;
    vector<int> v;
    v.reserve(100);
    cout << "v = [";
    for (int i = 0; i < n; ++i) {
        v.emplace_back(rand() % MAX);
        cout << v[i] << " ";
    }
    cout << "]" << endl;
    cout << "Legnagyobb: " << *max_element(v.begin(), v.end()) << endl;
}