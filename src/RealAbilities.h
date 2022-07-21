//
//  RealAbilities.h
//  DouroLand_demo
//
//  Created by Polly Zhou on 2022/7/17.
//

#ifndef RealAbilities_h
#define RealAbilities_h

#include "Ability.h"
#include "Object.h"

/****************************************************************
 * Derived class  1 from ability:
 * Single-attack ability: only one object for each hit
 *  attack lives: cut down their hp or kill them(when hp = 0)
 ***************************************************************/
class SingleAttackAbility : public Ability{
public:
    SingleAttackAbility(unsigned int ori): Ability(ori, Attribute::singleattack){ }
    ~SingleAttackAbility() = default;
    
    // The attacker can control the damage
    void attack(Life *life, int percentage);

};

/****************************************************************
 * Derived class  2 from ability:
 * Single-heal ability: only one object for each heal
 *  Heal lives: recover their hp or kill them(when hp = 0)
 ***************************************************************/
class SingleHealAbility : public Ability{
public:
    SingleHealAbility(unsigned int ori): Ability(ori, Attribute::singleheal){ }
    ~SingleHealAbility() = default;
    
    // The healer can control the heal degree
    void heal(Life *life, int percentage);
};

/****************************************************************
 * Derived class  3 from ability:
 * Single-support ability:
 *  Give buffs to only one object each time: buff one property, it can be decided by the user
 ***************************************************************/
class SingleSupportAbility : public Ability{
public:
    SingleSupportAbility(unsigned int ori): Ability(ori, Attribute::singlesupport){ }
    ~SingleSupportAbility() = default;
    
    // The supporter can control the buff degree
    void damage_buff(Attacker *attacker, int percentage);
    void spirit_buff(Life *life, int percentage);
    void defense_buff(Life *life, int percentage);

};

/****************************************************************
 * Derived class  4 from ability:
 * Single-control abitlity:
 *  Debuff one object's properties for each time, it can be decided by the user
 ***************************************************************/
class SingleControlAbility : public Ability{
public:
    SingleControlAbility(unsigned int ori): Ability(ori, Attribute::singlecontrol){ }
    ~SingleControlAbility() = default;

    // The supporter can control the buff degree
    void damage_debuff(Attacker *attacker, int percentage);
    void spirit_debuff(Life *life, int percentage);
    void defense_debuff(Life *life, int percentage);
};

#endif /* RealAbilities_h */
