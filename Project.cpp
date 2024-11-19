#include <iostream>
#include <string>

using namespace std;

/*
 * Abstract base class to represent a general vehicle
 */
class VehicleBase
{
public:
    virtual void move() = 0;          // Pure virtual function
    virtual void displayInfo() = 0;  // Virtual function
    virtual ~VehicleBase() {}        // Virtual destructor
};

/*
 * Class to represent a vehicle, inheriting from VehicleBase
 */
class Vehicle : public VehicleBase
{
private:
    string type;
    int speed;

public:
    static int vehicleCount;
    static int totalSpeed;

    Vehicle(string type, int speed) : type(type), speed(speed)
    {
        vehicleCount++;
        totalSpeed += speed;
    }

    ~Vehicle()
    {
        vehicleCount--;
        totalSpeed -= speed;
    }

    void move() override
    {
        cout << this->type << " is moving at " << this->speed << " km/h." << endl;
    }

    void displayInfo() override
    {
        cout << "Vehicle Type: " << this->type << "\nSpeed: " << this->speed << " km/h" << endl;
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

protected:
    string getType() { return type; }
    int getSpeed() { return speed; }
};

int Vehicle::vehicleCount = 0;
int Vehicle::totalSpeed = 0;

/*
 * Car class inherits from Vehicle
 */
class Car : public Vehicle
{
public:
    Car(int speed) : Vehicle("Car", speed) {}

    void move() override
    {
        cout << "Car is cruising at " << getSpeed() << " km/h." << endl;
    }

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
    Bike(int speed) : Vehicle("Bike", speed) {}

    void move() override
    {
        cout << "Bike is pedaling at " << getSpeed() << " km/h." << endl;
    }

    void pedal()
    {
        cout << "Pedaling..." << endl;
    }
};

/*
 * ElectricCar class inherits from Car
 */
class ElectricCar : public Car
{
    int batteryLevel;

public:
    ElectricCar(int speed, int batteryLevel) : Car(speed), batteryLevel(batteryLevel) {}

    void move() override
    {
        cout << "Electric Car is gliding at " << getSpeed() << " km/h with " << batteryLevel << "% battery." << endl;
    }

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
    vehicles[0] = new Car(80);            // Car object
    vehicles[1] = new ElectricCar(50, 100); // ElectricCar object
    vehicles[2] = new Bike(20);           // Bike object

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

    // Static member function calls
    Vehicle::displayVehicleCount();
    Vehicle::displayTotalSpeed();
    cout << "Average Speed of All Vehicles: " << Vehicle::averageSpeed() << " km/h" << endl;

    // Clean up dynamically allocated objects
    for (int i = 0; i < 3; i++)
    {
        delete vehicles[i];
    }

    return 0;
}

