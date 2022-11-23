//
// Created by LORA on 022 22.11.22.
//

#ifndef UNTITLED5_METHOD_H
#define UNTITLED5_METHOD_H
#include "library.h"

class RectangularMatrix : public Matrix {
public:
    RectangularMatrix(); //конструктор
    RectangularMatrix(int n, int m); //n*m = прямоугольная матрица
    RectangularMatrix(const RectangularMatrix &Copy); //конструктор копирования
    int getMatrix (int i, int j); //получение матрицы
    void setMatrix (int i, int j, int v); //значение матрицы
    char *toString() const; //матрица в строковом представлении
    RectangularMatrix operator+(const RectangularMatrix &Copy); //сложение
    RectangularMatrix operator=(const RectangularMatrix &Copy); //присваивание
    int Gauss(int n, int m);
private:
    int rows;
    int columns;
    static int digitCount(Array *mat, int n, int m);
};


#endif //UNTITLED5_METHOD_H
