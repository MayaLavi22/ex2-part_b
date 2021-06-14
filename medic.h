#ifndef MEDIC_H_
#define MEDIC_H_
#include <iostream>

#include "character.h"
#define MEDIC_MOVES 5
#define MEDIC_RELOAD 5 
#define MEDIC_ATTACK 0

namespace mtm 
{
    class Medic : public Character
    {
        int movement_range;
        CharacterType type;

        public:
            Medic(units_t health,units_t ammo,units_t range,units_t power,Team team) :
                Character(health, ammo, range, power,team), movement_range(MEDIC_MOVES), type(MEDIC) {};
            Medic(const Medic& medic);//build
            Medic& operator=(const Medic& medic) = default;

            bool isLegalMovement(int distance) const override{
                return distance <= movement_range;
            }  
            std::shared_ptr<Character> clone() const override; 
            void reload() override;
            
    };
}

#endif /* MEDIC_H_ */