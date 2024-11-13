#include<iostream>
#include<ctime>
#include<random>
#include<cmath>
using namespace std; 
int main(){
	
	int t = time(NULL); // Return the number of seconds since 1 January 1970 00Z
	srand(time(NULL));
	
	int i; 
	
	double m;         // denote your measurement to be scaled
	double rmin = 0;  // denote the minimum of the range of your measurement
	double rmax = 1;  // denote the maximum of the range of your measurement
	double tmin = 1;  // denote the minimum of the range of your desired target scaling
	double tmax = 3;  // denote the maximum of the range of your desired target scaling
	int random;    // denote your scaled number 
	
	string computerChoice; // rock, paper or scissors for computer
	string YourChoice;     // rock, paper or scissors which you choose 
	
	cout<<"Playing rock, paper, scissors with computer\n"; 
	
	int yourPoints = 0;            // counting points for you
	int computerPoints = 0;        // counting points for computer
	
	for (i=0;i<10;i++){
		
		// Scaling 0 to 1 random number to 1 to 3 random number
		// https://stats.stackexchange.com/questions/281162/scale-a-number-between-a-range
		
		m = float( rand() ) / float( RAND_MAX );
		
		random = round( (m - rmin)/(rmax - rmin) * (tmax - tmin) + tmin ); 
		
		// 1 - rock
		// 2 - paper
		// 3 - scissors 
		
		switch (random){
		
			case 1: 
				computerChoice = "rock"; 
				break;
				
			case 2: 
				computerChoice = "paper"; 
				break;
				
			case 3: 
				computerChoice = "scissors"; 
				break; 
			
		}
		
		cout<<"Do you choose rock, paper, or scissors?\n"; 
		cin>>YourChoice; 
		
		if (YourChoice=="rock"&&computerChoice=="paper"){
			computerPoints += 1; 
		} else if (YourChoice=="rock"&&computerChoice=="scissors"){
			yourPoints += 1; 
		}
		
		if (YourChoice=="paper"&&computerChoice=="scissors"){
			computerPoints += 1; 
		} else if (YourChoice=="paper"&&computerChoice=="rock"){
			yourPoints += 1; 
		}		
		
		if (YourChoice=="scissors"&&computerChoice=="rock"){
			computerPoints += 1; 
		} else if (YourChoice=="scissors"&&computerChoice=="paper"){
			yourPoints += 1; 
		}				
		
		if (YourChoice!="rock"&&YourChoice!="paper"&&YourChoice!="scissors"){
			cout<<"Invalid choice, please try again\n";
		}
		
		if (yourPoints>computerPoints){ 
			cout<<"You have "<<yourPoints<<" while computer have "<<computerPoints<<" you are winning, keep it up\n";
		}
		else if (computerPoints>yourPoints){
			cout<<"Computer have "<<computerPoints<<" while you have "<<yourPoints<<" you are losing, buck up\n"; 
		}
		else{
			cout<<"Computer have "<<computerPoints<<" while you have "<<yourPoints<<" you are neck to neck !\n"; 
		}
		
	}
	
	if (yourPoints>computerPoints){
		cout<<"You have "<<yourPoints<<" computer have "<<computerPoints<<" you win ! \n"; 
	}
	else if (yourPoints<computerPoints){
		cout<<"Computer have "<<computerPoints<<" you have "<<yourPoints<<" you lose ! \n"; 
	}
	else{
		cout<<"You draw because both of you have same points "<<" computer = "<<computerPoints<<" you = "<<yourPoints<<"\n"; 
	}
	
}
