#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 
int main(){
	vector<int> vec; 
	int temp;
	int count = 0; 
	cout<<"Start by entering an integer \n"; 
	while(cin>>temp){
		vec.push_back(temp); 
		if (count>0){
			int Max = *max_element(vec.begin(),vec.end()); 
			int Min = *min_element(vec.begin(),vec.end()); 
			if (temp == Max){
				cout<<vec[count]<<" is the largest so far \n"; 
			}
			else if (temp == Min){
				cout<<vec[count]<<" is the smallest so far \n"; 
			}
			else{
				cout<<vec[count]<<"\n"; 
			}
		} 
		else {
			cout<<vec[count]<<" is the first element \n"; 
		}
		count++;
	}
}
