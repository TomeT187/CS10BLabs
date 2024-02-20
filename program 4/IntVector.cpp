#include "IntVector.h"
#include <stdexcept>
#include <iostream>
using namespace std;

IntVector::IntVector(unsigned capacity, int value){
    _size = capacity;
    _capacity = capacity;
    if (capacity != 0){
        _data = new int[capacity];
        for (unsigned i = 0; i < capacity; i++){
            *(_data + i) = value;
        }
    }

}
void IntVector::expand(){
    if (_capacity == 0){
        _capacity = 1;
        int* temp = new int[_capacity];
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
//void IntVector::expand(unsigned amount){

//}

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