//
//  Ability.h
//  DouroLand_demo
//
//  Created by Polly Zhou on 2022/7/17.
//
#pragma once

#ifndef Ability_h
#define Ability_h

enum class Attribute{ singleattack, singleheal, singlecontrol, singlesupport, god };

/********************************************************************************************
 * Base class: "Ability"
 * Include all the most basic data that all the abilities should have:
 * 1. Original value: the output when the ability does not belong to any soul
 * 2. Real value: it will be initialized as 0 when it is not absorbed by any soul
 * 3. Attribute
 ******************************************************************************************/
class Ability{
public:
    Ability() = default;
    Ability(unsigned int ori, Attribute att): original_value(ori), attribute(att){ }
    ~Ability() = default;

// Basic data
public:
    unsigned int game_value = 0;
    Attribute get_attribute(){ return attribute; }
    
protected:
    unsigned int original_value;
    Attribute attribute;
    
// Adjust real value during the game
public:
    void set_original_value(int property){ original_value *= (1 + property / 100); }
    void set_game_value(int percentage){ game_value = original_value * (percentage / 100); }
};



#endif /* Ability_h */
