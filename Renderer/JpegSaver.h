//
// Created by Egor on 22.06.2022.
//
#pragma once
#include <iostream>
#include <vector>
#include "../Materials/Color.h"

class JpegSaver{

public:
    static void save(std::vector<std::vector<Color>> colors, const std::string& fileName);
};
