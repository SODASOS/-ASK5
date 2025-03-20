
class Student {
private:
    std::string name;

public:
    Student(const std::string& studentName) : name(studentName) {
        std::cout << "Student " << name << " created." << std::endl;
    }
    ~Student() {
        std::cout << "Student " << name << " destroyed." << std::endl;
    }

    std::string getName() const {
        return name;
    }
};

class University {
private:

public:
    University() {
        std::cout << "University created." << std::endl;
    }
    ~University() {
        std::cout << "University destroyed." << std::endl;
   
    }

    void addStudent(Student* student) {
        students.push_back(student);
        std::cout << "Student " << student->getName() << " added to university." << std::endl;
    }

    void listStudents() const {
        std::cout << "List of students in the university:" << std::endl;
        for (const auto& student : students) {
            std::cout << "- " << student->getName() << std::endl;
        }
    }
};

