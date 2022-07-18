//
//  Absorbable.cpp
//  DouroLand_demo
//
//  Created by Polly Zhou on 2022/7/17.
//

#include <stdio.h>
#include "Absorbable.h"

void Absorbable::change_ability_type(){
    switch(ability->get_attribute()){
        case Attribute::singleattack:{ ability = (SingleAttackAbility*)(ability);break; }
        case Attribute::singleheal:{ ability = (SingleHealAbility*)(ability);break; }
    }
}
