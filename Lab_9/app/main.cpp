#include <iostream>
#include "D:\Lab_9\Objects\objects.h"
using namespace std;

int main(int argc, char* argv[]) {

        string path = argv[1];
        Route routes;
        ifstream fin;
        int xkm, ykm;
        string name;
        RoutePoint point;

        if (argc == 2)
        {
            fin.open(path);
            if (!fin.is_open())
            {
                cout << "file is not open";
            }
            else
            {
                cout << "file is open" << endl;
            }

            while (fin >> xkm >> ykm >> name)
            {
                point.xKm = xkm;
                point.yKm = ykm;
                point.name = name;
                routes.addPoint(point);
            }
            IVehicle* vehicles[4] = { new Sedan, new Suv, new Bus, new Bicycle };
            for (int i = 0; i < 4; i++)
            {
                routes.run(vehicles[i]);
            }
            fin.close();
        }
        else
        {
            cout << "Error: Not enough arguments";
        }
        return 0;
}
