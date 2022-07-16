//
//  Bone.h
//  DouroContinent_demo
//
//  Created by Polly Zhou on 2022/7/14.
//

#ifndef Bone_h
#define Bone_h

#include "Ability.h"

enum class BoneType{ head, trunk, left_leg, right_leg, left_arm, right_arm, externed };

class Bone{
public:
    Bone() = default;
    Bone(BoneType t, unsigned int b1, unsigned int b2, std::string n, Attribute a): type(t), buff(b1){
        ability = new Ability(b2, n ,a);
    }
    ~Bone() = default;
    
    void display_info();
    
    Ability *ability;
    bool absorbable = true;
    BoneType type;
    unsigned int buff;
};


#endif /* Bone_h */
