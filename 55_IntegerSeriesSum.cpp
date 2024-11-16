#include<iostream>
#include<numeric>
#include<cctype>
#include<vector>
using namespace std; 
int char2digit ( char a ){
	int n = a - '0'; 
	return n; 
}
int main(){
	cout<<"Enter an integer reprsenting how many element you wish to sum \n"; 
	char n;  // no. of elements to sum
	cin>>n; // input from terminal
	char tmp; // element entered on screen to be tested 
	int temp; // numeric element entered on screen 
	vector<int> vec; // vector to store your series of integers
	if (isdigit(n)==0){
		cout<<"Invalid integer, quitting\n"; 
		exit(0); 
	}
	cout<<"Next, enter your own series of integers\n"; 
	while (true){
		cin.clear(); //clearing cin cache 
		cin>>tmp; 
		if (tmp == '|'){
			break;
		}
		if (isdigit(tmp)==0){
			cout<<tmp<<" is not a digit, stopping entering digits\n"; 
		}
		else{
			temp = char2digit(tmp); // converting char to digits  
			vec.push_back(temp); 
		}
	}
	cout<<"You entered : ";
	for (int i = 0; i < vec.size(); i++){
		cout<<vec[i]<<" "; 
	}
	cout<<"\n";
	int N = char2digit(n); // number of elements to sum 
	int Sum = accumulate( vec.begin(), vec.begin()+N, 0 ); 
	cout<<"The sum of the first "<<N<<" numbers are : "<<Sum<<"\n"; 
}
