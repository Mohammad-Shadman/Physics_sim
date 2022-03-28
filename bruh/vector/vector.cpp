#include "vector.h"
#include <math.h>

float x,y;

float Vector::abso(float n){
    if (n<0){n*=-1;}
    return n;
}

/*
Vector::Vector()=;
Vector::Vector(){
    x=0;y=0;

}
/
///*
*/


Vector::Vector (float xx =0, float yy= 0) {
    x = xx;
    y = yy;
}

Vector Vector::returnV(float xx,float yy){
    return (Vector(xx,yy));
}

void Vector::operator= (Vector v1){
    x = v1.x;
    y = v1.y;
}
Vector Vector::operator- (Vector v1){
    return Vector(x-v1.x , y-v1.y);
}
Vector Vector::operator+ (Vector v1){
    return Vector(x+v1.x , y+v1.y);
}

void Vector::operator+= (Vector v1){
    x += v1.x;
    y += v1.y;
}

void Vector::add (Vector v1) {
    x += v1.x;
    y += v1.y;
}

Vector Vector::addR (Vector v1) {
    
    return Vector(x+v1.x,y+v1.y);
}

void Vector::sub (Vector v1) {
    x -= v1.x;
    y -= v1.y;
}
Vector Vector::subR (Vector v1) {
    
    return Vector(x-v1.x,y-v1.y);
}

void Vector::scale (float s) {
    x *= s;
    y *= s;
}

Vector Vector::scaleR (float s) {
    return Vector(x*s,y*s);
}

void Vector::norm (Vector v1) {
    x /= v1.mag();
    y /= v1.mag();
}

float Vector::mag (){
    float magnitude = sqrtf(x*x + y*y);
    return magnitude;
}

float Vector::dot(Vector A, Vector B){
    return (A.x* B.x +A.y * B.y);

}

Vector Vector::cross(Vector a, Vector b){
    return (Vector(a.x*b.y,-b.x*a.y));

}  

Vector Vector::swapXY(Vector v1){
    return Vector(v1.y,v1.x);
}

Vector Vector::swapXY(){
    return Vector(y,x);
}

Vector Vector::swapRXY(){
    return Vector(y,x);
}

Vector Vector::proj(Vector u){
    return u.scaleR(dot(Vector(x,y),u)/(x*x+y*y));
    
}
