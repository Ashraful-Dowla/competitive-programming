#include <bits/stdc++.h>
using namespace std;

// 4
// ADAM
// MADAM
// NEVERODDOREVENING
// RACEF1CARFAST

const int N=1e3+10;
string s;
int dp[N][N];

//time complexity -> O(n^2)
int genPalindrome(int l,int r){
	if(l==r) return 1; //odd 
	if(l+1==r) return 1+(s[l]==s[r]); //even

	if(dp[l][r]!=-1) return dp[l][r];

	int cnt=0;
	if(s[l]==s[r]) cnt=genPalindrome(l+1,r-1)+2;
	else {
		cnt = genPalindrome(l+1,r);
		cnt = max(genPalindrome(l,r-1),cnt);
	}

	return dp[l][r]=cnt;
}

int main(){
	int t;
	cin>>t;

	while(t--) {
	    cin>>s;
	    memset(dp,-1,sizeof(dp));
	    cout<<genPalindrome(0,s.size()-1)<<endl;
	}
}