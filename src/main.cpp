//
//  main.cpp
//  DouroLand_demo
//
//  Created by Polly Zhou on 2022/7/20.
//

#include <iostream>
#include <string>
#include "Ring&Bone.h"

int main(){
    std::string s("hello");
    for(auto &c : s){
        c = toupper(c);
        std::cout << c << std::endl;
    }
    std::cout << s << std::endl;
    return 0;
}
