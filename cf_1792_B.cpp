/*
https://codeforces.com/contest/1792/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int a1,a2,a3,a4;
	cin>>a1>>a2>>a3>>a4;

	if(a1==0) cout<<1<<endl;
	else {
		int m = min(a2,a3);
		int ans = a1+ 2*m;
		ans += min(a1+1, max(a2-m,a3-m)+a4);
		cout<<ans<<endl;
	}
}

int main(){
	int t;
	cin>>t;

	while(t--) {
	    solve();
	}
}