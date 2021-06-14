#ifndef SNIPER_H_
#define SNIPER_H_
#include <iostream>
#include "character.h"
#define SNIPER_MOVES 4
#define SNIPER_RELOAD 2 
#define SNIPER_ATTACK 1

namespace mtm 
{
    class Sniper : public Character
    {
        int movement_range;
        CharacterType type;

        public:
            Sniper(units_t health,units_t ammo,units_t range,units_t power,Team team) :
                Character(health, ammo, range, power,team), movement_range(SNIPER_MOVES), type(SNIPER) {};
            Sniper(const Sniper& sniper);//build
            Sniper& operator=(const Sniper& sniper) = default;
            bool isLegalMovement(int distance) const override{
                return distance <= movement_range;
            }   
            std::shared_ptr<Character> clone() const override;
            void reload() override;
    };
}

#endif /* SNIPER_H_ */