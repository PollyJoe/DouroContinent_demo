//
//  Ring.h
//  DouroContinent_demo
//
//  Created by Polly Zhou on 2022/7/13.
//

#ifndef Ring_h
#define Ring_h

#include "Ability.h"

enum class Age{ten, hundred, thousand, ten_thousand, million, god};

class Ring{
public:
    Ring(Age a, unsigned int l): age(a), level_growth(l){}
    ~Ring() = default;
    
    virtual Attribute get_attribute() = 0;
    virtual void display_info() = 0;
    
    unsigned int get_level_growth(){ return level_growth; }
    Age get_age(){ return age; }
    
protected:
    Age age;
    unsigned int level_growth;
    
};

class AttackRing : public Ring{
public:
    AttackRing(Age a, unsigned int l, unsigned int b, std::string n): Ring(a, l), ability(b, n){}
    ~AttackRing() = default;
    
    Attribute get_attribute() override{ return attribute; }
    void display_info() override{
        printf("Age: ");
        switch(age){
            case Age::ten:{ printf("Ten years\n");break; }
            case Age::hundred:{ printf("Hundred years\n");break; }
            case Age::thousand:{ printf("Thousand years\n");break; }
            case Age::ten_thousand:{ printf("Ten thousand years\n");break; }
            case Age::million:{ printf("Million years orz\n");break; }
            case Age::god:{ printf("God level \\$O$/\n");break; }
        }
        ability.display_ability();
    }
    
private:
    Attribute attribute = Attribute::attack;
    AttackAbility ability;
};

#endif /* Ring_h */
