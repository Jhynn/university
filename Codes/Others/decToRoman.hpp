#include <iostream>

class DecimalToRoman
{
private:
    int  number;
    char dictionary[8];
public:
    DecimalToRoman(int number = 1) {
        this->number  = number;
        dictionary[0] = 'I'; // 1,
        dictionary[1] = 'V'; // 5,
        dictionary[2] = 'X'; // 10,
        dictionary[3] = 'L'; // 50,
        dictionary[4] = 'C'; // 100,
        dictionary[5] = 'D'; // 500,
        dictionary[6] = 'M'; // 1.000,
    }

    void setNumber(int number) {
        this->number = number;
    }

    void show() {
        int aux, j;
        std::cout << number << " = ";
        do {
            if (number / 1000 != 0) {
                aux = number / 1000;
                number %= 1000;
                j = 6;
            }

            else if (number / 500 != 0) {
                aux = number / 500;
                number %= 500;
                j = 5;
            }

            else if (number / 100 != 0) {
                aux = number / 100;
                number %= 100;
                j = 4;
            }

            else if (number / 50 != 0) {
                aux = number / 50;
                number %= 50;
                j = 3;
            }

            else if (number / 10 != 0) {
                aux = number / 10;
                number %= 10;
                j = 2;
            }

            else if (number / 9 != 0) {
                aux = number / 9;
                number %= 9;
                std::cout << "IX";
                continue;
            }

            else if (number / 5 != 0) {
                aux = number / 5;
                number %= 5;
                j = 1;
            }

            else if (number / 4 != 0) {
                aux = number / 4;
                number %= 4;
                std::cout << "IV";
                continue;
            }

            else {
                aux    = number;
                number = j = 0;
            }

            for (int i = 0; i < aux; i++)
                std::cout << dictionary[j];

        } while (number);
        std::cout << std::endl;
        number = this->number;
    }

    void show2() {
        int k, j = number;
        std::cout << j << " = ";
        do {
            if (j / 1000 != 0) {
                k = j / 1000;
                j %= 1000;
                std::cout << "M";
                continue;
            }

            else if (j / 500 != 0) {
                k = j / 500;
                j %= 500;
                std::cout << "D";
                continue;
            }

            else if (j / 100 != 0) {
                k = j / 100;
                j %= 100;
                std::cout << "C";
                continue;
            }

            else if (j / 50 != 0) {
                k = j / 50;
                j %= 50;
                std::cout << "L";
                continue;
            }

            else if (j / 10 != 0) {
                k = j / 10;
                j %= 10;
                std::cout << "X";
                continue;
            }

            else if (j / 9 != 0) {
                k = j / 9;
                j %= 9;
                std::cout << "IX";
                continue;
            }

            else if (j / 5 != 0) {
                k = j / 5;
                j %= 5;
                std::cout << "V";
                continue;
            }

            else if (j / 4 != 0) {
                k = j / 4;
                j %= 4;
                std::cout << "IV";
                continue;
            }

            else {
                std::cout << "I";
                j = 0;
                continue;
            }
        } while (j);
        std::cout << std::endl;
    }
};
