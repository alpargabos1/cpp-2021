//
// Created by Alpar on 9/27/2021.
//

#ifndef LAB2_POINT_H
#define LAB2_POINT_H

#include <iostream>
#include <cmath>
#include <fstream>
#include <ctime>
#include <bits/stdc++.h>

using namespace std;

class Point {
private:
    int x, y;
public:
    Point(int x = 0, int y = 0);

    int getX() const;

    int getY() const;

    void setX(int);

    void setY(int);

    void print() const;
};

double distance(const Point &a, const Point &b);

bool isSquare(const Point &a, const Point &b, const Point &c, const Point &d);

void testIsSquare(const char *filename);

Point *createArray(int numPoints);

void printArray(Point *points, int numPoints);

pair<Point, Point> closestPoints(Point *points, int numPoints);

pair<Point, Point> farthestPoints(Point *points, int numPoints);

bool comparator(const Point &a, const Point &b);

void sortPoints(Point* points, int numPoints);

#endif //LAB2_POINT_H
