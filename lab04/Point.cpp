//
// Created by Alpar on 10/11/2021.
//

#include <valarray>
#include "Point.h"

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

double Point::distanceTo(const Point &point) const {
    return sqrt(pow(point.getX() - x, 2) + pow(point.getY() - y, 2) * 1.0);

}
