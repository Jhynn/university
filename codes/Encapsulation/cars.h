class Car {
private:
    float km_l;
    float fuel_tank;
public:
    Car();
    ~Car();

    void
    show();
    
    void
    driveUp(int km);
    
    void
    refuelTank(float liters);
};
