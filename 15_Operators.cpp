#include<iostream>
using namespace std; 
int main(){
	double a, b; 	
	string c; 
	double d; 
	string status = "y"; 
	while (status=="y"){
		cout<<"Enter any number a, followed by either +, -, *, or /, followed by another number b\n";
		cin>>a>>c>>b; 
		cout<<"You want to calculate: "<<a<<" "<<c<<" "<<b<<"\n";
		if (c=="+"){
			d = a + b; 
		}
		else if (c=="-"){
			d = a - b; 
		}
		else if (c=="*"){
			d = a * b; 
		}
		else if (c=="/"){
			d = a / b; 
		}
		else{
			cout<<"You entered "<<c<<"\n"; 
			cout<<"Please enter either +, -, *, or /\n"; 
		}
		cout<<a<<" "<<c<<" "<<b<<" = "<<d<<"\n"; 
		cout<<"if you want to continue, key in y\n"; 
		cin>>status; 
	}
}

	