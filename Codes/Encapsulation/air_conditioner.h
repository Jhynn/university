#ifndef __air_h
#define __air_h

class AirConditioner
{
private:
    float air_conditioned;
    float room_temperature;
public:
    AirConditioner();
    ~AirConditioner();

    void toConditioner(unsigned int power_value);
    void setRoomTemperature(float user_room_temperature);
    void show();
};

#endif

