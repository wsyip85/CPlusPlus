#include<iostream>
using namespace std; 
int main(){
	for (int i =0; i < 26; i++){
		cout<<char('a'+i)<<" "<<int('a'+i)<<" | "<<char('A'+i)<<" "<<int('A'+i)<<"\n"; 
	}
}
