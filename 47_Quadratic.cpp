#include<iostream>
#include<cmath>
using namespace std; 
int main(){
	string status = "y"; 
	const   complex<double> i(0.0,1.0); 
	while (status == "y"){
		double a, b, c; 
		cout<<"Find the values of x satisfying quadratic equation ax^2 + bx + c = 0 \n"; 
		cout<<"Enter a followed by b followed by c\n"; 
		cin>>a>>b>>c;
		double Surd = b * b - 4 * a * c; 
		if ( Surd > 0 ){
			double x1 = -1.0 * b / (2.0 * a) + pow( Surd, 0.5 ) / ( 2.0 * a ); 
			double x2 = -1.0 * b / (2.0 * a) - pow( Surd, 0.5 ) / ( 2.0 * a ); 
			cout<<"The values of x could be "<<x1<<" or "<<x2<<"\n"; 
		}
		else if ( Surd < 0 ){
			cout<<"The imaginary value of x could be "<<-1.0 * b / (2.0 * a)<<" + "<<(pow( -1*Surd, 0.5 ) / ( 2.0 * a ))<<"i\n"; 
			cout<<"The imaginary value of x could also be "<<-1.0 * b / (2.0 * a)<<" - "<<(pow( -1*Surd, 0.5 ) / ( 2.0 * a ))<<"i\n";
		}
		else if ( Surd == 0 ){
			double x = -1.0 * b / (2.0 * a); 
			cout<<"The value of x is "<<x<<"\n"; 
		}
		cin.clear();
		cout<<"If you want to continue, press y, otherwise press any other key?\n"; 
		cin>>status; 
		cin.clear();
	}
}
