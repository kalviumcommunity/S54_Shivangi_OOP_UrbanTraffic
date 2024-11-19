#include <iostream>
#include <string>

using namespace std;

/*
 * Class to represent a vehicle
 */
class Vehicle
{
private:
    string type;
    int speed;

public:
    static int vehicleCount;
    static int totalSpeed;

    Vehicle(string type, int speed)
    {
        this->type = type;
        this->speed = speed;
        vehicleCount++;
        totalSpeed += speed;
    }

    ~Vehicle()
    {
        vehicleCount--;
        totalSpeed -= speed;
    }

    void displayInfo()
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

    /*
     * Overloaded move() methods to demonstrate polymorphism
     */
    void move()
    {
        cout << this->type << " is moving at " << this->speed << " km/h." << endl;
    }

    void move(int distance)
    {
        cout << this->type << " is moving at " << this->speed << " km/h for " << distance << " km." << endl;
    }

    void setType(string type) { this->type = type; }
    void setSpeed(int speed) { this->speed = speed; }

    string getType() { return type; }
    int getSpeed() { return speed; }
};

int Vehicle::vehicleCount = 0;
int Vehicle::totalSpeed = 0;

/*
 * Car class inherits from the Vehicle class (Single Inheritance)
 */
class Car : public Vehicle
{
public:
    Car(int speed) : Vehicle("Car", speed) {}

    void honkHorn()
    {
        cout << "HONK! HONK!" << endl;
    }
};

/*
 * Bike class inherits from the Vehicle class (Single Inheritance)
 */
class Bike : public Vehicle
{
public:
    Bike(int speed) : Vehicle("Bike", speed) {}

    void pedal()
    {
        cout << "Pedaling..." << endl;
    }
};

/*
 * ElectricCar class inherits from the Car class (Multilevel Inheritance)
 */
class ElectricCar : public Car
{
    int batteryLevel;

public:
    ElectricCar(int speed, int batteryLevel) : Car(speed), batteryLevel(batteryLevel) {}
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
    Vehicle *vehicles[3];
    vehicles[0] = new Car(80);
    vehicles[1] = new ElectricCar(50, 100);
    vehicles[2] = new Bike(20);

    for (int i = 0; i < 3; i++)
    {
        vehicles[i]->displayInfo();
        vehicles[i]->move();   // Calls the default move()
        vehicles[i]->move(10); // Calls the overloaded move(int)
    }

    static_cast<Car *>(vehicles[0])->honkHorn();
    static_cast<ElectricCar *>(vehicles[1])->charge();
    static_cast<Bike *>(vehicles[2])->pedal();

    Vehicle::displayVehicleCount();
    Vehicle::displayTotalSpeed();
    cout << "Average Speed of All Vehicles: " << Vehicle::averageSpeed() << " km/h" << endl;

    for (int i = 0; i < 3; i++)
    {
        delete vehicles[i];
    }

    return 0;
}
