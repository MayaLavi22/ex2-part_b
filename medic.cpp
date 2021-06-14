#include "medic.h"
#include "character.h"

#include <iostream>
#define NIPER_MOVES 4

namespace mtm
{
    /*Soldier::Soldier(int health,int ammo,int range,int power,int movement_range):
                 Character(health, ammo, range, power), movement_range(SOLDIER_MOVES) {}

    bool Soldier::Soldier::isLegalMovement(int distance) const
    {
        return distance <= movement_range;
    }  */
    Medic::Medic(const Medic& medic):
    Character(medic), movement_range(medic.movement_range), type(medic,type)
    {}

    std::shared_ptr<Character> Medic::clone() const
    {
        std::shared_ptr<Character> ptr(new Medic(*this));
        return ptr;
    }

}

