/* Given 1 + 9 / 10 returns 1.1 */
// Importing libraries 
#include<algorithm> // Find
#include<iostream>  // cin and cout
#include<vector>    // vector
#include<cctype>    // isdigit
#include<string>    // string
using namespace std;
int isNumeric ( string T ){
	/*
	Input is a string, T 
	Output integer 0 - Not a digit nor operator
	               1 - A double or integer
	               2 - An operator *, /, +, - 
	*/
	char t; 
	int Status = 1; 
	for (int i = 0; i < T.size(); i++){
		t = T[i];
		if ( i == 0 && t == '-' && T.size() > 1){
			continue; // For negative sign at the beginning
		} else if ( isdigit(t) != 0 || t == '.' ){
			continue; // For decimal dots or digits 
		} else if ( isdigit(t) == 0 && t != '.' ){
			// For non-digits and non-decimal dots 
			Status = 0; 
			break; 
		}
	}
	if (T.size() == 1){
		if ( T == "*" || T == "/" || T == "+" || T == "-" ){
			Status = 2; // For operators *, /, +, -
		}
	}
	return Status; 
}
double Evaluate ( vector<string> Expression, int* Status ){
	/*
	Given vector of string "1" "+" "2", converts 1 and 2 to double, 
	then applies 1 + 2. Same goes for *, /, -, and +
	Returns 3 in this example
	Also returns Status = 0 when your digits are not digits, 
	Status = 1 when your operator is not *, /, -, or +,
	Status = 2 when the calculation proceeds as planned
	*/
	int i;
	string t; 
	*Status = 2;
	for ( i = 0; i < Expression.size(); i++ ){
		t = Expression[i]; 
		if ( (i == 0 || i == 2) && isNumeric(t) != 1 ){
			// If the first and last token is NOT a digit, cancel and return 
			// Status = 0 which meant your digits are not digits 
			cout<<"Your digits are not digits, error !\n";
			*Status = 0; 
			return 0;
		}
		if ( i == 1 && isNumeric(t) != 2 ){
			// If the second expression is NOT an operator, 
			// cancel and return Status = 1, meaning your 
			// operator is not *, /, -, or +
			cout<<"Your operator is invalid, error !\n"; 
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
int Find ( vector<string> Expression, string Keyword ){
	/*
	Tries to find the location of Keyword inside string
	Expression. If not found, returns -999. If found, 
	returns the location. 
	*/
	vector<string>::iterator ip; 
	ip = find( Expression.begin(), Expression.end(), Keyword ); 
	int idx; 
	if ( ip != Expression.end() ){
		idx = ip - Expression.begin(); 
	}else{
		idx = -999; 
	}
	return idx; 
}
int printOut ( vector<string> Vec ){
	/*
	Prints out each element of a vector of strings
	*/
	int Status; 
	for (auto i : Vec ){
		Status = isNumeric( i ); 
		if (Status == 1){
			cout<<i<<"\tIs a digit\n"; 
		}
		else if (Status == 2){
			cout<<i<<"\tIs an operator\n"; 
		}
		else{
			cout<<i<<"\tIs not a digit nor operator, quitting\n"; 
			exit(0);
		}
	}
	return 0;
}
int main(){
	cout<<"Enter two operations, for example 1.0 + 2.0 / 3.0 followed by |\n";
	vector<string> Expression; 
	string Token; 
	while (cin>>Token){
		if (Token=="|"){
			break;
		}
		Expression.push_back(Token);
	}
	printOut(Expression);
	vector<string> tmp; 
	int i = 0; 
	for ( i = 0; i < Expression.size(); i++ ){
		if ( Expression[i] == "*" || Expression[i] == "/" ){
			break; 
		}
	}
	if ( i == Expression.size() ){
		i = 1; 
	}
	int j; 
	for ( j = i - 1; j <= i + 1; j++ ){
		tmp.push_back( Expression[j] ); 
	}
	cout<<"Evaluate first : \n"; 
	printOut(tmp);
	double Tmp; 
	int Status; 
	Tmp = Evaluate( tmp, &Status ); 
	cout<<"=\n"<<Tmp<<"\n";
	vector<string>ExpressionNew; 
	int k; 
	if ( i - 2 > 0 ){
		for ( k = 0; k <= i - 2; k++ ){
			ExpressionNew.push_back( Expression[k] ); 
		}
		ExpressionNew.push_back( to_string(Tmp) ); 
	}
	else if ( i - 2 < 0 ){
		ExpressionNew.push_back( to_string(Tmp) ); 		
		for ( k = i + 2; k < Expression.size(); k++ ){
			ExpressionNew.push_back( Expression[k] ); 
		}
	}
	cout<<"Updated expression : \n"; 
	printOut(ExpressionNew); 
	Tmp = Evaluate( ExpressionNew, &Status );
	cout<<"Final answer : \n"; 
	cout<<Tmp<<"\n"; 
}
