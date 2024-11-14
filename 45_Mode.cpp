#include<algorithm>
#include<iostream>
#include<vector>
using namespace std; 
vector<int> Unique ( vector<int> vec ){
	
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
	vector<int>::iterator ip = unique( vec.begin(), vec.end() ); 
	
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

int printVector ( vector<int> vec ){
	// Printing all elements in vector
	for (auto i: vec){
		cout<<i<<"\n";
	}
	return 0;
}

vector<int> nEl ( vector<int> vec, vector<int> vecUniq ){
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
	
	vector<int> vec = {1,2,3,1,2,1,5,6,1,7,2,3,2}; // 1,2,3,1,2,1,5,6,1,7,2,3,2 (original vector)
	
	vector<int> vecUniq = Unique( vec ); // 1,2,3,5,6,7 (unique numbers) 
	
	vector<int> NoEl = nEl( vec, vecUniq ); // 4,4,2,1,1,1 (occurrence of unique numbers) 
	
	int Max = *max_element( NoEl.begin(), NoEl.end() ); // 4 (maximum occurence of unique numbers) 
	
	for (int i = 0; i < vecUniq.size(); i++){ // Looping through unique numbers 
		
		if (NoEl[i] == Max){  // If occurence matches maximum occurence, print out as mode 
			
			cout<<vecUniq[i]<<" is mode \n"; 
			
		}
		
	}
	
}
