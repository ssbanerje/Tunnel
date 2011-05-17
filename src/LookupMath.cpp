#include "LookupMath.h"

//--------------------------------------------------------------
void LookupMath::initialize() {
    ofLog(OF_LOG_VERBOSE, "Math::Math()");
    MSA::OpenCL opencl;
    opencl.setup(CL_DEVICE_TYPE_GPU, 2);
    opencl.loadProgramFromFile("BuildMath.cl", false);
    MSA::OpenCLKernel* sinKernel = opencl.loadKernel("sine");
    MSA::OpenCLKernel* cosKernel = opencl.loadKernel("cosine");
    MSA::OpenCLKernel* atanKernel = opencl.loadKernel("arctan");
    MSA::OpenCLBuffer clBuf[3];
    clBuf[0].initBuffer(ARR_LEN*sizeof(float), CL_MEM_READ_WRITE);
    clBuf[1].initBuffer(ARR_LEN*sizeof(float), CL_MEM_READ_WRITE);
    clBuf[2].initBuffer(ARR_LEN*sizeof(float), CL_MEM_READ_WRITE);
    sinKernel->setArg(0, clBuf[0].getCLMem());
    cosKernel->setArg(0, clBuf[1].getCLMem());
    atanKernel->setArg(0, clBuf[2].getCLMem());
    opencl.finish();
    sinKernel->run1D(ARR_LEN);
    cosKernel->run1D(ARR_LEN);
    atanKernel->run1D(ARR_LEN);
    opencl.finish();
    clBuf[0].read(sinArr, 0, ARR_LEN*sizeof(float));
    clBuf[1].read(cosArr, 0, ARR_LEN*sizeof(float));
    clBuf[2].read(atanArr, 0, ARR_LEN*sizeof(float));
    opencl.finish();
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
    if(x>MAX_TAN)   return PI/2;
    else if(x<-MAX_TAN) return -PI/2;
    return atanArr[ARR_LEN + (int)((x-MAX_TAN)*0.5*ARR_LEN/MAX_TAN)];
}

//--------------------------------------------------------------
float LookupMath::atanLookupD(float x) {
    return atanLookup(x)*360/TWO_PI;
}
