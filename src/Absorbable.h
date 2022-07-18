//
//  Absorbable.h
//  DouroLand_demo
//
//  Created by Polly Zhou on 2022/7/17.
//

#ifndef Absorbable_h
#define Absorbable_h
#include "RealAbilities.h"

class Absorbable{
public:
    Absorbable(unsigned int ori, Attribute att){ ability = new Ability(ori, att); }
    virtual void display() = 0;
    virtual void change_ability_type();
    
public:
    Ability *ability;
    
};

#endif /* Absorbable_h */
