#include "PPP.h"

int main () 
{
	
	cout << "Please enter a floating-point value: "; 
	
	double n = 0; 
	
	cin >> n; 
	
	cout << "n == " << n 
	     << "\n" << "n+1 == " << n + 1 
         << "\n" << "three times n == " << 3 * n 
		 << "\n" << "twice n == " << n + n 
		 << "\n" << "n squared == " << n * n  
		 << "\n" << "half of n == " << n/2 
		 << "\n" << "square root of n == " << sqrt(n) 
		 << "\n"; 
	
}
