#include <iostream>
using namespace std;
int pow(int n,int m){
	if(m==0){
		return 1;
	}
	return n* pow(n,m-1);
}
// This functions takes less time.
int pow2(int n,int m){
	if(m==0){
		return 1;
	}
	if(m%2==0){
		return pow2(n*n,m/2);
	}else{
		return n*pow2(n*n,(m-1)/2);
	}
}
int main(int argc, char **argv)
{
	cout<<pow(2,7)<<"\n";
	cout<<pow2(2,7)<<"\n";
	return 0;
}
