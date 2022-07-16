//
//  Ability.h
//  DouroContinent_demo
//
//  Created by Polly Zhou on 2022/7/11.
//
#pragma once

#ifndef Ability_h
#define Ability_h

#include <string>

enum class Attribute{attack, defense, control, support, heal, none};
void display_attribute(Attribute a);

/********************************************************************************************
 * Ability:
 *  One of the basic elements used in Douro.
 *  This is the base class, many more new ability types will be generate from it.
 ********************************************************************************************/
class Ability{
public:
    Ability() = default;
    Ability(unsigned int b, std::string n, Attribute a): basic_value(b), name(n), attribute(a){}
    ~Ability() = default;
    
    void set_game_value(unsigned int property);
    void effect(unsigned int &object, unsigned const int max_object);
    void display_ability();
    Attribute get_attribute(){ return attribute; };

protected:
    unsigned int game_value = 0;
    unsigned int basic_value;
    std::string name;
    Attribute attribute;
};

#endif /* Ability_h */
