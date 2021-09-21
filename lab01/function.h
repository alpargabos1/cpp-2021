//
// Created by Alpar on 9/20/2021.
//

#ifndef CPP_2021_FUNCTION_H
#define CPP_2021_FUNCTION_H

#include <cmath>
#include <sstream> // stringstream, istringstream, ostringstream

using namespace std;

int countBits(int);

bool setBit(int &, int);

double mean(double [], int);

double stddev(double [], int);

pair<double, double> max2(double [], int);

double stringSum(int, char *argv[]);

int countWords(string);

string code(string);

string capitalizeWords(string);

void readLines();

#endif //CPP_2021_FUNCTION_H
