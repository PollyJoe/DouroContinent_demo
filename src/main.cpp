//
//  main.cpp
//  DouroLand_demo
//
//  Created by Polly Zhou on 2022/7/17.
//

#include <iostream>
#include <fstream>
#include <string>



int main(){
    std::string dir = "/Users/polly/Desktop/getline/hw.txt";
    std::ifstream file;
    file.open(dir);
    std::string line;
    while(getline(file, line)){
        std::cout<< line << std::endl;
    }
    return 0;
}
