//
//  main.cpp
//  DouroContinent_demo
//
//  Created by Polly Zhou on 2022/7/10.
//

#include <iostream>
#include "Soul.h"
#include "Beast.h"

int main(){
    //MillionRing *million_ring = new MillionRing(6, 500, "Starlight", Attribute::attack, 450, "Lightening", Attribute::attack);
    Ring *ring1 = new Ring(Age::hundred, 1, 102, "Slash", Attribute::attack);
    Ring *ring2 = new Ring(Age::hundred, 2, 150, "Lightening", Attribute::attack);
    Ring *ring3 = new Ring(Age::thousand, 2, 200, "Blaze", Attribute::attack);
    
    
    Bone *bone = new Bone(BoneType::head, 200, 190, "Wind", Attribute::attack);
    
    Soul *Zeus = new Soul(10, 75, 20, 46, 65, 21, Attribute::attack, "Zeus");
    
    Zeus->display_soul_info();
    Zeus->absorb(ring1);
    Zeus->level_up(9);
    Zeus->absorb(ring2);
    Zeus->level_up(8);
    Zeus->absorb(ring3);
    Zeus->absorb(bone);
    Zeus->display_soul_info();
    
    
    return 0;
}
