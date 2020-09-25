#ifndef __terrestrial_h
#define __terrestrial_h

#include "animal.h"

class Terrestrial : public Animal
{
public:
    inline
    Terrestrial() {
        environment = "Ground";
    }

    std::string
    getEnvironment() const {
        return environment;
    }
};

#endif
