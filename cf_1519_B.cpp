/*
https://codeforces.com/problemset/problem/1519/B
*/
#include <bits/stdc++.h>
using namespace std;

const int N=1e2+10;
int dp[N][N][N];

bool generate(int n,int m,int k){
	if(k==0 && n==1 && m==1) return true;
	if(dp[n][m][k]!=-1) return dp[n][m][k];

	bool isPossible=false;
	if(n>=2) isPossible|=generate(n-1,m,k-m);
	if(m>=2) isPossible|=generate(n,m-1,k-n);

	return dp[n][m][k]=isPossible;
}

int main(){
	int t;
	cin>>t;
	while(t--) {
	    int n,m,k;
		cin>>n>>m>>k;
		memset(dp,-1,sizeof(dp));
		cout<<(generate(n,m,k) ? "YES": "NO")<<endl;
	}
}