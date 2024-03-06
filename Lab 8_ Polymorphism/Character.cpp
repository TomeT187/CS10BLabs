#include "Character.h"
#include <iostream>


Character::Character(HeroType typeIn, const string &nameIn, double healthIn, double attackStrengthIn){
    type = typeIn;
    name = nameIn;
    health = healthIn;
    attackStrength = attackStrengthIn;
}

HeroType Character::getType() const{
    return type;
}

const string & Character::getName() const{
    return name;
}

int Character::getHealth() const{
    return health;
}

void Character::damage(double d){
    health = health - d;
}

bool Character::isAlive() const{
    return health > 0;
}