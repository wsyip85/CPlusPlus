#include<iostream>
#include<vector>
using namespace std; 
int getSquare(int Input){
	int Output=0;
	for (int i=0;i<Input;i++){
		Output+=Input;
	}
	return Output; 
}
vector<int> getVector (int Begin, int End, int Interval){
	vector<int> Vec((End-Begin)/Interval+1);
	int Index = 0; 
	for (int i = Begin; i <= End; i+=Interval ){ 
		Vec[Index] = i;
		Index++;
	}
	return Vec; 
}
int main(){
	vector<int> vec = getVector(0,100,1); 
	int i; 
	for (i = 0; i < vec.size(); i++ ){
		cout<<vec[i]<<"\t"<<getSquare(vec[i])<<"\n"; 
	}
}
