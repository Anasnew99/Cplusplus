#include <iostream>
#include <conio.h>
#include <regex>
#include <vector>
#include <string>
using namespace std;
int getNumber(){
	string s {""};
	string temp;
	while(true){
		temp = getch();
		if(temp == " "|| temp == "\r"){
			cout<<" ";
			break;
		}else if(temp == "\b"){
			if(s.size()!=0){
				s = s.substr(0,s.size()-1);
				cout<<"\b \b";
			}
			
		}
		else if(regex_match(temp,regex("[0-9]"))){
			cout<<temp;
			s+=temp;
		}
	}
	if(s!=""){
		return stoi(s);
	}
	return 0;
}
int main(int argc, char **argv)
{
	int n;
	int temp;
	cout<<"Enter N \n";
	cin>>n;
	vector<bool> a (n + 1,false); // First we assume that none element is present
	int i = 0;
	cout<<"\nEnter "<<n-1<<" Numbers from 1 to "<<n<<"(Not repeating) \n";
	while(i<n-1){
		temp = getNumber(); // Then We get each number from user and mark the number present
		if(temp == 0){
			break;
		}
		if(temp<0 ||temp > n){
			cout<<"\n\nERROR: Number Entered should be between 1 to "<<n;
			break;
		}
		if(a.at(temp)){
			cout<<"\n\nERROR: Number is already entered";
			break;
		}
		a.at(temp) = true;
		i++;
	}
	cout<<"\n \n";
	if(i==n-1){
		i=1;
		while(i<=n){ // Now we check which number is not present
			if(!a.at(i)){
				cout<<"RESULT: "<<i<<" is not present"<<endl;
				break;
			}
			i++;
		}
	}
	
	return 0;
}
