#ifndef __cartesian_hpp
#define __cartesian_hpp

#include "polar_coord.hpp"

class Cartesian {
private:
    double abscissa; // X.
    double ordered;  // Y.
private:
    void
    initialize(const double& x = 0, const double& y = 0) {
        abscissa = x;
        ordered  = y;
    }

public:
    Cartesian() {
        initialize();
    }

    Cartesian(const double& x, const double& y) {
        initialize(x, y);
    }

    Cartesian(const Cartesian& point) {
        initialize(point.abscissa, point.ordered);
    }

    void
    set(const double& x, const double& y) {
        initialize(x, y);
    }

    double
    getAbscissa() const {
        return abscissa;
    }

    double
    getOrdered() const {
        return ordered;
    }

    void
    move(const double& x = 0, const double& y = 0) {
        initialize(abscissa += x, ordered += y);
    }

    void
    moveScalar(const double& x = 1, const double& y = 1) {
        initialize(abscissa * x, ordered * y);
    }
/*
    void
    fromPolarCoordinates(const PolarCoordinates& pc) {
        set(pc.getRadial() * sin(pc.getPolar()), 
            pc.getRadial() * cos(pc.getPolar()));
    }

    Cartesian
    operator=(const PolarCoordinates& pc) {
        fromPolarCoordinates(pc);
        return *this;
    }
*/
    Cartesian
    operator=(const Cartesian& cartesian) {
        set(cartesian.getAbscissa(), cartesian.getOrdered());
        return *this;
    }
};

#endif
