#ifndef _ROS_custom_msg_BoatControls_h
#define _ROS_custom_msg_BoatControls_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace custom_msg
{

  class BoatControls : public ros::Msg
  {
    public:
      typedef int64_t _rudder_type;
      _rudder_type rudder;
      typedef int64_t _sail_type;
      _sail_type sail;

    BoatControls():
      rudder(0),
      sail(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_rudder;
      u_rudder.real = this->rudder;
      *(outbuffer + offset + 0) = (u_rudder.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rudder.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rudder.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rudder.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_rudder.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_rudder.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_rudder.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_rudder.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->rudder);
      union {
        int64_t real;
        uint64_t base;
      } u_sail;
      u_sail.real = this->sail;
      *(outbuffer + offset + 0) = (u_sail.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sail.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sail.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sail.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_sail.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_sail.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_sail.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_sail.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->sail);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_rudder;
      u_rudder.base = 0;
      u_rudder.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rudder.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rudder.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rudder.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_rudder.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_rudder.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_rudder.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_rudder.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->rudder = u_rudder.real;
      offset += sizeof(this->rudder);
      union {
        int64_t real;
        uint64_t base;
      } u_sail;
      u_sail.base = 0;
      u_sail.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sail.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sail.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sail.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_sail.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_sail.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_sail.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_sail.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->sail = u_sail.real;
      offset += sizeof(this->sail);
     return offset;
    }

    const char * getType(){ return "custom_msg/BoatControls"; };
    const char * getMD5(){ return "db661f7ba0f9259f68cc824722ef5fe2"; };

  };

}
#endif
