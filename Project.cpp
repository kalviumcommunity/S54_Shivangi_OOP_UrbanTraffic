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
 * Movement behavior interface
 */
class MovementBehavior
{
public:
    virtual void executeMove(const string &type, int speed) = 0;
    virtual ~MovementBehavior() {}
};

/*
 * Concrete movement behaviors
 */
class StandardMovement : public MovementBehavior
{
public:
    void executeMove(const string &type, int speed) override
    {
        cout << type << " is moving at " << speed << " km/h." << endl;
    }
};

class CruisingMovement : public MovementBehavior
{
public:
    void executeMove(const string &type, int speed) override
    {
        cout << type << " is cruising at " << speed << " km/h." << endl;
    }
};

class PedalingMovement : public MovementBehavior
{
public:
    void executeMove(const string &type, int speed) override
    {
        cout << type << " is pedaling at " << speed << " km/h." << endl;
    }
};

class GlidingMovement : public MovementBehavior
{
public:
    void executeMove(const string &type, int speed) override
    {
        cout << type << " is gliding at " << speed << " km/h." << endl;
    }
};

/*
 * Interface for rechargeable vehicles
 */
class Rechargeable
{
public:
    virtual void charge() = 0;
    virtual int getBatteryLevel() const = 0;
    virtual ~Rechargeable() {}
};

/*
 * Interface for vehicles that can make sounds
 */
class SoundMaker
{
public:
    virtual void makeSound() = 0;
    virtual ~SoundMaker() {}
};

/*
 * Class to represent a vehicle, inheriting from VehicleBase
 */
class Vehicle : public VehicleBase
{
private:
    string type;
    int speed;
    MovementBehavior *movementBehavior;

public:
    Vehicle(string type, int speed, MovementBehavior *behavior)
        : type(type), speed(speed), movementBehavior(behavior)
    {
        VehicleStatistics::incrementVehicle(speed);
    }

    virtual ~Vehicle()
    {
        VehicleStatistics::decrementVehicle(speed);
        delete movementBehavior;
    }

    void move() override
    {
        movementBehavior->executeMove(type, speed);
    }

    void displayInfo() override
    {
        cout << "Vehicle Type: " << this->type << "\nSpeed: " << this->speed << " km/h" << endl;
    }

protected:
    string getType() const { return type; }
    int getSpeed() const { return speed; }
};

/*
 * Car class inherits from Vehicle and implements SoundMaker
 */
class Car : public Vehicle, public SoundMaker
{
public:
    Car(int speed) : Vehicle("Car", speed, new CruisingMovement()) {}

    void makeSound() override
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
    Bike(int speed) : Vehicle("Bike", speed, new PedalingMovement()) {}

    void pedal()
    {
        cout << "Pedaling..." << endl;
    }
};

/*
 * ElectricCar class inherits from Vehicle and implements Rechargeable and SoundMaker
 */
class ElectricCar : public Vehicle, public Rechargeable, public SoundMaker
{
private:
    int batteryLevel;

public:
    ElectricCar(int speed, int batteryLevel)
        : Vehicle("Electric Car", speed, new GlidingMovement()),
          batteryLevel(batteryLevel) {}

    void move() override
    {
        if (batteryLevel > 0)
        {
            Vehicle::move();
            batteryLevel--; // Simulate battery consumption
        }
        else
        {
            cout << "Cannot move: Battery depleted!" << endl;
        }
    }

    void displayInfo() override
    {
        Vehicle::displayInfo();
        cout << "Battery Level: " << batteryLevel << "%" << endl;
    }

    // Implement Rechargeable interface
    void charge() override
    {
        batteryLevel = min(100, batteryLevel + 20);
        cout << "Charging... Battery level now at " << batteryLevel << "%" << endl;
    }

    int getBatteryLevel() const override
    {
        return batteryLevel;
    }

    // Implement SoundMaker interface
    void makeSound() override
    {
        cout << "Gentle Electric Hum!" << endl;
    }
};

/*
 * ElectricScooter class inherits from Vehicle and implements Rechargeable
 */
class ElectricScooter : public Vehicle, public Rechargeable
{
private:
    int batteryLevel;

public:
    ElectricScooter(int speed, int batteryLevel)
        : Vehicle("Electric Scooter", speed, new StandardMovement()),
          batteryLevel(batteryLevel) {}

    void move() override
    {
        if (batteryLevel > 0)
        {
            Vehicle::move();
            batteryLevel--; // Simulate battery consumption
        }
        else
        {
            cout << "Cannot move: Battery depleted!" << endl;
        }
    }

    void displayInfo() override
    {
        Vehicle::displayInfo();
        cout << "Battery Level: " << batteryLevel << "%" << endl;
    }

    // Implement Rechargeable interface
    void charge() override
    {
        batteryLevel = min(100, batteryLevel + 20);
        cout << "Charging... Battery level now at " << batteryLevel << "%" << endl;
    }

    int getBatteryLevel() const override
    {
        return batteryLevel;
    }
};

/*
 * Scooter class inherits from Vehicle
 */
class Scooter : public Vehicle
{
public:
    Scooter(int speed) : Vehicle("Scooter", speed, new StandardMovement()) {}
};

/*
 * Class to represent a traffic signal
 */
class TrafficSignal
{
private:
    string color;
    int timer;

public:
    TrafficSignal(string color, int timer)
    {
        this->color = color;
        this->timer = timer;
    }

    void changeSignal(string newColor)
    {
        this->color = newColor;
        cout << "Traffic signal changed to " << this->color << endl;
    }

    void displayStatus()
    {
        cout << "Traffic Signal: " << this->color << "\nTimer: " << this->timer << " seconds" << endl;
    }

    void setColor(string color) { this->color = color; }
    void setTimer(int timer) { this->timer = timer; }

    string getColor() { return color; }
    int getTimer() { return timer; }
};

/*
 * Main function
 */
int main()
{
    // Create an array of pointers to VehicleBase
    VehicleBase *vehicles[5];
    vehicles[0] = new Car(80);
    vehicles[1] = new ElectricCar(50, 100);
    vehicles[2] = new Bike(20);
    vehicles[3] = new ElectricScooter(30, 80);
    vehicles[4] = new Scooter(25);

    // Demonstrate polymorphism through the move() function
    for (int i = 0; i < 5; i++)
    {
        vehicles[i]->displayInfo();
        vehicles[i]->move();
        cout << endl;
    }

    // Demonstrate LSP with SoundMaker interface
    SoundMaker *soundMakers[] = {
        dynamic_cast<SoundMaker *>(vehicles[0]), // Car
        dynamic_cast<SoundMaker *>(vehicles[1])  // ElectricCar
    };

    cout << "\nDemonstrating vehicle sounds:" << endl;
    for (SoundMaker *sm : soundMakers)
    {
        if (sm)
            sm->makeSound();
    }

    // Demonstrate LSP with Rechargeable interface
    cout << "\nDemonstrating charging capabilities:" << endl;
    for (int i = 0; i < 5; i++)
    {
        Rechargeable *rechargeable = dynamic_cast<Rechargeable *>(vehicles[i]);
        if (rechargeable)
        {
            cout << "Charging vehicle " << i + 1 << ":" << endl;
            rechargeable->charge();
        }
    }

    // Static member function calls using VehicleStatistics class
    cout << "\nVehicle Statistics:" << endl;
    VehicleStatistics::displayVehicleCount();
    VehicleStatistics::displayTotalSpeed();
    cout << "Average Speed of All Vehicles: " << VehicleStatistics::averageSpeed() << " km/h" << endl;

    // Clean up dynamically allocated objects
    for (int i = 0; i < 5; i++)
    {
        delete vehicles[i];
    }

    return 0;
}
