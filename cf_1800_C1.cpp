/*
https://codeforces.com/contest/1800/problem/C1
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

//debug
#define vec_prnt(v) for(auto x: v) { cout<<x<<" "; } cout<<"\n"

const int N=1e5+10;
const int MOD=1e9+7;

void solve(){
	int n;
	cin>>n;

	multiset<ll> ms;
	ll ans=0;
	
	for(int i=0;i<n;++i){
		ll x;
		cin>>x;

		if(x) ms.insert(x);
		else if(x==0 && ms.size()) {
			auto it = (--ms.end());
			ans+=(*it);
			ms.erase(it);
		}
	}

	cout<<ans<<endl;
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}