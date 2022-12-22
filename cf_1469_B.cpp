/*
https://codeforces.com/problemset/problem/1469/B
*/
#include <bits/stdc++.h>
using namespace std;

int dp[105][105];
int n,m;
vector<int>red,blue;

int generate(int i,int j){
	if(i==n || j==m) return 0;
	if(dp[i][j]!=-1) return dp[i][j];

	int sum=0;
	if(i<n) sum = max(sum,red[i]+generate(i+1,j));
	if(j<m) sum = max(sum,blue[j]+generate(i,j+1));
	if(i<n && j<m) sum = max(sum, red[i]+blue[j]+generate(i+1,j+1));

	return dp[i][j]=sum;
}

int main(){
	int t;
	cin>>t;
	while(t--) {
	    cin>>n;
	    for(int i=0;i<n;++i){
	    	int x;
	    	cin>>x;
	    	red.push_back(x);
	    }
	    cin>>m;
	    for(int i=0;i<m;++i){
	    	int x;
	    	cin>>x;
	    	blue.push_back(x);
	    }

	    memset(dp,-1,sizeof(dp));
	    cout<<generate(0,0)<<endl;
	    red.clear();
	    blue.clear();
	}
}