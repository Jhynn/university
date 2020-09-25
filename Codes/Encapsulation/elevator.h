class Elevator
{
private:
    unsigned int total_floors;
    unsigned int current_floor;
    unsigned int lift_capacity;
    unsigned int present_people;
public:
    Elevator(unsigned int elevator_capacity, unsigned int elevator_total_floors);
    ~Elevator();

    unsigned int getCurrentFloor();
    unsigned int getPresentPeople();

    void goUp(unsigned int up_to = 0);
    void enterTheElevator(unsigned int people = 0);
    void skirt(unsigned int minus_people = 0);
    void goDown(unsigned int down_to = 0);
    void show();
};
