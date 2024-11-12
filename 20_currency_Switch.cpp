#include<iostream>
using namespace std; 
double fromYenTo (double yen, double* kroner, double* pounds, double* dollars){
	double k = yen * 0.0710;
	double p = yen * 0.0050;
	double d = yen * 0.0065; 
	*kroner = k; 
	*pounds = p; 
	*dollars = d;
	return 0;
}
double fromKronerTo (double kroner, double* yen, double* pounds, double* dollars){
	double y = kroner * 13.97; 
	double p = kroner * 0.071; 
	double d = kroner * 0.092; 
	*yen = y;
	*pounds = p; 
	*dollars = d; 
	return 0;
}
double fromPoundsTo (double pounds, double* yen, double* kroner, double* dollars){
	double y = pounds * 197.67; 
	double k = pounds * 14.14; 
	double d = pounds * 1.30; 
	*yen = y; 
	*kroner = k; 
	*dollars = d; 
	return 0;
}
int main(){
	double amount; 
	string status = "";
	char currency;  
	double outYen, outPounds, outKroner, outDollars;
	while ( status != "q" ){ 
		cout<<"Enter amount followed by currency (y for yen, k for kroner, p for pounds)\n"; 
		cin>>amount>>currency;
		switch (currency){
			case 'y': 
				fromYenTo(amount,&outKroner,&outPounds,&outDollars); 
				cout<<amount<<" yen == "<<outKroner<<" kroners == "<<outPounds<<" pounds == "<<outDollars<<" dollars \n"; 
				break; 
			case 'k': 
				fromKronerTo(amount,&outYen,&outPounds,&outDollars); 
				cout<<amount<<" kroner == "<<outKroner<<" yen == "<<outPounds<<" pounds == "<<outDollars<<" dollars \n"; 
				break;
			case 'p': 
				fromPoundsTo(amount,&outYen,&outKroner,&outDollars); 
				cout<<amount<<" pounds == "<<outKroner<<" yen == "<<outPounds<<" kroner == "<<outDollars<<" dollars \n"; 
				break;
			default: 
				cout<<"Expected y for yen, k for kroner, p for pounds, but you entered "<<currency<<" instead \n"; 
				break;
		}
		cout<<"Enter q to quit or any another button to continue:\n"; 
		cin>>status;
	}
}
