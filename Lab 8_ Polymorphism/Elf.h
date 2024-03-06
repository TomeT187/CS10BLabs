#include "Character.h"
class Elf: public Character{
    private:
        string familyName;
    public:
        Elf(const string &nameIn, double healthIn, double attackStrengthIn, string familyNameIn);
        void attack(Character &) override;
};