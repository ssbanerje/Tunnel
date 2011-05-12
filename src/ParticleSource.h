#ifndef __TUNNEL_PARTICLE_SOURCE_INC
#define __TUNNEL_PARTICLE_SOURCE_INC

#include "Particle.h"

class ParticleSource {
private:
    int x, y;
    double rate; // This gives the number of particles that should be created per second.
    double x_velocity, y_velocity;
    int r, g, b; 
    int ncreated; // This is the number of particles that this source has created.
    
public:
    ParticleSource(int x, int y, double rate, double x_velocity, double y_velocity, int r, int g, int b);
    int getNCreated() {return ncreated;}
    double getRate() {return rate;}
    Particle* create();
    
    int getX() {return x;}
    int getY() {return y;}
};

#endif