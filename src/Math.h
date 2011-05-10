#ifndef __TUNNEL_MATH_INC
#define __TUNNEL_MATH_INC

#include <math.h>

#include "ofMain.h"

#define ARR_LEN 1000

class Math {
private:
    float sinArr[ARR_LEN];
    float cosArr[ARR_LEN];
    
public:
    Math();
    float sinLookup(float x);
    float cosLookup(float x);
};


#endif