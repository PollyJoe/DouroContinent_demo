//
//  main.cpp
//  DouroContinent_demo
//
//  Created by Polly Zhou on 2022/7/10.
//

#include <stdio.h>
#include "Ring.h"



int main(){
    // Test for Ability module
    unsigned int hp = 10000;
    const unsigned int max_hp = 10000;
    unsigned int speed = 100;
    
    AttackAbility slash(100, "Slash");
    slash.set_game_value(200);
    slash.display_ability();
    slash.effect(hp);
    printf("Attacked hp = %d\n\n", hp);
    
    SupportAbility cheer(200, "Cheer");
    cheer.set_game_value(100);
    cheer.display_ability();
    cheer.effect(speed);
    printf("Buffed speed = %d\n\n", speed);
    
    HealAbility begonia(50, "Begonia");
    begonia.set_game_value(100);
    begonia.display_ability();
    begonia.effect(hp, max_hp);
    printf("Healed hp = %d\n\n", hp);
    
    //Test for Ring module
    AttackRing ring(Age::thousand, 3, 200, "Fire");
    ring.display_info();
    
    return 0;
}
