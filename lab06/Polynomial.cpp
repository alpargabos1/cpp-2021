//
// Created by Alpar on 10/25/2021.
//

#include <valarray>
#include "Polynomial.h"

Polynomial::Polynomial(int degree, const double *coefficients) {
    this->capacity = degree;
    this->coefficients = new double[degree + 1];
    for (int i = 0; i < degree + 1; ++i) {
        this->coefficients[i] = coefficients[i];
    }
}

Polynomial::Polynomial(const Polynomial &that) {
    this->capacity = that.capacity;
    this->coefficients = new double[that.capacity + 1];
    for (int i = 0; i < that.capacity + 1; ++i) {
        this->coefficients[i] = that.coefficients[i];
    }
}

Polynomial::Polynomial(Polynomial &&that) {
    this->capacity = that.capacity;
    this->coefficients = that.coefficients;

    that.capacity = 0;
    that.coefficients = nullptr;
}

Polynomial::~Polynomial() {
    delete[] this->coefficients;
}

int Polynomial::degree() const {
    return capacity;
}

double Polynomial::evaluate(double x) const {
    double result = 0;
    for (int i = 0; i < capacity; ++i) {
        result += pow(x, capacity - i) * coefficients[i];
    }
    return result + coefficients[capacity];
}

Polynomial Polynomial::derivative() const {
    Polynomial der(capacity - 1, coefficients);
    for (int i = 0; i < capacity - 1; ++i) {
        der.coefficients[i] = coefficients[i] * (capacity - i);
    }
    der.coefficients[der.capacity] = coefficients[der.capacity];
    return der;
}

double Polynomial::operator[](int index) const {
    if (index < 0 || index >= this->capacity) {
        throw out_of_range("Helytelen az index!");
    }
    return coefficients[index];
}

ostream &operator<<(ostream &out, const Polynomial &what) {
    if (what.capacity == 0) {
        throw out_of_range("Ures polinom!");
    }
    for (int i = 0; i < what.capacity + 1; ++i) {
        if (i < what.capacity) {
            out << what.coefficients[i] << "x^" << what.capacity - i << " + ";
        } else {
            out << what.coefficients[i];
        }
    }
    out << endl;
    return out;
}

Polynomial operator-(const Polynomial &a) {
    Polynomial res(a);
    for (int i = 0; i <= res.capacity; ++i) {
        res.coefficients[i] = (-1) * (res.coefficients[i]);
    }
    return res;
}

Polynomial operator+(const Polynomial &a, const Polynomial &b) {
    if (a.capacity >= b.capacity) {
        Polynomial res(a);
        for (int i = 0; i <= b.capacity; ++i) {
            res.coefficients[res.capacity - i] += b.coefficients[b.capacity - i];
        }
        return res;
    }

    Polynomial res(b);
    for (int i = 0; i <= a.capacity; ++i) {
        res.coefficients[res.capacity - i] += a.coefficients[a.capacity - i];
    }
    return res;

}

Polynomial operator-(const Polynomial &a, const Polynomial &b) {
    if (a.capacity >= b.capacity) {
        Polynomial res(a);
        return res + (-b);
    }

    Polynomial res(b);
    return res + (-a);

}
