/*
https://www.interviewbit.com/problems/painters-partition-problem/
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll Mod =1e7+3;

ll numberOfPainter(ll c[], int size, ll limit){
	ll sum=0,painters=1;

	for(int i=0;i<size;i++){
		sum+=c[i];
		if(sum>limit) {
			sum=c[i];
			painters++;
		}
	}

	return painters;
}

int main(){
	int A=10, B=1, C[]= {1,8,11,3}, n3=4;

	ll total_length=0,k=0,c[n3];
	for(int i=0;i<n3;i++){
		c[i]=C[i]*B;
		k = max(k,c[i]);
		total_length+=c[i];
	}

	ll lo=k, hi = total_length,mid,pnt=A;

	while(hi-lo>1){
		mid = (hi+lo)/2;

		if(numberOfPainter(c,n3,mid)<=pnt) hi=mid;
		else lo = mid+1;
	}

	cout<<lo%Mod<<endl; 
}