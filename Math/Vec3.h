//
// Created by Alexander Ivanets on 09.04.2022.
//

#ifndef HIRENDER_VEC3_H
#define HIRENDER_VEC3_H


class Vec3 {
    float x_;
    float y_;
    float z_;


public:
    Vec3(float x, float y, float z) : x_(x), y_(y), z_(z) {};
    Vec3 operator+(Vec3 &a) const;
    Vec3 operator-(Vec3 &a) const;
    Vec3 operator*(Vec3 &a) const;
    Vec3 operator-() const;
    bool operator==(Vec3 a) const;
    Vec3& operator=(Vec3 a);
    float getX() const;
    float getY() const;
    float getZ() const;

};


#endif //HIRENDER_VEC3_H