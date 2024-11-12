#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 
int main(){
	cout<<"How many numbers you want to sort?";
	int n; 
	cin>>n;
	cout<<"You want to sort "<<n<<" numbers \n";
	vector<int>vec(n);
	int i;
	int tmp; 
	for (i = 0; i < vec.size(); i++){
		cout<<"Enter no. number "<<i+1<<"\n"; 
		cin>>tmp; 
		vec[i]=tmp; 
	}
	cout<<"Here are the numbers you keyed in:\n"; 
	for (i = 0; i < vec.size(); i++){
		cout<<vec[i];
		if ( i < vec.size()-1 ){ 
			cout<<",";
		}
	}
	cout<<"\n";
	cout<<"Here are numbers which you keyed in; sorted:\n"; 
	sort(vec.begin(),vec.end()); 
	for (i = 0; i < vec.size(); i++){
		cout<<vec[i];
		if ( i < vec.size()-1 ){ 
			cout<<",";
		}
	}	
}
