#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main()
{
		 string studentname="OWAIS";
	 string vuid= "bc240203161" ;
	
	cout<<"STUDENT NAME: " <<studentname<<endl;
	cout<<"STUDENT ID: " <<vuid<<endl;
	
	string studentid=vuid.substr(2);
	
	string yearstr = studentid.substr(0,studentid.length()-2).substr(studentid.length()-6,4);
	int year;
	stringstream ss (yearstr);
	ss>>year;
	
	bool isleapyear =(year % 4 == 0 && year % 100!=0)|| (year %  400 == 0);
	cout<<"The year "<<year<<(isleapyear ? " is a leap year. " : " is not a leap year. ")<<endl;
	
	int month;
	while(true){
		
		cout<<"Enter the month (1-12), or -1 to stop: " ;
		cin>> month;
		
		if(month == -1)
		{
			break;
			
		}
		int days ;
		if(month < 1 || month > 12) 
		{
			
		cout<<" Invalid month ! " <<endl;	
			
		}
		else {
			
		switch(month)
		{
			
			case 1:case 3: case 5: case 7: case 8: case 10: case 12:;
			days = 31;
			break;
			
			case 4: 	case 6: 	case 9: 	case 11:
			days = 30;
			break;
			
			case 2:
				days = isleapyear ? 29 : 28;
				break;
		}	
			
			string monthname;
			switch(month){
				case 1:monthname = "January ";break;
				case 2:monthname = "February ";break;
				case 3:monthname = "March ";break;
				case 4:monthname="April"     ;break;
				case 5:monthname = "May ";break;
				case 6:monthname = "June ";break;
				case 7:monthname = "July ";break;
				case 8:monthname = "August ";break;
				case 9:monthname = "September ";break;
				case 10:monthname = "October ";break;
				case 11:monthname = "November ";break;
				case 12:monthname = "December ";break;
				
				
			}
			cout <<" Month " <<month<< " - " << monthname <<" has "<< days << " days. "<< endl;
		}
	}
	
	
	return 0;
}
