#ifndef __point_h
#define __point_h
// Alinne Grazielle & Matheus Miranda.
#include <iostream>
#include <math.h>

class Point {
private:
    double abscissa,
           ordenada;

public:
    Point() {
        this->abscissa = this->ordenada = 0;
    }

    Point(double abs, double ord) {
        this->abscissa = abs;
        this->ordenada = ord;
    }

    Point(const Point& point) {
        Point();
        movimentar(point);
    }

    double
    getAbscissa() const {
        return abscissa;
    }

    double
    getOrdenada() const {
        return ordenada;
    }

    void
    setAbscissa(double abs) {
        abscissa = abs;
    }

    void
    setOrdenada(double ord) {
        ordenada = ord;
    }

    void
    movimentar(double abs = 0, double ord = 0) {
        this->abscissa += abs;
        this->ordenada += ord;
    }

    void
    movimentar(const Point& point) {
        this->abscissa += point.getAbscissa();
        this->ordenada += point.getOrdenada();
    }

    void
    operator+=(const Point& point) {
        movimentar(point);
    }

    bool
    equal(const Point& point) {
        return (abscissa == point.getAbscissa()) && \
               (ordenada == point.getOrdenada());
    }

    bool
    operator==(const Point& point) {
        return equal(point);
    }

    void
    show() {
        std::cout << "(" << abscissa << ", " << ordenada << ")" << std::endl;
    }

    void
    distance(const Point& point, double *dist) {
        dist[0] = abscissa - point.getAbscissa();
        dist[1] = ordenada - point.getOrdenada();
    }

    double
    distance(const Point& point) {
        double x = abscissa - point.getAbscissa();
        double y = ordenada - point.getOrdenada();

        return sqrt(pow(x, 2) + pow(y, 2)); // Pitagoras.
    }

    void
    clone(const Point& point) {
        this->abscissa = point.getAbscissa();
        this->ordenada = point.getOrdenada();
    }
};

#endif
