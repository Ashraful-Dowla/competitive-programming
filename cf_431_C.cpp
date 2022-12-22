/*
https://codeforces.com/problemset/problem/431/C
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;
int n,k,d;
int dp[105][2];

int calc(int sum, bool pos){
	if(sum==0 && pos) return 1;
	if(dp[sum][pos]!=-1) return dp[sum][pos];

	int cnt=0;
	bool isPossible=pos;
	for(int i=1;i<=k;++i){
		if(sum-i>=0){
			isPossible|=(i==d);
			cnt=(cnt%MOD+calc(sum-i,isPossible)%MOD)%MOD;
		}	
	}

	return dp[sum][pos]=cnt;
}

int main(){
	cin>>n>>k>>d;

	memset(dp,-1,sizeof(dp));
	cout<<calc(n,false)<<endl;
}