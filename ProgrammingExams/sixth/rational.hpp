#ifndef __rational_
#define __rational_

#include <stdexcept>
#include <string>
#include <stdio.h>
#include <iostream>

class Rational {
private:
    int a, b;

public:
    Rational() {
        initialize();
    }

    Rational(int userA, int userB) {
        initialize(userA, userB);
    }

    Rational(const Rational &r) {
        initialize(r);
    }

    void
    simplify() {
        int maximum;

        if (a >= b)
            maximum = a;
        else
            maximum = b;

        for (int i = 2; i < maximum; i++) {
            if (a % i == 0 && b % i == 0) {
                a /= i;
                b /= i;
            }
        }
    }

    void
    signals() {
        if (a < 0 && b < 0) {
            a = a * (-1);
            b = b * (-1);

            return;
        } else if (a > 0 && b < 0) {
            a *= -1;
            b *= -1;
        }
    }

    void
    initialize(int userA = 0, int userB = 1) {
        a = userA;
        b = userB;

        if (userB == 0)
            throw std::invalid_argument("Denominador igual a ZERO.");

        signals();
        simplify();
    }

    void
    initialize(const Rational &r) {
        a = r.a;
        b = r.b;

        if (r.b == 0)
            throw std::invalid_argument("Denominador igual a ZERO.");

        signals();
        simplify();
    }

    int
    getA() const {
        return a;
    }

    int
    getB() const {
        return b;
    }

    void
    setA(const int userA) {
        a = userA;
        signals();
        simplify();
    }

    void
    setB(const int userB) {
        b = userB;
        signals();
        simplify();
    }

    void
    setAB(const int userA, const int userB) {
        setA(userA);
        setB(userB);
        signals();
        simplify();
    }

    std::string
    str() {
        char buffer[8];
        sprintf(buffer, "%d/%d\n", a, b);

        return std::string(buffer);
    }

    Rational
    sum(const Rational &r1) {
        Rational R;

        if (r1.b == b) {
            R.a = r1.a + a;
            R.b = r1.b;
            R.simplify();

            return R;
        } else {
            R.a = r1.a * b + a * r1.b;
            R.b = r1.b * b;
        }

        simplify();
        return R;
    }

    Rational
    multiply(const Rational &r1) {
        Rational R;

        R.a = r1.a * a;
        R.b = b * b;
        simplify();

        return R;
    }

    Rational
    minus(const Rational &r1) {
        Rational R;

        if (r1.b == b) {
            R.a = r1.a - a;
            R.b = r1.b;
            R.simplify();

            return R;
        } else {
            R.a = r1.a * b - a * r1.b;
            R.b = r1.b * b;
        }

        R.simplify();
        return R;
    }

    Rational
    operator=(const Rational &c) {
        a = c.a;
        b = c.b;

        return (*this);
    }

    Rational
    operator+(const Rational &s) {
        return sum(s);
    }

    Rational
    operator*(const Rational &m) {
        return multiply(m);
    }

    Rational
    operator-(const Rational &sub) {
        return minus(sub);
    }
};

#endif
