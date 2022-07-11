//
//  Ability.h
//  DouroContinent_demo
//
//  Created by Polly Zhou on 2022/7/11.
//

#ifndef Ability_h
#define Ability_h

#include <string>

enum class Attribute{ attack, defense, control, support, heal };

class Ability{
public:
    Ability(int b, std::string n, Attribute a): basic_value(b), name(n), attribute(a){}
    int real_value;

private:
    int basic_value;
    std::string name;
    Attribute attribute;
};

#endif /* Ability_h */
