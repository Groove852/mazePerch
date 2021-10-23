#ifndef _ROS_lolkek_openCR_h
#define _ROS_lolkek_openCR_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace lolkek
{

  class openCR : public ros::Msg
  {
    public:
      typedef float _temperature_type;
      _temperature_type temperature;
      typedef int32_t _currentSpd_type;
      _currentSpd_type currentSpd;
      typedef int32_t _blackBox_type;
      _blackBox_type blackBox;

    openCR():
      temperature(0),
      currentSpd(0),
      blackBox(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_temperature;
      u_temperature.real = this->temperature;
      *(outbuffer + offset + 0) = (u_temperature.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temperature.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_temperature.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_temperature.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->temperature);
      union {
        int32_t real;
        uint32_t base;
      } u_currentSpd;
      u_currentSpd.real = this->currentSpd;
      *(outbuffer + offset + 0) = (u_currentSpd.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_currentSpd.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_currentSpd.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_currentSpd.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->currentSpd);
      union {
        int32_t real;
        uint32_t base;
      } u_blackBox;
      u_blackBox.real = this->blackBox;
      *(outbuffer + offset + 0) = (u_blackBox.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_blackBox.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_blackBox.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_blackBox.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->blackBox);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_temperature;
      u_temperature.base = 0;
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->temperature = u_temperature.real;
      offset += sizeof(this->temperature);
      union {
        int32_t real;
        uint32_t base;
      } u_currentSpd;
      u_currentSpd.base = 0;
      u_currentSpd.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_currentSpd.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_currentSpd.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_currentSpd.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->currentSpd = u_currentSpd.real;
      offset += sizeof(this->currentSpd);
      union {
        int32_t real;
        uint32_t base;
      } u_blackBox;
      u_blackBox.base = 0;
      u_blackBox.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_blackBox.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_blackBox.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_blackBox.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->blackBox = u_blackBox.real;
      offset += sizeof(this->blackBox);
     return offset;
    }

    virtual const char * getType() override { return "lolkek/openCR"; };
    virtual const char * getMD5() override { return "ab52b957c4b5e78a34ac605cf2f481e1"; };

  };

}
#endif
