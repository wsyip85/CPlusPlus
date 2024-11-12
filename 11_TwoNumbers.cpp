#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	cout<<"Enter the type, either int or double, then enter two numbers\n";
	string type; 
	cin>>type;
	if (type=="double"){
		double val1;
		double val2;
		cout<<"Type double\n";
		cout<<"Input your first number:\n"; 
		cin>>val1;
		cout<<"Input your second number:\n"; 
		cin>>val2; 
		cout<<"The larger number is : "<<max(val1,val2)<<"\n"; 
		cout<<"The smaller number is : "<<min(val1,val2)<<"\n"; 
		cout<<"The sum of "<<val1<<" with "<<val2<<" is = "<<val1+val2<<"\n"; 
		cout<<"The product of "<<val1<<" with "<<val2<<" is = "<<val1*val2<<"\n";
		cout<<"The ratio of "<<val1<<" with "<<val2<<" is = "<<val1/val2<<"\n";
	} 
	else if (type=="int"){
		int val1;
		int val2; 
		cout<<"Type int\n";
		cout<<"Input your first number:\n"; 
		cin>>val1;
		cout<<"Input your second number:\n"; 
		cin>>val2; 
		cout<<"The larger number is : "<<max(val1,val2)<<"\n"; 
		cout<<"The smaller number is : "<<min(val1,val2)<<"\n"; 
		cout<<"The sum of "<<val1<<" with "<<val2<<" is = "<<val1+val2<<"\n"; 
		cout<<"The product of "<<val1<<" with "<<val2<<" is = "<<val1*val2<<"\n";
		cout<<"The ratio of "<<val1<<" with "<<val2<<" is = "<<val1/val2<<"\n";
	}
	else{
		cout<<"Please enter either double or int\n";
		cout<<"Now exiting, try again\n"; 
	}
}