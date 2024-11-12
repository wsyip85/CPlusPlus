#include<iostream>
#include<cmath>
using namespace std; 
int main(){
	int pennies, nickels, dimes, quarters, halfDollars, dollars, cents; 
	cout<<"Enter number of pennies \n"; cin>>pennies; 
	cout<<"Enter number of nickels \n"; cin>>nickels; 
	cout<<"Enter number of dimes \n"; cin>>dimes; 
	cout<<"Enter number of quarters \n"; cin>>quarters; 
	cout<<"Enter number of half dollars \n"; cin>>halfDollars; 
	cout<<"You have "<<pennies<<" pennies\n"; 
	cout<<"You have "<<nickels<<" nickels\n";
	cout<<"You have "<<dimes<<" dimes\n"; 
	cout<<"You have "<<quarters<<" quarters\n";
	cout<<"You have "<<halfDollars<<" half dollars\n";
	cents = pennies + nickels*5 + dimes*10 + quarters*25 + halfDollars*50; 
	dollars = floor(cents/100.0);
	cents = cents - dollars*100; 
	cout<<"The value of all of your coins is "<<dollars<<" dollars and "<<cents<<" cents\n";
}
