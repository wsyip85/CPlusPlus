#include<iostream>
using namespace std; 
int main(){
	string word; 
	while (cin>>word){
		for ( int i = 0; i < word.length(); i++ ){ 
			cout<<word[i]<<"\t"<<int(word[i])<<"\n"; 
		}
		cout<<"----\n"; 
	}
}