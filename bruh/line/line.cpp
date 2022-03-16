#include "../vector/vector.h"
#include <math.h>
#include "../physics/physics.h"
#include "line.h"



    float length,theta=0,mu;
    Vector Normal=Vector(0,0),a=Vector(0,0),b=Vector(0,0);
    
    Line::Line(Vector A, Vector B,float m = 0){
        a=A;
        b=B;
        Normal =(b.addR(a.scaleR(-1)).y,b.addR(a.scaleR(-1)).x);
        Normal.norm(Normal);
        mu=m;
        length=b.subR(a).mag();
        

    }
    void Line::findAltitude(Physics &Body){
        //re write the altitude function in physics here but improved and dont use area. uase area if nothing else can be done
        //--- nothing could be done after extensive reveiw, unless im straight retared
        float h= (2/length)*( (a.y*b.x+b.y*Body.plr.x+a.x*Body.plr.y)-(a.x*b.y+b.x*Body.plr.y+a.y*Body.plr.x));
        //float altitude=Normal.scaleR(-h).mag();
        if(Body.radius<=h){
            Body.addf(Normal.scaleR(Body.invElast));

        }

    }
    void Line::fricCalc(Physics &body){
        body.addf(Normal.scaleR(mu));

    }
    
    





