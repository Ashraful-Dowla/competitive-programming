/*
https://codeforces.com/contest/1779/problem/C
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
	int n,m;
	cin>>n>>m;

	multiset<ll>ms;
	ll arr[n+2];

	for(int i=1;i<=n;++i){
		cin>>arr[i];
	}

	ll curr=0;
	int ans=0;
	for(int i=m;i>=2;--i){
		curr-=arr[i];
		ms.insert(arr[i]);
		if(curr<0){
			auto it = (--ms.end());
			curr+=2*(*it);
			ms.erase(it);
			ans++;
		}
	}

	curr=0;
	ms.clear();
	for(int i=m+1;i<=n;++i){
		curr+=arr[i];
		ms.insert(-arr[i]);
		if(curr<0){
			auto it = (--ms.end());
			curr+=2*(*it);
			ms.erase(it);
			ans++;
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