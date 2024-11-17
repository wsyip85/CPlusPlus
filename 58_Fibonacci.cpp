//Generates first N values of Fibonacci series 
//Prints out error message IF N is NOT a digit 
//Prints out error message if largest Fibonacci number starts to overflow (becomes negative) because it is too large to fit insidei int. 
//IF N is an integer, the series and max will be integer, otherwise will use double. 
//
#include<iostream>
#include<vector>
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
vector<int> Fibonacci_Int( int N ){
	int Previous = 0;
	int Current = 1; 
	int Value; 
	int i = 0;
	vector<int> Output; 
	while ( i <= N ){
		Value = Previous + Current; 
		if (Value < 0){
			cout<<"You exceeded the maximum double value, halting\n"; 
			break;
		}
		Previous = Current; 
		Current = Value; 
		Output.push_back( Value ); 
		i++; 
	}
	return Output;
}
vector<double> Fibonacci_Dbl( double N ){
	double Previous = 0;
	double Current = 1; 
	double Value; 
	double i = 0;
	vector<double> Output; 
	while ( i <= N ){
		Value = Previous + Current; 
		if (Value < 0){
			cout<<"You exceeded the maximum double value, halting\n"; 
			break;
		}
		Previous = Current; 
		Current = Value; 
		Output.push_back( Value ); 
		i++; 
	}
	return Output;
}	
int printOutInt ( vector<int> vec ){
	for (int i = 0; i < vec.size(); i++){
		cout<<vec[i]<<" "; 
		if (i>0 && i%10==0){
			cout<<"\n"; 
		}
	}
	cout<<"\n"; 
	return 0;
}
int printOutDbl ( vector<double> vec ){
	for (int i = 0; i < vec.size(); i++){
		cout<<vec[i]<<" "; 
		if (i>0 && i%10==0){
			cout<<"\n"; 
		}
	}
	cout<<"\n"; 
	return 0;
}
int main (){
	string tmp; 
	string Continue = "y"; 
	vector<int> FbInt; 
	vector<double> FbDbl; 
	int NInt; 
	double NDbl; 
	while (Continue == "y"){
		cout<<"Enter how many values you want you Fibonacci series to be\n"; 
		cin.clear();
		cin>>tmp; 
		cout<<"You entered "<<tmp<<"\n"; 
		if (isNumeric(tmp)==0){
			cout<<tmp<<" is not a digit, please try again\n"; 
			continue;
		}
		if (isNumeric(tmp)==1){
			cout<<tmp<<" is an integer\n";
			NInt = stoi(tmp); 
			FbInt = Fibonacci_Int( NInt ); 
			printOutInt( FbInt );
		}
		if (isNumeric(tmp)==2){
			cout<<tmp<<" is a double\n"; 
			NDbl = stod(tmp); 
			FbDbl = Fibonacci_Dbl( NDbl ); 
			printOutDbl( FbDbl );
		}
		cout<<"To continue, press y, or else press any key\n"; 
		cin.clear();
		cin>>Continue; 
	}
}
