/*
https://codeforces.com/contest/1771/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;

void solve(){
	int n;
	cin>>n;
	int cnt[N];
	memset(cnt,0,sizeof(cnt));

	int mx=0,mn = INT_MAX;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		mx = max(mx,x);
		mn = min(mn,x);
		cnt[x]++;
	}

	if(mx==mn) cout<<cnt[mn]*1LL*(cnt[mn]-1)<<endl;
	else cout<<cnt[mx]*1LL*cnt[mn]*2<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--) {
	   solve();
	}
}