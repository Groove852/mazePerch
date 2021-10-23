#ifndef _ROS_lolkek_raspberry_h
#define _ROS_lolkek_raspberry_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace lolkek
{

  class raspberry : public ros::Msg
  {
    public:
      typedef int32_t _command_type;
      _command_type command;
      typedef int32_t _spd_type;
      _spd_type spd;

    raspberry():
      command(0),
      spd(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_command;
      u_command.real = this->command;
      *(outbuffer + offset + 0) = (u_command.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_command.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_command.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_command.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->command);
      union {
        int32_t real;
        uint32_t base;
      } u_spd;
      u_spd.real = this->spd;
      *(outbuffer + offset + 0) = (u_spd.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_spd.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_spd.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_spd.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->spd);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_command;
      u_command.base = 0;
      u_command.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_command.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_command.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_command.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->command = u_command.real;
      offset += sizeof(this->command);
      union {
        int32_t real;
        uint32_t base;
      } u_spd;
      u_spd.base = 0;
      u_spd.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_spd.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_spd.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_spd.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->spd = u_spd.real;
      offset += sizeof(this->spd);
     return offset;
    }

    virtual const char * getType() override { return "lolkek/raspberry"; };
    virtual const char * getMD5() override { return "c40dff7a5fb8ce35e369daefd1b52ec8"; };

  };

}
#endif
