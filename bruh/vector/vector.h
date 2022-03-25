#ifndef VECTOR_H
#define VECTOR_H


class Vector {

public:
    float x;
    float y;
    float abso(float n);
    //Vector ();
    Vector(const Vector &v1);
    Vector (float xx = 0, float yy = 0);
    void sub (Vector v1);
    Vector subR (Vector v1);
    void add (Vector v1);
    Vector addR (Vector v1);
    void scale (float s);
    Vector scaleR (float s);
    void norm (Vector v1);
    float mag ();
    void operator= (Vector v1);
    void operator+= (Vector v1);
    Vector operator- (Vector v1);
    Vector operator+ (Vector v1);
    float dot(Vector, Vector);
    Vector cross(Vector, Vector);
    Vector swapXY(Vector v1);
    Vector swapXY();
    Vector swapRXY();
    //Note to self: make sure to add projections to find closest point on a given line given a point/vector. --- done
    Vector proj(Vector);

};

#endif
