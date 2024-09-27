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

    // Destructor to demonstrate the use of delete
    ~Vehicle() {
        cout << "Vehicle " << this->type << " is being destroyed" << endl;
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

    // Destructor to demonstrate the use of delete
    ~TrafficSignal() {
        cout << "Traffic signal " << this->color << " is being destroyed" << endl;
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
    // Dynamically allocate memory for an array of Vehicle objects
    Vehicle* vehicles[3];
    vehicles[0] = new Vehicle("Car", 70);
    vehicles[1] = new Vehicle("Bus", 50);
    vehicles[2] = new Vehicle("Bike", 60);

    // Display information and simulate movement for each vehicle
    for (int i = 0; i < 3; i++) {
        vehicles[i]->displayInfo();
        vehicles[i]->move();
    }

    // Free the allocated memory for vehicles
    for (int i = 0; i < 3; i++) {
        delete vehicles[i];
    }

    // Dynamically allocate memory for an array of TrafficSignal objects
    TrafficSignal* signals[2];
    signals[0] = new TrafficSignal("Red", 30);
    signals[1] = new TrafficSignal("Green", 45);

    // Display status and change signal for each traffic signal
    for (int i = 0; i < 2; i++) {
        signals[i]->displayStatus();
        signals[i]->changeSignal(i == 0 ? "Green" : "Red");
    }

    // Free the allocated memory for signals
    for (int i = 0; i < 2; i++) {
        delete signals[i];
    }

    return 0;
}
