#include "Math.h"

//--------------------------------------------------------------
Math::Math() {
    ofLog(OF_LOG_VERBOSE, "Math::Math()");
    for (register int i=0; i<ARR_LEN; i++) {
        sinArr[i] = sinf(TWO_PI/ARR_LEN * i);
        cosArr[i] = cosf(TWO_PI/ARR_LEN * i);
    }
}

//--------------------------------------------------------------
float Math::sinLookup(float x) {
    float t = x;
    x<0 ? x=-x : x=x;
    int r = (int) (x/TWO_PI);
    x -= r*TWO_PI;
    return (t<0?-1:1)*sinArr[(int)(x/TWO_PI*ARR_LEN)];
}

//--------------------------------------------------------------
float Math::cosLookup(float x) {
    x<0 ? x=-x : x=x;
    int r = (int) (x/TWO_PI);
    x -= r*TWO_PI;
    return cosArr[(int)(x/TWO_PI*ARR_LEN)];
}

//--------------------------------------------------------------
float Math::sinLookupD(float x) {
    return sinLookup(x*TWO_PI/360);
}

//--------------------------------------------------------------
float Math::cosLookupD(float x) {
    return cosLookup(x*TWO_PI/360);
}