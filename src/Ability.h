//
//  Ability.h
//  DouroContinent_demo
//
//  Created by Polly Zhou on 2022/7/11.
//

#ifndef Ability_h
#define Ability_h

#include <string>

enum class Attribute{attack, defense, control, support, heal};

/********************************************************************************************
 * Ability:
 *  One of the basic elements used in Douro.
 *  This is the base class, many more new ability types will be generate from it.
 ********************************************************************************************/
class Ability{
public:
    Ability(unsigned int b, std::string n): basic_value(b), name(n){}
    ~Ability() = default;
    
    virtual void set_game_value(unsigned int property) = 0;
    virtual void effect(unsigned int &object) = 0;
    virtual void display_ability() = 0;

protected:
    unsigned int game_value;
    unsigned int basic_value;
    std::string name;
};

/****************************************************************************
 * Abilities with different properties:
 *      Attack, Defense, Control, Support, Heal
 ****************************************************************************/

// Attack
class AttackAbility : public Ability{
public:
    AttackAbility(unsigned int b, std::string n): Ability(b, n){}
    ~AttackAbility() = default;
    
    void set_game_value(unsigned int property) override{
        game_value = basic_value * (1 + property / 100);
    }
    void effect(unsigned int &object) override{
        object -= game_value;
    }
    void display_ability() override{
        printf("Ability: %s\n", name.c_str());
        printf("Attribute: Attack\n");
        printf("Damage: %d\n", game_value);
    }

private:
    Attribute attribute = Attribute::attack;
};

//Support
class SupportAbility : public Ability{
public:
    SupportAbility(unsigned int b, std::string n): Ability(b, n){}
    ~SupportAbility() = default;
    
    void set_game_value(unsigned int property) override{
        game_value = basic_value * (1 + property / 100);
    }
    void effect(unsigned int &object) override{
        object *= (1 + game_value / 100);
    }
    void display_ability() override{
        printf("Ability: %s\n", name.c_str());
        printf("Attribute: Support\n");
        printf("Support effect: %d%%\n", game_value);
    }

private:
    Attribute attribute = Attribute::support;
};

//Heal
class HealAbility : public Ability{
public:
    HealAbility(unsigned int b, std:: string n): Ability(b,n){}
    ~HealAbility() = default;
    
    void set_game_value(unsigned int property) override{
        game_value = basic_value * (1 + property / 100);
    }
    void effect(unsigned int &object) override{
        object += game_value;
    }
    void effect(unsigned int &object, const unsigned int max_value){
        effect(object);
        if(object > max_value) object = max_value;
    }
    void display_ability() override{
        printf("Ability: %s\n", name.c_str());
        printf("Attribute: Heal\n");
        printf("Heal: %d\n", game_value);
    }

private:
    Attribute attribute = Attribute::heal;
};
#endif /* Ability_h */
