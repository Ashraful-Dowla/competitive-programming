/*
https://leetcode.com/problems/powx-n/description/
*/
#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {
	
	if(x==1) return 1;
	if(x==-1) return abs(n)%2==0 ? 1: -1;
	if(n==INT_MIN) return 0;

	double p=1.0;
	for(int i=0;i<abs(n);++i){
		if(n<0) p*=(1/x);
		else p*=x;
	}

	return p;
}

int main(){
	double x = -1;
	int n = INT_MAX;

	cout<<myPow(x,n)<<endl;
	cout<<pow(x,n)<<endl;
}