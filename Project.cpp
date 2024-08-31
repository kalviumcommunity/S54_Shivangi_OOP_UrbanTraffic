#include <iostream>
#include <string>

using namespace std;

// Vehicle class
class Vehicle {
private:
    string type;
    int speed;

public:
    // constructor method
    Vehicle(string t, int s) : type(t), speed(s) {}

    // function to display vehicle information
    void displayInfo() {
        cout << "Vehicle Type: " << type << "\nSpeed: " << speed << " km/h" << endl;
    }

    // function to simulate movement
    void move() {
        cout << type << " is moving at " << speed << " km/h." << endl;
    }
};

//TrafficSignal class
class TrafficSignal {
private:
    string color;
    int timer;

public:
    // constructor method
    TrafficSignal(string c, int t) : color(c), timer(t) {}

    // function to change signal
    void changeSignal(string newColor) {
        color = newColor;
        cout << "Traffic signal changed to " << color << endl;
    }

    // function to display signal status
    void displayStatus() {
        cout << "Traffic Signal: " << color << "\nTimer: " << timer << " seconds" << endl;
    }
};

int main() {
    // car object for Vehicle class
    Vehicle car("Car", 80);
    car.displayInfo();
    car.move();

    // object for TrafficSignal class
    TrafficSignal signal("Red", 30);
    signal.displayStatus();
    signal.changeSignal("Green");

    return 0;
}
