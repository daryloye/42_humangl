#include "humangl.h"

Human::Human() 
: _movement(Movement::None),
  _movementStage(0), _movementStep(0)
{
    torso.setColour(glm::vec3(0.0f, 1.0f, 0.0f))
         .rotate(glm::vec3(0.1f, 0.0f, 0.0f))
         .scale(glm::vec3(0.25f, 0.50f, 0.125f))
         .updateModel();

    head.setColour(glm::vec3(0.93f, 0.91f, 0.82f))
        .scale(glm::vec3(0.25f, 0.25f, 0.25f))
        .attachTo(torso, glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f))
        .updateModel();

    leftUpperArm.setColour(glm::vec3(0.93f, 0.91f, 0.82f))
                .scale(glm::vec3(0.25f, 0.125f, 0.125f))
                .attachTo(torso, glm::vec3(-0.5f, 0.375f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f))
                // .rotate(glm::vec3(0.0f, 0.0f, glm::radians(90.0f)))
                .updateModel();

    leftLowerArm.setColour(glm::vec3(1.0f, 0.0f, 1.0f))
                .scale(glm::vec3(0.25f, 0.125f, 0.125f))
                .attachTo(leftUpperArm, glm::vec3(-0.5f, 0.0f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f))
                .updateModel();

    rightUpperArm.setColour(glm::vec3(0.93f, 0.91f, 0.82f))
                 .scale(glm::vec3(0.25f, 0.125f, 0.125f))
                 .attachTo(torso, glm::vec3(0.5f, 0.375f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f))
                // .rotate(glm::vec3(0.0f, 0.0f, glm::radians(-90.0f)))
                 .updateModel();

    rightLowerArm.setColour(glm::vec3(1.0f, 0.0f, 1.0f))
                 .scale(glm::vec3(0.25f, 0.125f, 0.125f))
                 .attachTo(rightUpperArm, glm::vec3(0.5f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f))
                 .updateModel();

    leftUpperLeg.setColour(glm::vec3(0.0f, 0.3f, 1.0f))
                .scale(glm::vec3(0.125f, 0.25f, 0.125f))
                .attachTo(torso, glm::vec3(0.25, -0.5f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f))
                .rotate(glm::vec3(0.25f, 0.0f, 0.0f))
                .updateModel();

    leftLowerLeg.setColour(glm::vec3(0.0f, 0.3f, 1.0f))
                .scale(glm::vec3(0.125f, 0.25f, 0.125f))
                .attachTo(leftUpperLeg, glm::vec3(0.0f, -0.5f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f))
                .updateModel();

    rightUpperLeg.setColour(glm::vec3(0.0f, 0.3f, 1.0f))
                 .scale(glm::vec3(0.125f, 0.25f, 0.125f))
                 .attachTo(torso, glm::vec3(-0.25, -0.5f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f))
                 .rotate(glm::vec3(-0.25f, 0.0f, 0.0f))
                 .updateModel();

    rightLowerLeg.setColour(glm::vec3(0.0f, 0.3f, 1.0f))
                 .scale(glm::vec3(0.125f, 0.25f, 0.125f))
                 .attachTo(rightUpperLeg, glm::vec3(0.0f, -0.5f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f))
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
}

void Human::rotate() {
    if (_movement == Movement::Jump) {
        auto elapsedTimeMs = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::steady_clock::now() - _movementStartTime
        );
        if (elapsedTimeMs.count() >= 2000) {
            _movement = Movement::None;
        } else {
            std::cout << "Jump " << elapsedTimeMs.count() << std::endl;
        }
    }

    if (_movement == Movement::Walk) {
        _movementStep++;
        if (_movementStep < 150) {
            leftUpperLeg.rotate(glm::vec3(0.01f, 0.0f, 0.0f));
            rightUpperLeg.rotate(glm::vec3(-0.01f, 0.0f, 0.0f));
        }
        else if (_movementStep < 450) {
            leftUpperLeg.rotate(glm::vec3(-0.01f, 0.0f, 0.0f));
            rightUpperLeg.rotate(glm::vec3(0.01f, 0.0f, 0.0f));
        }
        else if (_movementStep < 600) {
            leftUpperLeg.rotate(glm::vec3(0.01f, 0.0f, 0.0f));
            rightUpperLeg.rotate(glm::vec3(-0.01f, 0.0f, 0.0f));
        }
        else {
            _movementStep = 0;
            _movement = Movement::None;
        }
        std::cout<<_movementStep<<std::endl;
    }

    torso.rotate(glm::vec3(0.0f, 0.0025f, 0.0f))
         .updateModel();
    head.updateModel();
    leftUpperArm.updateModel();
    leftLowerArm.updateModel();
    rightUpperArm.updateModel();
    rightLowerArm.updateModel();
    leftUpperLeg.updateModel();
    leftLowerLeg.updateModel();
    rightUpperLeg.updateModel();
    rightLowerLeg.updateModel(); 
}

void Human::handleJump() {
    // auto startTime = std::chrono::steady_clock::now();

    // torso.translate(glm::vec3(0.0f, 0.010f, 0.0f))
    //      .updateModel();
    // head.updateModel();
    // leftUpperArm.updateModel();
    // leftLowerArm.updateModel();
    // rightUpperArm.updateModel();
    // rightLowerArm.updateModel();
    // leftUpperLeg.updateModel();
    // leftLowerLeg.updateModel();
    // rightUpperLeg.updateModel();
    // rightLowerLeg.updateModel();
    
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
