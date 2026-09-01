#include <iostream>
#include <string>
using namespace std;

int main()
{
    float temp;
    string reading;
    int StatusCode;

    cout << "Enter the temp: ";
    cin >> temp;


    if (temp < 0)
    {
        StatusCode = -1;
    }
    else if (temp <= 29)
    {
        StatusCode = 0;
    }
    else if (temp <= 44)
    {
        StatusCode = 1;
    }
    else if (temp <= 59)
    {
        StatusCode = 2;
    }
    else
    {
        StatusCode = 3;
    }

    float temperature = (temp * 9 / 5) + 32;
    cout<<"Temperature : "<<temp<<"°C " << "/" <<temperature<<"°F"<<endl;
    switch (StatusCode)
    {
        case -1:
            cout << "Status : SENSOR_ERROR" << endl;
            cout << "Action: Sensor fault - check wiring" << endl;
            break;

        case 0:
            cout << "Status : NORMAL" << endl;
            cout << "Action: No action required" << endl;
            break;

        case 1:
            cout << "Status : WARNING" << endl;
            cout << "Action: Alert sent to supervisor" << endl;
            break;

        case 2:
            cout << "Status : CRITICAL" << endl;
            cout << "Action: Cooling system triggered" << endl;
            break;

        case 3:
            cout << "Status : SHUTDOWN" << endl;
            cout << "Action: Emergency shutdown initiated" << endl;
            break;

        default:
            cout << "Recheck the temperature." << endl;
    }


    reading = (temp >= 25) ? "Above Average" : "Below Average";

    cout << "Reading: " << reading << endl;

    return 0;
}
