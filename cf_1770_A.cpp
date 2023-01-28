/*
https://codeforces.com/contest/1770/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
	int n,m;
	cin>>n>>m;

	vector<ll> vec;
	for(int i=0;i<n;++i){
		ll x;
		cin>>x;
		vec.push_back(x);
	}

	for(int i=0;i<m;++i){
		ll x;
		cin>>x;
		sort(vec.begin(),vec.end());
		vec[0]=x;
	}

	cout<<accumulate(vec.begin(),vec.end(),0LL)<<endl;

}

int main(){
	int t;
	cin>>t;

	while(t--) {
	    solve();
	}
}