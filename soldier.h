#ifndef SOLDIER_H_
#define SOLDIER_H_
#include <iostream>
#include <memory>
#include <vector>
#include "character.h"
#include "Auxiliaries.h"
#define SOLDIER_MOVES 3
#define SOLDIER_RELOAD 3 
#define SOLDIER_ATTACK 1

namespace mtm 
{
    class Soldier : public Character
    {
        int movement_range;
        CharacterType type;

        public:
            Soldier(units_t health,units_t ammo,units_t range,units_t power,Team team):
                Character(health, ammo, range, power, team), movement_range(SOLDIER_MOVES), type(SOLDIER) {}
            Soldier(const Soldier& soldier); //build for all
            Soldier& operator=(const Soldier& soldier) = default;
            void attack(int src_row, int src_col, int dst_row, int dst_col, int height, int width,
                        std::vector<std::vector<std::shared_ptr<Character>>> game_grid) override;
            bool isLegalMovement(int distance) const override{
                return distance<=movement_range;
            }
            std::shared_ptr<Character> clone() const override;
            CharacterType getCharacterType() override;
            void reload() override;
    };
}

#endif /* SOLDIER_H_ */