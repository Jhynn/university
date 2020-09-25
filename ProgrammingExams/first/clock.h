class Clock {
private:
    unsigned int hours;
    unsigned int minutes;
    unsigned int seconds;
public:
    Clock(unsigned int time_in_seconds = 0);
    
    void setTime(unsigned int timeInSeconds);
    void proceede(int advance_seconds);
    void show();

    void operator+(int sec);
    void operator-(int sec);
};
