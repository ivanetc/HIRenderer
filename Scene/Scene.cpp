//
// Created by Alexander Ivanets on 10.04.2022.
//

#include "Scene.h"

Scene::Scene() {
    primitives_ = std::vector<Primitive>();
    lights_ = std::vector<Light>();
}

std::vector<Primitive> *Scene::getPrimitives() {
    return  & primitives_;
}

Camera *Scene::getCamera() {
    return & camera_;
}

std::vector<Light> *Scene::getLights() {
    return & lights_;
}

void Scene::setCamera(Camera camera) {
    camera_ = camera;
}

void Scene::add(const Primitive& primitive) {
    this->primitives_.push_back(primitive);

}

void Scene::add(const Light & light) {
    this->lights_.push_back(light)
}
