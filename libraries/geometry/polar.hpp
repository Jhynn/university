#ifndef __polar_hpp
#define __polar_hpp

#include "cartesian.hpp"

#include <cmath>
#include <string>
#include <cstdio>

class Polar
{
private:
    double rho;   // radialCoordinate
    double theta; // polarCoordinate
protected:
    virtual void
    initialize(const double& radius = 0, const double& polar = 0) {
        rho   = radius;
        theta = polar;
        angle();
    }

    double abs(double number) {
        return number < 0 ? number * -1 : number;
    }

    void
    angle() {
        if (theta > 360) {
            double decimals = abs(theta) - (int) abs(theta);
            theta = (int) theta % 360;
            theta += decimals;
        }
    }
public:
    Polar() {
        initialize();
    }

    Polar(const double& radius, const double& polar) {
        initialize(radius, polar);
    }

    Polar(const Polar& point) {
        initialize(point.rho, point.theta);
    }

    Polar
    clone() const {
        return (*this);
    }

    void
    set(const double& radius, const double& polar) {
        initialize(radius, theta);
    }

    void
    set(const Polar& point) {
        initialize(point.rho, point.theta);
    }

    virtual void
    setRadial(const double& radius) {
        initialize(radius, this->theta);
    }

    virtual void
    setPolar(const double& polar) {
        initialize(this->rho, polar);
    }

    virtual double
    getRadial() const {
        return rho;
    }

    virtual double
    getPolar() const {
        return theta;
    }

    std::string
    str(std::string name = "") const {
        char buffer[512];
        sprintf(buffer, "%s(%lf, %lfº)\n", name.c_str(), rho, theta);
        return std::string(buffer);
    }

    void
    show() const {
        printf("%s", str().c_str());
    }

    Polar
    sum(const double& polar) const {
        return Polar(this->rho, this->theta + polar);
    }

    Polar
    sum(const Polar& point) const {
        return sum(point.theta);
    }

    Polar
    operator+(const double& polar) const {
        return sum(polar);
    }

    Polar
    operator+(const Polar& point) const {
        return sum(point.theta);
    }
    
    Polar
    sub(const double& polar) const {
        return sum(polar * -1);
    }

    Polar
    sub(const Polar& point) const {
        return sum(point.theta * -1);
    }

    Polar
    operator-(const double& polar) const {
        return sub(polar);
    }

    Polar
    operator-(const Polar& point) const {
        return sub(point.theta);
    }
    
    Polar
    muliply(const double& scalar) const {
        return Polar(this->rho * scalar, this->theta);
    }

    Polar
    operator*(const double& scalar) const {
        return muliply(scalar);
    }

    Polar
    operator=(const Polar& point) {
        return Polar(point.rho, point.theta);
    }

    void
    operator+=(const Polar& point) {
        *this = *this + point;
    }

    void
    operator-=(const Polar& point) {
        *this = *this - point;
    }

    void
    operator*=(const Polar& point) {
        *this = *this * point.rho;
    }

    bool
    operator==(const Polar& point) const {
        return rho == point.rho && theta == point.theta;
    }

    bool
    operator!=(const Polar& point) const {
        return !(*this == point);
    }

    void
    fromCartesian(const Cartesian& point) {
        theta = atan(point.getHeight() / point.getWidth());
        rho   = sqrt(pow(point.getWidth(), 2) + 
                pow(point.getHeight(), 2) + pow(point.getDepth(), 2));
    }

    void
    operator=(const Cartesian& point) {
        fromCartesian(point);
    }
};

#endif
