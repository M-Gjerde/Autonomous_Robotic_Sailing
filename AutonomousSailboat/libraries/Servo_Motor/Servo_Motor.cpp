#include <Servo_Motor.h>

void Servo_Motor::init(ros::NodeHandle* n){
	motorSetup();

	// Set the rudder at the Neutral position
	motorWrite(pwmNeutral);

	ActuatorROS::init(n);

}

void Servo_Motor::applyCommand(double command){
/*
	Serial.print("Command before: ");
	Serial.println(command);
*/
	unsigned int commandExact = pwmNeutral;

    if(command > anglemax)
        command = anglemax;
    if(command < anglemin)
        command = anglemin;

	// Generates the exact command:
	commandExact = mapf(command, anglemin, anglemax, pwmMin, pwmMax);
//	Logger::Log(0, F("MotorCommandExact"), String(commandExact));

	// Set the servo at the wanted position:
	
	motorWrite(commandExact);
        
	lastPwm = command*DEG_TO_RAD;

	Serial.print(commandExact);
	Serial.print(" = mapf(");
	Serial.print(command);
	Serial.print(", ");
	Serial.print(anglemax);
	Serial.print(", ");
	Serial.print(anglemin);
	Serial.print(", ");
	Serial.print(pwmMin);
	Serial.print(", ");
	Serial.print(pwmMax);
	Serial.print(");");
/*
	Serial.print("DEG_TO_RAD: ");
	Serial.println(DEG_TO_RAD);
	Serial.print("What it writes to the servo: ");
	Serial.println(commandExact);
*/
/*
	Serial.print("command (in degrees): ");
	Serial.println(command);
	Serial.print("lastPwm (In radians): ");
	Serial.println(lastPwm);
*/
	Serial.println("____________________________________");
	}

void Servo_Motor::communicateData(){
	msg.data = lastPwm;
	pub.publish(&msg);
}
