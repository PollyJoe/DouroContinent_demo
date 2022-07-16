//
//  Soul.cpp
//  DouroContinent_demo
//
//  Created by Polly Zhou on 2022/7/13.
//

#include "Soul.h"

void Soul::level_up(unsigned int growth){
    level += growth;
    if(level >= 100) level = 100;
    hp *= pow(1.1, growth);
    damage *= pow(1.1, growth);
    defense *= pow(1.1, growth);
    speed *= pow(1.1, growth);
    control *= pow(1.1, growth);
}

/**************************************
    Display info
 **************************************/
void Soul::display_soul_info(){
    printf("*****************************************\n");
    display_basic_info();
    printf("* =======================================\n");
    display_properties();
    printf("* =======================================\n");
    display_rings();
    printf("* =======================================\n");
    display_bones();
    printf("*****************************************\n");
    printf("\n\n");
}

void Soul::display_rings(){
    printf("* Rings: %lu ring(s)\n", rings.size());
    printf("* ---------------------------------------\n");
    for(int i = 0; i < rings.size(); i++){
        printf("* Ring %d:\n", i + 1);
        if(rings[i]->get_age() != Age::million)
            rings[i]->display_info();
        else{
            MillionRing *temp = (MillionRing*)(rings[i]);
            temp->display_info();
        }
        printf("* ---------------------------------------\n");
    }
}

void Soul::display_bones(){
    printf("* Bones:\n");
    printf("* ---------------------------------------\n");
    for(int i = 0; i < bones.size(); i++){
        printf("* Bone %d:\n", i + 1);
        bones[i]->display_info();
        printf("* ---------------------------------------\n");
    }
}

void Soul::display_properties(){
    printf("* HP: %d\n", hp);
    printf("* Damage: %d\n", damage);
    printf("* Defense: %d\n", defense);
    printf("* Control: %d\n", control);
    printf("* Speed: %d\n", speed);
}

void Soul::display_basic_info(){
    printf("* Name: %s\n", name.c_str());
    printf("* Attribute: "); display_attribute(attribute);
    printf("* Level: %d\n", level);
}

/*************************************************************
 * Absorb rings and bones
 **************************************************************/
bool Soul::ifabsorb(Ring *ring){
    if(!ring->absorbable) return false;
    else if(level % 10 != 0){
        printf("Cannot absorb. Not raised 10 levels yet.\n");
        return false;
    }
    else if(defense < 300 && (ring->get_age() == Age::ten_thousand || ring->get_age() == Age::million || ring->get_age() == Age::god)){
        printf("Your soul is not strong enough to bear the impact from the ring! You need to improve his/her defense to over 300!\n");
        return false;
    }
    else{
        switch(attribute){
            case Attribute::attack:
            case Attribute::defense:
            case Attribute::control:{
                if(ring->ability->get_attribute() == Attribute::heal ||
                   ring->ability->get_attribute() == Attribute::support){
                    printf("This is a combat soul. Only combat ring is absorbable.\n");
                    return false;
                }
                else return true;
            }
            case Attribute::heal:
            case Attribute::support:{
                if(ring->ability->get_attribute() != attribute){
                    printf("This is not a combat soul. Only the ring with the same attribute is absorbable.\n");
                    return false;
                } else return true;
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
        ring->ifabsorbed = true;
    }
    else{
        if(!ring->ifabsorbed) ring->~Ring();
    }
}

bool Soul::ifabsorb(Bone *bone){
    if(!bone->absorbable) return false;
    else if(defense < 300){
        printf("Your soul is not strong enough to bear the impact from the bone! You need to improve his/her defense to over 300!\n");
        return false;
    }
    else{
        switch(attribute){
            case Attribute::attack:
            case Attribute::defense:
            case Attribute::control:{
                if(bone->ability->get_attribute() == Attribute::heal||
                   bone->ability->get_attribute() == Attribute::support){
                    printf("This is a combat soul. Only combat bone is absorbable.\n");
                    return false;
                }
                else return true;
            }
            case Attribute::heal:
            case Attribute::support:{
                if(bone->ability->get_attribute() != attribute){
                    printf("This is not a combat soul. Only the bone with the same attribute is absorbable.\n");
                    return false;
                } else return true;
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

/*********************************************
 * Check vectors
 *********************************************/
bool Soul::check_rings(){
    if(rings.size() == 0) return false;
    else return true;
}

bool Soul::check_bones(){
    if(bones.size() == 0) return false;
    else return true;
}

bool Soul::check_self_made(){
    if(self_made.size() == 0) return false;
    else return true;
}

/*******************************************************************************************
 * Use ability:
 *  Choose the source first. Choose ring ability, bone ability or self-made ability.
 *  If the source vector is empty, the system will remind the player.
 *  Then choose the number of the ability, and the ability will be used.
 *******************************************************************************************/
Ability* Soul::use_ability(){
    Ability *chosen = NULL;
    char source = choose_ability_source();
    switch(source){
        case 'r':{
            int choice = choose_ability((int)rings.size());
            if(choice == -1) chosen = NULL;
            else if(rings[choice]->ability->get_attribute() == Attribute::none) chosen = NULL;
            else chosen = rings[choice]->ability;
            break;
        }
        case 'b':{
            int choice = choose_ability((int)bones.size());
            if(choice == -1) chosen = NULL;
            else if(bones[choice]->ability->get_attribute() == Attribute::none) chosen = NULL;
            else chosen = bones[choice]->ability;
            break;
        }
        case 's':{
            int choice = choose_ability((int)self_made.size());
            if(choice == -1) chosen = NULL;
            else chosen = self_made[choice];
            break;
        }
        default:break;
    }
    if(chosen == NULL) printf("Give up this turn.\n");
    return chosen;
}

int Soul::choose_ability(int vector_size){
    int choice = -1;
    printf("Choose the ability (Type the number of ability):\n");
    scanf("%d", &choice);
    int wrong_time = 0;
    while((choice < 0 || choice >= vector_size) && wrong_time < 3){
        printf("Wrong input. Choose again.\n");
        choice = -1;
        printf("Choose the ability (Type the number of ability):\n");
        scanf("%d", &choice);
        wrong_time++;
        if(wrong_time == 3) printf("Failed 3 times already. Automatically give up this turn.\n");
    }
    return choice;
}

char Soul::choose_ability_source(){
    char choice = 'n';
    if(check_rings()) printf("Use ability from rings (r).\n");
    if(check_bones()) printf("Use ability from bones (b).\n");
    if(check_self_made()) printf("Use self-made ability (s).\n");
    printf("Press any other key to give up using ability this turn.\n");
    scanf("%c", &choice);
    return choice;
}
