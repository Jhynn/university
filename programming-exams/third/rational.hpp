#ifndef __rational_hpp
#define __rational_hpp
// Alinne Grazielle & Matheus Miranda.
#include <stdexcept>
#include <string>
#include <stdio.h> 

class Rational {
private:
    int a, b;

private: // Somente as instâncias da classe usam estes métodos.
    int
    max() {
        return a >= b ? a / 2 : b / 2; // Retorna a metade do maior número.
    }

    bool
    isNegative(const int& number) {
        return number < 0;
    }

    void
    negate(int& number) {
        number *= -1;
    }

    void
    simplify() {
        bool aux = false;
        if (isNegative(a)) {
            negate(a);
            aux = true;
        } else if (isNegative(b)) {
            negate(b);
            aux = true;
        }

        if (a == b) {
            a = b = 1;
            if (aux)
                negate(a);
            return;
        }

        int maximum = max();
        // Inicia com dois porque não existe divisão por zero,
        // e qualquer número é divisível por um. 
        for (int i = 2; i < maximum; i++) {
            if (a % i == 0 && b % i == 0) {
                a /= i; b /= i;  // Atualiza o numerador e o denominador.
                maximum = max(); // Atualiza o valor do máximo (para a repetição).
                i = 2;           // Volta a percorrer do inicio (2);
            }
        }

        if (aux)
            negate(a);
    }

    void
    signals() {
        if (a < 0 && b < 0) {
            a = a * (-1);
            b = b * (-1);
            return;
        } else if(a > 0 && b < 0) {
            a *= -1;
            b *= -1;
        }
    }

public:
    Rational() {
        initialize();
    }

    Rational(int userA, int userB) {
        initialize(userA, userB);
    }

    Rational(const Rational& r) {
        initialize(r);
    }

    void
    initialize(int userA = 0, int userB = 1) {
        if (userB == 0)
            throw std::invalid_argument("Denominador igual a ZERO.");
        
        setAB(userA, userB);
        signals();
        simplify();
    }

    void
    initialize(const Rational& r) {
        if (r.b == 0)
            throw std::invalid_argument("Denominador igual a ZERO.");
        
        setAB(r.a, r.b);
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
    str() const {
        char buffer[8];
        sprintf(buffer, "%d/%d\n", a, b);
        return std::string (buffer);
    }

    Rational
    sum(const Rational& r1) {
        Rational R;
        if (r1.b == b) {
            R.a = r1.a + a;
            R.b = r1.b;
            signals();
            simplify();

            return R;
        } else {
            R.a = r1.a * b + a * r1.b;
            R.b = r1.b * b; 
        }
        signals();
        simplify();

        return R;
    }

    Rational
    multiply(const Rational& r1) {
        Rational R;
        R.a = r1.a * a;
        R.b = b * b;
        signals();
        simplify();

        return R;
    }

    Rational
    minus(const Rational& r1) {
        Rational R;

        if (r1.b == b) {
            R.a = r1.a - a;
            R.b = r1.b;
            signals();
            simplify();

            return R;
        } else {
            R.a = r1.a * b - a * r1.b;
            R.b = r1.b * b; 
        }
        signals();
        simplify();

        return R;
    }

    Rational
    operator=(const Rational& c) {
        setAB(c.a, c.b);
        return (*this);
    }

    Rational
    operator+(const Rational& s) {
        return sum(s);
    }

    Rational
    operator*(const Rational& m) {
        return multiply(m);
    }

    Rational
    operator-(const Rational& sub) {
        return minus(sub);
    }

    bool
    operator==(const Rational& r) const {
        return (a / b == r.a / r.b);
    }

    bool
    operator!=(const Rational& r) const {
        return !(*this == r);
    }
};

#endif 
