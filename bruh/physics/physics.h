#ifndef PHYSICS_H
#define PHYSICS_H
#include "../vector/vector.h"
//#include "../line/line.h"
class Physics{
    
public:
    Vector plr;
    Vector vel;
    Vector acc;
    float P_mu,mass,elastisity,radius,dt,invElast;
    Physics(Vector, float,float,float,float);
    void applyForces( Vector, float ,float,float );
    void addf(Vector f);
    void collision(Vector,Vector,float);
    Vector apply();
    void fric(Vector);
    //void collision(Line);
    Vector findN();
    void drag(float ,float );
};

#endif
