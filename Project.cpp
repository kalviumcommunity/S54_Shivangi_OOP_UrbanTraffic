#include <iostream>
#include <string>

using namespace std;

// Vehicle class
class Vehicle {
private:
    string type;
    int speed;

public:
    // Constructor method using the 'this' pointer
    Vehicle(string type, int speed) {
        this->type = type;  
        this->speed = speed;  
    }

    // Function to display vehicle information
    void displayInfo() {
        cout << "Vehicle Type: " << this->type << "\nSpeed: " << this->speed << " km/h" << endl;
    }

    // Function to simulate movement
    void move() {
        cout << this->type << " is moving at " << this->speed << " km/h." << endl;
    }

    // Function to change speed using 'this' pointer
    Vehicle* accelerate(int increment) {
        this->speed += increment;
        return this;
    }
};

// TrafficSignal class
class TrafficSignal {
private:
    string color;
    int timer;

public:
    // Constructor method using the 'this' pointer
    TrafficSignal(string color, int timer) {
        this->color = color;  
        this->timer = timer;  
    }

    // Function to change signal
    void changeSignal(string newColor) {
        this->color = newColor;
        cout << "Traffic signal changed to " << this->color << endl;
    }

    // Function to display signal status
    void displayStatus() {
        cout << "Traffic Signal: " << this->color << "\nTimer: " << this->timer << " seconds" << endl;
    }
};

int main() {
    // Car object for Vehicle class
    Vehicle car("Car", 80);
    car.displayInfo();
    car.accelerate(20)->move();  

    // Object for TrafficSignal class
    TrafficSignal signal("Red", 30);
    signal.displayStatus();
    signal.changeSignal("Green");

    return 0;
}
