//
// Created by Alexander Ivanets on 09.04.2022.
//

#include "Vec3.h"

Vec3 Vec3::operator+(Vec3 &a) const {
    return {x+a.x, y+a.y, z+a.z};
}

Vec3 Vec3::operator-(Vec3 &a) const {
    return {x-a.x, y-a.y,z-a.z};
}

Vec3 Vec3::operator*(Vec3 &a) const {
    return {x*a.x, y*a.y, z*a.z};
}

Vec3 Vec3::operator-() const{
    return {-x,-y,-z};
}

bool Vec3::operator==(Vec3 a) const {
    if(x == a.x, y == a.y, z == a.z){
        return true;
    } else{
        return false;
    }
}

Vec3& Vec3::operator=(Vec3 a){
    return *this;
}

float Vec3::getX() const {
    return this->x;
}

float Vec3::getY() const {
    return this->y;
}

float Vec3::getZ() const {
    return this->z;
}


