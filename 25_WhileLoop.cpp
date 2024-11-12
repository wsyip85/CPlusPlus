#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 
int main(){
	int temp; 
	vector<int> vec; 
	cout<<"Please key in numbers followed by spacebar\n";
	while (cin>>temp){
		vec.push_back(temp); 
	}
	cout<<"You keyed in these numbers\n"; 
	for (auto i: vec){
		cout<<i; 
	}
	cout<<"\n";
	int Max = *max_element(vec.begin(),vec.end());
	int Min = *min_element(vec.begin(),vec.end());
	cout<<"The maximum = "<<int Max<<"\n"; 
	cout<<"The minimum = "<<int Min<<"\n";
}
		