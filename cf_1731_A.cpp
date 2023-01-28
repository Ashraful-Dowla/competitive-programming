/*
https://codeforces.com/contest/1731/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){	
	int n;
	cin>>n;

	ll product=1;
	for(int i=0;i<n;++i){
		ll x;
		cin>>x;
		product*=x;
	}

	cout<<(product+n-1)*1LL*2022<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--) {
	    solve();
	}
}