#ifndef __ox_hpp
#define __ox_hpp

#include "terrestrial.h"

class Ox : public Terrestrial {
public:
    Ox() {
    }

    Ox(std::string name) {
        this->name = name;
    }

    void
    setName(std::string name) {
        this->name = name;
    }

    std::string
    getSound() const {
        return "Moo!";
    }

    std::string
    getName() const {
        return name;
    }

    std::string
    getMove() const {
        return "Walk";
    }
};

#endif
