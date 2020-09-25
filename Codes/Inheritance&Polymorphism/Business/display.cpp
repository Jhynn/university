#include "company.h"
#include "employee.h"

int main(int argc, char const *argv[]) {
    Employee alinne("Alinne", "Surgery Center", 2048); // Centro cirúrgico.
    alinne.advanceTime(402);                           // 1 ano, 1 mês e 7 dias.
    alinne.setSalary(8192);
    alinne.show();
    printf("To save people.\n");

    return 0;
}

/*
int main(int argc, char const *argv[]) {
    Company company;
    Employee a, b, c;
    a.setName("Somebody");
    b.setName("Someone");
    c.setName("Anyone");

    company.toHire(a);
    company.toHire(b);
    company.toHire(c);

    company.setName("Cia");

    company.info();
    company.show();

    return 0;
}
*/
