//
// Created by Egor on 22.06.2022.
//

#include "JpegSaver.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

void JpegSaver::save(std::vector<std::vector<Color>> colors, const std::string &fileName) {
    int image_width = colors.at(0).size();
    int image_height = colors.size();

    // Render
    auto *pixels = new uint8_t[image_width * image_height * 3];
    int index = 0;
    for (int j = image_height - 1; j >= 0; --j) {
        for (int i = 0; i < image_width; ++i) {
            Color color = colors.at(j).at(i);
            pixels[index++] = color.getR();
            pixels[index++] = color.getG();
            pixels[index++] = color.getB();

        }
    }
    stbi_write_jpg(fileName.c_str(), image_width, image_height, 3, pixels, 100);
}
