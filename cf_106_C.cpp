/*
https://codeforces.com/contest/106/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

const int N=1e3+10;
int dp[N];

int main(){
	int n,m,c,d;
	cin>>n>>m>>c>>d;

	for(int i=c;i<=n;++i){
		dp[i]=dp[i-c]+d;
 	}

 	int a,b;
 	for(int i=0;i<m;++i){
 		cin>>a>>b>>c>>d;

 		for(int j=0;j<a/b;++j){
 			for(int k=n;k>=c;--k){
 				dp[k] = max(dp[k],dp[k-c]+d);
 			}
 		}
 	}
	cout<<dp[n]<<endl;
}