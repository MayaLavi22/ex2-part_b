#include "sniper.h"
#include "character.h"

#include <iostream>
#define SNIPER_MOVES 4

namespace mtm
{
    /*Soldier::Soldier(int health,int ammo,int range,int power,int movement_range):
                 Character(health, ammo, range, power), movement_range(SOLDIER_MOVES) {}

    bool Soldier::Soldier::isLegalMovement(int distance) const
    {
        return distance <= movement_range;
    }  */
    Sniper::Sniper(const Sniper& sniper):
    Character(sniper), movement_range(sniper.movement_range), type(sniper.type)
    {}

    std::shared_ptr<Character> Sniper::clone() const
    {
        std::shared_ptr<Character> ptr(new Sniper(*this));
        return ptr;
    }

}

