#include<iostream>
using namespace std; 
int main(){
	int i = 0; 
	while (i<26){
		cout<<char('a'+i)<<" "<<int('a'+i)<<" | "<<char('A'+i)<<" "<<int('A'+i)<<"\n"; 
		i++;
	}
}
