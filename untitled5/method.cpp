//
// Created by LORA on 022 22.11.22.
//

#include "method.h"

RectangularMatrix::RectangularMatrix() {
    rows = 0;
    columns = 0;
    rank = 0;
    matrix = nullptr;
}

RectangularMatrix::RectangularMatrix(int n, int m) {
    rows = n;
    columns = m;
    rank = rows;
    matrix = new Array* [rows];
    //Array b(4);
    for (int i = 0; i < rows; i++) {
        matrix[i] = new Array [columns];
    }
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            matrix[i]->set(j, 0);
}

RectangularMatrix::RectangularMatrix(const RectangularMatrix &Copy) {
    rows = Copy.rows;
    columns = Copy.columns;
    rank = Copy.rank;
    matrix = new Array* [Copy.rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new Array[Copy.columns];
    }
    for (int i = 0; i < Copy.rows; i++)
        for (int j = 0; j < Copy.columns; j++)
            matrix[i]->set(j, Copy.matrix[i]->get(j));
}

int RectangularMatrix::getMatrix(int i, int j) {
    if (i >= rows || j >= columns || i < 0 || j < 0)
        throw out_of_range("Out of range matrix");
    return matrix[i]->get(j);
}

void RectangularMatrix::setMatrix(int i, int j,int v) {
    if (i >= rows || j >= columns || i < 0 || j < 0)
        throw out_of_range("Out of range matrix");
    matrix[i]->set(j, v);
}

char *RectangularMatrix::toString() const {
    int l, len;
    if (matrix == nullptr) return nullptr;
    l = digitCount(*matrix, rows, columns);
    char *buf = new char[l + rows * columns];
    len = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            len += std::sprintf(buf + len * sizeof(char), "%g", matrix[i]->get(j));
            if (j != columns - 1) {
                len += strSave(buf, len, (' '));
            }
        }
        if (i != rows - 1) {
            len += strSave(buf, len, ('\n'));

        } else {
            len += strSave(buf, len, ('\0'));
        }
    }
    return buf;
}


int RectangularMatrix::digitCount(Array *mat, int n, int m) {
    RectangularMatrix dif(n,m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dif.matrix[i]->set(j, mat[i].get(j));

        }
    }
    int len;
    len = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            while (dif.matrix[i]->get(j) > 0) {
                len++;
                dif.matrix[i]->set(j, dif.matrix[i]->get(j)/10);
            }
        }
    }
    return len;
}
int RectangularMatrix::Gauss(int n, int m) {
    n = rank;
    m=n+1;
    int j = n;
    float *xx = new float [m];
    int k, i, d, r, t;
    for (i = 0; i<n; i++)
    {
        d = matrix[i]->get(i);
        t = matrix[i]->get(j);
        for (j = n; j >= i; j--)
            t /= d;
        for (j = i + 1; j<n; j++)
        {
            d = matrix[j]->get(i);
            r = matrix[j]->get(k);
            for (k = n; k >= i; k--)
                r = r - d * matrix[i]->get(k);
        }
    }
    xx[n - 1] = matrix[n - 1]->get(n);
    for (i = n - 2; i >= 0; i--)
    {
        xx[i] = matrix[i]->get(n);
        for (j = i + 1; j<n; j++)
            xx[i] -= matrix[i]->get(j) * xx[j];
    }
    for (i = 0; i<n; i++)
        cout << xx[i] << " ";
    cout << endl;
}



