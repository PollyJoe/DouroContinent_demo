//
//  Object.h
//  DouroLand_demo
//
//  Created by Polly Zhou on 2022/7/17.
//
#pragma once

#ifndef Object_h
#define Object_h

/*************************************************************************************************
 * Base class: Life
 * Include all the creatures that can be hurt or killed
 * They have health point (hp),  spirit, and can defend themselves (defense)
 ************************************************************************************************/
class Life{
// Data of life: hp and defense
public:
    unsigned int game_hp;
    unsigned int game_defense;
    unsigned int game_spirit;
    bool ifalive = true;
protected:
    unsigned int origin_hp;
    unsigned int origin_defense;
    unsigned int origin_spirit;

// APIs
public:
    unsigned int max_hp(){ return origin_hp; }

// Game operation
public:
    virtual void reset_game_info() = 0;
    virtual void improve_body(unsigned int improve_hp, unsigned int improve_defense) = 0;
    void display_life(){
        printf("* HP: %d\n", origin_hp);
        printf("* Defense: %d", origin_defense);
        printf("* Spirit: %d", origin_spirit);
    }
    void display_game_life(){
        printf("* HP: %d", game_hp);
        printf("* Defense: %d", game_defense);
        printf("* Spirit: %d", game_spirit);
    }
};

/*************************************************************************************************
 * Base class: Attacker
 * Include everything that can attack others
 * They have damage
 ************************************************************************************************/
class Attacker{
// Data of attackers: damage
public:
    unsigned int game_damage;
protected:
    unsigned int origin_damage;

// Game operation
public:
    virtual void reset_game_info() = 0;
    virtual void improve_damage(unsigned int improve_damage) = 0;
    void display_attacker(){ printf("* Damage: %d", origin_damage); }
    void display_game_attacker(){ printf("* Damage: %d", game_damage); }
};

/*************************************************************************************************
 * Base class: Supporter
 * Include everything that can give others buff
 * They have buff percentage
 ************************************************************************************************/
class Supporter{
// Data of supporters: buff percentage
protected:
    unsigned int buff;
    
// Game operation
public:
    virtual void improve_buff(unsigned int improve_buff) = 0;
    void display_supporter(){ printf("* Buff percentage: %d", buff); }
};

/*************************************************************************************************
 * Base class: Healer
 * Include everything that can heal others
 * They have heal
 ************************************************************************************************/
class Healer{
// Data of healers: heal
protected:
    unsigned int heal;

//Game operation
public:
    virtual void improve_heal(unsigned int improve_heal) = 0;
    void display_supporter(){ printf("* Heal: %d", heal); }
};

/*************************************************************************************************
 * Base class: Controller
 * Include everything that can restrictl others' actions
 * They can weaken others (debuff)
 ************************************************************************************************/
class Controller{
// Data of controllers: debuff
protected:
    unsigned int debuff;
// Game operation
    virtual void improve_debuff(unsigned int improve_debuff) = 0;
    void display_supporter(){ printf("* Debuff: %d", debuff); }
};

#endif /* Object_h */
