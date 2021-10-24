//
// Created by Alpar on 10/18/2021.
//

#include <ctime>
#include "Matrix.h"

Matrix::Matrix(int mRows, int mCols) {
    this->mRows = mRows;
    this->mCols = mCols;
    this->mElements = new double *[mRows];
    for (int i = 0; i < mRows; ++i) {
        mElements[i] = new double[mCols];
    }
}

Matrix::Matrix(const Matrix &what) {
    mRows = what.mRows;
    mCols = what.mCols;
    mElements = new double *[mRows];
    for (int i = 0; i < mRows; ++i) {
        mElements[i] = new double[mCols];
    }
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = what.mElements[i][j];
        }
    }
}

Matrix::Matrix(Matrix &&what) {
    this->mRows = what.mRows;
    this->mCols = what.mCols;
    mElements = new double *[mRows];
    for (int i = 0; i < mRows; ++i) {
        mElements[i] = new double[mCols];
    }

    what.mRows = 0;
    what.mCols = 0;
    for (int i = 0; i < mRows; ++i) {
        what.mElements[i] = nullptr;
    }
    what.mElements = nullptr;

}

Matrix::~Matrix() {
    for (int i = 0; i < mRows; ++i) {
        delete[] mElements[i];
    }
    delete[] mElements;
}

void Matrix::fillMatrix(double value) {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = value;
        }
    }
}

void Matrix::randomMatrix(int a, int b) {
    srand(time(0));
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = rand() % (b - a + 1) + a;
        }
    }
}

void Matrix::printMatrix(ostream &os) const {
    for (int i = 0; i < mRows; i++)
        for (int j = 0; j < mCols; j++)
            // Prints ' ' if j != n-1 else prints '\n'
            cout << mElements[i][j] << " \n"[j == mCols - 1];
}

bool Matrix::isSquare() const {
    return mRows == mCols;
}

Matrix operator+(const Matrix &x, const Matrix &y) {
    if (x.mRows != y.mRows || y.mCols != x.mCols) {
        throw out_of_range("Nem megfelelo meretek!");
    }
    Matrix temp(x);

    for (int i = 0; i < x.mRows; ++i) {
        for (int j = 0; j < x.mCols; ++j) {
            temp.mElements[i][j] += y.mElements[i][j];
        }
    }

    return temp;
}

Matrix operator*(const Matrix &x, const Matrix &y) {
    if (x.mRows != y.mCols) {
        throw out_of_range("Nem megfelelo meretek!");
    }
    Matrix temp(x.mRows, y.mCols);

    for (int i = 0; i < x.mRows; ++i) {
        for (int j = 0; j < y.mCols; ++j) {
            for (int k = 0; k < x.mCols; ++k) {
                temp.mElements[i][j] += x.mElements[i][k] * y.mElements[k][j];
            }
//            temp.mElements[i][j] *= y.mElements[i][j];
        }
    }

    return temp;
}

Matrix &Matrix::operator=(const Matrix &mat) {
    if (this->mRows != mat.mRows || this->mCols != mat.mCols) {
        throw out_of_range("Nem megfelelo meretek!");
    }
    for (int i = 0; i < mat.mRows; ++i) {
        for (int j = 0; j < mat.mCols; ++j) {
            this->mElements[i][j] = mat.mElements[i][j];
        }
    }
}

ostream &operator<<(ostream &os, const Matrix &mat) {
    for (int i = 0; i < mat.mRows; ++i) {
        for (int j = 0; j < mat.mCols; ++j) {
            os << mat.mElements[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

istream &operator>>(istream &is, Matrix &mat) {
    for (int i = 0; i < mat.mRows; ++i) {
        for (int j = 0; j < mat.mCols; ++j) {
            is >> mat.mElements[0][j];
        }
    }

    return is;
}

double *Matrix::operator[](int index) {
    if (index < 0 || index >= this->mRows) {
        throw out_of_range("Helytelen az index!");
    }
    return mElements[index];
}

double *Matrix::operator[](int index) const {
    if (index < 0 || index >= this->mRows) {
        throw out_of_range("Helytelen az index!");
    }
    return mElements[index];
}

