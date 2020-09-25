#ifndef __shark_hpp
#define __shark_hpp

#include "aquatic.h"

class Shark : public Aquatic {
public:
    Shark() {
    }

    Shark(std::string name) {
        this->name = name;
    }

    void
    setName(std::string name) {
        this->name = name;
    }

    std::string
    getSound() const {
        return "!!!";
    }

    std::string
    getName() const {
        return name;
    }

    std::string
    getMove() const {
        return "Swim";
    }
};

#endif
