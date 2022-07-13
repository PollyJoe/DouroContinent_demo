//
//  main.cpp
//  DouroContinent_demo
//
//  Created by Polly Zhou on 2022/7/10.
//

#include <iostream>
#include "Soul.h"
bool ifabsorb(Soul absorber, Ring ring){
    if(absorber.get_level() % 10 != 0){
        printf("Cannot absorb. Not raised 10 levels yet.\n");
        return false;
    }
    else if(absorber.get_attribute() == Attribute::support && ring.ability.get_attribute() != Attribute::support){
        printf("Support-attribute soul can only absorb support-attribute ring.\n");
        return false;
    }
    else if(absorber.get_attribute() == Attribute::heal && ring.ability.get_attribute() != Attribute::heal){
        printf("Heal-attribute soul can only absorb heal-attribute ring.\n");
        return false;
    }
    else return true;
    
}
void absorb(Soul &absorber, Ring ring){
    bool ifable = ifabsorb(absorber, ring);
    if(ifable){
        absorber.rings.push_back(ring);
        absorber.level_up(ring.get_level_growth());
    }
}

int main(){
    Ring fire(Age::thousand, 2, 150, "Fire", Attribute::attack);
    Ring slash(Age::ten_thousand, 4, 300, "Slash", Attribute::attack);
    
    Soul Venus(10, 1000, 80, 60, 100, 40, Attribute::attack, "Venus");
    Soul Doctor(30, 10000, 150, 43, 87, 65, Attribute::heal, "Doctor");
    Venus.display_soul_info();
    absorb(Venus, fire);
    Venus.display_soul_info();
    absorb(Venus, slash);
    Venus.display_soul_info();
    Doctor.display_soul_info();
    absorb(Doctor, fire);
    Doctor.display_soul_info();
    
    return 0;
}
