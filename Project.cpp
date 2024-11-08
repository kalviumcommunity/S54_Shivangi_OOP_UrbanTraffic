#include <iostream>
#include <string>

using namespace std;

/*
 * Abstract class to represent a vehicle, showcasing abstraction
 */
class Vehicle
{
private:
    string type; // Type of vehicle, private to restrict direct access
    int speed;   // Speed of vehicle, private to enforce encapsulation

protected:
    /*
     * Protected function to set type and speed, accessible by derived classes
     */
    void setAttributes(string type, int speed)
    {
        this->type = type;
        this->speed = speed;
    }

public:
    static int vehicleCount;
    static int totalSpeed;

    Vehicle() : type("Unknown"), speed(0)
    {
        vehicleCount++;
    }

    virtual ~Vehicle()
    {
        vehicleCount--;
        totalSpeed -= speed;
    }

    /*
     * Pure virtual method to enforce specific information display in derived classes
     */
    virtual void displayInfo() = 0;

    void move()
    {
        cout << type << " is moving at " << speed << " km/h." << endl;
    }

    string getType() const { return type; } // Public getter for type
    int getSpeed() const { return speed; }  // Public getter for speed

    static void displayVehicleCount()
    {
        cout << "Total Vehicles: " << vehicleCount << endl;
    }

    static void displayTotalSpeed()
    {
        cout << "Total Speed of All Vehicles: " << totalSpeed << " km/h" << endl;
    }

    static double averageSpeed()
    {
        return vehicleCount > 0 ? static_cast<double>(totalSpeed) / vehicleCount : 0;
    }
};

/*
 * Static variables of the Vehicle class
 */
int Vehicle::vehicleCount = 0;
int Vehicle::totalSpeed = 0;

/*
 * Car class, inheriting from Vehicle, demonstrating abstraction with an added feature
 */
class Car : public Vehicle
{
private:
    string engineType; // Private member to highlight encapsulation

public:
    Car(int speed, string engineType = "Petrol") : engineType(engineType)
    {
        setAttributes("Car", speed);
        totalSpeed += speed;
    }

    void displayInfo() override
    {
        cout << "Vehicle Type: " << getType() << "\nSpeed: " << getSpeed() << " km/h"
             << "\nEngine Type: " << engineType << endl;
    }

    void honkHorn()
    {
        cout << "HONK! HONK!" << endl;
    }
};

/*
 * Bike class, inheriting from Vehicle, with unique attributes
 */
class Bike : public Vehicle
{
public:
    Bike(int speed) 
    {
        setAttributes("Bike", speed);
        totalSpeed += speed;
    }

    void displayInfo() override
    {
        cout << "Vehicle Type: " << getType() << "\nSpeed: " << getSpeed() << " km/h" << endl;
    }

    void pedal()
    {
        cout << "Pedaling..." << endl;
    }
};

/*
 * ElectricCar class inherits from Car to demonstrate multilevel inheritance and abstraction
 */
class ElectricCar : public Car
{
private:
    int batteryLevel;

public:
    ElectricCar(int speed, int batteryLevel) : Car(speed, "Electric"), batteryLevel(batteryLevel)
    {
    }

    void displayInfo() override
    {
        cout << "Vehicle Type: " << getType() << "\nSpeed: " << getSpeed() << " km/h"
             << "\nBattery Level: " << batteryLevel << "%" << endl;
    }

    void charge()
    {
        cout << "Charging..." << endl;
    }
};

/*
 * Class representing a Traffic Signal with encapsulated attributes and methods
 */
class TrafficSignal
{
private:
    string color; // Restricted access to ensure encapsulation
    int timer;    // Timer for signal change, private for data hiding

public:
    TrafficSignal(string color, int timer) : color(color), timer(timer) {}

    void changeSignal(string newColor)
    {
        color = newColor;
        cout << "Traffic signal changed to " << color << endl;
    }

    void displayStatus()
    {
        cout << "Traffic Signal: " << color << "\nTimer: " << timer << " seconds" << endl;
    }

    void setColor(string color) { this->color = color; } // Setter with restricted access
    void setTimer(int timer) { this->timer = timer; }    // Setter with restricted access

    string getColor() const { return color; } // Getter to access private color
    int getTimer() const { return timer; }    // Getter to access private timer
};

/*
 * Main function to demonstrate abstraction in action
 */
int main()
{
    Vehicle* vehicles[3];

    vehicles[0] = new Car(80, "Petrol");       // Car with petrol engine
    vehicles[1] = new ElectricCar(50, 100);    // Electric car with battery level
    vehicles[2] = new Bike(20);                // Bike with speed

    for (int i = 0; i < 3; i++)
    {
        vehicles[i]->displayInfo();
        vehicles[i]->move();
    }

    static_cast<Car*>(vehicles[0])->honkHorn();
    static_cast<ElectricCar*>(vehicles[1])->charge();
    static_cast<Bike*>(vehicles[2])->pedal();

    Vehicle::displayVehicleCount();
    Vehicle::displayTotalSpeed();
    cout << "Average Speed of All Vehicles: " << Vehicle::averageSpeed() << " km/h" << endl;

    TrafficSignal* signals[2];
    signals[0] = new TrafficSignal("Red", 30);
    signals[1] = new TrafficSignal("Green", 45);

    for (int i = 0; i < 2; i++)
    {
        signals[i]->displayStatus();
        signals[i]->changeSignal(i == 0 ? "Green" : "Red");
    }

    for (int i = 0; i < 3; i++)
    {
        delete vehicles[i];
    }

    for (int i = 0; i < 2; i++)
    {
        delete signals[i];
    }

    return 0;
}
