#include "humangl.h"

Human::Human() {
    torso.setColour(glm::vec3(0.0f, 1.0f, 0.0f))
         .scale(glm::vec3(0.25f, 0.50f, 0.25f))
        //  .translate(glm::vec3(0.0f, -0.25f, 0.0f))
        //  .rotate(glm::vec3(0.1f, 0.1f, 0.5f))
         .updateModel();

    head.setColour(glm::vec3(0.93f, 0.91f, 0.82f))
        .scale(glm::vec3(0.25f, 0.25f, 0.25f))
        .attachTo(torso, glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f))
        .updateModel();

    leftUpperArm.setColour(glm::vec3(0.93f, 0.91f, 0.82f))
                .scale(glm::vec3(0.25f, 0.125f, 0.125f))
                .attachTo(torso, glm::vec3(-0.5f, 0.375f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f))
                // .rotate(glm::vec3(0.0f, 0.0f, glm::radians(-90.0f)))
                .updateModel();

    leftLowerArm.setColour(glm::vec3(1.0f, 0.0f, 1.0f))
                .scale(glm::vec3(0.25f, 0.125f, 0.125f))
                .attachTo(leftUpperArm, glm::vec3(-0.5f, 0.0f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f))
                .updateModel();

    rightUpperArm.setColour(glm::vec3(0.93f, 0.91f, 0.82f))
                 .scale(glm::vec3(0.25f, 0.125f, 0.125f))
                 .attachTo(torso, glm::vec3(0.5f, 0.375f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f))
                 .updateModel();

    rightLowerArm.setColour(glm::vec3(1.0f, 0.0f, 1.0f))
                 .scale(glm::vec3(0.25f, 0.125f, 0.125f))
                 .attachTo(rightUpperArm, glm::vec3(0.5f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f))
                 .updateModel();

    leftUpperLeg.setColour(glm::vec3(0.0f, 0.0f, 1.0f))
                .scale(glm::vec3(0.125f, 0.25f, 0.25f))
                .attachTo(torso, glm::vec3(0.25, -0.5f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f))
                .updateModel();

    leftLowerLeg.setColour(glm::vec3(0.0f, 1.0f, 1.0f))
                .scale(glm::vec3(0.125f, 0.25f, 0.25f))
                .attachTo(leftUpperLeg, glm::vec3(0.0f, -0.5f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f))
                .updateModel();

    rightUpperLeg.setColour(glm::vec3(0.0f, 0.0f, 1.0f))
                 .scale(glm::vec3(0.125f, 0.25f, 0.25f))
                 .attachTo(torso, glm::vec3(-0.25, -0.5f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f))
                 .updateModel();

    rightLowerLeg.setColour(glm::vec3(0.0f, 1.0f, 1.0f))
                 .scale(glm::vec3(0.125f, 0.25f, 0.25f))
                 .attachTo(rightUpperLeg, glm::vec3(0.0f, -0.5f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f))
                 .updateModel();
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
