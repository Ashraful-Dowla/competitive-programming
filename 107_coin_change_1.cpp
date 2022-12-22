#include <bits/stdc++.h>
using namespace std;

const int N=3000;
vector<int>coins(N);
int dp[N];
int n;

int coinChange(int amount){
	if(amount==0) return 0;
	if(dp[amount]!=-1) return dp[amount];
	int ans=INT_MAX;
	for(int i=0;i<n;++i){
		if(amount-coins[i]>=0) {
			ans = min(ans+0LL,coinChange(amount-coins[i])+1LL);
		}
	}
	return dp[amount]=ans;
}

int main(){
	memset(dp,-1,sizeof(dp));
	cin>>n;
	for(int i=0;i<n;++i) cin>>coins[i];
	int amount;
	cin>>amount;
	int ans = coinChange(amount);
	cout<<(ans ==INT_MAX ? -1: ans)<<endl;
}s