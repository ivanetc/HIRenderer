//
// Created by Alexander Ivanets on 22.05.2022.
//

#include "Color.h"
#include <algorithm>

Color::Color(short r, short g, short b) : r_(r), g_(g), b_(b) {}

short Color::getR() const {
    return r_;
}

short Color::getG() const {
    return g_;
}

short Color::getB() const {
    return b_;
}

Color::Color() : r_(0), g_(0), b_(0) {}

Color Color::operator*(double c) const {
    if (c < 0) {
        return {0, 0, 0};
    }

    return {static_cast<short>(std::min(this->r_ * c, 255.0)),
            static_cast<short>(std::min(this->g_ * c, 255.0)),
            static_cast<short>(std::min(this->b_ * c, 255.0))};
}

Color Color::operator+(Color other) const {
    return {static_cast<short>(this->r_ + other.r_), static_cast<short>(this->g_ + other.g_), static_cast<short>(this->b_ + other.b_)};
}

void Color::setG(char G) {
    g_ = G;
}

void Color::setR(char R) {
    r_ = R;
}

void Color::setB(char B) {
    b_ = B;
}



