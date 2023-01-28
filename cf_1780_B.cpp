/*
https://codeforces.com/contest/1780/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
	int n;
	cin>>n;

	ll pf[n+2];
	pf[0]=0;

	for(int i=1;i<=n;++i){
		ll x;
		cin>>x;
		pf[i] = pf[i-1]+x;
	}

	ll s=pf[n];
	ll mx=0;
	for(int i=1;i<n;++i){
		mx = max(mx, __gcd(pf[i],s-pf[i]));
	}
	cout<<mx<<endl;
}

int main(){
	int t;
	cin>>t;

	while(t--){
		solve();
	}
}