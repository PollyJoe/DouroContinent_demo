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
    Ring(Age a, unsigned int l, unsigned int b, std::string n, Attribute att): age(a), level_growth(l){ ability = new Ability(b, n, att); }
    ~Ring();
    
    Ability *ability;
    bool absorbable = true;
    bool ifabsorbed = false;
    
    void display_info();
    void display_age();
    unsigned int get_level_growth(){ return level_growth; }
    Age get_age(){ return age; }
    
protected:
    Age age;
    unsigned int level_growth;
};

class MillionRing : public Ring{
public:
    MillionRing(unsigned int l, unsigned int b, std::string n, Attribute att,  unsigned int b1, std::string n1, Attribute att1): Ring(Age::million, l, b, n, att){ second_ability = new Ability(b1, n1, att1); }
    ~MillionRing();
    void display_info();
    Ability *second_ability;
};

class GodRing : public Ring{
public:
    GodRing(unsigned int l, unsigned int b, std::string n, Attribute att): Ring(Age::god, l, b, n, att){ }
    void display_info();
};



#endif /* Ring_h */
