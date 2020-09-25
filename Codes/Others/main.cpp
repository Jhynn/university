#include "decToRoman.hpp"

int main(int argc, char const *argv[]) {
    DecimalToRoman dtr;
    dtr.show2();

    dtr.setNumber(4);
    dtr.show2();

    dtr.setNumber(5);
    dtr.show2();

    dtr.setNumber(9);
    dtr.show2();

    dtr.setNumber(10);
    dtr.show2();

    dtr.setNumber(50);
    dtr.show2();

    dtr.setNumber(100);
    dtr.show2();

    dtr.setNumber(500);
    dtr.show2();

    dtr.setNumber(1000);
    dtr.show2();

    dtr.setNumber(2019);
    dtr.show2();

    return 0;
}
