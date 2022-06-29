#pragma once
#include "Scene/Scene.h"
#include "Privitives/3D/Sphere.h"
#include "Privitives/2D/Plane.h"
#include "Privitives/Lights/PointLight.h"
#include "Renderer/Renderer.h"
#include "Renderer/JpegSaver.h"
#include "Privitives/2D/Rectangle.h"
#include "Privitives/3D/Box.h"


int main() {
    Scene scene = Scene();
    auto sphereMaterial = Material(Color(150, 0, 24));
    auto sphereMaterial2 = Material(Color(200, 204, 100));
    auto sphereMaterial3 = Material(Color(200, 0, 0));
    auto rectMaterial = Material(Color(0, 200, 30));

    auto planeMaterial = Material(Color(200, 230, 201));
    auto * sphere = new Sphere(Point(-1, 0, -3.5), sphereMaterial, 0.6);
    auto * sphere2 = new Sphere(Point(1, 0, -3.5), sphereMaterial2, 0.8);
    auto * plane = new Plane(Point(0, -2, -4), Vec3(0, 1, 0), planeMaterial);
    auto * plane2 = new Plane(Point(0, 2, 4), Vec3(0, -1, 0), sphereMaterial3);

//    auto * rectangle = new Rectangle(Point(0, 0, -3), Vec3(0, 0, 1), rectMaterial, 0.5, 0.5);
    auto * box = new Box(Point(0, -1, -3), Vec3(1, 0, 1), rectMaterial, 0.5);

    auto * light = new PointLight(Point(-5, 0, 1.5), Color(255, 255, 255), 620);
    scene.add(light);
    scene.add(plane);
    scene.add(plane2);
    scene.add(sphere);
    scene.add(sphere2);
//    scene.add(rectangle);
    scene.add(box);


    auto camera = Camera(Point(), 16.0/9, 1280, 0.1);
    auto pixels = Renderer::Render(scene, camera);

    JpegSaver::save(pixels, "test.jpg");

    delete sphere;
    delete sphere2;
    delete light;
    delete plane;
    delete plane2;
//    delete rectangle;
    delete box;
}