//
//  Ability.cpp
//  DouroLand_demo
//
//  Created by Polly Zhou on 2022/7/17.
//

#include <stdio.h>
#include "Ability.h"

void SingleAttackAbility::effect(unsigned int &opponent_hp, unsigned int opponent_defense){
    // Set real hurt depends on offense's attack ability and defense's defense ability
    int hurt;
    if(opponent_defense >= real_value) hurt = 0;
    else hurt = real_value - opponent_defense;
  
    // Let the hurt take effect
    opponent_hp -= hurt;
}
