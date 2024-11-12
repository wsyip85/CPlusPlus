#include<iostream>
#include<algorithm>
#include<vector>
using namespace std; 
int main(){
	cout<<"How many words to store?\n"; 
	int n;
	cin>>n; 
	vector<string> vec(n); 
	cout<<"You wish to store "<<n<<" words\n"; 
	string tmp; 
	int i; 
	for (i=0;i<vec.size();i++){
		cout<<"Word no. "<<i<<" is :";
		cin>>tmp; 
		vec[i]=tmp; 
		cout<<"\n";
	}
	cout<<"You stored these words\n"; 
	for (i=0;i<vec.size();i++){
		cout<<vec[i];
		if (i<vec.size()-1){
			cout<<",";
		}
	}
	cout<<"\n";
	cout<<"Your stored words; sorted\n"; 
	sort(vec.begin(),vec.end());
	for (i=0;i<vec.size();i++){
		cout<<vec[i];
		if (i<vec.size()-1){
			cout<<",";
		}
	}	
}
