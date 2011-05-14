#include "LookupMath.h"

//--------------------------------------------------------------
LookupMath::LookupMath() {
    ofLog(OF_LOG_VERBOSE, "Math::Math()");
    for (register int i=0; i<ARR_LEN; i++) {
        sinArr[i] = sinf(TWO_PI/ARR_LEN * i);
        cosArr[i] = cosf(TWO_PI/ARR_LEN * i);
        atanArr[i] = atanf(-MAX_TAN + i*MAX_TAN/ARR_LEN);
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
float LookupMath::atanLookup(float x) {
    int lo, hi, mid;
    lo = 0;
    hi = ARR_LEN;
    while (lo<=hi) {
        mid = (lo+hi)/2;
        if (atanArr[mid]<x) {
            hi = mid;
        }
        else if (atanArr[mid]>x) {
            lo = mid;
        }
        else {
            break;
        }
    }
    return -PI/2 + mid*PI/ARR_LEN;
}

//--------------------------------------------------------------
float LookupMath::atanLookupD(float x) {
    return atanLookup(x)*360/TWO_PI;
}
