#ifndef __polar_coordinats_hpp
#define __polar_coordinats_hpp

#define PI 3.14159265

#include <cmath>

class PolarCoordinates // Position Vector.
{
private:
    double radial; // Radial Coordinate.
    double polar;  // Polar Coordinate.

private:
    void 
    initialize(const double& radius = 0, const double& theta = 0) {
        radial = radius;
        polar  = theta;
        angle(polar);
    }
/*
    double absolute(double number) {
        return number > 0 ? number : number * -1;
    }
*/
    double 
    angle(double theta) {
        if (theta > 360) {
            double decimals = abs(theta) - (int) abs(theta);
            theta = (int) theta % 360;
            theta += decimals;
        }
        return theta;
    }

public:
    PolarCoordinates() {
        initialize();
    }

    PolarCoordinates(const double& radius, const double& theta) {
        initialize(radius, theta);
    }

    PolarCoordinates(const PolarCoordinates& pc) {
        radial = pc.radial;
        polar  = pc.polar;
    }

    void 
    fromRectangularCoordinates(const double& ordered, const double& abscissa) {
        radial = sqrt(ordered * ordered + abscissa * abscissa);
        polar  = angle(atan(abscissa / ordered)/* * 180 / PI */);
    }

    void 
    setPolar(const double& theta) {
        polar = theta;
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
    // From polar to rectangular coordinates.
    double 
    getAbscissa() const {
        return radial * sin(polar);
    }
    // From polar to rectangular coordinates.
    double 
    getOrdered() const {
        return radial * cos(polar);
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
};

#endif
