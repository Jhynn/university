#ifndef __analitic_hpp
#define __analitic_hpp
// Matheus Miranda.
#include <string>
#include <stdio.h>
#include <cmath>

class Vector {  // Vector Position.
private:
    double abscissa;
    double ordened;

private:
    void
    initialize(const double& abs = 0, const double& ord = 0) {
        abscissa = abs;
        ordened  = ord;
    }

public:
    Vector() {
        initialize();
    }

    Vector(const double& abs, const double& ord) {
        initialize(abs, ord);
    }

    Vector(const Vector& v) {
        set(v.abscissa, v.ordened);
    }

    double
    getAbs() const {
        return abscissa;
    }

    double
    getOrd() const {
        return ordened;
    }

    void
    setAbs(const double& abs) {
        abscissa = abs;
    }

    void
    setOrd(const double& ord) {
        ordened = ord;
    }

    void
    set(const double& abs, const double& ord) {
        setAbs(abs);
        setOrd(ord);
    }

    std::string 
    str() const {
        char buffer[32];
        sprintf(buffer, "(%lf)î + (%lf*i)ĵ", abscissa, ordened);
        return buffer;
    }

    void
    show() {
        printf("%s\n", str().c_str());
    }

    double 
    module() const {
        return sqrt(abscissa * abscissa + ordened * ordened);
    }

    Vector
    sum(const Vector& v) const {
        return Vector(this->abscissa + v.getAbs(), this->ordened + v.getOrd());
    }

    Vector
    multiplyByScalar(const double scalar) const {
        Vector r;
        r.set(this->abscissa * scalar, this->ordened * scalar);

        return r;
    }

    Vector
    operator+(Vector& v) const {
        return sum(v);
    }

    Vector
    operator-(Vector& v) const {
        return sum(v * -1);
    }

    Vector
    operator*(const double scalar) const {
        return multiplyByScalar(scalar);
    }

    Vector
    operator=(const Vector& c) {
        set(c.abscissa, c.ordened);
        return (*this);
    }

    bool
    operator==(const Vector& r) const {
        return (abscissa == r.abscissa)
            && (ordened  == r.ordened);
    }

    bool
    operator!=(const Vector& r) const {
        return !(*this == r);
    }
};

#endif
