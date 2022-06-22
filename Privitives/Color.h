//
// Created by Alexander Ivanets on 22.05.2022.
//

#ifndef HIRENDER_COLOR_H
#define HIRENDER_COLOR_H


class Color {
    short r_;
    short g_;
    short b_;

public:
    Color();
    Color(short, short, short);
    short getR() const;
    short getG() const;
    short getB() const;
    Color operator*(double c) const;
};


#endif //HIRENDER_COLOR_H
