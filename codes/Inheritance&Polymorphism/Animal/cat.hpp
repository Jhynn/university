#ifndef __cat_h
#define __cat_h

#include "terrestrial.h"

class Cat : public Terrestrial {
public:
    inline
    Cat() {
    }

    inline
    Cat(std::string name) {
        this->name = name;
    }

    void
    setName(std::string name) {
        this->name = name;
    }

    std::string
    getSound() const {
        return "Meow!";
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
