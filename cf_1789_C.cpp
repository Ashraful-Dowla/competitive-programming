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
	int n,m;
	cin>>n>>m;

	vector<ll> cnt(n+m+10,0);
	ll arr[n];

	for(int i=0;i<n;++i){
		cin>>arr[i];
		cnt[arr[i]]=m+1;
	}

	for(int i=0;i<m;++i){
		int u,v;
		cin>>u>>v;
		cnt[arr[u-1]]-=(m-i);
		cnt[v]+=(m-i);
		arr[u-1]=v;
	}

	ll ans = n*1LL*m*(m+1);

	for(int i=0;i<=n+m;++i){
		ans-=(cnt[i]*(cnt[i]-1))/2;
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