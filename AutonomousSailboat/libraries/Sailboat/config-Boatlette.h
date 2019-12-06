/**CONFIG FOR OUR SAILBOAT BOATLETTE - MTA19735**/

#ifndef CONFIG_H
#define CONFIG_H


/**********************************************ID********************************************/
/**SENSORS**/
/***********/
#define NB_SENSORS		4

#define SENSOR_WINDSENSOR	0
#define SENSOR_GPS			1
#define SENSOR_IMU			2
#define SENSOR_BATTERY      3

#define NB_SENSORS_NOT_ROS		1

#define SENSOR_RC			0

/**ACTUATORS**/
/***********/
#define NB_ACTUATORS		2

#define ACTUATOR_RUDDER		0
#define ACTUATOR_SAIL		1

/**********************************************HARDWARE********************************************/
//RC Transceiver
//#define HK_TR6
#define TARANIS_Q_X7

//Using Grove Shield or not
#define SERVO_SHIELD

//IMU
//#define CMPS12_IMU
//#define XSENS_IMU
#define BNO055_IMU
#define USE_ARDUINO_GPS
#define USE_ARDUINO_WIND

//Enable or disable fusion of IMU and GPS data. This will get better data on the velocity of the boat.
//#define FUSE_GPS_IMU

/*****************************************CONFIGURATION****************************************/
/**CONFIG**/
/**********/
//WIND
#define WIND_ANGLE_MIN -180
#define WIND_ANGLE_MAX 180

#define WIND_SENSOR_MIN 0
#define WIND_SENSOR_MAX 1024

//RUDDER
#define RUDDER_POS_MIN  250
#define RUDDER_POS_NEUTRAL  360
#define RUDDER_POS_MAX  470

#define RUDDER_MIN  -41
#define RUDDER_NEUTRAL  0
#define RUDDER_MAX  45

//SAIL
#define SAIL_MIN 0
#define SAIL_NEUTRAL SAIL_MIN
#define SAIL_MAX 90

#define WINCH_ANGLE_MIN 234
#define WINCH_ANGLE_NEUTRAL WINCH_ANGLE_MIN
#define WINCH_ANGLE_MAX 91
#define WINCH_DIAMETER 30 // in mm

#endif
