#include <iostream>
#include <string>

using namespace std;

/*
 * Abstract class to represent a vehicle
 */
class Vehicle
{
private:
    /*
     * Private variables of the Vehicle class
     */
    string type;
    int speed;

public:
    static int vehicleCount;
    static int totalSpeed;

    /*
     * Constructor to create a Vehicle object
     * @param type the type of the vehicle
     * @param speed the speed of the vehicle
     */
    Vehicle(string type, int speed) : type(type), speed(speed)
    {
        vehicleCount++;
        totalSpeed += speed;
    }

    /*
     * Destructor to release the resources of a Vehicle object
     */
    virtual ~Vehicle()
    {
        vehicleCount--;
        totalSpeed -= speed;
    }

    /*
     * Pure virtual method to display the information of a Vehicle object
     * Making this a pure virtual function makes Vehicle an abstract class
     */
    virtual void displayInfo() = 0; // pure virtual

    /*
     * Static method to display the total number of Vehicle objects
     */
    static void displayVehicleCount()
    {
        cout << "Total Vehicles: " << vehicleCount << endl;
    }

    /*
     * Static method to display the total speed of all Vehicle objects
     */
    static void displayTotalSpeed()
    {
        cout << "Total Speed of All Vehicles: " << totalSpeed << " km/h" << endl;
    }

    /*
     * Static method to calculate the average speed of all Vehicle objects
     * @return the average speed of all Vehicle objects
     */
    static double averageSpeed()
    {
        return vehicleCount > 0 ? static_cast<double>(totalSpeed) / vehicleCount : 0;
    }

    /*
     * Method to simulate the movement of a Vehicle object
     */
    void move()
    {
        cout << this->type << " is moving at " << this->speed << " km/h." << endl;
    }

    /*
     * Setter functions for type and speed
     */
    void setType(string type) { this->type = type; }
    void setSpeed(int speed) { this->speed = speed; }

    /*
     * Getter functions for type and speed
     */
    string getType() { return type; }
    int getSpeed() { return speed; }
};

/*
 * Static variables of the Vehicle class
 */
int Vehicle::vehicleCount = 0;
int Vehicle::totalSpeed = 0;

/*
 * Car class inherits from the Vehicle class (Single Inheritance)
 */
class Car : public Vehicle
{
public:
    Car(int speed) : Vehicle("Car", speed) {}

    /*
     * Override the displayInfo() method
     */
    void displayInfo() override
    {
        cout << "Vehicle Type: " << getType() << "\nSpeed: " << getSpeed() << " km/h" << endl;
    }

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

    /*
     * Override the displayInfo() method
     */
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
 * ElectricCar class inherits from the Car class (Multilevel Inheritance)
 */
class ElectricCar : public Car
{
    int batteryLevel;

public:
    ElectricCar(int speed, int batteryLevel) : Car(speed), batteryLevel(batteryLevel) {}

    /*
     * Override the displayInfo() method
     */
    void displayInfo() override
    {
        cout << "Vehicle Type: " << getType() << "\nSpeed: " << getSpeed() << " km/h\nBattery Level: " << batteryLevel << "%" << endl;
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
    Vehicle *vehicles[3];
    /*
     * Creating objects of the inherited classes using constructors
     */
    vehicles[0] = new Car(80);
    vehicles[1] = new ElectricCar(50, 100);
    vehicles[2] = new Bike(20);

    for (int i = 0; i < 3; i++)
    {
        vehicles[i]->displayInfo(); // Calls the overridden method
        vehicles[i]->move();
    }

    /*
     * Calling methods of inherited classes
     */
    static_cast<Car *>(vehicles[0])->honkHorn();
    static_cast<ElectricCar *>(vehicles[1])->charge();
    static_cast<Bike *>(vehicles[2])->pedal();

    /*
     * Demonstrating function overloading
     */
    vehicles[0]->displayInfo();
    vehicles[1]->displayInfo();
    vehicles[2]->displayInfo();

    Vehicle::displayVehicleCount();
    Vehicle::displayTotalSpeed();
    cout << "Average Speed of All Vehicles: " << Vehicle::averageSpeed() << " km/h" << endl;

    TrafficSignal *signals[2];
    signals[0] = new TrafficSignal("Red", 30);
    signals[1] = new TrafficSignal("Green", 45);

    for (int i = 0; i < 2; i++)
    {
        signals[i]->displayStatus();
        signals[i]->changeSignal(i == 0 ? "Green" : "Red");
    }

    /*
     * Deleting the objects by calling destructors
     */
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
