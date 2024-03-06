#include "Wizard.h"
#include <iostream>


Wizard::Wizard(const string &nameIn, double healthIn, double attackStrengthIn, int rankIn) : Character(WIZARD,nameIn,healthIn,attackStrengthIn){
    rank = rankIn;
}

void Wizard::attack(Character & opponent){
    // cout << "starting attack" << endl;
    
    // cout << name << " attacking" << opponent.getName() << endl;
    if(opponent.getType() == WIZARD){
        Wizard &opp = dynamic_cast<Wizard &>(opponent);
        double damageToTake = (double(attackStrength) * (double(rank) / double(opp.rank)) );
        opponent.damage(damageToTake);
        cout << "Wizard " << name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
        cout << opponent.getName() << " takes " << damageToTake << " damage." << endl;
    }else{
        double damageToTake = double(attackStrength);
        opponent.damage(damageToTake);
        cout << "Wizard " << name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
        cout << opponent.getName() << " takes " << damageToTake << " damage." << endl;
    }
}