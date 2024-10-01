#include <iostream>
#include <string>

using namespace std;

/*
 * Class to represent a vehicle
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
    Vehicle(string type, int speed)
    {
        this->type = type;
        this->speed = speed;
        vehicleCount++;
        totalSpeed += speed;
    }

    /*
     * Destructor to release the resources of a Vehicle object
     */
    ~Vehicle()
    {
        vehicleCount--;
        totalSpeed -= speed;
    }

    /*
     * Method to display the information of a Vehicle object
     */
    void displayInfo()
    {
        cout << "Vehicle Type: " << this->type << "\nSpeed: " << this->speed << " km/h" << endl;
    }

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
     * Creating objects of the Vehicle class using constructors
     */
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
