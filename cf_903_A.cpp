/*
https://codeforces.com/contest/903/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

int dp[105];

bool generate(int x){
	if(x==0) return true;
	if(dp[x]!=-1) return dp[x];

	bool isPossible=false;
	if(x>=3) isPossible|=generate(x-3);
	if(x>=7) isPossible|=generate(x-7);

	return dp[x]=isPossible;
}

int main(){
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    memset(dp,-1,sizeof(dp));
	  	if(generate(n)) cout<<"YES"<<endl;
	  	else cout<<"NO"<<endl;
	}
}