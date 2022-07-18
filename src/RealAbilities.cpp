//
//  RealAbilities.cpp
//  DouroLand_demo
//
//  Created by Polly Zhou on 2022/7/17.
//

#include <stdio.h>
#include "RealAbilities.h"

void SingleAttackAbility::attack(Life *life, int percentage){
    int hurt;
    set_game_value(percentage);
    if(life->game_defense >= game_value){ hurt = 0; }
    else{ hurt = game_value - life->game_defense; }
    life->game_hp -= hurt;
    if(life->game_hp <= 0){
        life->game_hp = 0;
        life->ifalive = false;
        printf("Your object has been killed!\n");
    }
}

void SingleHealAbility::heal(Life *life, int percentage){
    set_game_value(percentage);
    life->game_hp += game_value;
    if(life->game_hp >= life->max_hp()) life->game_hp = life->max_hp();
}

void SingleSupportAbility::damage_buff(Attacker *attacker, int percentage){
    set_game_value(percentage);
    attacker->game_damage *= (1 + game_value / 100);
}

void SingleSupportAbility::defense_buff(Life *life, int percentage){
    set_game_value(percentage);
    life->game_defense *= (1 + game_value / 100);
}

void SingleSupportAbility::spirit_buff(Life *life, int percentage){
    set_game_value(percentage);
    life->game_spirit *= (1 + game_value / 100);
}

void SingleControlAbility::damage_debuff(Attacker *attacker, int percentage){
    set_game_value(percentage);
    attacker->game_damage *= (1 - game_value / 200);
}

void SingleControlAbility::defense_debuff(Life *life, int percentage){
    set_game_value(percentage);
    life->game_defense *= (1 - game_value / 200);
}

void SingleControlAbility::spirit_debuff(Life *life, int percentage){
    set_game_value(percentage);
    life->game_spirit *= (1 - game_value / 200);
}


