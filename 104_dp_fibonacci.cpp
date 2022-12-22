#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;

// 0 1 1 2 3 5 8 ..

int dp[N];

//top down approach
int fibonacci(int n){
	if(n==0 || n==1) return n;
	// memoise
	if(dp[n]!=-1) return dp[n];
	return dp[n] = fibonacci(n-1) + fibonacci(n-2);
}

int main(){
	memset(dp, -1, sizeof(dp));
	int n;
	cin>>n;
	cout<<fibonacci(n)<<endl;

	dp[0]=0;
	dp[1]=1;
	//bottom up approach
	for(int i=2;i<n;++i){
		dp[i] = dp[i-1] + dp[i-2];
	}
}