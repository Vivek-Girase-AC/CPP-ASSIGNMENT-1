#include<iostream>
#include<cmath>
using namespace std;
double computeRMS(double* signal , int n){
	float sum = 0;
	for(int i = 0 ; i < n ; i++){
		sum += (*signal *  *signal);
	     signal++;
	}
	return sqrt( sum / n);
}
void normalise(double* signal , int n){
	double max = abs(*signal);

	for(int i = 0 ; i < n ; i++){
		if(abs(*(signal + i)) > max){
			max = abs(*(signal + i));
		}
	}
	for(int i = 0 ; i < n ; i++){
		*(signal + i) = *(signal + i) / max ;
	}
	cout<<*signal;
}
int countZeroCrossings(double* signal, int n){
	int count = 0;

	for(int i = 0 ; i < n - 1; i++){
		double current = *(signal + i);
		double next = *(signal + i + 1);

	if((current > 0 && next < 0) || (current < 0 && next > 0)){
			 count++;
      }
	}
	return count;
}
void  applyGain(double* signal, int n , double gainFactor){
	for(int i = 0 ; i < n ; i++){

		*signal *= gainFactor;
		*signal++;
	}
}
int main(){
	int n;
	cout<<"Enter the number of signals:";
	cin>>n;

	double arr[n];
	for(int i = 0 ; i < n ; i++){
		cin>>arr[i];
	}
	double result = computeRMS(arr , n);
	cout<<result<<endl;

	for(int i = 0 ; i < n ; i++){
			cout<<arr[i]<<endl;
		}
	normalise(arr , n);
	for(int i = 0 ; i < n ; i++){
			cout<<arr[i]<<endl;
		}
	int crossings = countZeroCrossings(arr , n);
	cout<<crossings<<endl;


	double gainfactor = 2.0;
	for(int i = 0 ; i < n ; i++){
			cout<<arr[i]<<endl;
		}

	applyGain(arr,n,gainfactor);

	for(int i = 0 ; i < n ; i++){
				cout<<arr[i]<<endl;
			}



}
