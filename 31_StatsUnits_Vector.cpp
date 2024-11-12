#include<iostream>
#include<vector>
using namespace std; 
int main(){
	int count = 0; 
	double tmp; 
	string unit; 
	double Sum; 
	double value; 
	double Largest, Smallest;
	vector<double> vec; 
	cout<<"Enter a number followed by a unit m\n"; 
	while(cin>>tmp>>unit){
		if (unit!="m"){ 
			cout<<"Invalid unit, should be m, but you entered "<<unit<<" instead, now quitting \n"; 
			break; 
		}
		vec.push_back(tmp);
		if (count==0){
			value = tmp; 
			Largest = value; 
			Smallest = value; 
			Sum = value; 
			cout<<tmp<<unit<<" Entered \n"; 
		}
		else{
			cout<<tmp<<unit<<" Entered \n";  
			if (tmp>Largest){
				Largest = tmp; 
				cout<<Largest<<unit<<" is the largest value so far \n"; 
			} else if (tmp<Smallest){
				Smallest = tmp; 
				cout<<Smallest<<unit<<" is the smallest value so far \n"; 
			}
			Sum += tmp; 
			cout<<Sum<<unit<<" is the sum of numbers so far \n"; 
		}
		cout<<"You entered "; 
		for (auto i: vec){
			cout<<i<<" "; 
		}
		cout<<" m so far\n"; 
		count++; 
	}
}
