#include "Character.h"
class Wizard: public Character{
    private:
        int rank;
    public:
        Wizard(const string &nameIn, double healthIn, double attackStrengthIn, int rankIn);
        void attack(Character &) override;
};