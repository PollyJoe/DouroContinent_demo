//
//  Soul.cpp
//  DouroContinent_demo
//
//  Created by Polly Zhou on 2022/7/13.
//

#include "Soul.h"

void Soul::display_soul_info(){
    printf("******************************************\n");
    printf("Name: %s\n", name.c_str());
    printf("---------------------------------\n");
    printf("Attribute: "); display_attribute(attribute);
    printf("---------------------------------\n");
    printf("Rings: %lu ring(s)\n", rings.size());
    printf("---------------------------------\n");
    if(rings.size() != 0){
        for(int i = 0; i < rings.size(); i++){
            printf("Ring %d:\n", i + 1);
            rings[i].display_info();
            printf("---------------------------------\n");
        }
    }
    printf("******************************************\n");
    printf("\n");
}
