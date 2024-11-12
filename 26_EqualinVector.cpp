#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 
int detectEqual(vector<int> vec){
	int i, j; 
	for (i=0;i<vec.size();i++){
		for (j=i+1;j<vec.size();j++){
			if (vec[i]==vec[j]){
				cout<<"The "<<i<<"th element "<<
				" is same as the "<<j<<" th element "<<
				"which is equals to "<<vec[i]<<"\n"; 
			}
		}
	}
	return 0; 
}
int main(){
	int temp; 
	vector<int> vec; 
	cout<<"Please key in numbers followed by spacebar\n";
	while (cin>>temp){
		vec.push_back(temp); 
	}
	cout<<"You keyed in these numbers\n"; 
	for (auto i: vec){
		cout<<i; 
	}
	cout<<"\n";
	int Max = *max_element(vec.begin(),vec.end());
	int Min = *min_element(vec.begin(),vec.end());
	cout<<"The maximum = "<<Max<<"\n"; 
	cout<<"The minimum = "<<Min<<"\n";
	detectEqual(vec); 
}
