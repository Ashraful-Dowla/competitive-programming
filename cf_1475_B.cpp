/*
https://codeforces.com/problemset/problem/1475/B
*/
#include <bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int dp[N];

bool isPossible(int n){
	if(n==0) return true;
	if(dp[n]!=-1) return dp[n];

	bool chk=false;
	if(n-2020>=0){
		chk|=isPossible(n-2020);
		chk|=isPossible(n-2021);
	}

	return dp[n]=chk;
}

int main(){
	int t;
	cin>>t;
	memset(dp,-1,sizeof(dp));
	while(t--) {
	    int n;
	    cin>>n;
	    cout<<(isPossible(n) ? "YES": "NO")<<endl; 
	}
}