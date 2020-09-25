#ifndef __contact_hpp
#define __contact_hpp

#include <string>
#include <iostream>

class Contact
{
private:
    std::string name;
    std::string numberPhone;
public:
    Contact() {
        name        = "";
        numberPhone = "+01 (23) 45678-9012";
    }

    Contact(const std::string& name, const std::string& numberPhone) {
        this->name        = name;
        this->numberPhone = numberPhone;
    }

    void
    setName(const std::string& contactName) {
        name = contactName;
    }

    void
    setNumberPhone(const std::string& contactNumberPhone) {
        numberPhone = contactNumberPhone;
    }

    std::string
    getName() const {
        return name;
    }

    std::string
    getNumberPhone() const {
        return numberPhone;
    }

    void
    about() {
        std::cout << "Name........: " <<    name     << std::endl;
        std::cout << "Number phone: " << numberPhone << std::endl;
    }
};

#endif
