#include "Character.h"
class Warrior: public Character{
    private:
        string allegiance;
    public:
        Warrior(const string &nameIn, double healthIn, double attackStrengthIn, string allegianceIn);
        void attack(Character &) override;
};