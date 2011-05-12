#ifndef __TUNNEL_LOOKUP_MATH_INC
#define __TUNNEL_LOOKUP_MATH_INC

#include "ofMath.h"
#include "ofConstants.h"

#define ARR_LEN 1000

class LookupMath {
private:
    float sinArr[ARR_LEN];
    float cosArr[ARR_LEN];
    
public:
    LookupMath();
    float sinLookup(float x);
    float cosLookup(float x);
    float sinLookupD(float x);
    float cosLookupD(float x);
};


#endif