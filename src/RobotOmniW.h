#ifndef ROBOTOMINIW_H
#define ROBOTOMINIW_H

#include <Arduino.h>
#include <MotorController.h>


const int VALUE_X_0 = 128;
const int VALUE_Y_0 = 128;

class RobotOmniW {
public:
    RobotOmniW() : enabled(false) {};

    void configure(MotorControllerConfig motor_config);
    void moveByXY(byte value_x, byte value_y);
    void setEnabled() {
        this->enabled = true;
        this->motor_controller.setEnabled();
    };
    void setDisabled() {
        this->enabled = false;
        this->motor_controller.setDisabled();
    };
    bool isEnabled() {
        return this->enabled;
    };

private:
    bool enabled;
    MotorController motor_controller;
};

#endif // ROBOTOMINIW_H