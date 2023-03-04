/*
https://codeforces.com/contest/1791/problem/G2
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

#define vec_prnt(v) for(auto x: v) { cout<<x<<" "; } cout<<"\n"

const int N=1e5+10;
const int MOD=1e9+7;

void solve(){
	int n;
	ll c;
	cin>>n>>c;

	vector<pair<ll,ll>> vec;
	for(int i=0;i<n;++i){
		ll x;
		cin>>x;
		vec.push_back({x+min(i+1,n-i), x+i+1});
	}

	sort(vec.begin(),vec.end());
	vector<ll> pf;
	pf.push_back(0);

	for(int i=0;i<n;++i){
		pf.push_back(pf.back()+vec[i].first);
	}

	int ans=0;
	for(int i=0;i<n;++i){
		ll nc = c-vec[i].second;
		int lo=0,hi=n, mx=0;
		while(lo<=hi){
			int mid = (lo+hi)/2;
			int taken = mid+1;
			ll pc = pf[mid];

			if(i<mid){
				taken--;
				pc-=vec[i].first;
			}

			if(pc<=nc){
				lo = mid+1;
				mx = max(mx, taken);
			}
			else hi = mid-1;
		}

		ans = max(ans,mx);
	}

	cout<<ans<<endl;
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