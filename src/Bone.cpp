//
//  Bone.cpp
//  DouroContinent_demo
//
//  Created by Polly Zhou on 2022/7/15.
//

#include <stdio.h>
#include "Bone.h"

void Bone::display_info(){
    printf("* Bone type: ");
    switch(type){
        case BoneType::head:{printf("Head\n");break;}
        case BoneType::trunk:{printf("Trunk\n");break;}
        case BoneType::left_leg:{printf("Left leg\n");break;}
        case BoneType::right_leg:{printf("Right leg\n");break;}
        case BoneType::left_arm:{printf("Left arm\n");break;}
        case BoneType::right_arm:{printf("Right arm\n");break;}
        case BoneType::externed:{printf("Externed\n");break;}
        default:break;
    }
    ability->display_ability();
}
