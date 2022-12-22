/*
https://codeforces.com/problemset/problem/1526/B
*/
#include <bits/stdc++.h>
using namespace std;

vector<int>vec={11,111};
int dp[1105][2];

bool sumCheck(int sum,int idx){
	if(sum%11==0) return true;
	if(idx<0) return false;
	if(dp[sum][idx]!=-1) return dp[sum][idx];

	bool isPossible=false;
	for(long s=0;s<=sum;s+=vec[idx]){
		isPossible|=sumCheck(sum-s,idx-1);
	}

	return dp[sum][idx]=isPossible;
}

//chicken mcnugget theorm
//gcd(m,n)=1
// highest non achievable number = m*n-m-n

int main(){
	int t;
	cin>>t;

	memset(dp,-1,sizeof(dp));
	while(t--) {
	    int n;
	    cin>>n;

	    if(n>1099) cout<<"YES"<<endl;
	    else {
	    	 if(sumCheck(n,1)) cout<<"YES"<<endl;
	    	 else cout<<"NO"<<endl;
	    }
	}
}