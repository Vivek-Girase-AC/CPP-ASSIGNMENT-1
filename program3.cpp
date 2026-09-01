#include<iostream>
#include <iomanip>
using namespace std;
int main(){
	float arr[3][3];

	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 3 ; j++){
			 cin>>arr[i][j];
		}
	}
    cout << "             Room1   Room2   Room3" << endl;

    for(int i = 0; i < 3; i++)
    {
        cout << "Floor " << i + 1 << " : ";

        for(int j = 0; j < 3; j++)
        {
            cout << fixed << setprecision(1)
                 << arr[i][j] << "    ";
        }

        cout << endl;
    }
    float hightestAvg = 0;
	float hottestRoom = arr[0][0];
	int Floor = 0;
	int Room = 0;
	int roomHottest = 0;
		for(int i = 0 ; i < 3 ; i++){
			for(int j = 0 ; j < 3 ; j++){
				if(arr[i][j] > hottestRoom ){
					hottestRoom = arr[i][j];
					Floor = i;
					Room = j;
				}
			}
		}

   cout<<"Hottest Room :"<<"Floor "<<Floor<<", "<<"Room "<<Room<<"  "<<"->"<<hottestRoom<<endl;

       for(int i = 0 ; i < 3 ; i++){
    	   float sum = 0;
       	for(int j = 0 ; j < 3 ; j++){
       		sum += arr[i][j];
       	}
       	float Avg = sum / 3;
       	if(Avg > roomHottest)

       		hightestAvg = Avg;
       	    roomHottest = i;
       }

       cout<<"Hottest Floor: "<<"Floor"<<roomHottest<<" "<<"( avg "<<hightestAvg<<"°C)"<<endl;
       int rooWarning = 0;
       for(int i = 0 ; i < 3 ; i++){
    	   for(int j = 0 ; j < 3 ; j++){
    		   if(arr[i][j] >= 30){
    			   rooWarning++;
    		   }
    	   }
       }
       cout<<"Rooms at Warning or above:"<<rooWarning<<endl;
}


