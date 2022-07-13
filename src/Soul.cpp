//
//  Soul.cpp
//  DouroContinent_demo
//
//  Created by Polly Zhou on 2022/7/13.
//

#include "Soul.h"

void Soul::display_soul_info(){
    printf("******************************************\n");
    display_basic_info();
    printf("---------------------------------\n");
    display_properties();
    printf("---------------------------------\n");
    display_rings();
    printf("******************************************\n");
    printf("\n");
}

void Soul::display_rings(){
    printf("Rings: %lu ring(s)\n", rings.size());
    printf("---------------------------------\n");
    if(rings.size() != 0){
        for(int i = 0; i < rings.size(); i++){
            printf("Ring %d:\n", i + 1);
            rings[i].display_info();
            printf("---------------------------------\n");
        }
    }
}

void Soul::display_properties(){
    printf("HP: %d\n", hp);
    printf("Damage: %d\n", damage);
    printf("Defense: %d\n", defense);
    printf("Control: %d\n", control);
    printf("Speed: %d\n", speed);
}

void Soul::display_basic_info(){
    printf("Name: %s\n", name.c_str());
    printf("Attribute: "); display_attribute(attribute);
    printf("Level: %d\n", level);
}
