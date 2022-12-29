#include "objects.h"

Objects::Objects()
{
}

RoutePoint::RoutePoint(int xKm, int yKm, string name)
{
    this -> xKm = xKm;
    this -> yKm = yKm;
    this -> name = name;
}

RoutePoint::RoutePoint()
    {

    }

AbstractCar::AbstractCar()
    {

    }
bool AbstractCar::drive(int kilometres)

     {
        fuel_loss = (double)fuel_consumption * ((double)kilometres / 100.0);

        if (fuel_tank_now >= fuel_loss)
        {
            distation += kilometres;
            fuel_tank_past = fuel_tank_now;
            fuel_tank_now -= fuel_loss;
            return true;
        }
        else
        {
            fuel_tank_past = -1;
            return false;
        }
    }

void AbstractCar::refuel()
    {
        fuel_tank_now = fuel_tank;
    }

void AbstractCar::printStatus()
    {
        if (fuel_tank_past < fuel_loss)
        {
            cout << "Nikuda ne edem" << endl;
        }
        else {
            cout << "Obschii probeg: " << distation << endl;
            cout << "Ostavsheesia v bake toplivo: " << fuel_tank_now << endl;
        }
    }


Route::Route()
    {

    }


void Route::addPoint(const RoutePoint& point)
    {
        RoutePoints.push_back(point);
    }

void Route::run(IVehicle* vehicle)
    {

        vehicle->refuel();
        while (vehicle_counter < RoutePoints.size() - 1)
        {
            if (RoutePoints.size() > 1)
            {

                kilometres = sqrt(pow((RoutePoints[vehicle_counter + 1].xKm - RoutePoints[vehicle_counter].xKm), 2.0) +
                    pow((RoutePoints[vehicle_counter + 1].yKm - RoutePoints[vehicle_counter].yKm), 2.0));

                if (vehicle->drive(kilometres))
                {
                    vehicle->printStatus();
                    vehicle_counter++;
                }
                else
                {
                    cout << "Zapravlyau" << endl;
                    vehicle->refuel();
                }
            }
            else
            {
                cout << ("Nedostatochno tochek marshruta");
            }
        }
        vehicle_counter = 0;
        cout << endl;
    }

Sedan::Sedan()
    {
    distation = 0;
    fuel_tank = 100;
    fuel_consumption = 10;
    }

double Sedan::getFuel()
    {
    return this -> fuel_tank_now;
    }

double Sedan::getKm()
{
    return this -> distation;
}

Suv::Suv()
    {
    fuel_tank = 200;
    fuel_consumption = 21;
    }

Bus::Bus()
    {
    fuel_tank = 105;
    fuel_consumption = 15;
    }

Bicycle::Bicycle()
    {
        this->distation = 0;
    }

bool Bicycle::drive(int kilometres)
    {
        this->distation += kilometres;
        return true;
    }
int Bicycle::getKm()
    {
        return this->distation;
    }

void Bicycle::printStatus()
    {
        cout << "Obschii probeg: " << distation << endl;
    }

void Bicycle::refuel()
    {

    }

