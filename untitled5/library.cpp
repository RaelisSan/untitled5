//
// Created by Daria on 13.10.2022.
//

#include "library.h"
#include <iostream>
#include "Array.h"


Matrix::Matrix(){
    rank = 0;
    matrix = nullptr;
}

Matrix::Matrix(int ranked) {
    rank = ranked;

    Array b(3);
    //cout<<b.get(1)<<endl;

    matrix = new Array* [rank];
    for (int i = 0; i < rank; i++)
        for (int j = 0; j < rank; j++)
            matrix[i]->set(j, b.get(j));

}
int Matrix::getMatrix(int i, int j) {
    return matrix[i]->get(j);
}
Matrix::~Matrix() {
    delete [] matrix;
}

Matrix::Matrix(const Matrix &Copy) {
    rank =Copy.rank;
    matrix = new Array* [Copy.rank];
    for (int i = 0; i < Copy.rank; i++)
        for (int j = 0; j < Copy.rank; j++) {
            matrix[i]->set(j, Copy.matrix[i]->get(j));
        }
}


void Matrix::setMatrix(int i, int j, int v) {
    matrix[i]->set(j,v);
}

int Matrix::strSave(char *buf, int len, char e) {
    return std::sprintf(buf + len * sizeof(char), "%c", e);
}


char* Matrix::toString() const {
    int l, len;
    if (matrix == nullptr) return nullptr;
    l = dCount(*matrix, rank);
    char *buf = new char[l + rank * rank];
    len = 0;
    for (int i = 0; i < rank; i++) {
        for (int j = 0; j < rank; j++) {
            len += std::sprintf(buf + len * sizeof(char), "%d", matrix[i]->get(j));
            if (j != rank - 1) {
                len += strSave(buf, len, (' '));
            }
        }
        if (i != rank - 1) {
            len += Matrix::strSave(buf, len, ('\n'));

        } else {
            len += Matrix::strSave(buf, len, ('\0'));
        }
    }
    return buf;
}

Matrix Matrix::operator=(const Matrix &Copy) {
    if (this != &Copy) {
        delete[] matrix;
        rank = Copy.rank;
        matrix = new Array* [Copy.rank];

        for (int i = 0; i < Copy.rank; i++) {
            for (int j = 0; j < Copy.rank; j++) {
                matrix[i]->set(j, Copy.matrix[i]->get(j));
            }
        }
    }
    return *this;
}


Matrix Matrix::operator+(const Matrix &Copy) {
    Matrix temp (rank);
    for (int i = 0; i < rank; i++){
        for (int j = 0; j < rank; j++) {
            temp.matrix[i]->set(j, matrix[i]->get(j) + Copy.matrix[i]->get(j));
        }
    }
    return temp;
}

int Matrix::dCount(Array* mat, int r) {
    Matrix dif(r);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < r; j++) {
            dif.matrix[i]->set(j, mat[i].get(j));

        }
    }
    int len;
    len = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < r; j++) {
            while (dif.matrix[i]->get(j) > 0) {
                len++;
                dif.matrix[i]->set(j, dif.matrix[i]->get(j)/10);
            }
        }
    }
    return len;
}

void Matrix::transpose()  {
    Matrix other(rank);
    for (int i = 0; i < rank; i++) {
        for (int j = 0; j < rank; j++) {
            other.matrix[i]->set(j, matrix[i]->get(j));
        }
    }
    for (int i = 0; i < rank; i++) {
        for (int j = 0; j < rank; j++) {
            matrix[i]->set(j, other.matrix[i]->get(j));

        }
    }
}


int Matrix::Gauss(int n, int m) {
    n = rank;
    m = n + 1;
    int j = n;
    float *xx = new float[m];
    int k, i, d, r, t;
    for (i = 0; i < n; i++) {
        d = matrix[i]->get(i);
        t = matrix[i]->get(j);
        for (j = n; j >= i; j--)
            t /= d;
        for (j = i + 1; j < n; j++) {
            d = matrix[j]->get(i);
            r = matrix[j]->get(k);
            for (k = n; k >= i; k--)
                r = r - d * matrix[i]->get(k);
        }
    }
    xx[n - 1] = matrix[n - 1]->get(n);
    for (i = n - 2; i >= 0; i--) {
        xx[i] = matrix[i]->get(n);
        for (j = i + 1; j < n; j++)
            xx[i] -= matrix[i]->get(j) * xx[j];
    }
    for (i = 0; i < n; i++)
        cout << xx[i] << " ";
    cout << endl;
}