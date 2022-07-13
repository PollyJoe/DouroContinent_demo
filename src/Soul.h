//
//  Soul.h
//  DouroContinent_demo
//
//  Created by Polly Zhou on 2022/7/10.
//
#pragma once

#ifndef Soul_h
#define Soul_h

#include "Ring.h"
#include <vector>
#include <any>
#include <cmath>
class Soul{
public:
    Soul() = default;
    Soul(unsigned int l, unsigned int h, unsigned int da, unsigned int de, unsigned int s, unsigned int c, Attribute a, std::string n): level(l), hp(h), damage(da), defense(de), speed(s), control(c), attribute(a), name(n){}
    
    //Properties in real game
    unsigned int game_hp = 0;
    unsigned int game_damage = 0;
    unsigned int game_defense = 0;
    unsigned int game_speed = 0;

    
    //Abilities, including the ones from rings, the ones from bones, and those self-made
    std::vector<Ring> rings;
    std::vector<Ability> self_made;
    
    //Display basic info
    void display_soul_info();
    void display_basic_info();
    void display_properties();
    void display_rings();
    
    //APIs
    unsigned int get_level(){return level;}
    Attribute get_attribute(){return attribute;}

    //Self-improvements
    void level_up(unsigned int growth){
        level += growth;
        hp *= pow(1.1, growth);
        damage *= pow(1.1, growth);
        defense *= pow(1.1, growth);
        speed *= pow(1.1, growth);
        control *= pow(1.1, growth);
    }
    
private:
    unsigned int level;  //Level of soul force
    unsigned int exp = 0;
    unsigned int hp;
    unsigned int damage;
    unsigned int defense;
    unsigned int speed;
    unsigned int control;
    Attribute attribute;
    std::string name;
};



#endif /* Soul_h */
