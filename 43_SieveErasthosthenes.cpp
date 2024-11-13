#include<iostream>
#include<vector>
using namespace std; 
int main(){
	
	int bottom = 0; // The least number in the range
	int top = 0;    // The largest number in the range 
	cout<<"Enter the bottom number:\n";
	cin>>bottom;
	cout<<"Enter the top number:\n";
	cin>>top;
	cout<<"Determine prime numbers from "<<bottom<<" to "<<top<<"\n";

	// Allocating the full range 
	int Size = top - bottom + 1; 
	int i; 
	vector<int> vec(Size); 
	for (i=0; i<vec.size(); i++){
		vec[i] = i+1;
	}

	//Removing all multiples of two except two 
	vector<int> vecFiltered; 
	for (i=0; i<vec.size(); i++){
		if (vec[i]%2!=0 || vec[i]==2){
			vecFiltered.push_back(vec[i]);
		}
	}
	
	//Removing all multiples of three except three 
	vec.clear();
	vec = vecFiltered;
	vecFiltered.clear();
	for (i=0; i<vec.size(); i++){
		if (vec[i]%3!=0 || vec[i]==3){
			vecFiltered.push_back(vec[i]);
		}
	}

	//Removing all multiples of five except five 
	vec.clear();
	vec = vecFiltered;
	vecFiltered.clear();
	for (i=0; i<vec.size(); i++){
		if (vec[i]%5!=0 || vec[i]==5){
			vecFiltered.push_back(vec[i]);
		}
	}
	
	
	//Removing all multiples of seven except seven 
	vec.clear();
	vec = vecFiltered;
	vecFiltered.clear();
	for (i=0; i<vec.size(); i++){
		if (vec[i]%7!=0 || vec[i]==7){
			vecFiltered.push_back(vec[i]);
		}
	}
	
	// Printing out the final list of prime numbers 
	cout<<"The list of prime numbers from "<<bottom<<" to "<<top<<":\n";
	for (i=0; i<vecFiltered.size(); i++){
		cout<<vecFiltered[i]<<"\n";
	}
		
	
}
		