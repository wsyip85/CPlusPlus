#include<iostream>
using namespace std; 
int main(){
	cout<<"Enter your letter's recipient:\n"; 
	string friend_name; 
	cin>>friend_name;
	cout<<"Enter your letter's recipient's age:\n"; 
	double age; 
	cin>>age; 
	cout<<"Enter your mutual friend's name:\n"; 
	string mutual_friend; 
	cin>>mutual_friend; 
	cout<<"Finally, enter your own name:\n"; 
	string my_name;
	cin>>my_name; 
	cout<<"Now writing your letter\n";
	cout<<"...\n";
	cout<<"Dear "<<friend_name<<","; 
	cout<<"\n";
	cout<<"\n";
	cout<<"\tHappy birthday!";
	cout<<"\n"; 
	if (age<=0) {
		cout<<"\tAre you kidding about your age?"; 
	}
	else if (age>0 && age<=17) {
		cout<<"\tWow, next year you can vote"; 
	}
	else {
		cout<<"\tNext year you will be "<<age+1<<" years old"; 
	}
	cout<<"\n"; 
	cout<<"\tAny news from "<<mutual_friend<<" ?"; 
	cout<<"\n";
	cout<<"\n"; 
	cout<<"\t\tYours truly,\n"; 
	cout<<"\n";
	cout<<"\n";
	cout<<"\t\t"<<my_name; 
}
