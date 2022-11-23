//
// Created by Daria on 13.10.2022.
//

#ifndef MATRIXX_ARRAY_H
#define MATRIXX_ARRAY_H

#endif //MATRIXX_ARRAY_H
#ifndef __CLASSARRAY_H
#define __CLASSARRAY_H

#include <iostream>

using namespace std;

class Array{

public:
    Array ();// конструктор по умолчанию
    Array(int capacity);// конструктор с параметрами
    Array(const Array &other);// Конструктор копирования
    ~Array();// Деструктор*/

    int get(int index);// получение элемента массива
    void set(int index, int val);// вставка по индексу
    void pushDataFromTail(int val);// добавление в конец
    int getArrayPart(int index, int index2);// получение среза массива
    void deleteArray(int index);// удаление по индексу
    void existArray(int val);// проверка на включение
    char *cStr() const;
private:

    int size  ; // емкость массива
    int length  ; // фактическая длина массива
    int * array; // массив, в котором хранятся данные
    int size2 ; // емкость для 2-го массива
    static int digitCount(int *array, int order2);
    static int strCat(char *buf, int len, char elem);


};

#endif /*__CLASSARRAY_H*/