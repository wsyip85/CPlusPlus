/*
Given 1 + 2 typed in terminal returns 
1 + 2 = 3 

Likewise, 1.0 + 2.0 typed in terminal returns 
1.0 + 2.0 = 3.0 

Applies for *, /, -, + operators

Limited to One Operator

*/
#include<iostream>
#include<vector>
#include<cctype>
#include<string>
using namespace std; 
int isNumeric ( string T ){
	// Input is a string, t 
	// Output integer: 
	//   0 - Not a digit nor operator
	//   1 - A double or integer
	//   2 - An operator *, /, +, - 
	char t; 
	int Status = 1; 
	for (int i = 0; i < T.size(); i++){
		t = T[i]; 
		if ( i == 0 && t == '-' && T.size() > 1){
			continue; 
		} else if ( isdigit(t) != 0 || t == '.' ){
			continue;			
		} else if ( isdigit(t) == 0 && t != '.' ){
			Status = 0; 
			break; 
		}
	}
	if (T.size() == 1){
		if ( T == "*" || T == "/" || T == "+" || T == "-" ){
			Status = 2; 
		}
	}
	return Status; 
}
double Evaluate ( vector<string> Expression, int* Status ){
    // Given a vector of string of "1" "+" "2", 
	// converts 1 and 2 to double, 
	// then applies 1 + 2. 
	// Same goes for *, /, -, and + 
	int i;
	string t; 
	//  Status = 0 when your digits are not digits 
	//         = 1 when your operator is not *, /, -, or + 
	//         = 2 when the calculation proceeds as planned
	*Status = 2; 
	for ( i = 0; i < Expression.size(); i++ ){
		t = Expression[i]; 
		if ( (i == 0 || i == 2) && isNumeric(t) != 1 ){
			cout<<"01\n"; 
			*Status = 0; 
			return 0; 
		}
		if ( i == 1 && isNumeric(t) != 2 ){
			cout<<"02\t"<<isNumeric(t)<<"\t"<<t<<"\n";
			*Status = 1;
			return 0; 
		}
	}
	double a, b, c;  
	a = stod( Expression[0] ); 
	b = stod( Expression[2] ); 
	string Op = Expression[1];  
	if (Op == "+"){
		c = a + b; 
	}
	else if (Op == "-"){
		c = a - b;
	}
	else if (Op == "*"){
		c = a * b; 
	}
	else if (Op == "/"){
		c = a / b; 
	}
	return c; 
}
int main(){
	cout<<"Enter a positive or negative number followed by operator (+,-,/,*) followed by another positive number \n"; 
	cout<<"For example, -1.0 / 2.0 will return -0.5\n"; 
	cout<<"Keep entering, until you press q which halts the program\n";
	string Token;
	int Status;	
    vector<string> Expression;	
	string Quit; 
	while (true){
		while (cin>>Token){
			if (Token=="|"){
				break;
			}
			Expression.push_back(Token); 
		}
		double Result = Evaluate(Expression,&Status); 
		cout<<Expression[0]<<" "<<Expression[1]<<" "<<Expression[2]<<" = "<<Result<<"\n";
		cout<<"Keep entering more expressions press c, or press q to quit\n"; 
		cin.clear();
		cin>>Quit; 
		if (Quit=="q"){
			cout<<"Quitting\n"; 
			exit(0); 
		}
		else{
			cout<<"Enter a new expression\n"; 
			Expression.clear();
		}
		cin.clear();
	}
}
