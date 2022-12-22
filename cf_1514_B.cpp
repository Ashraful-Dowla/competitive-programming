/*
https://codeforces.com/problemset/problem/1514/B
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;

int binaryExp(int a,int b){
	int ans=1;
	while(b>0) {
	    if(b&1) ans=(ans*1LL*a)%MOD;
	    a=(a*1LL*a)%MOD;
	    b>>=1;
	}
	return ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		cout<<binaryExp(n,k)<<endl;
	}
}