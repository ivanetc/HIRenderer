//
// Created by Alexander Ivanets on 09.04.2022.
//

#ifndef HIRENDER_VEC3_H
#define HIRENDER_VEC3_H


class Vec3 {
    float x;
    float y;
    float z;

public:
    Vec3(float x, float y, float z) : x(x), y(y), z(z) {};
    Vec3 operator+(Vec3 &a){
        return *new Vec3(x+a.x,y+a.y,z+a.z);
    }
    Vec3 operator-(Vec3 &a){
        return *new Vec3(x-a.x, y-a.y,z-a.z);
    }
    Vec3 operator*(Vec3 &a){
        return *new Vec3(x*a.x, y*a.y, z*a.z);
    }
    void rotate(double, double, double );
    bool operator==(Vec3);
    void operator=(Vec3);

    float getX() const;
    float getY() const;
    float getZ() const;
};


#endif //HIRENDER_VEC3_H
