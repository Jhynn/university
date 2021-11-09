#include <iostream>
#include "alumn.h"

Alumn::Alumn(float user_score_1, float user_score_2, float user_score_3) {
    score_1 = user_score_1;
    score_2 = user_score_2;
    score_3 = user_score_3;
}

Alumn::~Alumn() {

}

void
Alumn::setScore1(float score) {
    score_1 = score;
}

float
Alumn::getScore1() {
    return score_1;
}

void
Alumn::setScore2(float score) {
    score_2 = score;
}

float
Alumn::getScore2() {
    return score_2;
}

void
Alumn::setScore3(float score) {
    score_3 = score;
}

float
Alumn::getScore3() {
    return score_3;
}

void
Alumn::show() {
    if (!name.empty()) std::cout << name << std::endl;
    
    std::cout << "1ª nota: " << score_1 << std::endl;
    std::cout << "2ª nota: " << score_2 << std::endl;
    std::cout << "3ª nota: " << score_3 << std::endl;
}
