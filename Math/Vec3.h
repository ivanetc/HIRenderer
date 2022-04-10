//
// Created by Alexander Ivanets on 09.04.2022.
//

#ifndef HIRENDER_VEC3_H
#define HIRENDER_VEC3_H

// make getter for x, y, z
class Vec3 {
    float x;
    float y;
    float z;

public:
    Vec3(float x, float y, float z) : x(x), y(y), z(z) {};
    Vec3 operator+(Vec3 &a) const;
    Vec3 operator-(Vec3 &a) const;
    Vec3 operator*(Vec3 &a) const;
    Vec3 operator-() const;
    bool operator==(Vec3 a) const;
    Vec3& operator=(Vec3 a);
};


#endif //HIRENDER_VEC3_H
