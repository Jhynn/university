#ifndef __alumn_h
#define __alumn_h

#include <iostream>
#include <string>

class Alumn {
private:
    std::string name;
    float score_1, score_2, score_3;
public:
    Alumn(float score_1 = 0, float score_2 = 0, float score_3 = 0);
    ~Alumn();

    inline void
    setName(std::string alumn_name) {
        name = alumn_name;
    }

    inline std::string
    getName() {
        return name;
    }

    void
    setScore1(float score);

    float
    getScore1();

    void
    setScore2(float score);

    float
    getScore2();

    void
    setScore3(float score);

    float
    getScore3();

    void
    show();
};

#endif
