#include "humangl.h"

Human::Human() {
    torso.setColour(glm::vec3(0.0f, 1.0f, 0.0f))
         .scale(glm::vec3(0.25f, 0.50f, 0.25f))
         .translate(glm::vec4(0.0f, -0.25f, 0.0f, 0.0f))
         .rotate(glm::vec3(0.1, 0.1, 0.5));
    glm::mat4 torsoTransform = torso.updateModel(glm::mat4(1.0f));

    head.setColour(glm::vec3(0.93f, 0.91f, 0.82f))
        .scale(glm::vec3(0.25, 0.25, 0.25))
        .translate(glm::vec4);
    head.updateModel(torsoTransform);
    
    // leftUpperArm.setColour(glm::vec3(0.93f, 0.91f, 0.82f));
    // leftLowerArm.setColour(glm::vec3(0.93f, 0.91f, 0.82f));
    // rightUpperArm.setColour(glm::vec3(0.93f, 0.91f, 0.82f));
    // rightLowerArm.setColour(glm::vec3(0.93f, 0.91f, 0.82f));

    // leftUpperLeg.setColour(glm::vec3(0.0f, 0.0f, 1.0f));
    // leftLowerLeg.setColour(glm::vec3(0.0f, 0.0f, 1.0f));
    // rightUpperLeg.setColour(glm::vec3(0.0f, 0.0f, 1.0f));
    // rightLowerLeg.setColour(glm::vec3(0.0f, 0.0f, 1.0f));
    
    // head.translate(worldPosition)
    //     .rotate(torso._rotation);
    // head.updateModel(glm::mat4(1.0f));
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

