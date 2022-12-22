/*
https://www.spoj.com/problems/ZSUM/
*/
#include <bits/stdc++.h>
using namespace std;

const int M=10000007;

int binaryExp(int a,int b){
	int ans=1;
	while(b){
		if(b&1) ans = (ans*1LL*a)%M;
		a=(a*1LL*a)%M;
		b>>=1;
	}
	return ans;
}

int main(){
	while(true){
		int n,k;
		cin>>n>>k;
		if(n==0&&k==0) break;
		int sum = 0;

		sum = (sum + binaryExp(n,k))%M;
		sum = (sum + binaryExp(n,n))%M;
		sum = (sum + (2*1LL*binaryExp(n-1,k))%M)%M;
		sum = (sum + (2*1LL*binaryExp(n-1,n-1))%M)%M;

		cout<<sum<<endl;
	}
}