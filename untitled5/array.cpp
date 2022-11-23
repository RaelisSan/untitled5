//
// Created by Daria on 13.10.2022.
//

#include "Array.h"


Array::Array()
{
    this-> size = 25;
    this-> length = 0;
    this->array = new int[this->size];
}


Array::Array(int size)
{
    this->size = size;
    this->length = 0;
    this->size2 = size;
    this->array = new int[this->size];
    for(int i=0; i<size;i++){
        pushDataFromTail(i);
    }

}

Array::Array(const Array &other){
    this->size2 = other.size2;
    this->array = new int[other.size2];
    for(int i=0;i <other.size2; i++)
    {
        this->array[i] = other.array[i];
    }
};

Array::~Array(){
    delete[] array;
};

int Array::get(int index)
{
    return this->array[index];
}

void Array::set(int index, int val){

    this-> array [index] = val;
}


void Array::pushDataFromTail(int val)
{
    this-> array [this-> length] = val;
    this-> length ++;
}

int Array::getArrayPart(int index, int index2) {

    for(int i = index; i < index2; i ++)
    {
        cout<< array[i]<<endl;

    }
}

void Array::deleteArray(int index) {
    for(int i = index;i< this->size; i++)
    {
        this->array[i] = this->array[i+1];
    }

}

void  Array::existArray(int val) {
    int value = 0;
    for (int i = 0; i < this->size; i ++)
    {
        if (this->array[i] == val)
        {
            cout<<"Exist"<<endl;

        }
        else{
            value ++;
        }
        if (value== this->size)
        {
            cout<< "Not Found"<<endl;

        }
    }
}
char* Array::cStr() const{
    int len;
    int l;
    if (array == nullptr) return nullptr;
    l = digitCount(array, size);
    char *buf = new char[l + size * size];
    len = 0;
    for (int i = 0; i < size; i++) {
        len += std::sprintf(buf + len * sizeof(char), "%d", array[i]);
        if (i != size - 1) {
            len += strCat(buf, len, (' '));
        }
        else {
            len += strCat(buf, len, ('\0'));
        }
    }
    return buf;

}
int Array::digitCount(int *array, int order2) {
    Array other(order2);

    for (int i = 0; i < order2; i++) {
        other.array[i] = array[i];
    }
    int len;
    len = 0;
    for (int i = 0; i < order2; i++) {
        while (other.array[i] > 0) {
            len++;
            other.array[i] = other.array[i] / 10;
        }
    }
    return len;
}

int Array::strCat(char *buf, int len, char elem) {
    return std::sprintf(buf + len * sizeof(char), "%c", elem);
}