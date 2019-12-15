#include <RCModule.h>
#include <Arduino.h>
#include <Sailboat.h>

void RC::updateMeasures(){
	if(millis() - watchdog > 10000 && controlling){
		controlling = false;
		Sailboat::Instance()->setController(previousController);
		Serial.println("Setting mode to Previous controller: " + String(previousController));
	}
}

void RC::interruptCH(uint8_t channel, uint8_t pin){
	//Serial.println(channel + String(", ") + String(pin) + String(" Interrupted"));
	if (digitalRead(pin) == HIGH) {
		rc_start[channel] = micros();
		//Serial.println("HIGH");
	} else {
		//Serial.println("LOW");
		uint16_t rc_compare = (uint16_t)(micros() - rc_start[channel]);
		rc_values[channel] = rc_compare;
		counter[channel] = counter[channel] + 1;
		rc_prevValues[channel][counter[channel]%10] = rc_values[channel];
		if (counter[channel] > 9) {
			
			uint16_t total = 0;
			for(int i = 0; i < 10; ++i){

				total = total + rc_prevValues[channel][i];
			}
			float mean = total/10;
			//Serial.println(String("[")  + rc_prevValues[channel][0] +String("], [") + rc_prevValues[channel][1] + String("], [") + rc_prevValues[channel][2] + String("], [") + rc_prevValues[channel][3] + String("], [") + rc_prevValues[channel][4] + String("], [") + rc_prevValues[channel][5] + String("]"));
			//Serial.println("Average Value: " + String(mean));
			if (abs(prevMean[channel] - mean) > 15) {
				Serial.println("Recent Value: " + String(rc_values[channel]));
				//Serial.println("");
				//Serial.println("");
				//Serial.println("");
				//Serial.println("Previous Average Value: "+ String(prevMean[channel]));
				//Serial.println("Average difference: " + String(abs(prevMean[channel] - mean)));
				//Serial.println("Changing to controlling");
				if(!controlling){
					previousController = Sailboat::Instance()->actualControllerIndex();
					Sailboat::Instance()->setController(RC_CONTROLLER);
					Serial.println("Setting mode to RC");
				}
				controlling = true;
				watchdog = millis();

			}
			prevMean[channel] = mean;
			
		}
		
	}
	
		
}

void(* resetFunc) (void) = 0;

void RC::resetArduino(uint8_t channel, uint8_t pin) {
	

	if (digitalRead(pin) == HIGH) {
		rc_start[channel] = micros();
		//Serial.println("HIGH");
	} else {
		
		uint16_t rc_compare = (uint16_t)(micros() - rc_start[channel]);
		rc_values[channel] = rc_compare;

		if (rc_values[channel] > 1900){
			Serial.println("reset Arduino called");
			Serial.println(rc_values[channel]);
			delay(1000);
			//resetFunc();
			delay(100);
		}
	}
}
