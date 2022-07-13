//
//  main.cpp
//  DouroContinent_demo
//
//  Created by Polly Zhou on 2022/7/10.
//

#include <iostream>
#include "Soul.h"
void absorb(Soul &absorber, Ring ring){
    absorber.rings.push_back(ring);
}

int main(){
    Ring fire(Age::thousand, 2, 150, "Fire", Attribute::attack);
    Ring slash(Age::ten_thousand, 4, 300, "Slash", Attribute::attack);
    
    Soul Venus(10, 1000, 80, 60, 100, Attribute::attack, "Venus");
    Venus.display_soul_info();
    absorb(Venus, fire);
    Venus.display_soul_info();
    absorb(Venus, slash);
    Venus.display_soul_info();
    
    return 0;
}
