#include <bits/stdc++.h>
using namespace std;

const int N=2e5+10;
int wt[N],val[N];

long long dp[105][100050];

long long knapsack(int idx, int left_value){
	if(left_value==0) return 0;
	if(idx<0) return 1e15;
	if(dp[idx][left_value]!=-1) return dp[idx][left_value];

	long long ans = knapsack(idx-1, left_value);
	if(left_value-val[idx]>=0){
		ans = min(ans, knapsack(idx-1, left_value-val[idx]) + wt[idx]);
	}
	return dp[idx][left_value]=ans;
}

int main(){
	memset(dp,-1,sizeof(dp));
	int n,w;
	cin>>n>>w;
	for(int i=0;i<n;++i){
		cin>>wt[i]>>val[i];
	}
	int max_value = 1e5;
	for(int i=max_value; i>=0; --i){
		if(knapsack(n-1,i)<=w){
			cout<<i<<endl;
			break;
		}
	}
}