//
//  Ring&Bone.h
//  DouroLand_demo
//
//  Created by Polly Zhou on 2022/7/18.
//

#ifndef Ring_Bone_h
#define Ring_Bone_h
#include "Ability.h"

enum class Age{ ten, hundred, thousand, ten_thousand, million, god };
/********************************************************************************************
 * Base class: Ring
 *  Age: It is set according to the age of the beast carrying this ring.
 *  Attribute: It is set according to the attribute of the ability it carries.
 *  Level growth: the number of levels souls can raise once they absorb the ring
 ********************************************************************************************/
class Ring{
public:
    Ring(Age a, unsigned int lg, Attribute att): age(a), level_growth(lg), attribute(att){ };
public:
    void get_attribute(){};
    virtual void display_ring_info() = 0;
    
// Basic data of a normal ring
protected:
    Age age;
    unsigned int level_growth;
    Attribute attribute;
};

/************************************************************************************************
 * Base class: Bone
 *************************************************************************************************/
class Bone{
    
};

#endif /* Ring_Bone_h */
