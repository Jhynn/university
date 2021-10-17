#ifndef __cartesian_hpp
#define __cartesian_hpp

#include <cmath>
#include <cstdio>
#include <string>

#include "polar.hpp"
#include "spherical.hpp"
#include "cylindrical.hpp"

class Cartesian
{
private:
    double width;  // abscissa = X,
    double height; // ordered  = Y,
    double depth;  // -------- = Z.
private:
    void
    initialize(const double& x = 0, const double& y = 0, const double& z = 0) {
        width  = x;
        height = y;
        depth  = z;
    }

    Cartesian
    sum(const double& x, const double& y, const double& z) const {
        return Cartesian(width + x, height + y, z + depth);
    }

    Cartesian
    mul(const double& x, const double& y, const double& z) const {
        return Cartesian(width * x, height * y, z * depth);
    }
public:
    Cartesian() {
        initialize();
    }

    Cartesian(const double& x, const double& y, const double& z = 0) {
        initialize(x, y, z);
    }

    Cartesian(const Cartesian& point) {
        initialize(point.width, point.height, point.depth);
    }

    Cartesian
    clone() {
        return (*this);
    }

    void
    set(const double& x, const double& y, const double& z = 0) {
        initialize(x, y, z);
    }

    double
    getWidth() const {
        return width;
    }

    double
    getHeight() const {
        return height;
    }

    double
    getDepth() const {
        return depth;
    }

    std::string
    str(std::string name = "") const {
        char buffer[512];
        sprintf(buffer, "%s(%lf, %lf, %lf)\n", name.c_str(),
                width, height, depth);
        return std::string(buffer);
    }

    void
    show() const {
        printf("%s", str().c_str());
    }

    void
    move(const double& x, const double& y, const double& z) {
        initialize(width += x, height += y, depth += z);
    }

    void
    moveScalar(const double& x = 1, const double& y = 1, const double& z = 1) {
        initialize(width * x, height * y, depth * z);
    }

    Cartesian
    sum(const Cartesian& point) const {
        return sum(point.width, point.height, point.depth);
    }

    Cartesian
    sub(const Cartesian& point) const {
        return sum(point.width * -1, point.height * -1, point.depth * -1);
    }

    Cartesian
    mul(const Cartesian& point) const {
        return mul(point.width, point.height, point.depth);
    }

    Cartesian
    operator+(const Cartesian& point) const {
        return sum(point);
    }

    Cartesian
    operator-(const Cartesian& point) const {
        return sub(point);
    }

    Cartesian
    operator*(const Cartesian& point) const {
        return mul(point);
    }

    Cartesian
    operator=(const Cartesian& point) {
        return Cartesian(point.width, point.height, point.depth);
    }

    Cartesian
    operator+=(const Cartesian& point) {
        return *this = *this + point;
    }

    Cartesian
    operator-=(const Cartesian& point) {
        return *this = *this - point;
    }

    Cartesian
    operator*=(const Cartesian& point) {
        return *this = *this * point;
    }

    bool
    operator==(const Cartesian& point) const {
        return width == point.width && height == point.height && depth == point.depth;
    }

    bool
    operator!=(const Cartesian& point) const {
        return !(*this == point);
    }
/*
    void
    fromPolar(const Polar& point) {
        width  = point.getRadial() * cos(point.getPolar());
        height = point.getRadial() * sin(point.getPolar());
        depth  = .0;
    }

    void
    fromSpherical(const Spherical& point) {
        width  = point.getRho() * sin(point.getPhi()) * cos(point.getTheta());
        height = point.getRho() * sin(point.getPhi()) * sin(point.getPhi());
        depth  = point.getRho() * cos(point.getPhi());
    }

    void
    fromCylindrical(const Cylindrical& point) {
        width  = point.getRho() * cos(point.getTheta());
        height = point.getRho() * sin(point.getTheta());
        depth  = point.getZ();
    }

    void
    operator=(const Spherical& point) {
        fromSpherical(point);
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
