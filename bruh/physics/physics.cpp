#include "../vector/vector.h"
#include "physics.h"
#include "../line/line.h"
#include <math.h>

    
    Vector plr;
    Vector vel;
    Vector acc;
    Vector norm;
    Vector orientation = Vector (0,1);// normalized vector of velocity before it goes to 0. first initiallized to look up
    float P_mu,mass,elastisity,radius,dt,invElast;

    Physics::Physics( Vector p, float C_mu=1,float m=1,float e =1,float r=1){
        
        plr = p;
        P_mu = C_mu;
        mass= m;
        elastisity = e;
        invElast=1-elastisity;
        radius=r;
        
    }
    
    void Physics::addf(Vector f){
        f.scale(1/mass);
        acc.add(f);
    }
    
    Vector Physics::apply(){
        //if (vel.mag() < 4)
        vel.add(acc);
        plr.add(vel);
        return plr;
    }

    //void Physics::collision(Line l){
        //b=sqrtf((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y)); tis will be done in main for optimisation
        //float h= (2/b)*( (A.y*B.x+B.y*plr.x+A.x*plr.y)-(A.x*B.y+B.x*plr.y+A.y*plr.x));
        //if ()
        //{
            //the hight may be wrong thus need to revise--- revised with line class
            //line

        //}

    //}
    void Physics::fric(Vector fc){
        
        
    }
    void Physics::applyForces(float gravity=0,Vector wind=0,Vector friction=0){
        Vector forces= Vector (0,0);
        
        //gravity
        forces.add(Vector(0,gravity));
        //wind
        forces.add(wind);
        //friction
        //forces.add(Vector(0,n));
    }

    Vector Physics::findN(){

    }
    
