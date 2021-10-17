#ifndef __cylindrical_hpp
#define __cylindrical_hpp

#include "polar.hpp"
#include "spherical.hpp"
#include "cartesian.hpp"

#include <cmath>
#include <string>
#include <cstdio>

class Cylindrical 
{
private:
    double rho;   // radialCoordinate
    double theta; // polarCoordinate
    double z;     // Scalar coordinate.
private:
    void
    initialize(const double& rho = 0, const double& theta = 0, const double& k = 0) {
        this->rho   = rho;
        this->theta = theta;
        this->z     = k;
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
    Cylindrical() {
        initialize();
    }

    Cylindrical(const double& rho, const double& theta, const double& k) {
        initialize(rho, theta, k);
    }

    Cylindrical(const Cylindrical& point) {
        initialize(point.rho, point.theta, point.z);
    }

    Cylindrical
    clone() const {
        return (*this);
    }

    void
    set(const double& rho, const double& theta, const double& k) {
        initialize(rho, theta, k);
    }

    void
    set(const Cylindrical& point) {
        initialize(point.rho, point.theta, point.z);
    }

    void
    setRho(const double& radius) {
        rho = radius;
    }

    void
    setTheta(const double& angle) {
        this->theta = angle;
    }

    void
    setZ(const double& k) {
        this->z = k;
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
    getZ() const {
        return z;
    }

    std::string
    str(std::string name = "") const {
        char buffer[512];
        sprintf(buffer, "%s(%lf, %lfº, %lf)\n", name.c_str(), rho, theta, z);
        return std::string(buffer);
    }

    void
    show() const {
        printf("%s", str().c_str());
    }
/*
    void
    fromCartesian(const Cartesian& point) {
        z = point.getDepth();
        setRho(sqrt(pow(point.getHeight(), 2) + pow(point.getWidth(), 2)));
        setTheta(atan(point.getHeight() / point.getWidth()));
    }

    void
    fromSpherical(const Spherical& point) {
        rho   = point.getRho() * sin(point.getPhi());
        theta = point.getTheta();
        z     = point.getRho() * cos(point.getPhi());
    }

    void
    fromPolar(const Polar& point) {
        Cylindrical(point.getRadial(), point.getPolar(), 0);
    }

    void
    operator=(const Cartesian& point) {
        fromCartesian(point);
    }

    void
    operator=(const Spherical& point) {
        fromSpherical(point);
    }

    void
    operator=(const Polar& point) {
        fromPolar(point);
    }
*/
};

#endif
