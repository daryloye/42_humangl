#include "humangl.h"

Human::Human() {
    head.setColour(glm::vec3(0.93f, 0.91f, 0.82f));
    torso.setColour(glm::vec3(0.0f, 1.0f, 0.0f));
    
    leftUpperArm.setColour(glm::vec3(0.93f, 0.91f, 0.82f));
    leftLowerArm.setColour(glm::vec3(0.93f, 0.91f, 0.82f));
    rightUpperArm.setColour(glm::vec3(0.93f, 0.91f, 0.82f));
    rightLowerArm.setColour(glm::vec3(0.93f, 0.91f, 0.82f));

    leftUpperLeg.setColour(glm::vec3(0.0f, 0.0f, 1.0f));
    leftLowerLeg.setColour(glm::vec3(0.0f, 0.0f, 1.0f));
    rightUpperLeg.setColour(glm::vec3(0.0f, 0.0f, 1.0f));
    rightLowerLeg.setColour(glm::vec3(0.0f, 0.0f, 1.0f));


    head.translate(glm::vec3(0.0f, 0.375f, 0.0f));
    head.scale(glm::vec3(0.25f, 0.25f, 0.25f));

    torso.scale(glm::vec3(0.25f, 0.50f, 0.25f));

    // Arms
    leftUpperArm.translate(glm::vec3(-0.1875f, 0.125f, 0.0f));
    leftUpperArm.scale(glm::vec3(0.125f, 0.25f, 0.25f));
    
    leftLowerArm.translate(glm::vec3(-0.1875f, -0.125f, 0.0f));
    leftLowerArm.scale(glm::vec3(0.125f, 0.25f, 0.25f));
    
    rightUpperArm.translate(glm::vec3(0.1875f, 0.125f, 0.25f));
    rightUpperArm.scale(glm::vec3(0.125f, 0.25f, 0.25f));

    rightLowerArm.translate(glm::vec3(0.1875f, -0.125f, 0.25f));
    rightLowerArm.scale(glm::vec3(0.125f, 0.25f, 0.25f));

    // Legs
    leftUpperLeg.translate(glm::vec3(-0.0625f, -0.375f, 0.25f));
    leftUpperLeg.scale(glm::vec3(0.125f, 0.25f, 0.25f));

    leftLowerLeg.translate(glm::vec3(-0.0625f, -0.625f, 0.25f));
    leftLowerLeg.scale(glm::vec3(0.125f, 0.25f, 0.25f));
    
    rightUpperLeg.translate(glm::vec3(0.0625f, -0.375f, 0.25f));
    rightUpperLeg.scale(glm::vec3(0.125f, 0.25f, 0.25f));
    
    rightLowerLeg.translate(glm::vec3(0.0625f, -0.625f, 0.25f));
    rightLowerLeg.scale(glm::vec3(0.125f, 0.25f, 0.25f));
}

void Human::upload() {
    head.upload();
    torso.upload();

    leftUpperArm.upload();
    leftLowerArm.upload();
    rightUpperArm.upload();
    rightLowerArm.upload();

    leftUpperLeg.upload();
    leftLowerLeg.upload();
    rightUpperLeg.upload();
    rightLowerLeg.upload();
}

void Human::draw() {
    head.draw();
    torso.draw();

    leftUpperArm.draw();
    leftLowerArm.draw();
    rightUpperArm.draw();
    rightLowerArm.draw();

    leftUpperLeg.draw();
    leftLowerLeg.draw();
    rightUpperLeg.draw();
    rightLowerLeg.draw();
}