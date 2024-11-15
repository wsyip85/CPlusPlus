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
		if ( c != -999 ){
			cout<<"Temperature in Celcius cannot be below -273.15, please try again\n"; 
		}
		else{
			cout<<"Quitting\n"; 
		}
	}
	return 0; 
}
int main(){
	double c = 0;
	double k; 
	while (c!=-999){
		cout<<"Enter any temperature in Celcius, it will be converted to Kelvin, to quit enter -999\n"; 
		cin >> c; 
		k = ctok( c ); 
	}
}
