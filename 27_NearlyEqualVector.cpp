#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
double detectEqual(vector<double> vec){
	int i, j; 
	for (i=0;i<vec.size();i++){
		for (j=i+1;j<vec.size();j++){
			if (vec[i]==vec[j]){
				cout<<"The "<<i<<"th element "<<
				" is same as the "<<j<<" th element "<<
				"which is equals to "<<vec[i]<<"\n"; 
			}
			else if (abs(vec[i]-vec[j])<0.01){
				cout<<"The "<<i<<"th element "<<
				" is nearly the same as the "<<j<<
				" th element "<<
				" whereby "<<vec[i]<<" is compared to "<<
				vec[j]<<"\n";   				
			}
		}
	}
	return 0; 
}
int main(){
	double temp; 
	vector<double> vec; 
	cout<<"Please key in numbers followed by spacebar\n";
	while (cin>>temp){
		vec.push_back(temp); 
	}
	cout<<"You keyed in these numbers\n"; 
	for (auto i: vec){
		cout<<i<<"\t"; 
	}
	cout<<"\n";
	double Max = *max_element(vec.begin(),vec.end());
	double Min = *min_element(vec.begin(),vec.end());
	cout<<"The maximum = "<<Max<<"\n"; 
	cout<<"The minimum = "<<Min<<"\n";
	detectEqual(vec); 
}
