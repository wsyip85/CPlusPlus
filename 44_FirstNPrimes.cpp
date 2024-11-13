#include<iostream>
#include<vector>
using namespace std; 
int isPrime ( int No ){ // returns 1 if it is a prime, 0 otherwise 
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
	int n;
	int count;
	int m = 1;
	int status; // 1 if prime, 0 otherwise
	vector<int> vec; 
	string Continue = "y"; 
	while (Continue == "y"){
		count = 0; 
		cout<<"Enter a number \n"; 
		cin>>n;
		cout<<"The first "<<n<<" prime numbers are \n"; 
		while (count<n){
			status = isPrime( m ); 
			if ( status == 1 ){
				vec.push_back(m); 
				count++; 
			}
			m++;
		}
		cout<<"List of "<<count<<" prime numbers \n"; 
		for (auto i: vec){
			cout<<i<<"\n";
		}
		cout<<"To continue, press y, to quit press any other button\n"; 
		cin.clear();
		cin>>Continue;
	}
}
