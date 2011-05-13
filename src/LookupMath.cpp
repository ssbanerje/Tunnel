#include "LookupMath.h"

//--------------------------------------------------------------
LookupMath::LookupMath() {
    ofLog(OF_LOG_VERBOSE, "Math::Math()");
    for (register int i=0; i<ARR_LEN; i++) {
        sinArr[i] = sinf(TWO_PI/ARR_LEN * i);
        cosArr[i] = cosf(TWO_PI/ARR_LEN * i);
        tanArr[i] = tanf(TWO_PI/ARR_LEN * i);
    }
}

//--------------------------------------------------------------
float LookupMath::sinLookup(float x) {
    int t = x<0?-1:1;
    x *= t;
    int r = (int) (x/TWO_PI);
    x -= r*TWO_PI;
    return t*sinArr[(int)(x/TWO_PI*ARR_LEN)];
}

//--------------------------------------------------------------
float LookupMath::tanLookup(float x) {
    int t = x<0?-1:1;
    x *= t;
    int r = (int) (x/TWO_PI);
    x -= r*TWO_PI;
    return t*sinArr[(int)(x/TWO_PI*ARR_LEN)];
}

//--------------------------------------------------------------
float LookupMath::cosLookup(float x) {
    x<0 ? x=-x : x=x;
    int r = (int) (x/TWO_PI);
    x -= r*TWO_PI;
    return cosArr[(int)(x/TWO_PI*ARR_LEN)];
}

//--------------------------------------------------------------
float LookupMath::sinLookupD(float x) {
    return sinLookup(x*TWO_PI/360);
}

//--------------------------------------------------------------
float LookupMath::cosLookupD(float x) {
    return cosLookup(x*TWO_PI/360);
}

//--------------------------------------------------------------
float LookupMath::tanLookupD(float x) {
    return sinLookup(x*TWO_PI/360);
}

//--------------------------------------------------------------
float LookupMath::arcTanLookup(float x) {
    register int lo,hi,mid;
    if(x<0) {
        lo = ARR_LEN/4;
        hi = ARR_LEN/2;
    }
    else {
        lo = 0;
        hi = ARR_LEN/4;
    }
    while (lo<hi) {
        mid = lo+hi/2;
        if (x<tanArr[mid])
            hi = mid;
        else if(x>tanArr[mid])
            lo = mid;
        else
            break;
    }
    mid = (lo+hi)/2;
    return TWO_PI*mid/ARR_LEN;
}

//--------------------------------------------------------------
float LookupMath::arcTanLookupD(float x) {
    return arcTanLookup(x)*360/TWO_PI;
}
