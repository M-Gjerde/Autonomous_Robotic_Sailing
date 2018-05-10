#include "RudderSailControl.h"
#include <Sailboat.h>

RudderSail::RudderSail(){
  
}

void RudderSail::init() {
  
}

void RudderSail::Control(const geometry_msgs::Twist& cmd) {
  Sailboat::Instance()->getRudder()->applyCommand(cmd.angular.x);
  Sailboat::Instance()->getSail()->applyCommand(cmd.angular.y);
#ifdef ACTUATOR_RUDDER2
  Sailboat::Instance()->getRudder2()->applyCommand(cmd.angular.z);
#endif
}
