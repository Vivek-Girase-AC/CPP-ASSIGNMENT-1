#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{

    if (argc != 4)
    {
        cout << "Usage   : ./sensor_monitor <warn_threshold> <critical_threshold> <num_readings>" << endl;
        cout << "Error   : Missing arguments." << endl;
        return 1;
    }


    int warn_threshold = stoi(argv[1]);
    int critical_threshold = stoi(argv[2]);
    int num_readings = stoi(argv[3]);


    if (warn_threshold >= critical_threshold)
    {
        cout << "Error   : Warn threshold must be less than critical threshold."
             << endl;
        return 1;
    }

    if (num_readings < 1 || num_readings > 500)
    {
        cout << "Error   : Number of readings must be between 1 and 500."
             << endl;
        return 1;
    }

    cout << "Config  : Warn=" << warn_threshold
         << "°C  Critical=" << critical_threshold
         << "°C  Readings=" << num_readings << endl;

    int normal = 0;
    int warning = 0;
    int critical_count = 0;
    int shutdown = 0;

    for (int i = 0; i < num_readings; i++)
    {
        int temperature = rand() % 70;

        if (temperature < warn_threshold)
        {
            normal++;
        }
        else if (temperature < critical_threshold)
        {
            warning++;
        }
        else if (temperature < 70)
        {
            critical_count++;
        }
        else
        {
            shutdown++;
        }
    }

    cout << "Results : Normal:" << normal
         << "  Warning:" << warning
         << "  Critical:" << critical_count
         << "  Shutdown:" << shutdown << endl;

    return 0;
}
