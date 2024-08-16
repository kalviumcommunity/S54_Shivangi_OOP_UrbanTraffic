# Urban Traffic Simulation

A realistic simulation of traffic flow in an urban environment using Object-Oriented Programming concepts. The goal is to analyze traffic patterns, congestion points, and the impact of traffic signals on vehicle flow.

## Usage of OOP Concepts

1. **Classes:** 
    1. Vehicles
    2. TrafficSignal
    3. Pedestrian
    4. Intersection
    5. Road

2. **Objects:** To create instances of classes for each vehicle, traffic signal, pedestrian, and the intersection in the simualtion.

3. **`this` pointer:** The `this` pointer can be used to refer to the current instance of a class.

4. **Encapsulation:** To encapsulate properties and behaviors within their respective classes. 
    - Example - `Vehicle` class encapsulates speed, position, and lane-changing behavior.

5. **Abstraction:** To define clear interfaces and hide implementation details.
    - Example - TrafficSignal class provides an interface to change signals without exposing internal timer logic.

6. **Inheritance:** To create a hierarchy of vehicle types (e.g., Car, Bus, Bike) that inherit from a base Vehicle class.
    - Example -
        - **`class Vehicle`** _{ /* base class */ }_; 
        - **`class Car : public Vehicle`** _{ /* derived class */ }_;

7. **Polymorhism:** To define a common interface for different vehicle types and traffic signals, allowing for dynamic method invocation.

## Features

- **Roads and Lanes:** Represent roads with multiple lanes and simulate lane-changing behavior.
- **Traffic Rules:** Enforce traffic rules such as speed limits, stop signs, and right-of-way.
- **Congestion Analysis:** Monitor and report traffic congestion at different points in the simulation.
- **Event Logging:** Log events such as accidents, traffic jams, and signal changes for analysis.


