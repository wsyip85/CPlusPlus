/*
Computer generates 4 random unique numbers say 1234 
If you guess 1359, the computer prints out '1 cow and 1 bull'
1 cow meaning you got 1 right, that is number 1 in the right space 
1 bull meaning you got number wrong, that is number 3 in the wrong space
4 bulls means you win
*/
#include<cmath>
#include<ctime>
#include<random>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std; 
vector<int> getUnique ( vector<int> Vec ){
	//Return a vector of unique values from vector Vec
	sort( Vec.begin(), Vec.end() ); 
	Vec.erase( unique( Vec.begin(), Vec.end() ), Vec.end() ); 
	return Vec; 
}
int countUnique ( vector<int> Vec ){
	// This function counts the number of unique elements of vector Vec
	vector<int> VecUnique = getUnique( Vec ); 
	// Count number of elements 
	int N = VecUnique.size(); 
	return N; 
}
int isNumeric( string Input ){
	// This function checks if you entered NOT a digit, a double, or an integer 
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
int getRandom (){
	// This function gets random number between 0 to 9
	// Scaling 0 to 1 random number to 1 to 9 random number
	// https://stats.stackexchange.com/questions/281162/scale-a-number-between-a-range
	double m = float( rand() ) / float( RAND_MAX ); // Random number between 0 to 1
	double rmin = 0;  // denote the minimum of the range of your measurement
	double rmax = 1;  // denote the maximum of the range of your measurement
	double tmin = 0;  // denote the minimum of the range of your desired target scaling
	double tmax = 9;  // denote the maximum of the range of your desired target scaling
    int random = round( (m - rmin)/(rmax - rmin) * (tmax - tmin) + tmin ); 
	return random; 
}
vector<int> getUniqueRandom( int N, int* Status ){
	// This function returns a vector of N unique numbers between 0 to 9
	// However, function reports an error if N exceeds 10 
	int status = 1; 
	*Status = status; 
	vector<int> Out; 
	int i;
	int tmp; 
	i = 0; 
	if ( N > 10 ){
		cout<<"Error, "<<
		"you entered more than 10 random numbers,"
		<<" but there are only 10 digits, \n"; 
		status = 0; 
		*Status = status; // More than 10 random numbers 
		return Out; 
	}
	if ( N < 1 ){
		cout<<"Error, "<<
		"you entered too few random numbers"<<"\n"; 
		status = 2; 
		*Status = status; // Too few random numbers
		return Out; 
	}
	int count = 0; 
	while (true){
		tmp = getRandom();
		if (i==0){
			Out.push_back(tmp); 
			count++;
		}
		else{
			auto first = Out.begin();
			auto last = Out.end();
			auto it = find(first,last,tmp); 
			if (it != Out.end()){
				continue;
			}
			else{
				Out.push_back(tmp);
				count++;
			}
		}
		if (count>=N){
			break;
		}
		i++;
	}
	return Out; 
}
int printOutInt ( vector<int> vec ){
	// This function prints out 
	for (int i = 0; i < vec.size(); i++){
		cout<<vec[i]<<" "; 
		if (i>0 && i%10==0){
			cout<<"\n"; 
		}
	}
	cout<<"\n"; 
	return 0;
}
int main(){
	string ToContinue = "y"; 
	int i, j; // Loop variables
	int t = time(NULL); // Return the number of seconds since 1 January 1970 00Z
	srand(time(NULL));
	int Status; // Status of get unique random number from PC
				// If we enter more than 10 random numbers 
				// The program halts because there are only 0 to 9 digits 
	string tmp; 
	vector<int> ComputerVec; 
	while (true){
		cout<<"Enter number of random numbers you want to guess \n"; 
		cin>>tmp; 
		if (isNumeric(tmp)==0){
			cout<<"Error: Invalid number entered, please try again\n"; 
			continue; 
		}else{
			ComputerVec = getUniqueRandom(stoi(tmp),&Status); 
		}
		if (Status==1){
			//cout<<"The computer random numbers, which you should guess in this game, is \n"; 
			//printOutInt( ComputerVec );
			break; 
		}
		else if (Status==0){
			cout<<"Error: You entered too many random numbers, please try again\n"; 
			continue; 
		}
		else if (Status==2){
			cout<<"Error: You entered too few random numbers, please try again\n"; 
			continue; 
		}
	}
	while (ToContinue == "y"){
		vector<int> MyVec; // The vector you entered to guess computer vector
		while (true){
			cout<<"Now, please enter your random number, "<<
			"consistent with the number of random numbers "<<
			"you want to guess \n"; 
			cin.clear();
			int status;        // This status returns 0 if WE (not computer) entered a non-digit	
			int N = stoi(tmp); // Number of unique random digits we want to guess
			for (i = 0; i < N; i++){
				cin>>tmp; 
				status = isNumeric( tmp ); 
				if (status == 0){
					cout<<"Error: Non-integer entered, please try again\n"; 
					continue; 
				}
				else{
					MyVec.push_back(stoi(tmp)); 
				}
			}
			int M = countUnique( MyVec ); 
			if ( M < MyVec.size() ){
				cout<<MyVec.size();
				cout<<"Error: You have duplicates in your guess, please try again\n"; 
				continue; 
			}
			cout<<"You entered this \n"; 
			printOutInt( MyVec );
			break; 
		}
		cout<<"Calculating cows -- your digit is same as computer digit AND same position as computer\n"; 
		cout<<"Calculating bulls -- your digit is same as computer digit BUT different position as computer\n";
		int Cows = 0; 
		int Bulls = 0; 
		for (i = 0; i < MyVec.size(); i++){
			for (j = 0; j < ComputerVec.size(); j++){
				if ( MyVec[i] == ComputerVec[j] ){
					if ( i == j ){ 
						Cows++; 
					}
					else{
						Bulls++;
					}
				}
			}
		}
		cout<<"You have "<<Cows<<" cows \n"; 
		cout<<"You have "<<Bulls<<" bulls \n"; 
		if (Cows==ComputerVec.size()){
			cout<<"You won by guess ALL correctly, congratulations !\n"; 
			break;
		}
		cout<<"You win when you have "<<MyVec.size()<<" cows \n"; 
		cout<<"To continue guessing, press y, press any other key to quit\n"; 
		cin.clear();
		cin>>ToContinue;
		if (ToContinue!="y"){
			break;
		}
	}
	cout<<"The answer is \n"; 
	printOutInt(ComputerVec); 
}
