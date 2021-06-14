#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "Auxiliaries.h"
#include <iostream>
#include <memory>
#include <vector>

namespace mtm
{
    class Character
    {
        
        int health;
        int ammo;
        int range;
        int power;
        Team team;
        
        public:
            Character(units_t health,units_t ammo,units_t range,units_t power, Team team):
                health(health), ammo(ammo),range(range),power(power), team(team){}
            Character(const Character& character) = default;   
            Character& operator=(const Character& character) = default;
            virtual ~Character() = default;
            virtual bool isLegalMovement(int distance) const;
            virtual void attack(int src_row, int src_col, int dst_row, int dst_col, int height, int width, std::vector<std::vector<std::shared_ptr<Character>>> game_grid);
            void reduceHealth(int points_reduced){
                health = health - points_reduced;
            }
            virtual CharacterType getCharacterType();
            virtual void reload();
            void SetAmmo(int x) {ammo+=x;}
            virtual std::shared_ptr<Character> clone() const = 0; 
    };

}

#endif /* CHARACTER_H_ */