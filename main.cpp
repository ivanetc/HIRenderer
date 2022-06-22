#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#define CHANNEL_NUM 3

int main() {

    // Image

    const int image_width = 800;
    const int image_height = 600;

    // Render
    auto* pixels = new uint8_t[image_width * image_height * CHANNEL_NUM];
    int index = 0;
    for (int j = image_height-1; j >= 0; --j) {
        for (int i = 0; i < image_width; ++i) {
            auto r = double(i) / (image_width-1);
            auto g = double(j) / (image_height-1);
            auto b = 0.25;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            pixels[index++] = ir;
            pixels[index++] = ig;
            pixels[index++] = ib;

           // std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
    stbi_write_jpg("stbjpg3.jpg", image_width, image_height, 3, pixels, 100);
}