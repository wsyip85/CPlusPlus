#include<iostream>
using namespace std; 
int str2digit (string digit){
	int ndigit;
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
	return ndigit;
}
int main(){
	string digit01, digit02, operation, ops; 
	double ndigit01, ndigit02, answer; 
	string status = "y"; 
	while (status=="y"){
		cout<<"Enter string digit followed by operation followed by another string digit, for example seven plus one\n"; 
		cin>>digit01>>operation>>digit02; 
		ndigit01 = str2digit(digit01);
		ndigit02 = str2digit(digit02);
		if (ndigit01==-1||ndigit02==-1) {
			cout<<"Invalid operation\n"; 
		}
		else{
			if (operation=="plus"){
				answer = ndigit01 + ndigit02; 
				ops = "+";
			}
			else if (operation=="minus"){
				answer = ndigit01 - ndigit02; 
				ops = "-";
			}
			else if (operation=="times"){
				answer = ndigit01 * ndigit02;
				ops = "*";
			}
			else if (operation=="divide"){
				answer = ndigit01 / ndigit02; 
				ops = "/";
			}
			else{
				answer = -999; 
			}
			if (answer!=-999){
				cout<<ndigit01<<" "<<ops<<" "<<ndigit02<<" = "<<answer<<"\n"; 
			}
			else{
				cout<<"Invalid operation\n"; 
			}
		}
		cout<<"To continue, press y, else press anything followed by enter to quit\n";
		cin.clear(); 
		cin>>status;
	}
}
