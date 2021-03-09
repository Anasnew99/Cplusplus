#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;
vector<int> splitIntoNumbers(string s,int totalNumbers){
	vector<int> numbers;
	int i=0;
	while (i<totalNumbers) 
    { 	size_t newSpacePosition = s.find(' ');
		if(newSpacePosition <s.size()){
			numbers.push_back(stoi(s.substr(0,newSpacePosition)));
			s = s.substr(newSpacePosition+1, s.size());
		}else{
			numbers.push_back(stoi(s));
		}
		i++;
    } 
	return numbers;
  
}
int main(int argc, char **argv)
{
	string s,fix;
	int N,sum;
	cin>>N;
	sum = (N*(N+1))/2;
	getline(cin,fix);
	getline(cin,s);
	vector<int> splitted_arr = splitIntoNumbers(s,N-1);
	for(int k:splitted_arr){
		sum -= k;
	}
	cout<<"\n"<<sum;
	return 0;
}
