#include <WindSensor.h>


#define CSn 14
#define CLK 15
#define DO 16

void WindSensor::init(){
	pinMode(WIND_SENSOR_PIN, INPUT);
#ifdef WIND_ANEMOMETER_PIN
	pinMode(WIND_ANEMOMETER_PIN, INPUT);
#endif
#ifdef SAILBOAT_BOATLETTE

/*	pinMode(CSn, OUTPUT);
	pinMode(CLK, OUTPUT);
	pinMode(DO, INPUT);
	
	digitalWrite(CLK, HIGH);
	digitalWrite(CSn, HIGH);
*/
	
#endif
}
void WindSensor::updateAnemometer(){
#ifdef WIND_ANEMOMETER_PIN
	if ((millis() - contactBounceTime) > 15 ) { // debounce the switch contact.
		anemometerRevolution++;
		contactBounceTime = millis();
	}
	if(millis() - timeAnemometer > 2000){
		windSpeed = anemometerRevolution * 1.061/2.0;
		anemometerRevolution = 0;
		timeAnemometer = millis();
	}
#endif
}

void WindSensor::updateMeasures(){
//	Logger::Log(1, F("SetupWindSensor()"), F(""));  // Done in the Setup
	// Safety:
#ifdef SAILBOAT_BOATLETTE
//#define CSn 10
//#define CLK 11
//#define DO 12
         dataOut=0;

	  digitalWrite(14, LOW);
	  delayMicroseconds(1); //Waiting for Tclkfe

	  //Passing 10 times, from 0 to 9
	  for(int x=0; x<10; x++){
	    digitalWrite(15, LOW);
	    delayMicroseconds(1); //Tclk/2
	    digitalWrite(15, HIGH);
	    delayMicroseconds(1); //Tdo valid, like Tclk/2
	    dataOut = (dataOut << 1) | digitalRead(16);   //shift all the entering data to the left and past the pin state to it. 1e bit is MSB
		//dataOut ++;
	  }
	//Serial.println(dataOut);
	  digitalWrite(14, HIGH); //

	    //dataOut =   map(dataOut,0,65000,0,360);
	   // Serial.println(dataOut);
	
#else
	value1 = analogRead(WIND_SENSOR_PIN);
	value1 = 666;
#endif

	// If no value / no sensor:
	if ((value < WIND_SENSOR_MIN) || (value > WIND_SENSOR_MAX)){
		// This test might not detect if the signal wire is not linked but if it is activated,
		//   there is 100% chances that it's true !
		//Logger::Warning(F("WindAngle"), F("No Wind Sensor/Value read or sensor in bad state!"));
	}
	else {
		// Feedback initialization:
		//Logger::Message(F("##\t"), F("Wind Sensor seems to be OK"), F(""), 1);
	}

	#ifdef WIND_ANEMOMETER_PIN
	if(millis() - timeAnemometer > 4000 && digitalRead(WIND_ANEMOMETER_PIN)==HIGH){
		windSpeed = 0;
		anemometerRevolution=0;
		timeAnemometer = millis();
	}
	#endif
//	Logger::Log(0, F("Wind sensor corrected value :"), String(value));

	// returns the angle, with reference to the boat:
	//angle = mapf(dataOut, WIND_SENSOR_MIN, WIND_SENSOR_MAX, WIND_ANGLE_MIN, WIND_ANGLE_MAX);  // The angle is now in the [0;+360] interval
	angle = mapf(dataOut, 0, 1024, -180, 180);  // The angle is now in the [0;+360] interval	
//angle = fmod(angle + 180,360);
   // if (angle < 0)
       // angle += 360;
 // angle -= 180;
	//angle = -angle;
	angle = angle*DEG_TO_RAD;
	//angle = kf.updateEstimate(angle);
//Serial.print("dataOut :");
//Serial.println(dataOut);

Serial.print("angle :");
Serial.println(angle);
}


void WindSensor::updateTest(){
	angle = 120;
}

void WindSensor::communicateData(){
    msg.x = 0;
    msg.y = 0;
#ifdef WIND_ANEMOMETER_PIN
	msg.x = windSpeed*cos(angle);
	msg.y = windSpeed*sin(angle);
#endif
	msg.theta = angle;

	pub.publish(&msg);
}
