/*
https://codeforces.com/contest/1767/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
	int n;
	cin>>n;

	ll t1;
	cin>>t1;

	vector<ll>vec;
	for(int i=0;i<n-1;++i){
		ll x;
		cin>>x;
		vec.push_back(x);
	}

	sort(vec.begin(),vec.end());
	ll ans=t1;
	for(int i=0;i<vec.size();++i){
		if(ans<vec[i]){
			ans = (ans+vec[i]+1)/2;
		}
	}
	cout<<ans<<endl;
}

int main(){
	int t;
	cin>>t;

	while(t--) {
	    solve();
	}
}