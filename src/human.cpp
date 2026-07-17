#include "humangl.h"

Human::Human() 
: _movement(Movement::None),
  _movementStage(0), _movementStep(0)
{
    torso.setColour(glm::vec3(0.0f, 1.0f, 0.0f))
         .rotate(glm::vec3(0.2f, 0.0f, 0.0f))
         .scale(glm::vec3(0.25f, 0.50f, 0.125f))
         .updateModel();

    head.setColour(glm::vec3(0.93f, 0.91f, 0.82f))
        .scale(glm::vec3(0.25f, 0.25f, 0.25f))
        .attachTo(torso, glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f))
        .updateModel();

    leftUpperArm.setColour(glm::vec3(0.0f, 1.0f, 0.0f))
                .scale(glm::vec3(0.25f, 0.125f, 0.125f))
                .rotate(glm::vec3(0.0f, 0.0f, glm::radians(90.0f)) + LIMB_BASE_ROTATION)
                .attachTo(torso, glm::vec3(-0.5f, 0.375f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f))
                .updateModel();

    leftLowerArm.setColour(glm::vec3(0.93f, 0.91f, 0.82f))
                .scale(glm::vec3(0.25f, 0.125f, 0.125f))
                .rotate(glm::vec3(0.0f, 0.5f, 0.0f))
                .attachTo(leftUpperArm, glm::vec3(-0.5f, 0.0f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f))
                .updateModel();

    rightUpperArm.setColour(glm::vec3(0.0f, 1.0f, 0.0f))
                 .scale(glm::vec3(0.25f, 0.125f, 0.125f))
                 .rotate(glm::vec3(0.0f, 0.0f, glm::radians(-90.0f)) - LIMB_BASE_ROTATION)
                 .attachTo(torso, glm::vec3(0.5f, 0.375f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f))
                 .updateModel();

    rightLowerArm.setColour(glm::vec3(0.93f, 0.91f, 0.82f))
                 .scale(glm::vec3(0.25f, 0.125f, 0.125f))
                 .rotate(glm::vec3(0.0f, -0.5f, 0.0f))
                 .attachTo(rightUpperArm, glm::vec3(0.5f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f))
                 .updateModel();

    leftUpperLeg.setColour(glm::vec3(0.0f, 0.3f, 1.0f))
                .scale(glm::vec3(0.125f, 0.25f, 0.125f))
                .rotate(LIMB_BASE_ROTATION)
                .attachTo(torso, glm::vec3(0.25, -0.5f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f))
                .updateModel();

    leftLowerLeg.setColour(glm::vec3(0.93f, 0.91f, 0.82f))
                .scale(glm::vec3(0.125f, 0.25f, 0.125f))
                .rotate(glm::vec3(0.25f, 0.0f, 0.0f))
                .attachTo(leftUpperLeg, glm::vec3(0.0f, -0.5f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f))
                .updateModel();

    rightUpperLeg.setColour(glm::vec3(0.0f, 0.3f, 1.0f))
                 .scale(glm::vec3(0.125f, 0.25f, 0.125f))
                 .rotate(-LIMB_BASE_ROTATION)
                 .attachTo(torso, glm::vec3(-0.25, -0.5f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f))
                 .updateModel();

    rightLowerLeg.setColour(glm::vec3(0.93f, 0.91f, 0.82f))
                 .scale(glm::vec3(0.125f, 0.25f, 0.125f))
                 .rotate(glm::vec3(0.25f, 0.0f, 0.0f))
                 .attachTo(rightUpperLeg, glm::vec3(0.0f, -0.5f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f))
                 .updateModel();

    eyeLeft.setColour(glm::vec3(0.0f, 0.0f, 0.0f))
        .scale(glm::vec3(0.0625f, 0.03125f, 0.03125f))
        .attachTo(head, glm::vec3(0.25f, 0.25f, 0.5f), glm::vec3(0.0f, 0.0f, 1.0f))
        .updateModel();

    eyeRight.setColour(glm::vec3(0.0f, 0.0f, 0.0f))
        .scale(glm::vec3(0.0625f, 0.03125f, 0.03125f))
        .attachTo(head, glm::vec3(-0.25f, 0.25f, 0.5f), glm::vec3(0.0f, 0.0f, 1.0f))
        .updateModel();

    nose.setColour(glm::vec3(0.6f, 0.3f, 0.0f))
        .scale(glm::vec3(0.0625f, 0.0833f, 0.03125f))
        .attachTo(head, glm::vec3(0.0f, -0.125f, 0.5f), glm::vec3(0.0f, 0.0f, 1.0f))
        .updateModel();
}

void Human::upload() {
    torso.upload();
    head.upload();

    leftUpperArm.upload();
    leftLowerArm.upload();
    rightUpperArm.upload();
    rightLowerArm.upload();

    leftUpperLeg.upload();
    leftLowerLeg.upload();
    rightUpperLeg.upload();
    rightLowerLeg.upload();

    eyeLeft.upload();
    eyeRight.upload();
    nose.upload();
}

void Human::draw() {
    torso.draw();
    head.draw();

    leftUpperArm.draw();
    leftLowerArm.draw();
    rightUpperArm.draw();
    rightLowerArm.draw();

    leftUpperLeg.draw();
    leftLowerLeg.draw();
    rightUpperLeg.draw();
    rightLowerLeg.draw();

    eyeLeft.draw();
    eyeRight.draw();
    nose.draw();
}

void Human::updateModel() {
    torso.updateModel();
    head.updateModel();
    leftUpperArm.updateModel();
    leftLowerArm.updateModel();
    rightUpperArm.updateModel();
    rightLowerArm.updateModel();
    leftUpperLeg.updateModel();
    leftLowerLeg.updateModel();
    rightUpperLeg.updateModel();
    rightLowerLeg.updateModel();
    eyeLeft.updateModel();
    eyeRight.updateModel();
    nose.updateModel();
}

void Human::rotate() {
    torso.rotate(glm::vec3(0.0f, 0.00125f, 0.0f));
}

void Human::jump() {
    if (_movement != Movement::Jump) {
        return;
    }
    
    float heightMax = 0.25f;
    float angularSpeed = glm::pi<float>();   // 0.5 cycle per second
    
    float elapsedSeconds = std::chrono::duration<float>(
        std::chrono::steady_clock::now() - _movementStartTime
    ).count();
    
    float height = heightMax * std::sin(angularSpeed * elapsedSeconds);

    torso.setTranslation(glm::vec3(0.0f, height, 0.0f));

    if (elapsedSeconds >= 1.0f) {
        _movement = Movement::None;
    }
}

void Human::walk() {
    if (_movement != Movement::Walk) {
        return;
    }
    
    float angleMax = glm::radians(45.0f);
    float angularSpeed = 2.0f * glm::pi<float>();   // 1 cycle per second
    
    float elapsedSeconds = std::chrono::duration<float>(
        std::chrono::steady_clock::now() - _movementStartTime
    ).count();
    
    float angle = angleMax * std::sin(angularSpeed * elapsedSeconds);

    leftUpperArm.setRotation(glm::vec3(angle, 0.0f, glm::radians(90.0f)) + LIMB_BASE_ROTATION);
    rightUpperArm.setRotation(glm::vec3(-angle, 0.0f, glm::radians(-90.0f)) - LIMB_BASE_ROTATION);
    leftUpperLeg.setRotation(glm::vec3(angle, 0.0f, 0.0f) + LIMB_BASE_ROTATION);
    rightUpperLeg.setRotation(glm::vec3(-angle, 0.0f, 0.0f) - LIMB_BASE_ROTATION);

    if (elapsedSeconds >= 1.0f) {
        _movement = Movement::None;
    }
}

void Human::handleJump() {    
    if (_movement != Movement::None) {
        return;
    }
    _movement = Movement::Jump;
    _movementStartTime = std::chrono::steady_clock::now();
}

void Human::handleWalk() {
    if (_movement != Movement::None) {
        return;
    }
    _movement = Movement::Walk;
    _movementStartTime = std::chrono::steady_clock::now();
}
