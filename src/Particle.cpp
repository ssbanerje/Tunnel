#include "Particle.h"

//--------------------------------------------------------------
Particle::Particle(int x, int y, double x_velocity, double y_velocity, int r, int g, int b) {
    this->x = x;
    this->y = y;
    this->x_velocity = x_velocity;
    this->y_velocity = y_velocity;
    this->r = r;
    this->g = g;
    this->b = b;
}

//--------------------------------------------------------------
void Particle::move(double time_delta) {
    x += time_delta * x_velocity;
    y += time_delta * y_velocity;
}