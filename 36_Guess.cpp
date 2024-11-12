#include<iostream>
using namespace std; 
int main(){
	
	int Top = 100;
	int Bottom = 0;
	int tmpTop;
	int tmpBottom;
	int newGuess; 
	string answer; 
	
	cout<<"You want to guess a number between "<<Bottom<<" and "<<Top<<"\n";
	
	tmpTop = Top;
	tmpBottom = Bottom; 
	
	int diff = tmpTop - tmpBottom; 
	
	while( diff > 1 ){ 
	
		newGuess = (tmpTop + tmpBottom)/2;
		cout<<"Is the number less than "<<newGuess<<" ?\n";
		cin>>answer;
		if (answer=="y"){
			tmpTop = newGuess; 
			tmpBottom = tmpBottom; 
			cout<<"The answer is between "<<tmpTop<<" and "<<tmpBottom<<"\n";
		}
		else{
			tmpTop = tmpTop;
			tmpBottom = newGuess;
			cout<<"The answer is between "<<tmpTop<<" and "<<tmpBottom<<"\n";
		}	

		diff = tmpTop - tmpBottom;
			
	}

	cout<<"Is the answer "<<tmpTop<< "?\n"; 
	cin>>answer;
	if (answer=="y"){
		cout<<"Your number is "<<tmpTop<<"\n"; 
	}
	else{
		cout<<"Your number is "<<tmpBottom<<"\n";
	}
	
}
