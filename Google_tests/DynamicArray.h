//
// Created by dana  gershon on 9/30/22.
//

#ifndef DYNAMICARRAY_DYNAMICARRAY_H
#define DYNAMICARRAY_DYNAMICARRAY_H

#include <iostream>
#include <string>


class DynamicArray{
    int* arr = nullptr;
    int size; // always 1 or greater
    int count; // always 0 or greater

    void growSize();

    void shrinkSize();

public:
    explicit DynamicArray(int input_size=1);

    ~DynamicArray();

    int getCount();

    void print();

    int& operator[] (int i);

    void append(int num);

    void removeLast();

    void addAt(int i, int num);

    void replaceAt(int i, int num);

    void removeAt(int i);
};


#endif //DYNAMICARRAY_DYNAMICARRAY_H
