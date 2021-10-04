//
// Created by Alpar on 9/27/2021.
//

#include "Point.h"

Point::Point(int x, int y) {
    if (x >= 0 && x <= 2000 && y >= 0 && y <= 2000) {
        this->x = x;
        this->y = y;
    } else {
        this->x = 0;
        this->y = 0;
    }
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

void Point::print() const {
    cout << "(" << x << " , " << y << ") ";
}

void Point::setX(int num) {
    this->x = num;
}

void Point::setY(int num) {
    this->y = num;
}

double distance(const Point &a, const Point &b) {
    return sqrt(pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2) * 1.0);
}

bool isSquare(const Point &a, const Point &b, const Point &c, const Point &d) {
    if (distance(a, b) == distance(a, c) && distance(c, d) == distance(b, d) && distance(a, c) == distance(b, d)) {
        return true;
    }
    return false;
}

void testIsSquare(const char *filename) {
    std::ifstream ifs(filename);
    if (!ifs) {
        std::cout << "File is not avaliable!" << std::endl;
    }
    int x, y;
    Point points[4];
    while (!ifs.eof()) {
        for (int i = 0; i < 4; i++) {
            ifs >> x;
            ifs >> y;
            Point np(x, y);
            points[i] = np;
        }
        isSquare(points[0], points[1], points[2], points[3]) ? std::cout << "YES" << endl : std::cout << "NO"
                                                                                                      << std::endl;
    }
}

Point *createArray(int numPoints) {
    auto *points = new Point[numPoints];
    srand(time(0));
    Point temp;
    for (int i = 0; i < numPoints; ++i) {
        temp.setX(rand() % 10);
        temp.setY(rand() % 10);
        points[i] = temp;
    }
    return points;
}

void printArray(Point *points, int numPoints) {
    for (int i = 0; i < numPoints; ++i) {
        points[i].print();
        cout << " ";
    }
}

pair<Point, Point> closestPoints(Point *points, int numPoints) {
    pair<Point, Point> minPair{points[0], points[1]};
    double min = distance(minPair.first, minPair.second);
    for (int i = 0; i < numPoints; ++i)
        for (int j = i + 1; j < numPoints; ++j)
            if (distance(points[i], points[j]) < min) {
                minPair.first = points[i];
                minPair.second = points[j];
                min = distance(points[i], points[j]);
            }
    return minPair;
}

pair<Point, Point> farthestPoints(Point *points, int numPoints) {
    pair<Point, Point> maxPair{points[0], points[1]};
    double max = distance(maxPair.first, maxPair.second);
    for (int i = 0; i < numPoints; ++i)
        for (int j = i + 1; j < numPoints; ++j)
            if (distance(points[i], points[j]) > max) {
                maxPair.first = points[i];
                maxPair.second = points[j];
                max = distance(points[i], points[j]);
            }
    return maxPair;
}

bool comparator(const Point &a, const Point &b) {
    return a.getX() < b.getX();
}

void sortPoints(Point *points, int numPoints) {
    sort(points, points + numPoints, comparator);
}