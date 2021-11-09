#ifndef __animal_h
#define __animal_h

#include <string>

class Animal {
protected:
    std::string name;
    std::string environment;
public:
    inline
    Animal() {
        name = "";
    }
    
    virtual std::string
    getName() const = 0;

    virtual std::string
    getMove() const = 0;

    virtual std::string
    getEnvironment() const = 0;
};

#endif
