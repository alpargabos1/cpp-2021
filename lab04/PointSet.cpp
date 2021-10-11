//
// Created by Alpar on 10/11/2021.
//

#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "PointSet.h"

bool stat[M][M];

void PointSet::computeDistances() {
    for (int i = 0; i < points.size() - 1; ++i) {
        for (int j = i + 1; j < points.size(); ++j) {
            distances.push_back(points[i].distanceTo(points[j]));
        }
    }
    sort(distances.begin(), distances.end());
}

PointSet::PointSet(int n) {
    init();
    int x, y;
    while (points.size() < n) {
        x = rand() % 100;
        y = rand() % 100;
        if (!stat[x][y]) {
            points.emplace_back(x, y);
            stat[x][y]++;
        }
    }
    computeDistances();
//    for (int i = 0; i < distances.size(); ++i) {
//        cout << distances[i] << " " << endl;
//    }
}

double PointSet::maxDistance() const {
    return *max_element(distances.begin(), distances.end());
}

double PointSet::minDistance() const {
    return *min_element(distances.begin(), distances.end());
}

int PointSet::numDistances() const {
    return distances.size();
}

void PointSet::printPoints() const {
    for (auto p: points) {
        cout << "[" << p.getX() << " , " << p.getY() << "] ";
    }
    cout << endl;
}

void PointSet::printDistances() const {
    for(auto dis:distances){
        cout << dis << " ";
    }
    cout << endl;
}

void PointSet::sortPointsX() {

}

void PointSet::sortPointsY() {

}

void PointSet::sortDistances() {

}

int PointSet::numDistinctDistances() {
    auto it = unique(distances.begin(), distances.end());
    return it - distances.begin();
}

void PointSet::init() {
    srand(time(0));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            stat[i][j] = 0;
        }
    }
}
