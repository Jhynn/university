#ifndef __whale_hpp
#define __whale_hpp

#include "aquatic.h"

class Whale : public Aquatic {
public:
    Whale() {
    }

    Whale(std::string name) {
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
