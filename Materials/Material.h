//
// Created by Alexander Ivanets on 09.04.2022.
//

#ifndef HIRENDER_MATERIAL_H
#define HIRENDER_MATERIAL_H


#include "../Privitives/Color.h"

class Material {
    Color color_;

public:
    Material();
    Material(Color);
    Color getColor() const;

};


#endif //HIRENDER_MATERIAL_H
