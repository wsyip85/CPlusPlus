#include<algorithm>
#include<iostream>
#include<vector>
using namespace std; 
vector<string> Unique ( vector<string> vec ){
	
	/*
	This function gets the vector of unique 
	elements from the input vector
	*/

    //
    // Sorting the vector 
	//
	sort( vec.begin(), vec.end() ); 
	
	//
	// Declaring vector of integer iterator variable. 
	//
	// Then replacing consecutive same elements with undefined
	//   and shifting the vector element pointer to the next 
	//     different element. 
	//
	// The size of the original vector is maintained by 
	//   making elements at the end of the modified vector 
	//     to be undefined. 
	//  
	// The vector interator variable returned by unique points to 
	//   the first undefined element at the end of the modified 
	//     vector. 
	//
	vector<string>::iterator ip = unique( vec.begin(), vec.end() ); 
	
	//
	// Resize the vector by number of elements between the 
	//  beginning until the first undefined element exclusive
	//
	vec.resize(distance(vec.begin(),ip)); 
	
	//
	// Returning the vector which was sorted and 
	//   where duplicates have been removed. 
	// 
	return vec; 
	
}

int printVector ( vector<string> vec ){
	// Printing all elements in vector
	for (auto i: vec){
		cout<<i<<"\n";
	}
	return 0;
}

vector<int> nEl ( vector<string> vec, vector<string> vecUniq ){
	// Takes in two vectors
	//   One is the original vector (vec)
	//     Two is the vector of unique elements of the original vector (vecUniq)
	// Returns one vector
	//   That is, the population of each unique element inside original vector vec. 
		
	vector<int> NoEl; 	
		
	for (auto i: vecUniq){
		auto j = count( vec.begin(), vec.end(), i ); 
		NoEl.push_back(j); 
	}
	
	return NoEl; 
	
}	
	
int main(){
	
	// a, b, c, a, b, a, e, f, a, g, b, c, b
	vector<string> vec = {"a","b","c","a","b","a","e","f","a","g","b","c","b"}; // a, b, c, a, b, a, e, f, a, g, b, c, b (original vector)
	
	vector<string> vecUniq = Unique( vec ); // a,b,c,e,f,g (unique numbers) 
	
	vector<int> NoEl = nEl( vec, vecUniq ); // 4,4,2,1,1,1 (occurrence of unique numbers) 
	
	int Max = *max_element( NoEl.begin(), NoEl.end() ); // 4 (maximum occurence of unique numbers) 
	
	for (int i = 0; i < vecUniq.size(); i++){ // Looping through unique numbers 
		
		if (NoEl[i] == Max){  // If occurence matches maximum occurence, print out as mode 
			
			cout<<vecUniq[i]<<" is mode \n"; 
			
		}
		
	}
	
}
