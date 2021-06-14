#ifndef GAME_H_
#define GAME_H_

#include "Auxiliaries.h"
#include "character.h"
#include <iostream>
#include <memory>
#include <vector>

namespace mtm
{
    class Game
    {
        enum Team { POWERLIFTERS, CROSSFITTERS };

        enum CharacterType {SOLDIER, MEDIC, SNIPER};

        typedef int units_t;

        units_t height;
        units_t width;
        std::vector<std::vector<std::shared_ptr<Character>>> game_grid;
        std::shared_ptr<Character> GameGetCharacter(const GridPoint& p);
        public: 
            Game(units_t height, units_t width);
            ~Game() = default;
            Game(const Game& other);
            Game& operator=(const Game& other);
            
            void addCharacter(const GridPoint& coordinates, std::shared_ptr<Character> character);
            static std::shared_ptr<Character> makeCharacter(CharacterType type, Team team,
                units_t health, units_t ammo, units_t range, units_t power);
            void move(const GridPoint & src_coordinates, const GridPoint & dst_coordinates); 
            void attack(const GridPoint & src_coordinates, const GridPoint & dst_coordinates);
            void reload(const GridPoint & coordinates);
            std::ostream& printGameBoard(std::ostream& os, const char* begin,
                const char* end, unsigned int width) const;
            bool isOver(Team* winningTeam=NULL) const;
    };
}

#endif /* GAME_H_ */