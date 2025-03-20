#include <iostream>
#include <vector>
#include <string>
class Engine {
public:
    Engine() {
        std::cout << "Engine created." << std::endl;
    }
    ~Engine() {
        std::cout << "Engine destroyed." << std::endl;
    }

    void run() {
        std::cout << "Engine is running..." << std::endl;
    }
};

class Car {
private:
    Engine engine; 

public:
    Car() : engine() {
        std::cout << "Car created." << std::endl;
    }
    ~Car() {
        std::cout << "Car destroyed." << std::endl;
    }

    void start() {
        std::cout << "Starting the car..." << std::endl;
        engine.run();
    }
};

