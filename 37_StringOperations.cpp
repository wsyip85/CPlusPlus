#include<iostream>
using namespace std; 
int main(){
	double val01,val02;
	string oper; 
	int status = 1; 
	while (status!=-99){
		cout<<"Enter number followed by operation followed by number\n"; 
		cin>>val01>>oper>>val02;
		if (oper=="+"){
			cout<<val01<<" "<<oper<<" "<<val02<<" = "<<val01+val02<<"\n";
		}
		else if (oper=="*"){
			cout<<val01<<" "<<oper<<" "<<val02<<" = "<<val01*val02<<"\n";
		}
		else if (oper=="/"){
			cout<<val01<<" "<<oper<<" "<<val02<<" = "<<val01/val02<<"\n";
		}
		else if (oper=="-"){
			cout<<val01<<" "<<oper<<" "<<val02<<" = "<<val01-val02<<"\n";
		}
		else{
			cout<<"Invalid operation\n"; 
		}
		cout<<"To quit, press -99, else continue\n"; 
		cin.clear();
		cin>>status; 
		cin.clear();
	}
}
