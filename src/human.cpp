#include "humangl.h"

Human::Human() {
    head.setColour(glm::vec3(0.93f, 0.91f, 0.82f));
    torso.setColour(glm::vec3(0.0f, 1.0f, 0.0f));
    
    // leftUpperArm.setColour(glm::vec3(0.93f, 0.91f, 0.82f));
    // leftLowerArm.setColour(glm::vec3(0.93f, 0.91f, 0.82f));
    // rightUpperArm.setColour(glm::vec3(0.93f, 0.91f, 0.82f));
    // rightLowerArm.setColour(glm::vec3(0.93f, 0.91f, 0.82f));

    // leftUpperLeg.setColour(glm::vec3(0.0f, 0.0f, 1.0f));
    // leftLowerLeg.setColour(glm::vec3(0.0f, 0.0f, 1.0f));
    // rightUpperLeg.setColour(glm::vec3(0.0f, 0.0f, 1.0f));
    // rightLowerLeg.setColour(glm::vec3(0.0f, 0.0f, 1.0f));

    glm::vec4 headAnchorPoint = glm::vec4(0.0f, 0.5f, 0.0f, 1.0f);

    torso.translate(glm::vec3(0, -0.25, 0));
    torso.rotate(glm::vec3(0.1, 0.1, 0.5));
    torso.scale(glm::vec3(0.25f, 0.50f, 0.25f));
    torso.updateModel();
    
    headAnchorPoint = torso._model * headAnchorPoint;
    glm::vec3 headUpVector = glm::normalize(glm::vec3(torso._model * glm::vec4(0, 1, 0, 0)));
    
    head.translate(glm::vec3(headAnchorPoint) + headUpVector * 0.125f);
    head.scale(glm::vec3(0.25, 0.25, 0.25));
    head.rotate(torso._rotation);
    head.updateModel();

}

void Human::upload() {
    head.upload();
    torso.upload();

    // leftUpperArm.upload();
    // leftLowerArm.upload();
    // rightUpperArm.upload();
    // rightLowerArm.upload();

    // leftUpperLeg.upload();
    // leftLowerLeg.upload();
    // rightUpperLeg.upload();
    // rightLowerLeg.upload();
}

void Human::draw() {
    head.draw();
    torso.draw();

    // leftUpperArm.draw();
    // leftLowerArm.draw();
    // rightUpperArm.draw();
    // rightLowerArm.draw();

    // leftUpperLeg.draw();
    // leftLowerLeg.draw();
    // rightUpperLeg.draw();
    // rightLowerLeg.draw();
}

