#include "soldier.h"
#include "character.h"

#include <iostream>
#define SOLDIER_MOVES 3

namespace mtm
{
    /*Soldier::Soldier(int health,int ammo,int range,int power,int movement_range):
                 Character(health, ammo, range, power), movement_range(SOLDIER_MOVES) {}

    bool Soldier::Soldier::isLegalMovement(int distance) const
    {
        return distance <= movement_range;
    }  */
    Soldier::Soldier(const Soldier& soldier):
    Character(soldier), movement_range(soldier.movement_range), type(soldier.type)
    {}

    std::shared_ptr<Character> Soldier::clone() const
    {
        std::shared_ptr<Character> ptr(new Soldier(*this));
        return ptr;
    }

    void Soldier::attack(int src_row, int src_col, int dst_row, int dst_col, int height, int width,
                        std::vector<std::vector<std::shared_ptr<Character>>> game_grid)
    {
        if(game_grid[dst_row][dst_col].getCharacterType() != SOLDIER)
        {
            this->reduceHealth(power);
        }

        GridPoint::GridPoint destination = new GridPoint::GridPoint(dst_row, dst_col);
        for(int i = 0; i<height, i++)
        {
            for (int j = 0; j < width; j++)
            {
                GridPoint::GridPoint current = new GridPoint::GridPoint(i, j);
                if(GridPoint::distance(&destination, &current) <= (ceil(power\3))){
                    game_grid[i][j].reduceHealth(ceil(power\2));
                }
            }
            
        }
    }

    void Soldier::reload()
    {
        SetAmmo(SOLDIER_RELOAD);
    }

    CharacterType getCharacterType()
    {
        return type;
    }

}

