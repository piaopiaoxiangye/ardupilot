#pragma once

#include <AP_HAL/AP_HAL.h>
#include <AP_HAL/Device.h>
#include <AP_HAL/utility/OwnPtr.h>

#include "AP_Baro_Backend.h"

#define HAL_BARO_LPS25H_I2C_BUS 0
#define HAL_BARO_LPS25H_I2C_ADDR 0x5D


class AP_Baro_LPS2XH : public AP_Baro_Backend
{
public:
    enum LPS2XH_TYPE {
        BARO_LPS22H = 0,
        BARO_LPS25H = 1,
    };

    AP_Baro_LPS2XH(AP_Baro &baro, AP_HAL::OwnPtr<AP_HAL::Device> dev);

    /* AP_Baro public interface: */
    void update();

    static AP_Baro_Backend *probe(AP_Baro &baro, AP_HAL::OwnPtr<AP_HAL::Device> dev);


private:
    virtual ~AP_Baro_LPS2XH(void) {};

    bool _init(void);
    void _timer(void);
    void _update_temperature(void);
    void _update_pressure(void);

   bool _check_whoami(void);

    AP_HAL::OwnPtr<AP_HAL::Device> _dev;

    bool _has_sample;
    uint8_t _instance;
    float _pressure;
    float _temperature;

    uint32_t CallTime = 0;

   enum LPS2XH_TYPE _lps2xh_type;

   // WHOAMI values
#define   LPS22HB_WHOAMI     0xB1
#define 	 LPS25HB_WHOAMI		0xBD
};
