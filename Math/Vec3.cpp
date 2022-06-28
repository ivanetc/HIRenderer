//
// Created by Alexander Ivanets on 09.04.2022.
//

#include <cmath>
#include "Vec3.h"

float toRadians(float degrees) {
    return degrees * M_PI / 180.0;
}

Vec3 Vec3::operator+(Vec3 &a) const {
    return {x_ + a.x_, y_ + a.y_, z_ + a.z_};
}

Vec3 Vec3::operator-(Vec3 a) const {
    return {x_ - a.x_, y_ - a.y_, z_ - a.z_};
}

Vec3 Vec3::operator*(Vec3 a) const {
    return {x_ * a.x_, y_ * a.y_, z_ * a.z_};
}

Vec3 Vec3::operator-() const{
    return {-x_, -y_, -z_};
}

Vec3 Vec3::operator/(float i) const {
    return {x_/i, y_ / i, x_ / i};
}

bool Vec3::operator==(Vec3 a) const {
    return x_ == a.x_ && y_ == a.y_ && z_ == a.z_;
}

Vec3& Vec3::operator=(Vec3 a){
    x_=a.x_;
    y_=a.y_;
    z_=a.z_;
    return *this;
}

float Vec3::getX() const {
    return this->x_;
}

float Vec3::getY() const {
    return this->y_;
}

float Vec3::getZ() const {
    return this->z_;
}

float Vec3::dot(const Vec3 &u, const Vec3 &v) {
    return u.x_ * v.x_ + u.y_ * v.y_ + u.z_ * v.z_;
}

Vec3 Vec3::operator*(float t) const {
    return {this->x_ * t, this->y_ * t, this->z_ * t};
}

double Vec3::length() const {
    return sqrt(pow(this->x_, 2) + pow(this->y_, 2) + pow(this->z_, 2));
}

Vec3 Vec3::rotate(float angleX, float angleY, float angleZ) const {
    angleX = toRadians(angleX);
    angleY = toRadians(angleY);
    angleZ = toRadians(angleZ);

    auto rotatedVector1 = Vec3(x_, y_, z_);
    rotatedVector1.y_ = y_ * cos(angleX) + z_ * sin(angleX);
    rotatedVector1.z_ = -y_ * sin(angleX) + z_ * cos(angleX);

    auto rotatedVector2 = Vec3(rotatedVector1);
    rotatedVector2.x_ = rotatedVector1.x_ * cos(angleY) + rotatedVector1.x_ * sin(angleY);
    rotatedVector2.z_ = -rotatedVector1.x_ * sin(angleY) + rotatedVector1.z_ * cos(angleY);

    auto rotatedVector3 = Vec3(rotatedVector2);
    rotatedVector3.x_ = rotatedVector2.x_ * cos(angleZ) - rotatedVector2.y_ * sin(angleZ);
    rotatedVector3.y_ = rotatedVector2.x_ * sin(angleZ) + rotatedVector2.y_ * cos(angleZ);

    return rotatedVector3;
}

Vec3 Vec3::operator*(int t) const {
    return * this * (float )t;
}

Vec3 Vec3::operator*(double t) const {
    return * this * (float )t;
}

Vec3 operator*(float i, const Vec3& n) {
    return {i * n.getX(), i * n.getY(), i * n.getZ()};
}

Vec3 operator*(int i, const Vec3& n) {
    return (float) i * n;
}

