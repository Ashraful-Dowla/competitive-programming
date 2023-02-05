/*
https://codeforces.com/contest/1791/problem/D
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

const int MOD=1e9+7;

void solve(){
	int n;
	cin>>n;

	string s;
	cin>>s;
	s = '_'+s;

	int pf[n+3],sf[n+3];
	memset(pf,0,sizeof(pf));
	memset(sf,0,sizeof(sf));

	bool chk1[30],chk2[30];
	memset(chk1,false,sizeof(chk1));
	memset(chk2,false,sizeof(chk2));

	for(int i=1;i<=n;++i){
		pf[i] = pf[i-1] + (!chk1[s[i]-'a']);
		chk1[s[i]-'a'] = true;
	}

	for(int i=n;i>=1;--i){
		sf[i] = sf[i+1] + (!chk2[s[i]-'a']);
		chk2[s[i]-'a'] = true;
	}

	int mx=0;
	for(int i=1;i<=n;++i){
		mx = max(mx, pf[i]+sf[i+1]);
	}
	cout<<mx<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}