//
// Created by Alexander Ivanets on 09.04.2022.
//

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



