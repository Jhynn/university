#include "television.h"
#include <iostream>

Television::Television() {
    channel         = 0;
    sound_intensity = 0;
}

Television::~Television() {

}

void 
Television::change_channel(unsigned int go_to) {
    channel += go_to;
}

void 
Television::vary_intensity(int quantity) {
    sound_intensity += quantity;
}

void 
Television::show() {
    std::cout << "Canal:  " << channel << std::endl;
    std::cout << "Volume: " << sound_intensity << std::endl;
}
