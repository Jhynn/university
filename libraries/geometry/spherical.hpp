#ifndef __spherical_hpp
#define __spherical_hpp

#include "polar.hpp"
#include "cartesian.hpp"
#include "cylindrical.hpp"

#include <cmath>
#include <string>
#include <cstdio>

class Spherical
{
private:
    double rho;
    double theta;
    double phi;
private:
    void
    initialize(const double& radius = 0, const double& theta = 0, const double& phi = 0) {
        this->rho   = radius;
        this->theta = theta;
        this->phi   = phi;
        angle(this->theta); angle(this->phi);
    }

    double abs(double number) {
        return number < 0 ? number * -1 : number;
    }

    void
    angle(double& angle) {
        if (angle > 360) {
            double decimals = abs(angle) - (int) abs(angle);
            angle = (int) angle % 360;
            angle += decimals;
        }
    }
public:
    Spherical() {
        initialize();
    }

    Spherical(const double& radius, const double& polar, const double& phi) {
        initialize(radius, polar, phi);
    }

    Spherical(const Spherical& point) {
        initialize(point.rho, point.theta, point.phi);
    }

    Spherical
    clone() const {
        return (*this);
    }

    void
    set(const double& radius, const double& theta, const double& phi) {
        initialize(radius, theta, phi);
    }

    void
    set(const Spherical& point) {
        initialize(point.rho, point.theta, point.phi);
    }

    void
    setRho(const double& scalar) {
        rho = scalar;
    }

    void
    setTheta(const double& angle) {
        theta = angle;
    }

    void
    setPhi(const double& angle) {
        phi = angle;
    }

    double
    getRho() const {
        return rho;
    }

    double
    getTheta() const {
        return theta;
    }

    double
    getPhi() const {
        return phi;
    }

    std::string
    str(std::string name = "") const {
        char buffer[512];
        sprintf(buffer, "%s(%lf, %lfº, %lfº)\n", name.c_str(), this->rho, this->theta, phi);
        return std::string(buffer);
    }

    void
    show() const {
        printf("%s", str().c_str());
    }
/*
    void
    fromCartesian(const Cartesian& point) {
        rho   = sqrt(pow(point.getHeight(), 2) + pow(point.getDepth(), 2)
                + pow(point.getWidth(), 2));
        theta = atan(point.getHeight() / point.getWidth());
        phi   = acos(point.getDepth() / r.rho);
    }

    void
    fromCylindrical(const Cylindrical& point) {
        rho   = sqrt(pow(point.getRadial(), 2) + pow(point.getZ(), 2));
        theta = point.getRadial();
        phi   = acos(point.getZ() / r.rho);
    }

    void
    fromPolar(const Polar& point) {
        Spherical(point.getRadial(), point.getPolar(), 0.0);
    }

    void
    operator=(const Cartesian& point) {
        fromCartesian(point);
    }

    void
    operator=(const Cylindrical& point) {
        fromCylindrical(point);
    }

    void
    operator=(const Polar& point) {
        fromPolar(point);
    }
*/
};

#endif
