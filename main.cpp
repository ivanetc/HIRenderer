#pragma once
#include "Scene/Scene.h"
#include "Privitives/3D/Sphere.h"
#include "Privitives/Lights/PointLight.h"
#include "Renderer/Renderer.h"
#include "Renderer/JpegSaver.h"


int main() {
    Scene scene = Scene();
    auto sphereMaterial = Material(Color(150, 0, 24));
    auto sphereMaterial2 = Material(Color(200, 204, 100));
    auto * sphere = new Sphere(Point(-1, 0, -2.5), sphereMaterial, 0.6);
    auto * sphere2 = new Sphere(Point(1, 0, -2.5), sphereMaterial2, 0.8);
    auto * light = new PointLight(Point(-2, 4, 2), Color(255, 255, 255), 200);
    scene.add(light);
    scene.add(sphere);
    scene.add(sphere2);

    auto camera = Camera(Point(), 16.0/9, 1280, 0.1);
    auto pixels = Renderer::Render(scene, camera);

    JpegSaver::save(pixels, "test.jpg");

    delete sphere;
    delete sphere2;
    delete light;
}