//
// Created by Alpar on 11/8/2021.
//

#include "Functions.h"


vector<string> fruits{
        "melon", "strawberry", "raspberry", "apple", "banana", "walnut", "lemon"
};

vector<int> numbers{
        2, 4, 6, 0, 8
};

vector<double> numbers2{
        2.2, 4, -6.7, 0, 8.79, -10.88
};

vector<string> months{
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
};

vector<pair<string, double>> months2{
        make_pair("January", 3.5),
        make_pair("February", 2.5),
        make_pair("March", 6),
        make_pair("April", 8),
        make_pair("May", 10),
        make_pair("June", 12),
        make_pair("July", 13.5),
        make_pair("August", 16),
        make_pair("September", 11),
        make_pair("October", 6),
        make_pair("November", 7.5),
        make_pair("December", 3.7)
};

void feladat1() {
    string myStr = "berry";
    auto result = find_if(fruits.begin(), fruits.end(), [myStr](const string &e) {
        return e.find(myStr) != -1;
    });
    cout << ((result != fruits.end()) ? *result : "Nincs") << endl;
}

void feladat2() {
    auto result = all_of(numbers.begin(), numbers.end(), [](int i) {
        return i % 2 == 0;
    });
    cout << ((result) ? "Igen" : "Nem") << endl;
}

void feladat3() {
    for_each(numbers.begin(), numbers.end(), [](int i) {
        i *= 2;
        cout << i << " ";
    });
    cout << endl;
}

void feladat4() {
    auto result = count_if(months.begin(), months.end(), [](const string &s) {
        return (s.length() == 5);
    });
    cout << result << endl;
}

void feladat5() {
    sort(numbers.begin(), numbers.end());
    for (int number: numbers) {
        cout << number << " ";
    }
    cout << endl;
    sort(numbers.begin(), numbers.end(), greater<>());
    for (int number: numbers) {
        cout << number << " ";
    }
}

void feladat6() {
    typedef pair<string, double> P;
    sort(months2.begin(), months2.end(), [](const P &a, const P &b) {
        return a.second < b.second;
    });
    cout << endl;
    for (const P &m: months2) {
        cout << m.first << " " << m.second << endl;
    }
    cout << endl;
}

void feladat7() {
    sort(numbers2.begin(), numbers2.end(), [](const double &a, const double &b) {
        return abs(a) < abs(b);
    });
    for (double number: numbers2) {
        cout << number << " ";
    }
}

void feladat8() {
    for_each(months.begin(), months.end(), [](string &s) {
        s[0] = tolower(s[0]);
    });
    cout << endl;
    for (const string &s: months) {
        cout << s << " ";
    }
    cout << endl;
}

void feladat9() {
    string abc = "abcdefghijklmnopqrstuvwxyz";
    random_shuffle(abc.begin(), abc.end());
    cout << endl << abc;

    sort(months.begin(), months.end(), [abc](const string &x, const string &y) {
        return lexicographical_compare(x.begin(), x.end(), y.begin(), y.end(), [abc](const char &c1, const char &c2) {
            return find(abc.begin(), abc.end(), c1) < find(abc.begin(), abc.end(), c2);
        });
    });
    for (string i: months) {
        cout << i << endl;
    }
}
