#include<iostream>
using namespace std; 
double ctok ( double c ){
	double k = c + 273.15; 
	return k; 
}
int main(){
	double c = 0;
	double k; 
	while (c!=-999){
		cout<<"Enter any temperature in Celcius, it will be converted to Kelvin, to quit enter -999\n"; 
		cin >> c; 
		k = ctok( c ); 
		try { 
			if ( k < 0 ){
				throw 505; 
			}
			else{
				cout<<c<<" Celcius is equals to "<<k<<" Kelvin \n"; 
			}
		}
		catch(int ErrorNo){
			if (c!=-999){
				cout<<"Temperature in Celcius cannot be below -273.15, please try again\n"; 
			}
		}
	}
}
