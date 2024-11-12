#include<iostream>
using namespace std;
int main(){
	cout<<"Enter distance \n"; 
	double d;
	cin>>d;
	cout<<"Enter units of distance in km or miles\n"; 
	string unit;
	cin>>unit;
	if (unit=="km"){
		cout<<d<<"    km "<<" = "<<d/1.609<<" miles \n";
	} 
	else if (unit=="miles"){
		cout<<d<<" miles "<<" = "<<d*1.609<<"    km \n";
	}
	else{
		cout<<"Try again, enter either km or miles in unit of distance\n";
	}
}
		