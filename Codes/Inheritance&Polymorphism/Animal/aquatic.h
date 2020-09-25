#ifndef __aquatic_h
#define __aquatic_h

#include "animal.h"

class Aquatic : public Animal {
public:
    inline
    Aquatic() {
        environment = "Water";
    }
    
    std::string
    getEnvironment() const {
        return environment;
    }
};

#endif
