#ifndef __polar_coordinats_hpp
#define __polar_coordinats_hpp

#define PI 3.14159265

#include "cartesian.hpp"

#include <cmath>
#include <string>
#include <stdio.h>

class PolarCoordinates {    // Position Vector.
private:
    double radial;          // Radial Coordinate.
    double polar;           // Polar Coordinate.

private:
    void
    initialize(const double& radius = 0, const double& theta = 0) {
        radial = radius;
        polar  = theta;
        angle();
    }
/*
    double absolute(double number) {
        return number > 0 ? number : number * -1;
    }
*/
    void 
    angle() {
        if (polar > 360) {
            double decimals = abs(polar) - (int) abs(polar);
            polar = (int) polar % 360;
            polar += decimals;
        }
    }

public:
    PolarCoordinates() {
        initialize();
    }

    PolarCoordinates(const double& radius, const double& theta) {
        initialize(radius, theta);
    }

    PolarCoordinates(const PolarCoordinates& pc) {
        initialize(pc.radial, pc.polar);
    }
/*
    void 
    fromRectangularCoordinates(const Cartesian& point) {
        radial = sqrt(point.getOrdered() * point.getOrdered() 
                    + point.getAbscissa() * point.getAbscissa());
        polar  = atan(point.getAbscissa() / point.getOrdered()); // * 180 / PI
        angle();
    }
*/
    void 
    setPolar(const double& theta) {
        initialize(radial, theta);
    }

    void 
    setRadial(const double& radius) {
        radial = radius;
    }

    double 
    getPolar() const {
        return polar;
    }

    double 
    getRadial() const {
        return radial;
    }

    void 
    set(const double& radius, const double& theta) {
        initialize(radius, theta);
    }

    std::string
    str() const {
        char buffer[128];
        sprintf(buffer, "Radial: %lf\nPolar: %lf\n", radial, polar);
        return std::string (buffer);
    }

    void
    show() {
        printf("%s", str().c_str());
    }

    void 
    multiplyByScalar(const double& scalar) {
        radial *= scalar;
    }

    void 
    sumDegrees(const double& theta) {
        polar += theta;
    }

    void 
    subDegrees(double& theta) {
        sumDegrees(theta *= -1);
    }

    PolarCoordinates
    operator=(const PolarCoordinates& pc) {
        set(pc.radial, pc.polar);
        return *this;
    }

    void 
    operator+(const double& theta) {
        sumDegrees(theta);
    }

    void 
    operator-(double& theta) {
        subDegrees(theta);
    }

    void 
    operator*(const double& scalar) {
        multiplyByScalar(scalar);
    }

    void
    operator=(const Cartesian& point) {
        //fromRectangularCoordinates(point);
    }
};

#endif
