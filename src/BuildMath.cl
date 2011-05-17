#define ARR_LEN 1000
#define MAX_TAN 57.29f

//--------------------------------------------------------------
__kernel void sine(__global float *arr) {
	int gid = get_global_id(0);
	arr[gid] = sinpi((float)2.0f/ARR_LEN*gid);
}

//--------------------------------------------------------------
__kernel void cosine(__global float *arr) {
	int gid = get_global_id(0);
	arr[gid] = cospi(2.0f/ARR_LEN*gid);
}

//--------------------------------------------------------------
__kernel void arctan(__global float *arr) {
	int gid = get_global_id(0);
	arr[gid] = atan(-MAX_TAN + 2*gid*MAX_TAN/ARR_LEN);
}
