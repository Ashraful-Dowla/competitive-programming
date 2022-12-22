#include <bits/stdc++.h>
using namespace std;

string text1,text2;
int dp[1002][1002];

//time complexity => O(N^2)
int lcs(int i,int j){
	if(i<0||j<0) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	int ans =lcs(i-1,j);
	ans = max(ans, lcs(i,j-1));
	ans = max(ans, lcs(i-1,j-1) + (text1[i]==text2[j]));
	return dp[i][j]=ans;
}

int main(){
	memset(dp,-1,sizeof(dp));
	cin>>text1>>text2;
	cout<<lcs(text1.size()-1,text2.size()-1)<<endl;
}