/*
https://codeforces.com/gym/101628/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD=1e9+7;
const int N=1e5+10;

string s,w;
ll dp[N][12];

ll generate(int i,int j){
	if(j==w.size()) return 1;
	if(dp[i][j]!=-1) return dp[i][j];

	ll cnt=0;
	for(int k=i;k<s.size();++k){
		if(s[k]==w[j]) {
			cnt+=generate(k+1,j+1);
		}
	}

	return dp[i][j]=cnt%MOD;
}

int main(){
	cin>>s>>w;
	memset(dp,-1,sizeof(dp));
	cout<<generate(0,0)<<endl;
}