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
    
    void attack(Soul *object);
    
protected:
    bool ifalive = true;
    Ring ring;
};

#endif /* Beast_h */
