//
// Created by Alexander Ivanets on 09.04.2022.
//

#include <cmath>
#include "Vec3.h"

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
    return u.x_ * v.x_ + u.y_ * v.y_ + u.z_ + v.z_;
}

Vec3 Vec3::operator*(float t) const {
    return {this->x_*t, this->y_*t, this->z_*t};
}

double Vec3::length() const {
    return sqrt(pow(this->x_, 2) + pow(this->y_, 2) + pow(this->z_, 2));
}

Vec3 operator*(float i, const Vec3& n) {
    return {i * n.getX(), i * n.getY(), i * n.getZ()};
}

Vec3 operator*(int i, const Vec3& n) {
    return (float) i * n;
}

double Vec3::length() const {
    return sqrt(pow(this->x_, 2) + pow(this->y_, 2) + pow(this->z_, 2));
}

