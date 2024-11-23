#include<algorithm>
#include<iostream>
#include<vector>
#include<cctype>
#include<string>
using namespace std;
int isNumeric ( string T ){
	int Status = 1; 
	for (int i = 0; i < T.size(); i++){
		if ( i == 0 && T[i] == '-' && T.size() > 1){
			continue; // For negative sign at the beginning (Status=1)
		} else if ( isdigit(T[i]) != 0 || T[i] == '.' ){
			continue; // For decimal dots or digits (Status=1) 
		} else if ( isdigit(T[i]) == 0 && T[i] != '.' ){
			// For non-digits and non-decimal dots (Status=0)
			Status = 0; 
			break; 
		}
	}		
	if (T.size() == 1){
		if ( T == "*" || T == "/" || T == "+" || T == "-" ){
			Status = 2; // For operators *, /, +, - (Status=2)
		}
	}
	return Status; 
}
double Evaluate ( vector<string> Expression ){ // Evaluate a operator b
	if (Expression.size()<3){
		cout<<"Too few elements to evaluate, error!\n"; 
		return 0;
	}
	for (int i = 0; i < Expression.size(); i++){ 
		if ( (i == 0 || i == 2) && isNumeric(Expression[i]) != 1 ){
			cout<<"Your digits are not digits, error !\n";
			return 0;
		}
		if ( i == 1 && isNumeric(Expression[i]) != 2 ){
			cout<<"Your operator is invalid, error !\n"; 
			return 0; 
		}
	}
	double a = stod( Expression[0] );
	double b = stod( Expression[2] );
	string Op = Expression[1];
	double c; 
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
int Find ( vector<string> Expression, string Keyword ){ // Find Keyword in Expression
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
int printOut ( vector<string> Vec ){ // Printout Vector of strings
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
	string element; 
	while (true){ // Reading in each user-entered terminal 
		cin>>element; 
		if (element == "|"){ // Stop reading when "|" is entered
			break;
		}
		Expression.push_back( element );
	}
	printOut( Expression ); // Printout expression to be evaluated 
	if ( Expression.size() < 3 ){
		cout<<"Too few expression to evaluate, exit\n"; 
		exit(0);
	}
	int i; // Loop variables 
	int j; 
	int k; 
	double Tmp; 
	vector<string> tmp; 
	vector<string> ExpressionNew; 
	while (Expression.size() >= 3){ 
		if (Expression.size()==3){ // If expression is just a * b (3 elements)
			Tmp = Evaluate( Expression ); 
			cout<<"Final answer : \n"; 
			cout<<Tmp<<"\n"; 
			exit(0);
		}
		if (Expression.size()<3){ 
			cout<<"Too few expression to evaluate, exit\n";
			exit(0);
		}
		for ( i = 0; i < Expression.size(); i++ ){
			if ( Expression[i] == "*" || Expression[i] == "/" ){
				break; // Meaning * or / found 
			}
		}
		if ( i == Expression.size() ){
			i = 1; // Meaning no * or / found 
		}
		tmp.clear();
		for ( j = i - 1; j <= i + 1; j++ ){ // Select digits adjacent to * or /
			tmp.push_back( Expression[j] );
		}
		cout<<"Evaluate first : \n"; 
		printOut(tmp);
		Tmp = Evaluate( tmp ); // Evaluate digits adjacent to * or /
		cout<<"=\n"<<Tmp<<"\n";
		ExpressionNew.clear(); // Clear and update Expression
		if ( i - 2 > 0 ){
			for ( k = 0; k <= i - 2; k++ ){
				ExpressionNew.push_back( Expression[k] ); 
			}
			ExpressionNew.push_back( to_string(Tmp) ); 
			if ( i - 2 < Expression.size() ){
				for ( k = i + 2; k < Expression.size(); k++ ){
					ExpressionNew.push_back( Expression[k] ); 
				}
			}
		}
		else if ( i - 2 < 0 ){
			ExpressionNew.push_back( to_string(Tmp) ); 	
			for ( k = i + 2; k < Expression.size(); k++ ){
				ExpressionNew.push_back( Expression[k] ); 
			}
		}
		cout<<"Updated expression : \n"; // Clear and update Expression 
		printOut(ExpressionNew); 
		Expression.clear(); 
		for ( i = 0; i < ExpressionNew.size(); i++ ){
			Expression.push_back( ExpressionNew[i] ); 
		}
	}
}
	
		
		
		