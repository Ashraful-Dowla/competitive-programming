/*
https://codeforces.com/problemset/problem/651/A
*/
#include <bits/stdc++.h>
using namespace std;

int dp[105][105];
int generate(int a,int b){
	if(a==0||b==0) return 0;
	if(dp[a][b]!=-1) return dp[a][b];

	int cnt=0;
	if(a>=2) cnt = max(cnt, generate(a-2,b+1)+1);
	if(b>=2) cnt = max(cnt, generate(a+1,b-2)+1);

	return dp[a][b]=cnt;
}

int main(){
	int a,b;
	cin>>a>>b;
	memset(dp,-1,sizeof(dp));
	cout<<generate(a,b)<<endl;
}