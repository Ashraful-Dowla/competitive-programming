/*
https://www.spoj.com/problems/OPMODULO/
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	long long l,r;
	cin>>l>>r;
	long long lq = log2(l);
	long long start= pow(2,lq);
	if(start<l) start*=2;
	long long sum = 0;
	while(start<=r){
		sum+=(start);
		start*=2;
	}
	cout<<sum<<endl;
}