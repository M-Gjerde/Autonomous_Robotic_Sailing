#include <RCModule.h>
#include <Arduino.h>
#include <Sailboat.h>

void RC::updateMeasures(){
/*
	if(millis() - watchdog > 10000 && controlling){
		controlling = false;
		Sailboat::Instance()->setController(previousController);
		Serial.print("No longer controlling");
	}
*/
}

void RC::interruptCH(uint8_t channel, uint8_t pin){
	
	//Serial.println("interruptCH is running!!");

	/*
	//ORIGINAL CODE
	if (digitalRead(pin) == HIGH) {
		rc_start[channel] = micros();
	} else {
		uint16_t rc_compare = (uint16_t)(micros() - rc_start[channel]);
		rc_values[channel] = rc_compare;

	}
	*/

	uint16_t rc_compare = pulseIn(pin, HIGH);
	rc_values[channel] = rc_compare;

	//Serial.print("rc_compare: ");
	//Serial.println(rc_compare);

	Serial.println("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _");
	if(!controlling){
		previousController = Sailboat::Instance()->actualControllerIndex();
		Sailboat::Instance()->setController(RC_CONTROLLER);
		Serial.print("RC controller is set");
	}

	controlling = true;

	watchdog = millis();
}
