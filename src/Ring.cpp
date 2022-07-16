//
//  Ring.cpp
//  DouroContinent_demo
//
//  Created by Polly Zhou on 2022/7/13.
//

#include <iostream>
#include "Ring.h"
void display_Age(Age a){
    switch(a){
        case Age::ten:{ printf("Ten years\n");break; }
        case Age::hundred:{ printf("Hundred years\n");break; }
        case Age::thousand:{ printf("Thousand years\n");break; }
        case Age::ten_thousand:{ printf("Ten thousand years\\n");break; }
        case Age::million:{ printf("Million years orz\n");break; }
        case Age::god:{ printf("God level \\$O$/\n");break; }
    }
}

Ring::~Ring(){
    delete ability;
}

MillionRing::~MillionRing(){
    delete ability;
    delete second_ability;
    delete this;
}

void Ring::display_info(){
    display_age();
    ability->display_ability();
}

void Ring::display_age(){
    printf("* Age: ");
    display_Age(age);
}

void MillionRing::display_info(){
    display_age();
    printf("* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("* First ability:\n");
    ability->display_ability();
    printf("* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("* Second ability:\n");
    second_ability->display_ability();
}
