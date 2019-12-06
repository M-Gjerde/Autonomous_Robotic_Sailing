#ifndef _ROS_custom_msg_GPS_h
#define _ROS_custom_msg_GPS_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace custom_msg
{

  class GPS : public ros::Msg
  {
    public:
      typedef uint8_t _hour_type;
      _hour_type hour;
      typedef uint8_t _minute_type;
      _minute_type minute;
      typedef uint8_t _seconds_type;
      _seconds_type seconds;
      typedef uint16_t _milliseconds_type;
      _milliseconds_type milliseconds;
      typedef uint8_t _year_type;
      _year_type year;
      typedef uint8_t _month_type;
      _month_type month;
      typedef uint8_t _day_type;
      _day_type day;
      typedef float _latitude_type;
      _latitude_type latitude;
      typedef float _longitude_type;
      _longitude_type longitude;
      typedef int32_t _latitude_fixed_type;
      _latitude_fixed_type latitude_fixed;
      typedef int32_t _longitude_fixed_type;
      _longitude_fixed_type longitude_fixed;
      typedef float _latitudeDegrees_type;
      _latitudeDegrees_type latitudeDegrees;
      typedef float _longitudeDegrees_type;
      _longitudeDegrees_type longitudeDegrees;
      typedef float _geoidheight_type;
      _geoidheight_type geoidheight;
      typedef float _altitude_type;
      _altitude_type altitude;
      typedef float _speed_type;
      _speed_type speed;
      typedef float _angle_type;
      _angle_type angle;
      typedef float _magvariation_type;
      _magvariation_type magvariation;
      typedef float _HDOP_type;
      _HDOP_type HDOP;
      typedef const char* _lat_type;
      _lat_type lat;
      typedef const char* _lon_type;
      _lon_type lon;
      typedef const char* _mag_type;
      _mag_type mag;
      typedef bool _fix_type;
      _fix_type fix;
      typedef uint8_t _fixquality_type;
      _fixquality_type fixquality;
      typedef uint8_t _satellites_type;
      _satellites_type satellites;

    GPS():
      hour(0),
      minute(0),
      seconds(0),
      milliseconds(0),
      year(0),
      month(0),
      day(0),
      latitude(0),
      longitude(0),
      latitude_fixed(0),
      longitude_fixed(0),
      latitudeDegrees(0),
      longitudeDegrees(0),
      geoidheight(0),
      altitude(0),
      speed(0),
      angle(0),
      magvariation(0),
      HDOP(0),
      lat(""),
      lon(""),
      mag(""),
      fix(0),
      fixquality(0),
      satellites(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->hour >> (8 * 0)) & 0xFF;
      offset += sizeof(this->hour);
      *(outbuffer + offset + 0) = (this->minute >> (8 * 0)) & 0xFF;
      offset += sizeof(this->minute);
      *(outbuffer + offset + 0) = (this->seconds >> (8 * 0)) & 0xFF;
      offset += sizeof(this->seconds);
      *(outbuffer + offset + 0) = (this->milliseconds >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->milliseconds >> (8 * 1)) & 0xFF;
      offset += sizeof(this->milliseconds);
      *(outbuffer + offset + 0) = (this->year >> (8 * 0)) & 0xFF;
      offset += sizeof(this->year);
      *(outbuffer + offset + 0) = (this->month >> (8 * 0)) & 0xFF;
      offset += sizeof(this->month);
      *(outbuffer + offset + 0) = (this->day >> (8 * 0)) & 0xFF;
      offset += sizeof(this->day);
      union {
        float real;
        uint32_t base;
      } u_latitude;
      u_latitude.real = this->latitude;
      *(outbuffer + offset + 0) = (u_latitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_latitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_latitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_latitude.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->latitude);
      union {
        float real;
        uint32_t base;
      } u_longitude;
      u_longitude.real = this->longitude;
      *(outbuffer + offset + 0) = (u_longitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_longitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_longitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_longitude.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->longitude);
      union {
        int32_t real;
        uint32_t base;
      } u_latitude_fixed;
      u_latitude_fixed.real = this->latitude_fixed;
      *(outbuffer + offset + 0) = (u_latitude_fixed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_latitude_fixed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_latitude_fixed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_latitude_fixed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->latitude_fixed);
      union {
        int32_t real;
        uint32_t base;
      } u_longitude_fixed;
      u_longitude_fixed.real = this->longitude_fixed;
      *(outbuffer + offset + 0) = (u_longitude_fixed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_longitude_fixed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_longitude_fixed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_longitude_fixed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->longitude_fixed);
      union {
        float real;
        uint32_t base;
      } u_latitudeDegrees;
      u_latitudeDegrees.real = this->latitudeDegrees;
      *(outbuffer + offset + 0) = (u_latitudeDegrees.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_latitudeDegrees.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_latitudeDegrees.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_latitudeDegrees.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->latitudeDegrees);
      union {
        float real;
        uint32_t base;
      } u_longitudeDegrees;
      u_longitudeDegrees.real = this->longitudeDegrees;
      *(outbuffer + offset + 0) = (u_longitudeDegrees.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_longitudeDegrees.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_longitudeDegrees.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_longitudeDegrees.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->longitudeDegrees);
      union {
        float real;
        uint32_t base;
      } u_geoidheight;
      u_geoidheight.real = this->geoidheight;
      *(outbuffer + offset + 0) = (u_geoidheight.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_geoidheight.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_geoidheight.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_geoidheight.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->geoidheight);
      union {
        float real;
        uint32_t base;
      } u_altitude;
      u_altitude.real = this->altitude;
      *(outbuffer + offset + 0) = (u_altitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_altitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_altitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_altitude.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->altitude);
      union {
        float real;
        uint32_t base;
      } u_speed;
      u_speed.real = this->speed;
      *(outbuffer + offset + 0) = (u_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->speed);
      union {
        float real;
        uint32_t base;
      } u_angle;
      u_angle.real = this->angle;
      *(outbuffer + offset + 0) = (u_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle);
      union {
        float real;
        uint32_t base;
      } u_magvariation;
      u_magvariation.real = this->magvariation;
      *(outbuffer + offset + 0) = (u_magvariation.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_magvariation.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_magvariation.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_magvariation.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->magvariation);
      union {
        float real;
        uint32_t base;
      } u_HDOP;
      u_HDOP.real = this->HDOP;
      *(outbuffer + offset + 0) = (u_HDOP.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_HDOP.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_HDOP.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_HDOP.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->HDOP);
      uint32_t length_lat = strlen(this->lat);
      varToArr(outbuffer + offset, length_lat);
      offset += 4;
      memcpy(outbuffer + offset, this->lat, length_lat);
      offset += length_lat;
      uint32_t length_lon = strlen(this->lon);
      varToArr(outbuffer + offset, length_lon);
      offset += 4;
      memcpy(outbuffer + offset, this->lon, length_lon);
      offset += length_lon;
      uint32_t length_mag = strlen(this->mag);
      varToArr(outbuffer + offset, length_mag);
      offset += 4;
      memcpy(outbuffer + offset, this->mag, length_mag);
      offset += length_mag;
      union {
        bool real;
        uint8_t base;
      } u_fix;
      u_fix.real = this->fix;
      *(outbuffer + offset + 0) = (u_fix.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->fix);
      *(outbuffer + offset + 0) = (this->fixquality >> (8 * 0)) & 0xFF;
      offset += sizeof(this->fixquality);
      *(outbuffer + offset + 0) = (this->satellites >> (8 * 0)) & 0xFF;
      offset += sizeof(this->satellites);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->hour =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->hour);
      this->minute =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->minute);
      this->seconds =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->seconds);
      this->milliseconds =  ((uint16_t) (*(inbuffer + offset)));
      this->milliseconds |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->milliseconds);
      this->year =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->year);
      this->month =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->month);
      this->day =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->day);
      union {
        float real;
        uint32_t base;
      } u_latitude;
      u_latitude.base = 0;
      u_latitude.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_latitude.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_latitude.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_latitude.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->latitude = u_latitude.real;
      offset += sizeof(this->latitude);
      union {
        float real;
        uint32_t base;
      } u_longitude;
      u_longitude.base = 0;
      u_longitude.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_longitude.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_longitude.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_longitude.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->longitude = u_longitude.real;
      offset += sizeof(this->longitude);
      union {
        int32_t real;
        uint32_t base;
      } u_latitude_fixed;
      u_latitude_fixed.base = 0;
      u_latitude_fixed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_latitude_fixed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_latitude_fixed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_latitude_fixed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->latitude_fixed = u_latitude_fixed.real;
      offset += sizeof(this->latitude_fixed);
      union {
        int32_t real;
        uint32_t base;
      } u_longitude_fixed;
      u_longitude_fixed.base = 0;
      u_longitude_fixed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_longitude_fixed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_longitude_fixed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_longitude_fixed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->longitude_fixed = u_longitude_fixed.real;
      offset += sizeof(this->longitude_fixed);
      union {
        float real;
        uint32_t base;
      } u_latitudeDegrees;
      u_latitudeDegrees.base = 0;
      u_latitudeDegrees.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_latitudeDegrees.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_latitudeDegrees.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_latitudeDegrees.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->latitudeDegrees = u_latitudeDegrees.real;
      offset += sizeof(this->latitudeDegrees);
      union {
        float real;
        uint32_t base;
      } u_longitudeDegrees;
      u_longitudeDegrees.base = 0;
      u_longitudeDegrees.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_longitudeDegrees.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_longitudeDegrees.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_longitudeDegrees.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->longitudeDegrees = u_longitudeDegrees.real;
      offset += sizeof(this->longitudeDegrees);
      union {
        float real;
        uint32_t base;
      } u_geoidheight;
      u_geoidheight.base = 0;
      u_geoidheight.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_geoidheight.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_geoidheight.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_geoidheight.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->geoidheight = u_geoidheight.real;
      offset += sizeof(this->geoidheight);
      union {
        float real;
        uint32_t base;
      } u_altitude;
      u_altitude.base = 0;
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->altitude = u_altitude.real;
      offset += sizeof(this->altitude);
      union {
        float real;
        uint32_t base;
      } u_speed;
      u_speed.base = 0;
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->speed = u_speed.real;
      offset += sizeof(this->speed);
      union {
        float real;
        uint32_t base;
      } u_angle;
      u_angle.base = 0;
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle = u_angle.real;
      offset += sizeof(this->angle);
      union {
        float real;
        uint32_t base;
      } u_magvariation;
      u_magvariation.base = 0;
      u_magvariation.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_magvariation.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_magvariation.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_magvariation.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->magvariation = u_magvariation.real;
      offset += sizeof(this->magvariation);
      union {
        float real;
        uint32_t base;
      } u_HDOP;
      u_HDOP.base = 0;
      u_HDOP.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_HDOP.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_HDOP.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_HDOP.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->HDOP = u_HDOP.real;
      offset += sizeof(this->HDOP);
      uint32_t length_lat;
      arrToVar(length_lat, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_lat; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_lat-1]=0;
      this->lat = (char *)(inbuffer + offset-1);
      offset += length_lat;
      uint32_t length_lon;
      arrToVar(length_lon, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_lon; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_lon-1]=0;
      this->lon = (char *)(inbuffer + offset-1);
      offset += length_lon;
      uint32_t length_mag;
      arrToVar(length_mag, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_mag; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_mag-1]=0;
      this->mag = (char *)(inbuffer + offset-1);
      offset += length_mag;
      union {
        bool real;
        uint8_t base;
      } u_fix;
      u_fix.base = 0;
      u_fix.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->fix = u_fix.real;
      offset += sizeof(this->fix);
      this->fixquality =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->fixquality);
      this->satellites =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->satellites);
     return offset;
    }

    const char * getType(){ return "custom_msg/GPS"; };
    const char * getMD5(){ return "b76468d03618c050d45464b49d6e1372"; };

  };

}
#endif
