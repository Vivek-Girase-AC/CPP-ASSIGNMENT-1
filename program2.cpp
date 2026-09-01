#include <iostream>
#include <iomanip>
#include<algorithm>
using namespace std;

int main()
{
    int N;

    cout << "Enter the Number of Reading: ";
    cin >> N;

    cout << "Reading entered: " << N << endl;

    float arr[N];
    float skip;
    cout << "Valid Readings: ";
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
        if(arr[i] < 0){
           skip++;
           continue;
        }
    }
    cout<<"Skipped (errors) :"<<skip<<endl;

    int index = 0;
    float val = 0;
    for(int i = 0 ; i < N ; i++){
    	if(arr[i] >= 45){
    		index = i + 1;
    		val = arr[i];
    		break;
    	}
    }

    cout << "First CRITICAL : Index " << index
         << " -> " << fixed << setprecision(1)
         << val << "°C" << endl;

    float min = 0;
    float max = 0;
    float sum = 0;
    float Avg;
    bool firstValid = true;
    for(int i = 0 ; i < N ;i++){

        if(arr[i] < 0)
        {
            continue;
        }
        sum += arr[i];
    	if(firstValid)
    	    {
    	        min = arr[i];
    	        max = arr[i];
    	        firstValid = false;
    	    }

    	if(arr[i] < min){
    		min = arr[i];
    	}
    	if(arr[i] > max){
    		max = arr[i];
    	}
    }

    Avg = sum / (N - skip);
    cout<<"Min :" <<min<<"°C"<<" ";
      cout<<"Max :" <<max<<"°C"<<" ";
      cout<<"Avg :" <<Avg<<"°C"<<endl;

      int Normal = 0;
      int Warning = 0;
      int Critical = 0;
      int Shutdown = 0;
      for(int i = 0 ; i < N ; i++){
    	  if(arr[i] > 0 && arr[i] <= 29){
    		  Normal++;
    	  }else if(arr[i] <= 44){
    		  Warning++;
    	  }else if(arr[i] <= 59){
    		  Critical++;
    	  }else{
    		  Shutdown++;
    	  }
      }
      cout<<"Normal: "<<Normal<<" "
    	  <<"Warning: "<<Warning<<" "
		  <<"Critical: "<<Critical<<" "
		  <<"Shutdown:"<<Shutdown;

}
