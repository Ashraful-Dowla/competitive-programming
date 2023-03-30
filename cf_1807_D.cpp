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
	int n,q;
	cin>>n>>q;

	vector<ll> pf(n+5,0);
	for(int i=1;i<=n;++i){
		ll x;
		cin>>x;
		pf[i] = pf[i-1]+x;
	}

	while(q--){
		int l,r;
		ll k;
		cin>>l>>r>>k;

		ll total = pf[n] - pf[r] + pf[l-1] + k*(r-l+1);
		if(total%2) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;  
	}
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}