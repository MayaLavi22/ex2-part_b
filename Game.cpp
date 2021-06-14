#include "Game.h"
#include "Auxiliaries.h"
#include <iostream>
#include <vector>
#include "character.h"
#include "soldier.h"
#include "medic.h"
#include "sniper.h"
#include <memory>

namespace mtm
{
    std::shared_ptr<Character> Game::GameGetCharacter(const GridPoint& p)
    {
        for (int i=0; i<height;i++){
            for(int j=0; j<width;j++){
                GridPoint temp(i,j);
                if(temp==p){
                    return game_grid[i][j];
                }
            }
        }
        return nullptr;
    }
    Game::Game(units_t height, units_t width) 
    {
        std::vector<std::vector<std::shared_ptr<Character>>>game_grid(height, std::vector<std::shared_ptr<Character>>(width, nullptr)); 
        this->height=height;
        this->width=width;
    }
    
    Game::Game(const Game& other):
        height(other.height), width(other.width)
        {
            for(int i = 0; i<height; i++){
                for(int j = 0; j<width; j++){
                    game_grid[i][j] = other.game_grid[i][j]->clone();
                }
            }
        }
    
    Game& Game::operator=(const Game& other)
    {
        if(this == &other)
        {
            return *this;
        }
        delete[] &game_grid; //see if it works and doesn't do a double delete
        height = other.height;
        width = other.width;
        for(int i = 0; i<height; i++){
            for(int j = 0; j<width; j++){
                game_grid[i][j] = other.game_grid[i][j]->clone();
            }
        }

        return *this;
    }

    void Game::addCharacter(const GridPoint& coordinates, std::shared_ptr<Character> character)
    {
        for (int i=0; i<height;i++){
            for(int j=0; j<width;j++){
                GridPoint temp(i,j);
                if(temp==coordinates){
                    game_grid[i][j]=character;
                }
            }
        }
    }

    static std::shared_ptr<Character> makeCharacter(CharacterType type, Team team,
                        units_t health, units_t ammo, units_t range, units_t power)
    {
        std::shared_ptr<Character> ptr;
        switch(type){
            case SOLDIER:{
                ptr.reset(new Soldier(health,ammo,range,power,team));
                return ptr;
            }
            case MEDIC:{
                ptr.reset(new Medic(health,ammo,range,power,team));
                return ptr;
            }
            case SNIPER:{
                ptr.reset(new Sniper(health,ammo,range,power,team));
                return ptr;
            }
        }

        return nullptr; //shouldn't reach this line
    }
    void Game::move(const GridPoint & src_coordinates, const GridPoint & dst_coordinates)
    {
        int src_i,src_j,dst_i,dst_j;
        for(int i=0;i<height;i++){
            for (int j=0;j<width;j++){
                GridPoint temp(i,j);
                if(temp==src_coordinates){
                    src_i=i;
                    src_j=j;
                }
                if (temp==dst_coordinates){
                    dst_i=i;
                    dst_j=j;
                }
            }
        }
        this->GameGetCharacter(dst_coordinates)=this->GameGetCharacter(src_coordinates);
        game_grid[dst_i][dst_j]=game_grid[src_i][src_j];
        game_grid[src_i][src_j]=nullptr;
    }

    void Game::attack(const GridPoint & src_coordinates, const GridPoint & dst_coordinates)
    {
        std::shared_ptr<Character> chara= game_grid.getCharacter(gridPoint);
        chara.attack(game_grid);
        //check if a characters health reached 0
    }

    void reload(const GridPoint & coordinates)
    {
        character.reload(this->GameGetCharacter(coordinates));
    }
}

