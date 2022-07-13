//
//  Ring.cpp
//  DouroContinent_demo
//
//  Created by Polly Zhou on 2022/7/13.
//

#include <iostream>
#include "Ring.h"
void display_Age(Age a){
    switch(a){
        case Age::ten:{ printf("Ten years\n");break; }
        case Age::hundred:{ printf("Hundred years\n");break; }
        case Age::thousand:{ printf("Thousand years\n");break; }
        case Age::ten_thousand:{ printf("Ten thousand years\n");break; }
        case Age::million:{ printf("Million years orz\n");break; }
        case Age::god:{ printf("God level \\$O$/\n");break; }
    }
}
