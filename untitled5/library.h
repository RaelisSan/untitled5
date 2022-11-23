//
// Created by Daria on 13.10.2022.
//

#ifndef MATRIXX_LIBRARY_H
#define MATRIXX_LIBRARY_H

#endif //MATRIXX_LIBRARY_H
#ifndef UNTITLED7_LIBRARY_H
#define UNTITLED7_LIBRARY_H

#include <iostream>
#include "Array.h"
using namespace std;

class Matrix {
public:
    Matrix(); //конструктор
    Matrix(int ranked); //конструктор с параметрами
    Matrix(const Matrix &Copy); //конструктор копирования
    ~Matrix(); //деструктор
    virtual int getMatrix (int i, int j); //получение матрицы
    virtual void setMatrix (int i, int j, int v); //значение матрицы
    virtual char *toString() const; //матрица в строковом представлении
    virtual void transpose(); //транспонирование
    virtual Matrix operator+(const Matrix &Copy); //сложение
    virtual Matrix operator=(const Matrix &Copy); //присваивание
    virtual int Gauss(int n, int m);
protected:
    int rank; //порядок матрицы
    //int **matrix; //набор элементов
    Array** matrix;
    static int strSave(char *buf, int len, char e); //статистическй метод сохранения символов
    static int dCount(Array *mat, int r); //статистическй метод подсчёта цифр
};
#endif //UNTITLED7_LIBRARY_H

