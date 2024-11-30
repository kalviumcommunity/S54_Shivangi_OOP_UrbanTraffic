#include <iostream>
#include <string>

using namespace std;

/*
 * Abstract base class to represent a general vehicle
 */
class VehicleBase
{
public:
    virtual void move() = 0;        // Pure virtual function
    virtual void displayInfo() = 0; // Virtual function
    virtual ~VehicleBase() {}       // Virtual destructor
};

/*
 * Class to handle vehicle statistics
 */
class VehicleStatistics
{
private:
    static int vehicleCount;
    static int totalSpeed;

public:
    static void incrementVehicle(int speed)
    {
        vehicleCount++;
        totalSpeed += speed;
    }

    static void decrementVehicle(int speed)
    {
        vehicleCount--;
        totalSpeed -= speed;
    }

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

int VehicleStatistics::vehicleCount = 0;
int VehicleStatistics::totalSpeed = 0;

/*
 * Movement strategy interface following Open/Closed Principle
 */
class MovementStrategy {
public:
    virtual void executeMove(const string& type, int speed) = 0;
    virtual ~MovementStrategy() {}
};

/*
 * Concrete movement strategies
 */
class StandardMovement : public MovementStrategy {
public:
    void executeMove(const string& type, int speed) override {
        cout << type << " is moving at " << speed << " km/h." << endl;
    }
};

class CarMovement : public MovementStrategy {
public:
    void executeMove(const string& type, int speed) override {
        cout << type << " is cruising at " << speed << " km/h." << endl;
    }
};

class BikeMovement : public MovementStrategy {
public:
    void executeMove(const string& type, int speed) override {
        cout << type << " is pedaling at " << speed << " km/h." << endl;
    }
};

class ElectricMovement : public MovementStrategy {
private:
    int batteryLevel;
public:
    ElectricMovement(int battery) : batteryLevel(battery) {}
    void executeMove(const string& type, int speed) override {
        cout << type << " is gliding at " << speed << " km/h with " << batteryLevel << "% battery." << endl;
    }
};

/*
 * Class to represent a vehicle, inheriting from VehicleBase
 */
class Vehicle : public VehicleBase
{
private:
    string type;
    int speed;
    MovementStrategy* moveStrategy;

public:
    Vehicle(string type, int speed, MovementStrategy* strategy) 
        : type(type), speed(speed), moveStrategy(strategy)
    {
        VehicleStatistics::incrementVehicle(speed);
    }

    ~Vehicle()
    {
        VehicleStatistics::decrementVehicle(speed);
        delete moveStrategy;
    }

    void move() override
    {
        moveStrategy->executeMove(type, speed);
    }

    void displayInfo() override
    {
        cout << "Vehicle Type: " << this->type << "\nSpeed: " << this->speed << " km/h" << endl;
    }

protected:
    string getType() { return type; }
    int getSpeed() { return speed; }
};

/*
 * Car class inherits from Vehicle
 */
class Car : public Vehicle
{
public:
    Car(int speed) : Vehicle("Car", speed, new CarMovement()) {}

    void honkHorn()
    {
        cout << "HONK! HONK!" << endl;
    }
};

/*
 * Bike class inherits from Vehicle
 */
class Bike : public Vehicle
{
public:
    Bike(int speed) : Vehicle("Bike", speed, new BikeMovement()) {}

    void pedal()
    {
        cout << "Pedaling..." << endl;
    }
};

/*
 * ElectricCar class inherits from Car
 */
class ElectricCar : public Vehicle
{
    int batteryLevel;

public:
    ElectricCar(int speed, int batteryLevel) 
        : Vehicle("Electric Car", speed, new ElectricMovement(batteryLevel)),
          batteryLevel(batteryLevel) {}

    void charge()
    {
        cout << "Charging..." << endl;
    }
};

/*
 * Class to represent a traffic signal
 */
class TrafficSignal
{
private:
    /*
     * Private variables of the TrafficSignal class
     */
    string color;
    int timer;

public:
    /*
     * Constructor to create a TrafficSignal object
     * @param color the color of the traffic signal
     * @param timer the timer of the traffic signal
     */
    TrafficSignal(string color, int timer)
    {
        this->color = color;
        this->timer = timer;
    }

    /*
     * Method to change the color of a TrafficSignal object
     * @param newColor the new color of the traffic signal
     */
    void changeSignal(string newColor)
    {
        this->color = newColor;
        cout << "Traffic signal changed to " << this->color << endl;
    }

    /*
     * Method to display the status of a TrafficSignal object
     */
    void displayStatus()
    {
        cout << "Traffic Signal: " << this->color << "\nTimer: " << this->timer << " seconds" << endl;
    }

    /*
     * Setter functions for color and timer
     */
    void setColor(string color) { this->color = color; }
    void setTimer(int timer) { this->timer = timer; }

    /*
     * Getter functions for color and timer
     */
    string getColor() { return color; }
    int getTimer() { return timer; }
};

/*
 * Main function
 */
int main()
{
    // Create an array of pointers to VehicleBase
    VehicleBase *vehicles[3];
    vehicles[0] = new Car(80);              // Car object
    vehicles[1] = new ElectricCar(50, 100); // ElectricCar object
    vehicles[2] = new Bike(20);             // Bike object

    // Demonstrate polymorphism through the move() function
    for (int i = 0; i < 3; i++)
    {
        vehicles[i]->displayInfo();
        vehicles[i]->move();
    }

    // Specific functionality of derived classes
    static_cast<Car *>(vehicles[0])->honkHorn();
    static_cast<ElectricCar *>(vehicles[1])->charge();
    static_cast<Bike *>(vehicles[2])->pedal();

    // Static member function calls using VehicleStatistics class
    VehicleStatistics::displayVehicleCount();
    VehicleStatistics::displayTotalSpeed();
    cout << "Average Speed of All Vehicles: " << VehicleStatistics::averageSpeed() << " km/h" << endl;

    // Clean up dynamically allocated objects
    for (int i = 0; i < 3; i++)
    {
        delete vehicles[i];
    }

    return 0;
}
