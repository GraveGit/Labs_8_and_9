#ifndef OBJECTS_H
#define OBJECTS_H
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;

class Objects
{
public:
    Objects();
};

class IVehicle {
public:
    virtual bool drive(int kilometres) = 0;
    virtual void refuel() = 0;
    virtual void printStatus() = 0;
};

class Bicycle : public IVehicle {

private:
    int distation = 0;
public:

    Bicycle();

    bool drive(int kilometres);
    void printStatus();
    void refuel();
    int getKm();
};

class AbstractCar : public IVehicle {

protected:
    //double kilometres;
    double fuel_tank_now = 0;
    int distation = 0;
    double fuel_loss;
    double fuel_tank;
    int fuel_consumption;
    double fuel_tank_past; // костыль

public:

    AbstractCar();

    bool drive(int kilometres);
    void refuel();
    void printStatus();

};

class Sedan : public AbstractCar {
public:
    Sedan();
    double getFuel();
    double getKm();
};

class Bus : public AbstractCar {
public:
    Bus();
};

class Suv : public AbstractCar {
public:
    Suv();
};


struct RoutePoint
{
    RoutePoint();
    RoutePoint(int x, int y, string Name);
    int xKm;
    int yKm;
    string name;
};

class Route {

public:

    int vehicle_counter = 0;
    int kilometres = 0;

    Route();

    vector <RoutePoint> RoutePoints;

    void addPoint(const RoutePoint& point);
    void run(IVehicle* vehicle);
};




#endif // OBJECTS_H
