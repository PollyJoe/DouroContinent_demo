//
//  Ability.cpp
//  DouroContinent_demo
//
//  Created by Polly Zhou on 2022/7/13.
//

#include <stdio.h>
#include "Ability.h"

void display_attribute(Attribute a){
    switch(a){
        case Attribute::attack:{printf("Attack\n");break;}
        case Attribute::defense:{printf("Defense\n");break;}
        case Attribute::control:{printf("Control\n");break;}
        case Attribute::support:{printf("Support\n");break;}
        case Attribute::heal:{printf("Heal\n");break;}
        default:break;
    }
}

void Ability::set_game_value(unsigned int property){
    game_value = basic_value * (1 + property / 50);
}

void Ability::effect(unsigned int &object, unsigned const int max_object){
    switch(attribute){
        case Attribute::attack:{object -= game_value;break;}
        case Attribute::defense:{
            if(game_value > max_object) object += max_object;
            else object += game_value;
            break;
        }
        case Attribute::control:{
            if(game_value <= max_object) break;
            else{ object *= (1 - (game_value - max_object) / (game_value + max_object));break; }
        }
        case Attribute::support:{object *= (1 + game_value / 100);break;}
        case Attribute::heal:{
            object += game_value;
            if(object > max_object) object = max_object;
            break;
        }
        default:break;
    }
}

void Ability::display_ability(){
    switch(attribute){
        case Attribute::attack:{
            printf("* Ability: %s\n", name.c_str());
            printf("* Attribute: Attack\n");
            printf("* Damage: %d\n", game_value);
            printf("* Basic ability: %d\n", basic_value);
            break;
        }
        case Attribute::defense:{printf("Defense\n");break;}
        case Attribute::control:{printf("Control\n");break;}
        case Attribute::support:{
            printf("* Ability: %s\n", name.c_str());
            printf("* Attribute: Support\n");
            printf("* Support effect: %d%%\n", game_value);
            printf("* Basic ability: %d\n", basic_value);
            break;
        }
        case Attribute::heal:{
            printf("* Ability: %s\n", name.c_str());
            printf("* Attribute: Heal\n");
            printf("* Heal: %d\n", game_value);
            printf("* Basic ability: %d\n", basic_value);
            break;
        }
        default:break;
    }
}
