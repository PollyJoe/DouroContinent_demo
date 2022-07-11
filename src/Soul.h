//
//  Soul.h
//  DouroContinent_demo
//
//  Created by Polly Zhou on 2022/7/10.
//

#ifndef Soul_h
#define Soul_h

#include <vector>
#include "Ability.h"

class Soul{
public:
    //Constructor and destructors
    Soul(int h, int da, int de, int c, int s, std::string n): basic_hp(h), basic_damage(da), basic_defense(de), basic_control(c), basic_speed(s), name(n)
    {
        game_hp = basic_hp;
        game_damage = basic_damage;
        game_defense = basic_defense;
        game_control = basic_control;
        game_speed = basic_speed;
    }
    ~Soul() = default;
    
    int game_hp;
    int game_damage;
    int game_defense;
    int game_control;
    int game_speed;
    
    void display_info();
    void revive();
    void hurt(int hurt);
    void heal(int heal);
    
    
private:
    int basic_hp;
    int basic_damage;
    int basic_defense;
    int basic_control;
    int basic_speed;
    std::string name;
};

#endif /* Soul_h */
