#include <iostream>
#include <string>

using namespace std;

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

    void move()
    {
        cout << this->type << " is moving at " << this->speed << " km/h." << endl;
    }
};

int Vehicle::vehicleCount = 0;
int Vehicle::totalSpeed = 0;

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
};

int main()
{
    Vehicle *vehicles[3];
    vehicles[0] = new Vehicle("Car", 80);
    vehicles[1] = new Vehicle("Bus", 50);
    vehicles[2] = new Vehicle("Bike", 60);

    for (int i = 0; i < 3; i++)
    {
        vehicles[i]->displayInfo();
        vehicles[i]->move();
    }

    Vehicle::displayVehicleCount();
    Vehicle::displayTotalSpeed();
    cout << "Average Speed of All Vehicles: " << Vehicle::averageSpeed() << " km/h" << endl;

    TrafficSignal signals[2] = {
        TrafficSignal("Red", 30),
        TrafficSignal("Green", 45)};

    for (int i = 0; i < 2; i++)
    {
        signals[i].displayStatus();
        signals[i].changeSignal(i == 0 ? "Green" : "Red");
    }

    for (int i = 0; i < 3; i++)
    {
        delete vehicles[i];
    }

    Vehicle::displayVehicleCount();
    Vehicle::displayTotalSpeed();
    cout << "Average Speed of All Vehicles: " << Vehicle::averageSpeed() << " km/h" << endl;

    return 0;
}
