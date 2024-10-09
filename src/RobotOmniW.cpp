#include "RobotOmniW.h"


void RobotOmniW::configure(MotorControllerConfig motor_config) {
  this->motor_controller.configure(motor_config);
}

void RobotOmniW::moveByXY(byte value_x, byte value_y) {
  int s_y = value_y >= VALUE_Y_0 ? value_y - VALUE_Y_0 : value_y;
  int s_x = value_x >= VALUE_X_0 ? value_x - VALUE_X_0 : value_x;
  int speed = s_y + s_x;

  if(value_x == VALUE_X_0 && value_y == VALUE_Y_0)
    motor_controller.brake();
  else if(value_x == VALUE_X_0 && value_y > VALUE_Y_0)
    motor_controller.forward(speed);
  else if(value_x == VALUE_X_0 && value_y < VALUE_Y_0)
    motor_controller.backward(speed);
  else if(value_x < VALUE_X_0 && value_y == VALUE_Y_0)
    motor_controller.left(speed);
  else if(value_x > VALUE_X_0 && value_y == VALUE_Y_0)
    motor_controller.right(speed);
  else if(value_x < VALUE_X_0 && value_y < VALUE_Y_0)
    motor_controller.forwardLeft(speed);
  else if(value_x > VALUE_X_0 && value_y < VALUE_Y_0)
    motor_controller.forwardRight(speed);
  else if(value_x < VALUE_X_0 && value_y > VALUE_Y_0)
    motor_controller.backwardLeft(speed);
  else if(value_x > VALUE_X_0 && value_y > VALUE_Y_0)
    motor_controller.backwardRight(speed);
}
