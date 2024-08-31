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

    // Function to change speed using 'this' pointer, demonstrating method chaining
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
    // Array of Vehicle objects
    Vehicle vehicles[3] = {
        Vehicle("Car", 80),
        Vehicle("Bus", 50),
        Vehicle("Bike", 60)
    };

    // Display information and simulate movement for each vehicle
    for (int i = 0; i < 3; i++) {
        vehicles[i].displayInfo();
        vehicles[i].move();
    }

    // Array of TrafficSignal objects
    TrafficSignal signals[2] = {
        TrafficSignal("Red", 30),
        TrafficSignal("Green", 45)
    };

    // Display status and change signal for each traffic signal
    for (int i = 0; i < 2; i++) {
        signals[i].displayStatus();
        signals[i].changeSignal(i == 0 ? "Green" : "Red");
    }

    return 0;
}
