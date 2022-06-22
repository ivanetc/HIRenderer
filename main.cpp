#pragma once
#include "Scene/Scene.h"
#include "Privitives/3D/Sphere.h"
#include "Privitives/Lights/PointLight.h"
#include "Renderer/Renderer.h"
#include "Renderer/JpegSaver.h"


int main() {
    Scene scene = Scene();
    auto sphereMaterial = Material(Color(50, 20, 180));
    auto * sphere = new Sphere(Point(-10, 0, 0), sphereMaterial, 3);
    auto * light = new PointLight(Point(-3, -3, 0), Color(255, 255, 255), 300);
    scene.add(light);
    scene.add(sphere);

    auto camera = Camera(Point(), 16.0/9, 1280, 1);
    auto pixels = Renderer::Render(scene, camera);

    JpegSaver::save(pixels, "test.jpg");

    delete sphere;
    delete light;
}