#include<iostream>
using namespace std; 
double ctok ( double c ){
	double k = c + 273.15; 
	try { 
		if ( k < 0 ){
			throw 505; 
		}
		else{
			cout<<c<<" Celcius is equivalent to "<<k<<" Kelvin \n"; 
			return k; 
		}
	}
	catch(int ErrorNo){
		cout<<"Temperature in Celcius cannot be below -273.15, please try again\n"; 
		}
	return 0; 
}
double ktoc ( double k ){
	double c = k - 273.15; 
	try { 
		if ( c < -273.15 ){
			throw 505; 
		}
		else{
			cout<<k<<" Kelvin is equivalent to "<<c<<" Celcius \n"; 
			return k; 
		}
	}
	catch(int ErrorNo){
		cout<<"Temperature in Kelvin cannot be below 0, please try again\n"; 
		}
	return 0; 
}
int main(){
	double input = 0; 
	double output;
	string units;
	int status;
	while (status!=-999){
		cout<<"Enter number followed by units (Celcius or Kelvin)\n"; 
		cin>>input>>units; 
		if (units == "Celcius"){
			output = ctok( input ); 
		}
		else if (units == "Kelvin"){
			output = ktoc( input ); 
		}
		else{
			cout<<"Invalid unit, please try again\n"; 
		}
		cout<<"To quit enter -999, else enter any other number\n"; 
		cin.clear();
		cin>>status;
		if (!cin) {
			break; 
		}
	}
}
