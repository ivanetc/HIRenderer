//
// Created by Alexander Ivanets on 22.05.2022.
//

#include "Color.h"

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
    if (c > 1 || c < 0) {
        return *this;
    }

    return {static_cast<short>(this->r_ * c), static_cast<short>(this->g_ * c), static_cast<short>(this->b_ * c)};
}
