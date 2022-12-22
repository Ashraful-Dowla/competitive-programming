#include <bits/stdc++.h>
using namespace std;

const int N=3000;
vector<int>arr(N);
int dp[N];

// time complexity -> O(N^2)
int lis(int idx){
	if(dp[idx]!=-1) return dp[idx];
	int ans=1;
	for(int j=0;j<idx;++j){
		if(arr[idx]>arr[j]){
			ans = max(ans, lis(j)+1);
		}
	}
	return dp[idx]=ans;
}

int main(){
	memset(dp,-1,sizeof(dp));
	int n;
	cin>>n;
	for(int i=0;i<n;++i) cin>>arr[i];

	int ans=0;
	for(int i=0;i<n;++i){
		ans = max(ans, lis(i));
	}
	cout<<ans<<endl;
}