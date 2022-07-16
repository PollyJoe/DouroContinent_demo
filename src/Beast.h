//
//  Beast.h
//  DouroContinent_demo
//
//  Created by Polly Zhou on 2022/7/15.
//

#ifndef Beast_h
#define Beast_h

#include "Ring.h"
#include "Bone.h"

class Beast{
public:
    Beast() = default;
    Beast(Age a, unsigned int l, unsigned int b, std::string n, Attribute att): ring(a, l, b, n, att){ }
    ~Beast() = default;
    
    bool ifalive = true;
    Ring ring;
    
    unsigned int hp;
};

class OverTenThousandBeast : public Beast{
public:
    OverTenThousandBeast(Age a1, unsigned int l, unsigned int b, std::string n1, Attribute att, BoneType t, unsigned int b1, unsigned int b2, std::string n2, Attribute a2):Beast(a1, l, b, n1, att), bone(t, b1, b2, n2, a2){ }
    
    Bone bone;
};
#endif /* Beast_h */
