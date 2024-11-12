#include<iostream>
using namespace std; 
int main(){
	constexpr double cm_per_inch = 2.54; 
	double length; 
	string unit; 
	string status; 
	status = "y"; 
	while (status=="y"){
		cout<<"Please enter a length followed by a unit (cm or i):\n"; 
		cin>>length>>unit; 		
		if (unit=="i"){
			cout<<length<<" i == "<<length*cm_per_inch<<" cm\n"; 
		}
		else if (unit=="cm"){
			cout<<length<<" cm == "<<length/cm_per_inch<<" i\n"; 
		}
		else{
			cout<<"Please enter length followed by unit (cm or i):\n"; 
			cout<<"But you entered length followed by "<<unit<<"\n"; 
		}
		cout<<"Press y if you want to continue, otherwise press any button\n"; 
		cin>>status; 
	}
}
