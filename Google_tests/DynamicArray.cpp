#include "DynamicArray.h"

DynamicArray::DynamicArray(int input_size) {
    arr = new int[input_size];
    size = input_size;
    count = 0;
}

DynamicArray::~DynamicArray() {
    delete [] arr;
}

void DynamicArray::growSize() {
    std::cout << "doubling size" << std::endl;
    int* new_arr = new int[size*2];
    for(int i=0; i<count; i++){
        new_arr[i] = arr[i];
    }
    size *= 2;
    delete [] arr;
    arr = new_arr;
}

void DynamicArray::shrinkSize() {
    // count >= 1 and count <= size/2
    std::cout << "halving size" << std::endl;
    int* new_arr = new int[count];
    for(int i=0; i<count; i++){
        new_arr[i] = arr[i];
    }
    size = count;
    delete [] arr;
    arr = new_arr;
}

int DynamicArray::getCount() {
    return count;
}

void DynamicArray::print() {
    std::cout << "printing array:" << std::endl;
    if(count == 0){
        return;
    }
    std::cout << "[";
    for(int i=0; i<count-1; i++){
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[count-1] << "]" << std::endl;
}

int &DynamicArray::operator[](int i) {
    if(i >= 0 && i < count){
        return arr[i];
    } else {
        std::cout << "index out of bound" << std::endl;
    }
}

void DynamicArray::append(int num) {
    if(count == size){
        growSize();
    }
    arr[count++] = num;
}

void DynamicArray::removeLast() {
    if(count == 0){
        std::cout << "Cannot remove because array is empty" << std::endl;
    }
    arr[--count] = 0;
    if(count > 0 && count <= size/2){
        shrinkSize();
    }
}

void DynamicArray::addAt(int i, int num) {
    if(i < 0 || i >= count){
        std::cout << "insertion index out of bound" << std::endl;
    } else if(count == size){
        growSize();
    }
    for(int j=count-1; j>=i; j--){
        arr[j+1] = arr[j];
    }
    arr[i] = num;
    count++;
}

void DynamicArray::replaceAt(int i, int num) {
    if(i < 0 || i >= count){
        std::cout << "insertion index out of bound" << std::endl;
    } else {
        arr[i] = num;
    }
}

void DynamicArray::removeAt(int i) {
    if(i < 0 || i >= count){
        // also handles case of count == 0
        std::cout << "remove index out of bound" << std::endl;
    }else if(i == count-1){
        removeLast();
    } else{
        for(int j=i+1; j<count; j++){
            arr[j-1] = arr[j];
        }
        arr[--count] = 0;
        if(count > 0 && count <= size/2){
            shrinkSize();
        }
    }
}













