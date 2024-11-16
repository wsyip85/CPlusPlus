#include<iostream>
#include<cctype>
using namespace std; 
int main(){
	char tmp; 
	int n; 
	cout<<"Enter any key, to quit press |\n"; 
	while (true){
		cin.clear(); 
		cin>>tmp; 
		if (tmp=='|'){
			cout<<"Quitting\n"; 
			break; 
		}
		if (isdigit(tmp)==0){
			cout<<tmp<<" is not a digit\n"; 
		}
		else{
			cout<<tmp<<" is a digit\n";
		}
	}
}
