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
    Attribute get_attribute(){ return attribute; };
    virtual void display_ring_info() = 0;
    
// Basic data of a normal ring
protected:
    Age age;
    unsigned int level_growth;
    Attribute attribute;
};

/************************************************************************************************
 * Base class: Bone
 *  Attribute: It is set according to the ability it contains (if it contains)
 *  Ability: The abiltiy that the bone carries (not in the base class)
 *  Buff: similar to level growth, improve the properties, the object will e set depends on the attribute of the bone:
 *      1. Single attack: damage
 *      2. Single support: buff;
 *      3. Single heal: heal;
 *      4. Single control: spirit;
 *************************************************************************************************/
class Bone{
public:
    Bone(unsigned int bu, Attribute att): buff(bu), attribute(att){ }

public:
    Attribute get_attribute(){ return attribute; }
    virtual void display_info() = 0;

protected:
    unsigned int buff;
    Attribute attribute;
};

#endif /* Ring_Bone_h */
