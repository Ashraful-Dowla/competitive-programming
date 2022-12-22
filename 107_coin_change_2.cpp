/*
https://leetcode.com/problems/coin-change-2/
*/
#include <bits/stdc++.h>
using namespace std;

const int N=3000;
vector<int>coins(N);
int dp[300][N];
int n;

int coinChange(int idx, int amount){
	if(amount==0) return 1;
	if(idx<0) return 0;
	if(dp[idx][amount]!=-1) return dp[idx][amount];
	
	int ways=0;
	for(int coin_amount=0; coin_amount<=amount; coin_amount+=coins[idx]){
		ways +=coinChange(idx-1,amount-coin_amount);
	}

	return dp[idx][amount]=ways;
}

int main(){
	memset(dp,-1,sizeof(dp));
	cin>>n;
	for(int i=0;i<n;++i) cin>>coins[i];
	int amount;
	cin>>amount;
	int ans = coinChange(n-1,amount);
	cout<<ans<<endl;
}