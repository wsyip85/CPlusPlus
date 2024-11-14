#include<iostream>
#include<algorithm>
#include<vector>
using namespace std; 
int findInteger ( vector<int> Vec, int Keyword ){
	vector<int>::iterator it = find( Vec.begin(), Vec.end(), Keyword ); 
	int Pos = it - Vec.begin(); 
	return Pos; 
}
int findString ( vector<string> Vec, string Keyword ){
	vector<string>::iterator it = find( Vec.begin(), Vec.end(), Keyword ); 
	int Pos = it - Vec.begin();
	return Pos; 
}
int main(){
	vector<string> Names; 
	vector<int> Values; 
	string Name; 
	int Value;
	int Pos; 
	int Status = 0;
	while (Status==0){
		cout<<"Enter name (string) followed by value (integer), to terminate enter NoName 0\n";
		cin>>Name>>Value;
		Pos = findString( Names, Name ); 
		if (Names.size()==0 || Pos!=Names.size()){
			Names.push_back(Name);
			Values.push_back(Value); 			
		}
		else if (Names.size()>0 && Pos!=Names.size()){
			cout<<"The name already exists, please try again\n"; 
		}
		else if (Name == "NoName"){
			Status = 1; 
		}
		else{
			Names.push_back(Name);
			Values.push_back(Value); 
		}
		cin.clear();
	}
	cout<<"The names and values which you entered are \n";
	for (int i = 0; i < Names.size(); i++){
		cout<<Names[i]<<" "<<Values[i]<<"\n";
	}
	int Found;
	Status = 0; 
	int i;
	string Mode; 
	while (Status == 0){
		cout<<"Enter Names, press Enter, then followed by name to search by name to obtain values\n";
		cout<<"Or Enter Values, press Enter, then followed by value to search by value to obtain name\n";
		cin.clear();
		cin>>Mode; 
		Found = 0;
		if (Mode=="Names"){
			cin.clear();
			cin>>Name; 
			for (i = 0; i < Names.size(); i++){
				if (Names[i] == Name){
					cout<<"The value corresponding to "<<Name<<" is "<<Values[i]<<"\n"; 
					Found = 1; 
					break; 
				}
			}
		}
		if (Mode=="Values"){
			cin.clear();
			cin>>Value;
			for (i = 0; i < Values.size(); i++){
				if (Values[i] == Value){
					cout<<"The name corresponding to "<<Value<<" is "<<Names[i]<<"\n";
					Found = 1; 
					break;
				}
			}
		}
		if (Found == 0){
			cout<<"Your name or value are not found\n"; 
		}
		cout<<"To continue, type 0, to continue, type any other number\n"; 
		cin.clear();
		cin>>Status; 
	}
}
