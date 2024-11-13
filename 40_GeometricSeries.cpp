#include<iostream>
using namespace std; 
int main(){
	cout<<"Enter the initial number of the geometric series:\n"; 
	int a; 
	cin>>a;
	cout<<"Enter the ratio of the geometric series\n"; 
	int r; 
	cin>>r; 
	cout<<"Enter the accumulated sum of the geometric series:\n"; 
	int end; 
	cin>>end; 
	int length = 1; 
	int value = a; 
	int sum = value; 
	while (sum<=end){
		cout<<"the "<<length<<" number of the series is "<<value<<" and accumulated value is "<<sum<<"\n"; 
		length = length + 1; 
		value = value * r; 
		sum = sum + value; 
	}
	cout<<"You need "<<length<<" number of steps to accumulate more than "<<end<<"\n"; 
}
