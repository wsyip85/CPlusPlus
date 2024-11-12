#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std; 
int main(){ 
	string status = "y";
	vector<double> vec = {};
	double tmp;
	double Max, Min; 
	double Sum, Mean; 
	while (status == "y"){
		cout<<"Enter a series of numbers terminated by -99\n";
		cin>>tmp; 
		while (tmp!=-99){
			vec.push_back(tmp); 
			cin>>tmp;
		}
		Max = *max_element(vec.begin(),vec.end()); 
		Min = *min_element(vec.begin(),vec.end()); 
		Sum = accumulate(vec.begin(),vec.end(),0); 
		Mean = Sum / vec.size(); 
		cout<<" The largest value is = "<<Max<<"\n"<<
		" and the smallest value is "<<Min<<"\n"<<
		" , meanwhile the sum of all entered values are "<<Sum<<"\n"<<
		" , and the average of all entered values are "<<Mean<<"\n"; 
		cout<<"To continue, press y, to end press any other button\n"; 
		cin>>status; 
		vec.clear();
	}
}

		