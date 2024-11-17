#include<iostream>
#include<vector>
using namespace std; 
vector<double> Shift( vector<double> vec, vector<double> Out, int m ){
	int i; 
	for ( i = 0; i < vec.size(); i++ ){
		if ( m > 0 ){
			if ( (i+m) < vec.size() ){ 
				Out[ i ] = vec[ i + m ];
			}
			else{
				Out[ i ] = 0; 
			}
		}
		if ( m < 0 ){
			if ( (i+m) < 0 ){
				Out[ i ] = 0; 
			}
			else{
				Out[ i ] = vec[ i + m ];
			}
		}
		if ( m == 0 ){
			Out = vec; 
		}
	}
	return Out; 
}
int isNumeric( string Input ){
	int status = 1; 
	for (int i = 0; i < Input.length(); i++){
		if (isdigit(Input[i]) || Input[i] == '.' || Input[i] == ' '){
			continue; 
		}
		else{
			status = 0; 
			break; 
		}
	}
	return status; 
}
vector<double> subtract (vector<double> Vec2, vector<double> Vec1){
	vector<double> VecOut; 
	for (int i = 0; i < Vec2.size(); i++){
		cout<<Vec2[i]<<" - "<<Vec1[i]<<" = "<<Vec2[i] - Vec1[i]<<"\n";
		VecOut.push_back( Vec2[i] - Vec1[i] );
	}
	return VecOut; 
}
int printOut ( vector<double> vec ){
	for (int i = 0; i < vec.size(); i++){
		cout<<vec[i]<<" "; 
	}
	cout<<"\n"; 
	return 0;
}
int main(){
	vector<double> MyVec; 
	string tmp;
	cout<<"Enter a series of numbers ending with | \n"; 
	while(true){
		cin.clear(); 
		cin>>tmp; 
		if ( isNumeric( tmp ) == 1 ){
			MyVec.push_back(stod(tmp));
		}
		else if ( tmp == "|" ){
			cout<<"End of series \n"; 
			break; 
		}
		else if ( isNumeric( tmp ) == 0 ){
			cout<<"Invalid number, terminating\n"; 
			break; 
		}
	}
	cout<<"You have entered: \n"; 
	printOut( MyVec );
	vector<double> shiftedVec = MyVec;
	int m; 
	cout<<"Would you like to shift the vector front (negative m) or back (positive m)?\n"; 
	cin.clear();
	cin>>m;
	shiftedVec = Shift( MyVec, shiftedVec, m ); 
	cout<<"You have shifted it by "<<m<<"\n"; 
	printOut( shiftedVec ); 
	if ( m < 0 ){
		cout<<"Operation to compute past difference \n"; 
		vector<double> diffVec = subtract(MyVec,shiftedVec); 		
		cout<<"The vector of difference with past "<<abs(m)<<" is :\n"; 
		printOut(diffVec);
	}
}			
