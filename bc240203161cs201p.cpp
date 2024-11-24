#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
int main(){
	string studentname="OWAIS";
	string vuid="bc240203161";
	
	cout<<"STUDENT NAME: "<<studentname<<endl;
	cout<<"VUID: "<<vuid<<endl;
	
	int marks[3];
	int totalmarks=0;
	double  average;
	char grade;
	int highestmarks,lowestmarks;
	
	for(int i=0 ;i<3; ++i){
		
		do{
			cout<<"Enter marks for subject  "<<(i+1)<<" : ";
		cin>>marks[i];
		
		if(marks[i]< 0 || marks [i]> 100){
			cout<<" Invalid input. mark should between 0 and 100. "<<endl;
	 }
			
		} while(marks[i]< 0 || marks [i]> 100);
			totalmarks += marks[i];
			
			
		}
		
		average = totalmarks/3.0;
		
		if(average>=90) {
			
			grade ='A';
			
		}
		else if(average>=80){
			
			grade ='B';
			
			}
			else if(average>=70){
			
			grade ='C';
			
			}
			else if(average>=60){
			
		grade ='D';
			
			}
			else{
			grade ='F';
			}
		
	highestmarks= *max_element(marks,marks+3);
	lowestmarks= *min_element(marks,marks+3);
	
	cout<<"\nMarks have been entered. Here is your result:\n";
	cout<<"Obtained marks out of 300: "<<totalmarks <<endl;
	cout<<fixed << setprecision(4)<<"Average marks: " <<average <<endl;
	cout<<"Grade : "<< grade <<endl;
	cout<<"Highest marks : "<< highestmarks <<endl;
	cout<<"Lowest marks : "<<  lowestmarks <<endl;
	
	
	
	
	
	return 0;
}
