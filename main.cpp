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
    auto * sphere2 = new Sphere(Point(0, 0, -5), sphereMaterial2, 1.2);
    auto * plane = new Plane(Point(0, -2, -4), Vec3(0, 1, 0), planeMaterial);
    auto * plane2 = new Plane(Point(0, 2, 4), Vec3(0, -1, 0), sphereMaterial3);

    Vec3 axis_x = Vec3(1, 0, 0);
    Vec3 axis_y = Vec3(0, 1, 0);
    Vec3 axis_z = Vec3(0, 0, 1);

    auto * box = new Box(
            Point(1.7, -0.8, -3),
            rectMaterial,
            axis_x.rotate(0, 140, 0) * 0.7,
            axis_y.rotate(0, 0, 0) * 0.7,
            axis_z.rotate(0, 140, 0) * 0.7
    );

    auto * light = new PointLight(Point(-1, 1, 1.5), Color(255, 255, 255), 500);
    scene.add(light);
    scene.add(plane);
    scene.add(plane2);
    scene.add(sphere);
    scene.add(sphere2);
    scene.add(box);


    auto camera = Camera(Point(), 16.0/9, 1280, 0.1);
    camera.samplesPerPixel = 5;
    auto pixels = Renderer::Render(scene, camera);

    JpegSaver::save(pixels, "test.jpg");

    delete sphere;
    delete sphere2;
    delete light;
    delete plane;
    delete plane2;
    delete box;
}