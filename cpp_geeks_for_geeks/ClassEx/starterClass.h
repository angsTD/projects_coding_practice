//
//  starterClass.h
//  ClassEx
//
//  Created by Angalo Kurian Maliyil on 10/27/17.
//  Copyright © 2017 Angelo. All rights reserved.
//

#ifndef starterClass_h
#define starterClass_h
#include <stdint.h>
class Starter
{
    uint8_t accumulator;
    
public:
    Starter(uint8_t x):accumulator(x){
        printf("acc:%u \n",accumulator);}
    uint8_t getAcc(){return accumulator;}
};

#endif /* starterClass_h */
