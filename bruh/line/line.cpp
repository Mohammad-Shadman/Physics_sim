#include "../vector/vector.h"
#include <math.h>
#include "../physics/physics.h"
#include "line.h"



    float length,theta=0,mu;
    long double m;
    Vector Normal(0,0),a(0,0),b(0,0);
    
    Line::Line(Vector A, Vector B,float m = 0){
        a=(A);
        b= (B);
        Normal =(b.addR(a.scaleR(-1)).y,b.addR(a.scaleR(-1)).x);
        Normal.norm(Normal);
        mu=m;
        length=b.subR(a).mag();
        m=(a.y-b.y)/(a.x-b.x);
        

    }
    void Line::findAltitude(Physics &Body){
        /*
        ---re write the altitude function in physics here but improved and dont use area. use area if nothing else can be done
        --- nothing could be done after extensive reveiw, unless im straight retared ---> i was straight retarded
        float altitude=Normal.scaleR(-h).mag();
        ---this is the old revision, the new revision uses vector projection.
        
        float h= (2/length)*( (a.y*b.x+b.y*Body.plr.x+a.x*Body.plr.y)-(a.x*b.y+b.x*Body.plr.y+a.y*Body.plr.x));\

        if(Body.radius<=h){
            Body.addf(Normal.scaleR(Body.invElast));
        }*/
        //if(Body.radius<=))

        Vector temp = (Body.plr-(b-a).proj(Body.plr));
        Vector temp2 = (temp-Body.plr);
        if(temp.dot(temp,temp)<=temp.dot(temp2,temp2)){
        Body.vel.x=(Body.vel.x*(1-m*m)+2*m*Body.vel.y);
        Body.vel.y=(Body.vel.x*(m*m-1)+2*m*Body.vel.x);       
        Body.vel.scale(1/(m*m+1));
        }
    }
    void Line::fricCalc(Physics &body){
        body.addf(Normal.scaleR(mu));

    }
    
    





