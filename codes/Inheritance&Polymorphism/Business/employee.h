#ifndef __employee_h
#define __employee_h

#include <string>

class Employee {
private:
    std::string  name;
    std::string  department;
    unsigned int time;
    float        salary;
public:
    Employee();
    Employee(std::string name, std::string department, float salary);

    void setName(std::string userName);
    void setSalary(float salary);
    void setDepartment(std::string department);

    void        getTime();
    std::string getName();
    std::string getDepartment();
    float       getSalary();

    void advanceTime(unsigned int time);
    void show();
};

#endif
