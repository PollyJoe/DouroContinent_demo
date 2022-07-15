//
//  Soul.cpp
//  DouroContinent_demo
//
//  Created by Polly Zhou on 2022/7/13.
//

#include "Soul.h"

void Soul::level_up(unsigned int growth){
    level += growth;
    hp *= pow(1.1, growth);
    damage *= pow(1.1, growth);
    defense *= pow(1.1, growth);
    speed *= pow(1.1, growth);
    control *= pow(1.1, growth);
}

void Soul::display_soul_info(){
    printf("******************************************\n");
    display_basic_info();
    printf("======================================\n");
    display_properties();
    printf("======================================\n");
    display_rings();
    printf("======================================\n");
    display_bones();
    printf("******************************************\n");
    printf("\n");
}

void Soul::display_rings(){
    printf("Rings: %lu ring(s)\n", rings.size());
    printf("---------------------------------\n");
    for(int i = 0; i < rings.size(); i++){
        printf("Ring %d:\n", i + 1);
        rings[i]->display_info();
        printf("---------------------------------\n");
    }
}

void Soul::display_bones(){
    printf("Bones:\n");
    printf("---------------------------------\n");
    for(int i = 0; i < bones.size(); i++){
        printf("Bone %d:\n", i + 1);
        bones[i]->display_info();
        printf("---------------------------------\n");
    }
}

void Soul::display_properties(){
    printf("HP: %d\n", hp);
    printf("Damage: %d\n", damage);
    printf("Defense: %d\n", defense);
    printf("Control: %d\n", control);
    printf("Speed: %d\n", speed);
}

void Soul::display_basic_info(){
    printf("Name: %s\n", name.c_str());
    printf("Attribute: "); display_attribute(attribute);
    printf("Level: %d\n", level);
}

bool Soul::ifabsorb(Ring *ring){
    if(!ring->absorbable) return false;
    else if(level % 10 != 0){
        printf("Cannot absorb. Not raised 10 levels yet.\n");
        return false;
    }
    else{
        switch(attribute){
            case Attribute::attack:
            case Attribute::defense:
            case Attribute::control:{
                if(ring->ability.get_attribute() == Attribute::heal ||
                   ring->ability.get_attribute() == Attribute::support){
                    printf("This is a combat soul. Only combat ring is absorbable.\n");
                    return false;
                }
                else return true;
            }
            case Attribute::heal:
            case Attribute::support:{
                if(ring->ability.get_attribute() != attribute){
                    printf("This is not a combat soul. Only the ring with the same attribute is absorbable.\n");
                    return false;
                }
                else return true;
            }
            default: return true;
        }
    }
}

void Soul::absorb(Ring *ring){
    bool ifable = ifabsorb(ring);
    if(ifable){
        rings.push_back(ring);
        level_up(ring->get_level_growth());
        ring->absorbable = false;
    }
}

bool Soul::ifabsorb(Bone *bone){
    if(!bone->absorbable) return false;
    else{
        switch(attribute){
            case Attribute::attack:
            case Attribute::defense:
            case Attribute::control:{
                if(bone->ability.get_attribute() == Attribute::heal||
                   bone->ability.get_attribute() == Attribute::support){
                    printf("This is a combat soul. Only combat bone is absorbable.\n");
                    return false;
                }
                else return true;
            }
            case Attribute::heal:
            case Attribute::support:{
                if(bone->ability.get_attribute() != attribute){
                    printf("This is not a combat soul. Only the bone with the same attribute is absorbable.\n");
                    return false;
                }
                else return true;
            }
            default: return true;
        }
    }
}

void Soul::absorb(Bone *bone){
    bool ifable = ifabsorb(bone);
    if(ifable){
        bones.push_back(bone);
        switch(bone->type){
            case BoneType::head:{control *= (1 + bone->buff / 100);break;}
            case BoneType::trunk:{defense *= (1 + bone->buff / 100);break;}
            case BoneType::left_arm:{damage *= (1 + 0.8 * bone->buff / 100);break;}
            case BoneType::right_arm:{damage *= (1 + bone->buff / 100);break;}
            case BoneType::left_leg:{speed *= (1 + 0.8 * bone->buff / 100);break;}
            case BoneType::right_leg:{speed *= (1 + bone->buff / 100);break;}
            case BoneType::externed:{
                control *= (1 + 2 * bone->buff / 100);
                defense *= (1 + 2 * bone->buff / 100);
                damage *= (1 + 2 * bone->buff / 100);
                speed *= (1 + 2 * bone->buff / 100);
                break;
            }
            default:break;
        }
        bone->absorbable = false;
    }
}
