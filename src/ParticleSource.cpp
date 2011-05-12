#include "ParticleSource.h"

//--------------------------------------------------------------
ParticleSource::ParticleSource(int x, int y, double rate, double x_velocity, double y_velocity, int r, int g, int b) {
    this->x = x;
    this->y = y;
    this->rate = rate;
    this->x_velocity = x_velocity;
    this->y_velocity = y_velocity;
    this->r = r;
    this->g = g;
    this->b = b;
    this->ncreated = 0;
}

//--------------------------------------------------------------
Particle* ParticleSource::create() {
    ncreated += 1;
    return new Particle(x, y, x_velocity, y_velocity, r, g, b);
}