#include "Elf.h"
#include <iostream>


void Elf::attack(Character & opponent){
    // cout << "starting attack" << endl;
    
    // cout << name << " attacking" << opponent.getName() << endl;
    if (opponent.getType() == ELF){
        Elf &opp = dynamic_cast<Elf &>(opponent);
        if (familyName != opp.familyName){
            double damageToTake = ( (double(health) / double(MAX_HEALTH)) * double(attackStrength) );
            opponent.damage(damageToTake);
            cout << "Elf " << name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
            cout << opponent.getName() << " takes " << damageToTake << " damage." << endl;
        }else{
            cout << "Elf " << name << " does not attack Elf " << opponent.getName() << "." << endl;
            cout << "They are both members of the "<< familyName << " family." << endl;
        }
    }else{
        
        double damageToTake = ( (double(health) / double(MAX_HEALTH)) * double(attackStrength) );
        opponent.damage(damageToTake);
        cout << "Elf " << name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
        cout << opponent.getName() << " takes " << damageToTake << " damage." << endl;
    }
}

Elf::Elf(const string &nameIn, double healthIn, double attackStrengthIn, string familyNameIn) : Character(ELF,nameIn,healthIn,attackStrengthIn){
    familyName = familyNameIn;
}