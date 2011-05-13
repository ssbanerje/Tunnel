#ifndef __TUNNEL_PARTICLE_INC
#define __TUNNEL_PARTICLE_INC

class Particle {
    double x, y;
    double x_velocity, y_velocity;
    int r, g, b;
    
public:
    Particle(int x, int y, double x_velocity, double y_velocity, int r, int g, int b);
    
    int getX() {return (int)floor(x);}
    int getY() {return (int)floor(y);}
    int getR() {return r;}
    int getG() {return g;}
    int getB() {return b;}
    
    void move(double time_delta);
};

#endif
