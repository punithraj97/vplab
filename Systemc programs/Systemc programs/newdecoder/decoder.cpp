//
//  Full_adder.cpp
//  FULLADDER
//
//  Created by Behrad Niazmand on 7/19/14.
//  Copyright (c) 2014 Behrad Niazmand. All rights reserved.
//

#include "decoder.h"

void encoder::proc_encoder()
{
    if (enable.read())
    {
    switch (input.read())
        {
            case 0: // input: 0, output should be 0001
                output.write(1);
                break;
            
            case 1: // input: 1, output should be 0010
                output.write(2);
                break;

            case 2: // input: 2, output should be 0100
                output.write(4);
                break;

            case 3: // input: 3, output should be 1000
                output.write(8);
                break;
        }
    }
    
    else
        output.write(0); // If the enable is zero
}