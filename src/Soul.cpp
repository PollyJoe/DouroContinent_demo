//
//  Soul.cpp
//  DouroContinent_demo
//
//  Created by Polly Zhou on 2022/7/10.
//

#include <stdio.h>
#include "Soul.h"

void Soul::display_info(){
    printf("Name: %s\n", name.c_str());
    printf("HP: %d\n", game_hp);
    printf("Damage: %d\n", game_damage);
    printf("Defense: %d\n", game_defense);
    printf("Control: %d\n", game_control);
    printf("Speed: %d\n\n", game_speed);
}

void Soul::revive(){
    game_hp = basic_hp;
    game_damage = basic_damage;
    game_defense = basic_defense;
    game_control = basic_control;
    game_speed = basic_speed;
}

