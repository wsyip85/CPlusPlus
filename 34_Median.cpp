#include<iostream>
#include<vector>
#include<cmath>
using namespace std; 
int main(){
	vector<double> vec; 
	double tmp; 
	double mid;
	string status = "y"; 
	while (status=="y"){
		cout<<"Enter a series of numbers ending in -99\n"; 
		cin>>tmp; 
		while (tmp!=-99){ //Do not terminate cin with a character, else it will remain in the buffer 
			vec.push_back(tmp); 
			cin>>tmp; 
		}
		int n = vec.size();
		if (n%2==0) {
			mid = vec[floor(n/2)-1]/2.0 + vec[floor(n/2)]/2.0; 
		}
		else {
			mid = vec[floor(n/2)]; 
		}
		cout<<"The median is = "<<mid<<"\n";
		cout<<"To continue, press y, to exit press any button\n"; 
		cin>>status;
		vec.clear(); 
	}
}
