#include<iostream>
using namespace std; 
int main(){
	string unit; 
	double amount; 
	cout<<"Enter amount followed by unit (cm or in or ft or m)\n"; 
	while (cin>>amount>>unit){
		if (unit == "cm"){
			cout<<amount<<" cm == "<<amount*0.393701<<" inches == "<<amount*0.0328084<<" feet == "<<amount*0.01<<" metres "<<"\n";
		}
		else if (unit == "in"){
			cout<<amount<<" inches == "<<amount*2.54<<" cm == "<<amount*0.0833333<<" feet == "<<amount*0.0254<<" metres "<<"\n";
		}
		else if (unit == "ft"){
			cout<<amount<<" feet == "<<amount*12<<" inches == "<<amount*30.48<<" cm == "<<amount*0.3048<<" metres "<<"\n";
		}
		else if (unit == "m"){
			cout<<amount<<" m == "<<amount*39.3701<<" inches == "<<amount*3.28084<<" feet == "<<amount*100<<" cm "<<"\n"; 
		}
		else{
			cout<<"Invalid unit "<<unit<<" entered: quitting\n"; 
			break;
		}
	}
}
