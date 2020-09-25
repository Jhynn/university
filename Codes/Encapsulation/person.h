#include <string>

class Person {
private:
    std::string name;
    unsigned long int cpf;
    unsigned int cep;
public:
    Person();
    Person(std::string user_name, unsigned int cep = 0, unsigned int cpf = 0);
    ~Person();

    void setName(std::string user_name);
    void setCpf(unsigned long int user_cpf);
    void setCep(unsigned int user_cep);

    unsigned long int getCpf();
    unsigned int getCep();
    std::string getName();

    void show();
};
