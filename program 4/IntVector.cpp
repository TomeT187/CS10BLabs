#include "IntVector.h"
#include <stdexcept>
#include <iostream>
using namespace std;

IntVector::IntVector(unsigned capacity, int value){
    _size = capacity;
    _capacity = capacity;
    //if (capacity != 0){
        _data = new int[capacity];
        for (unsigned i = 0; i < capacity; i++){
            *(_data + i) = value;
        }
    //}

}
void IntVector::expand(){
    if (_capacity == 0){
        _capacity = 1;        
        int* temp = new int[_capacity];
        _data = temp;

        return;
    }
    int* temp = new int[_capacity * 2];
    for (unsigned i = 0; i < _capacity; i++){ 
        temp[i] = _data[i];
    }
    _capacity = _capacity * 2;
    delete[] _data;
    _data = temp;

}

void IntVector::expand(unsigned amount){
    int* temp = new int[_capacity + amount];
    for (unsigned i = 0; i < _capacity; i++){ 
        temp[i] = _data[i];
    }
    if(_capacity != 0){
        delete[] _data;
    }
    _data = temp;
    _capacity = _capacity + amount;
}

IntVector::~IntVector(){
    delete[] _data;
    _data = nullptr;
}
unsigned IntVector::size() const{
    return _size;
}
unsigned IntVector::capacity() const{
    return _capacity;
}
bool IntVector::empty() const{
    return _size == 0;
}
const int& IntVector::at(unsigned index) const{
    if (index >= _size){
        throw out_of_range("IntVector::at_range_check");
    }
    return *(_data + index);
}
const int & IntVector::front() const{
    return *(_data );
}
const int & IntVector::back() const{
    return *(_data + _size - 1);
}

int & IntVector::at(unsigned index){
    if (index >= _size){
        throw out_of_range("IntVector::at_range_check");
    }
    return *(_data + index);
}

void IntVector::insert(unsigned index, int value){
    if (index > _size){
        throw out_of_range("IntVector::insert_range_check");
    }
    _size++;
    if (_size > _capacity){
        expand();
    }
    int temp = at(index);
    at(index) = value;
    for (unsigned i = index + 1; i < _size; i++){
        at(i) = temp;
        temp = at(i);
    }
}

void IntVector::erase(unsigned index){
    if (index >= _size){
        throw out_of_range("IntVector::erase_range_check");
    }
    
    for (unsigned i = index; i < _size-1; i++){
        at(i) = at(i + 1);
    }
    _size--;
}

int & IntVector::front(){
    return *(_data );
}

 int & IntVector::back() {
    return *(_data + _size - 1);
}

void IntVector::assign(unsigned n, int value){
    if(n > _capacity){
        if( (_capacity * 2) > (n) ){
            expand();
        }else{
            expand(n - _capacity);
        }
    }
    for (unsigned i = 0; i < n; i++){ 
        _data[i] = value;
    }
    _size = n;

}

void IntVector::push_back(int value){
    _size++;
    if (_size > _capacity){
        expand();
    }
    at(_size - 1) = value;
}
void IntVector::pop_back(){
    _size--;
}

void IntVector::clear(){
    _size = 0;
}
void IntVector::resize(unsigned n, int value){
    if (n > _capacity){
        if( (_capacity * 2) > (n) ){
            expand();
        }else{
            expand(n - _capacity);
        }
    }
    if (n < _size){
        _size = n;
    }else if(n > _size){
        for (unsigned i = _size; i < n; i++){
            _data[i] = value;
        }
        _size = n;
    }
}

void IntVector::reserve(unsigned n){
    if (n > _capacity){
        expand(n - _capacity);
    }
}


