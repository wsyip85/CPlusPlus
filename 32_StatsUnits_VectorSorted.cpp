#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 
vector<double> sortedVec (vector<double> vec){
	sort(vec.begin(),vec.end()); 
	return vec; 
}
int main(){
	int count = 0; 
	double tmp; 
	string unit; 
	double Sum; 
	double value; 
	double Largest, Smallest;
	vector<double> vec; 
	vector<double> vecSorted; 
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
			} else if (tmp<Smallest){
				Smallest = tmp; 
			}
			Sum += tmp; 
			cout<<Largest<<unit<<" is the largest value so far \n"; 
			cout<<Smallest<<unit<<" is the smallest value so far \n"; 
			cout<<Sum<<unit<<" is the sum of numbers so far \n"; 
		}
		cout<<"You entered "; 
		for (auto i: vec){
			cout<<i<<" "; 
		}
		vecSorted = sortedVec(vec); 
		cout<<" m so far\n"; 
		cout<<"Your numbers sorted : "; 
		for (auto i: vecSorted){
			cout<<i<<" "; 
		}
		cout<<" m so far ";
		cout<<"\n";
		count++; 
	}
}
