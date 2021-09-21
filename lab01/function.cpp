//
// Created by Alpar on 9/20/2021.
//

#include <iostream>
#include "function.h"

int countBits(int number) {
    int counter = 0;
    while (number) {
        counter += number & 1;
        number >>= 1;
    }
    return counter;
}

bool setBit(int &number, int order) {
    if (order > 31 || order < 0)
        return false;
    number = (1 << order) | number;
    return true;
}

double mean(double array[], int numElements) {
    if (numElements == 0)
        return NAN;
    double avg = 0;
    for (int i = 0; i < numElements; i++)
        avg += array[i];
    return avg / numElements;
}

double stddev(double array[], int numElements) {
    if (numElements == 0)
        return NAN;
    double avg = 0;
    for (int i = 0; i < numElements; i++)
        avg += array[i];
    avg = avg / numElements;
    double deviation = 0;
    for (int i = 0; i < numElements; ++i) {
        array[i] = (array[i] - avg);
        deviation += (array[i] * array[i]);
    }
    return sqrt(deviation / numElements);
}

pair<double, double> max2(double array[], int numElements) {
    pair<double, double> result{NAN, NAN};
    if (numElements == 0) {
        return result;
    }
    result.first = INT16_MIN;
    result.second = INT16_MIN;
    for (int i = 0; i < numElements; ++i) {
        if (result.first < array[i]) {
            if (result.second < array[i]) {
                result.first = result.second;
                result.second = array[i];
            } else {
                result.first = array[i];
            }
        }
    }
    return result;
}

double stringSum(int argc, char *argv[]) {

    double num, sum = 0;
    for (int i = 0; i < argc; ++i) {
        istringstream iss(argv[i]);
        if (iss >> num) {
            sum += num;
        }
    }
    return sum;
}

int countWords(string text) {
    int sum = 0;
    string ex = " ";
    istringstream iss(text);
    while (iss >> ex) {
        sum++;
    }
    return sum;
}

string code(string text) {
    for (char &i: text) {
        if ((i >= 'a' && i < 'z') || (i >= 'A' && i < 'Z')) {
            i++;
        }
        if (i == 'z') {
            i = 'a';
        }
        if (i == 'Z') {
            i = 'A';
        }
    }
    return text;
}

string capitalizeWords(string text) {
    if (isalpha(text[0])) {
        text[0] = toupper(text[0]);
    }
    for (int i = 1; i < text.length(); ++i) {
        if (text[i - 1] == ' ') {
            text[i] = toupper(text[i]);
        } else {
            text[i] = tolower(text[i]);
        }
    }
    return text;
}


void readLines() {
    string line;
    cout << "String 4\n\tEnter a line: " << endl;
    getline(cin, line);
    cout << capitalizeWords(line) << endl;
}
