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

int countWords(string text){
    int sum = 0;
    string ex = " ";
    istringstream iss(text);
    while(iss >> ex){
        sum ++;
    }
    return sum;
}
