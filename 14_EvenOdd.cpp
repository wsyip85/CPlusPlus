#include<iostream>
using namespace std; 
int main(){
	cout<<"Key in an integer, key in -999 to end:\n"; 
	int n;
	cin>>n;
	while (n!=-999){	
		if (n%2==0){
			cout<<n<<" is even \n";
		}
		else{
			cout<<n<<" is odd \n"; 
		}
		cout<<"Key in another integer, key in -999 to end:\n"; 
		cin>>n;
	}
	cout<<"End\n"; 
}
