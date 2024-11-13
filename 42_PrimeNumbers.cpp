#include<iostream>
#include<vector>
using namespace std; 
int isPrime ( int No ){
	int status = 1;
	int i; 
	for ( i = 2; i < No; i++ ){
		if (No%i==0) {
			status = 0; 
			break;
		}
	}
	return status; 
}
int main(){
	int i; 
	int status; 
	int bottom, top; 
	vector<double> PrimeVec; 
	int quit = 0; 
	while (quit == 0){
		cout<<"Print out a list of prime numbers between bottom and top\n"; 
		cout<<"Enter the bottom number:\n"; 
		cin>>bottom;
		cout<<"Enter the top number:\n"; 
		cin>>top; 
		cout<<"Calculating the list of prime numbers between "<<bottom<<" and "<<top<<"\n"; 
		for (i = 1; i < top + 1; i++){
			status = isPrime( i ); 
			if (status == 1){
				PrimeVec.push_back(i); 
			}
		}
		cout<<"The list of prime numbers between 1 to 100 is listed below:\n"; 
		for (i = 0; i < PrimeVec.size(); i++){
			cout<<PrimeVec[i]<<"\n"; 
		}
		cout<<"If you want to continue, press 0, else to quit, press any other number\n";
		cin.clear();
		cin>>quit;
		cin.clear(); 
	}
}
