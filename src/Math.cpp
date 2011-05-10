#include "Math.h"

//--------------------------------------------------------------
Math::Math() {
    for (register int i=0; i<ARR_LEN; i++) {
        sinArr[i] = sinf(TWO_PI/ARR_LEN * i);
        cosArr[i] = cosf(TWO_PI/ARR_LEN * i);
    }
}

//--------------------------------------------------------------
float Math::sinLookup(float x) {
    int r = (int) (x/TWO_PI);
    x -= r*TWO_PI;
    return sinArr[(int)(x/TWO_PI*ARR_LEN)];
}

//--------------------------------------------------------------
float Math::cosLookup(float x) {
    int r = (int) (x/TWO_PI);
    x -= r*TWO_PI;
    return cosArr[(int)(x/TWO_PI*ARR_LEN)];
}