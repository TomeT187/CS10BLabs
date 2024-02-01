#include "Distance.h"
#include <iostream>

Distance::Distance(){
    _feet = 0.0;
    _inches = 0;
}

Distance::Distance(unsigned ft, double in){
    _feet = ft;
    _inches = in;
    init();
}

Distance::Distance(double in){
    _feet = 0.0;
    _inches = in;
    init();
}

unsigned Distance::getFeet() const{
    return _feet;
}

double Distance::getInches() const{
    return _inches;
}

double Distance::distanceInInches() const{
    return (_feet * 12.0) + _inches;
}

double Distance::distanceInFeet() const{
    return _feet + (_inches / 12.0);
}

double Distance::distanceInMeters() const{
    return distanceInInches() * 0.0254;
}

Distance Distance::operator+(const Distance &rhs) const{
    Distance temp(_feet + rhs._feet, _inches + rhs._inches);
    return temp;
}

Distance Distance::operator-(const Distance &rhs) const{
    double inches = distanceInInches() - rhs.distanceInInches();
    Distance temp(inches);
    return temp;


    
}

ostream & operator<<(ostream &out, const Distance &rhs){
    out << rhs._feet << "\' " << rhs._inches << "\"";
    return out;
}


void Distance::init(){
    if(_inches < 0){
        _inches = _inches * -1;
    }
    while (_inches > 12.0){
        _inches -= 12.0;
        _feet++;
    }

}