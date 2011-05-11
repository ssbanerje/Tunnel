#ifndef __TUNNEL_MATH_INC
#define __TUNNEL_MATH_INC

#include "ofMath.h"
#include "ofConstants.h"

#define ARR_LEN 1000

class Math {
private:
    float sinArr[ARR_LEN];
    float cosArr[ARR_LEN];
    
public:
    Math();
    float sinLookup(float x);
    float cosLookup(float x);
    float sinLookupD(float x);
    float cosLookupD(float x);
};


#endif