#include <iostream>
#include <vector>
#include <string>
class Manager; 

class Programmer {
private:
    std::string name;
    Manager* manager; 

public:
    Programmer(const std::string& programmerName) : name(programmerName), manager(nullptr) {
        std::cout << "Programmer " << name << " created." << std::endl;
    }
    ~Programmer() {
        std::cout << "Programmer " << name << " destroyed." << std::endl;
    }

    std::string getName() const {
        return name;
    }

    void setManager(Manager* newManager) {
        manager = newManager;
    }

    Manager* getManager() const {
        return manager;
    }
};

class Manager {
private:
    std::string name;
    std::vector<Programmer*> subordinates;

public:
    Manager(const std::string& managerName) : name(managerName) {
        std::cout << "Manager " << name << " created." << std::endl;
    }
    ~Manager() {
        std::cout << "Manager " << name << " destroyed." << std::endl;
    }

    std::string getName() const {
        return name;
    }

    void assignProgrammer(Programmer* programmer) {
        subordinates.push_back(programmer);
        programmer->setManager(this); // Устанавливаем менеджера у программиста
        std::cout << "Programmer " << programmer->getName() << " assigned to manager " << name << "." << std::endl;
    }

    void listSubordinates() const {
        std::cout << "List of subordinates for manager " << name << ":" << std::endl;
        for (const auto& programmer : subordinates) {
            std::cout << "- " << programmer->getName() << std::endl;
        }
    }
};

int main() {

    std::cout << "--- Composotion ---" << std::endl;
    Car myCar;
    myCar.start();

    std::cout << "\n--- Aggregation ---" << std::endl;
    University myUniversity;
    Student* student1 = new Student("Alice");
    Student* student2 = new Student("Bob");
    myUniversity.addStudent(student1);
    myUniversity.addStudent(student2);
    myUniversity.listStudents();

    delete student1;
    delete student2;
  
    std::cout << "\n--- Bidirectional Association ---" << std::endl;
    Manager manager1("John");
    Programmer programmer1("Charlie");
    Programmer programmer2("David");

    manager1.assignProgrammer(&programmer1);
    manager1.assignProgrammer(&programmer2);
    manager1.listSubordinates();


    if (programmer1.getManager() != nullptr) {
        std::cout << "Programmer " << programmer1.getName() << " is managed by "
                  << programmer1.getManager()->getName() << std::endl;
    } else {
        std::cout << "Programmer " << programmer1.getName() << " has no manager." << std::endl;
    }

    return 0;
}
