#include<iostream>
using namespace std; 
int main(){
	constexpr double cm_per_inch = 2.54; 
	double length; 
	char unit; 
	string status; 
	status = "y"; 
	while (status=="y"){
		cout<<"Please enter a length followed by a unit (c for cm or i for inches):\n"; 
		cin>>length>>unit; 		
		switch (unit){
			case 'i': 
				cout<<length<<" i == "<<length*cm_per_inch<<" cm\n";
				break; 
			case 'c': 
				cout<<length<<" cm == "<<length/cm_per_inch<<" i\n";
				break; 
			default:
				cout<<"Please enter length followed by unit (cm or i):\n";
				cout<<"But you entered length followed by "<<unit<<"\n"; 
				break;
		}
		cout<<"Press y if you want to continue, otherwise press any button\n"; 
		cin>>status; 
	}
}
