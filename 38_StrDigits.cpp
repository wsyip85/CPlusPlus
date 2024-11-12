#include<iostream>
using namespace std; 
int main(){
	cout<<"Enter digit one, two, until nine and zero\n"; 
	string digit; 
	double ndigit; 
	cin>>digit;
	while (digit!="-99"){
		if (digit=="zero"){
			ndigit = 0;
		}
		else if (digit=="one"){
			ndigit = 1; 
		}
		else if (digit=="two"){
			ndigit = 2; 
		}
		else if (digit=="three"){
			ndigit = 3; 
		}
		else if (digit=="four"){
			ndigit = 4; 
		}
		else if (digit=="five"){
			ndigit = 5; 
		}
		else if (digit=="six"){
			ndigit = 6; 
		}
		else if (digit=="seven"){
			ndigit = 7; 
		}
		else if (digit=="eight"){
			ndigit = 8; 
		}
		else if (digit=="nine"){
			ndigit = 9; 
		}
		else{	
			ndigit = -1; 
		}
		if (ndigit!=-1){
			cout<<digit<<" = "<<ndigit<<"\n"; 
		}
		else{
			cout<<"invalid digit\n";
		}
		cin>>digit;
	}
}
