//
//  Ring.h
//  DouroContinent_demo
//
//  Created by Polly Zhou on 2022/7/13.
//
#pragma once

#ifndef Ring_h
#define Ring_h

#include "Ability.h"

enum class Age{ten, hundred, thousand, ten_thousand, million, god};
void display_Age(Age a);

class Ring{
public:
    Ring(Age a, unsigned int l, unsigned int b, std::string n, Attribute att): age(a), level_growth(l), ability(b, n, att){}
    ~Ring() = default;
    
    Ability ability;
    
    void display_info(){
        display_age();
        ability.display_ability();
    };
    void display_age(){
        printf("Age: ");
        display_Age(age);
    }
    unsigned int get_level_growth(){ return level_growth; }
    Age get_age(){ return age; }
    
private:
    Age age;
    unsigned int level_growth;
};


#endif /* Ring_h */
