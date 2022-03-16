#ifndef LINE_H
#define LINE_H
#include "../vector/vector.h"
#include "../physics/physics.h"

class Line{
    public:
        float length,theta,mu;
        Vector Normal,a,b;
        Line(Vector,Vector,float);
        Vector getNormal();
        void fricCalc(Physics&);
        void findAltitude(Physics&);
    
    




};



#endif