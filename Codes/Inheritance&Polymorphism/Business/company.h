#ifndef __company_h
#define __company_h

#include <string>
#include "employee.h"
#include <list>

class Company
{
private:
    static unsigned int id;

    std::string name;
    Employee*   employees[9]; // Vetor de ponteiros para Empregados.
    int         employeesQuantity;
public:
    Company();
    Company(std::string companyName);

    void setName(std::string newName);

    unsigned int getId()   const;
    std::string  getName() const;

    void toHire(Employee &employee);                          // Contratar.
    void toDismiss(std::string employeeName);                 // Despedir.
    void toSubsidize(std::string department, float percents); // Bonificar.
    void show();
    void info();
};

#endif
