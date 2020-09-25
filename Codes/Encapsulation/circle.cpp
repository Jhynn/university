#include "circle.h"
#include <math.h>

Circle::Circle(float circle_radius) {
    distance      = 0;
    radius        = circle_radius;
    circunference = M_PI * radius * 2;
    area          = M_PI * radius * radius;
}

Circle::~Circle() {

}

float 
Circle::circle_area() {
    return area;
}

float
Circle::circle_circunference() {
    return circunference;
}
