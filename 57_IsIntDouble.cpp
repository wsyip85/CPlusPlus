// Enter a number, this program says whether integer or string or not a digit 
#include<iostream>
using namespace std; 
int isNumeric( string Input ){
	int status = 1;  // Is an integer 
	for (int i = 0; i < Input.length(); i++){
		if (isdigit(Input[i]) || Input[i] == '.' || Input[i] == ' '){
			continue; 
		}
		else{
			status = 0; // Is not a digit
			break; 
		}
	}
	if ( status == 1 ){
		if ( Input.find(".") != string::npos ){
			status = 2; // Is a double
		}
	}
	return status; 
}
int main(){
	string tmp; 
	int n; 
	while (true){
		cout<<"Enter any key, to quit press |\n"; 
		cin.clear(); 
		cin>>tmp; 
		if (tmp=="|"){
			cout<<"Quitting\n"; 
			break; 
		}
		if (isNumeric(tmp)==0){
			cout<<tmp<<" is not a digit\n"; 
		}
		if (isNumeric(tmp)==1){
			cout<<tmp<<" is an integer\n";
		}
		if (isNumeric(tmp)==2){
			cout<<tmp<<" is a double\n"; 
		}
	}
}
