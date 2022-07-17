//
//  Ability.h
//  DouroLand_demo
//
//  Created by Polly Zhou on 2022/7/17.
//

#ifndef Ability_h
#define Ability_h

enum class Attribute{ god };

/********************************************************************************************
 * Base class: "Ability"
 * Include all the most basic data that all the abilities should have:
 * 1. Original value: the output when the ability does not belong to any soul
 * 2. Real value: it will be initialized as 0 when it is not absorbed by any soul
 *3. Attribute
 ******************************************************************************************/
class Ability{
public:
    Ability() = default;
    Ability(unsigned int ori): original_value(ori){ }
    ~Ability() = default;
    
    unsigned int real_value = 0;
    
protected:
    unsigned int original_value;
};

/*************************************************************************************************
 * Base class: Life
 * Include all the creatures that can be hurt or killed
 * They have health point (hp), and can defend themselves (defense and speed)
 ************************************************************************************************/
class Life{
public:
    Life() = default;
    Life(unsigned int hp, unsigned int defense): game_hp(hp), origin_hp(hp), game_defense(defense), origin_defense(defense){ }
    ~Life() = default;
    
// Data of life: hp and defense
public:
    unsigned int game_hp;
    unsigned int game_defense;
protected:
    unsigned int origin_hp;
    unsigned int origin_defense;

// Game operation
public:
    void reset_game_info(){ game_hp = origin_hp; }
};

/*************************************************************************************************
 * Base class: Attacker
 * Include everything that can attack others
 * They have damage
 ************************************************************************************************/
class Attacker{
public:
    Attacker() = default;
    Attacker(unsigned int damage): game_damage(damage), origin_damage(damage){ }
    ~Attacker() = default;

//
public:
    unsigned int game_damage;
protected:
    unsigned int origin_damage;
};


#endif /* Ability_h */
