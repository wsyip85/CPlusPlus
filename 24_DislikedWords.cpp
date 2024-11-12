#include<iostream>
#include<vector>
using namespace std;
vector<string> DislikedWords(){
	vector<string> DWords; 
	string status = "c";	
	string temp; 
	while (status!="q"){
		cout<<"Enter your disliked words:\n"; 
		cin>>temp; 
		DWords.push_back(temp); 
		cout<<"To stop, key in q, to continue key in any word"; 
		cin>>status; 
	}
	return DWords; 
}
int main(){
	string Alphabet; 
	vector<string> Dwords = DislikedWords(); 
	int status = 0; 
	cout<<"Listing a to z, disliked words become BLEEP\n"; 
	cout<<"There are "<<Dwords.size()<<" that you disliked\n"; 
	cout<<"The words you dislike are :\n"; 
	int i, j; 
	for ( j = 0; j < Dwords.size(); j++ ){
		cout<<"You disliked "<<Dwords[j]<<"\n"; 
	}
	cout<<"Altogether, "<<Dwords.size()<<" words were disliked \n"; 
	cout<<"Listing down a to z, words you disliked get labelled BEEP\n"; 
	string tmp; 
	for ( i = 0; i < 26; i++ ){
		tmp = char('a'+i);
        for ( j = 0; j < Dwords.size(); j++ ){ 
			status = 0; 
			if (Dwords[j]==tmp){
				cout<<tmp<<" is disliked, BEEP\n"; 
				status = 1; 
				break; 
			}
		}
		if (status==0){
			cout<<tmp<<"\n"; 
		}
	}
}
