#include "humangl.h"

Human::Human() {
    head.setColour(glm::vec3(1.0f, 0.0f, 0.0f));
    torso.setColour(glm::vec3(0.0f, 1.0f, 0.0f));
}

void Human::upload() {
    head.upload();
    torso.upload();
}

void Human::draw() {
    head.draw();
    torso.draw();
}