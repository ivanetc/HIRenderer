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
    Vec3() : x_(0), y_(0), z_(0) {};
    Vec3(float d);
    Vec3(float x, float y, float z) : x_(x), y_(y), z_(z) {};
    Vec3 operator+(Vec3 &a) const;
    Vec3 operator-(Vec3 a) const;
    Vec3 operator*(Vec3 a) const;
    Vec3 operator*(float t) const;
    Vec3 operator/(float i) const;
    Vec3 operator-() const;
    bool operator==(Vec3 a) const;
    Vec3& operator=(Vec3 a);
    float getX() const;
    float getY() const;
    float getZ() const;
    static float dot(const Vec3 &u, const Vec3 &v);
    double length() const;
    Vec3 rotate(float angleX, float angleY, float angleZ);
};

Vec3 operator*(int i, const Vec3& n);
Vec3 operator*(float i, const Vec3& n);

#endif //HIRENDER_VEC3_H
