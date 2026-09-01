#include<iostream>
using namespace std;
void resetSensorPairV1(int reading1 , int reading2){
	reading1 = reading1 + reading2;
    reading2 = reading1 - reading2;
    reading1 = reading1 - reading2;
//	cout<<reading1;
//	cout<<reading2;
}
void resetSensorPairV2(int& reading1 , int& reading2){
	int temp = reading1;
	reading1 = reading2;
	reading2 = temp;
}
void resetSensorPairV3(int *reading1 , int *reading2){
	int temp = *reading1;
	*reading1 = *reading2;
	*reading2 = temp;
}
int main(){
	int A = 55;
	int B = 12;
    cout<<"----- V1 : Call By Value -----"<<endl;
 	cout<<"Before :" <<"A = "<<A<<" "<<"B = "<<B<<endl;
	resetSensorPairV1(A,B); // call by value passes the copy not original value
	                        // when after the scope of function the value remain original
	                        // if we print the value of the a and b in the function the value will change but after the scope the value remain unchange
	                        // if we have to swap the value of both a and b we can swap them with the help reference variable;
	cout<<"After :"<<"A = "<<A<<" "<<"B = "<<B<<endl;

	cout<<"----- V2 : Call By reference -----"<<endl;
	cout<<"Before :" <<"A = "<<A<<" "<<"B = "<<B<<endl;
	resetSensorPairV2(A,B); // call by reference means is the another name to an existing variable now the value get swap
	cout<<"Before :" <<"A = "<<A<<" "<<"B = "<<B<<endl;

	cout<<"----- V2 : Call By Pointer -----"<<endl;
	cout<<"Before :" <<"A = "<<A<<" "<<"B = "<<B<<endl;
	resetSensorPairV3(&A,&B);
	cout<<"Before :" <<"A = "<<A<<" "<<"B = "<<B<<endl;


}
