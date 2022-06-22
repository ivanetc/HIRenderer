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