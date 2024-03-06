#include "Warrior.h"
#include <iostream>


void Warrior::attack(Character & opponent){
    // cout << "starting attack" << endl;
    
    // cout << name << " attacking" << opponent.getName() << endl;
    if (opponent.getType() == WARRIOR){
        Warrior &opp = dynamic_cast<Warrior &>(opponent);
        if (allegiance != opp.allegiance){
            double damageToTake = ( (double(health) / double(MAX_HEALTH)) * double(attackStrength) );
            opponent.damage(damageToTake);
            cout << "Warrior " << name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
            cout << opponent.getName() << " takes " << damageToTake << " damage." << endl;
        }else{
            cout << "Warrior " << name << " does not attack Warrior " << opponent.getName() << "." << endl;
            cout << "They share an allegiance with "<< allegiance << "." << endl;
        }
    }else{

        double damageToTake = ( (double(health) / double(MAX_HEALTH)) * double(attackStrength) );
        opponent.damage(damageToTake);
        cout << "Warrior " << name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
        cout << opponent.getName() << " takes " << damageToTake << " damage." << endl;
    }
}

Warrior::Warrior(const string &nameIn, double healthIn, double attackStrengthIn, string allegianceIn) : Character(WARRIOR,nameIn,healthIn,attackStrengthIn){
    allegiance = allegianceIn;
}