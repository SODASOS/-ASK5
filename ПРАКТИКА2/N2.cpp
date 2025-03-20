class Person {
protected:
    std::string name;
    int age;

public:
    Person(const std::string& name, int age) : name(name), age(age) {}

    virtual void printInfo() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
    }

    virtual ~Person() {} 
};

class Student : virtual public Person { 
protected:
    std::string university;

public:
    Student(const std::string& name, int age, const std::string& university)
        : Person(name, age), university(university) {}

    void printStudentInfo() const { 
        std::cout << "University: " << university << std::endl;
    }
};

class Worker : virtual public Person { 
protected:
    std::string company;

public:
    Worker(const std::string& name, int age, const std::string& company)
        : Person(name, age), company(company) {}

    void printWorkerInfo() const { 
        std::cout << "Company: " << company << std::endl;
    }
};

class Intern : public Student, public Worker {
public:
    Intern(const std::string& name, int age, const std::string& university, const std::string& company)
        : Person(name, age), Student(name, age, university), Worker(name, age, company) {}

    void printInfo() const override {
        Person::printInfo(); 
        Student::printStudentInfo(); 
        Worker::printWorkerInfo(); 
    }
};

int main() {
    std::cout << "--- Employee and Manager ---" << std::endl;
    Employee* emp1 = new Employee("John Doe", 50000.0);
    Employee* mgr1 = new Manager("Jane Smith", 75000.0, 15000.0);

    emp1->printInfo();
    std::cout << std::endl;
    mgr1->printInfo(); 

    delete emp1;
    delete mgr1;


    std::cout << "\n--- Person, Student, Worker, and Intern ---" << std::endl;
    Intern intern("Alice Johnson", 20, "Stanford", "Google");
    intern.printInfo(); 

    return 0;
}
