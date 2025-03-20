#include <iostream>
#include <string>
class Employee {
protected:
    std::string name;
    double salary;
public:
    Employee(const std::string& name, double salary) : name(name), salary(salary) {}

    virtual void printInfo() const {
        std::cout << "Employee Name: " << name << std::endl;
        std::cout << "Salary: $" << salary << std::endl;
    }

    virtual ~Employee() {}
};

class Manager : public Employee {
private:
    double bonus; 

public:
    Manager(const std::string& name, double salary, double bonus) : Employee(name, salary), bonus(bonus) {}

    void printInfo() const override {
        std::cout << "Manager Name: " << name << std::endl;
        std::cout << "Salary: $" << salary << std::endl;
        std::cout << "Bonus: $" << bonus << std::endl;
        std::cout << "Total Compensation: $" << salary + bonus << std::endl;
    }
};
