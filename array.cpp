#include "array.h"
#include <iostream>
#include <stdexcept>

Array::Array():capacity(BUFFERSIZE), size(0){
    data = new int[capacity];
}

 Array::~Array(){
    delete[] data;
}

Array& Array::operator+=(int i){
    add(i);
    return *this;
}

void Array::add(int i){
    if(size < capacity){
         this->data[size++] = i;       
    }else{
        increaseCapacity();
        this->data[size++] = i;
    }
}

int& Array::operator[](int index){
    return this->data[index]; 
}

int& Array::get(int index){
    // check if index is in range
    if(index < 0 || index > size - 1){
        std::cerr<<"Index out of bond. Size:" << size << " Index: "<< index;
        throw std::out_of_range("Array index out of bounds");
    }else{
        return this->data[index]; 
    }
}
bool Array::removeElement(int item){
    int index = findIndex(item);
    return removeIndex(index);
    
}

bool Array::removeIndex(int index){
    if(index == -1 || index >= size)
        return false;
    
    for(int i = index; i < this->size-1; i++){
        this->data[i] = this->data[i+1];
    }
    this->data[size-1] = 0;
    this->size--;
    return true;
}

int Array::findIndex(int item){
    for(int i =0; i < this->size; i++){
        if(this->data[i] == item)
            return i;
    }
    return -1;
}

void Array::increaseCapacity(){
    int * temp = data;
    capacity *= 2;
    data = new int[capacity];
    for(int i = 0; i < size; i++){
        data[i] = temp[i];
    }
    delete[] temp;
}

void Array::sort(){
    quickSort(data,0,size-1);
}

void Array::quickSort(int * data, int left, int right){
    //pick a pivit
    if(right <= left){
        return;
    }
    // set the item in the middle to pivot
    int pivot = data[(right-left)/2 + left];
    int i = left;
    int j = right;

    while(i <= j){
        
        while(data[i] < pivot) i++; //skip all element to the left that are smaller
        while(data[j] > pivot) j--; //skip all element to the right that are bigger
        //swap the elements that do not fit their postions
        if(i <= j){
            std::swap(data[i],data[j]);
            i++;
            j--;
        }
    }
     //sort left and right sides excluding the pivot
     quickSort(data, left, j);
     quickSort(data, i, right);

}

void Array::print(){
    std::cout<< "[ ";
    for(int i =0; i < this->size; i++){
        std::cout<< this->data[i]<<" ";
    }
    std::cout << "]" << std::endl;
}
