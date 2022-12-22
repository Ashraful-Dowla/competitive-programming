/*
https://codeforces.com/contest/1748/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int t;
	cin>>t;

	while(t--) {
	    int n;
	    cin>>n;
	    ll arr[n+2],sum[n+2];

	    sum[0]=0LL;
	    for(int i=1;i<=n;++i){
	    	cin>>arr[i];
	    	sum[i]=sum[i-1]+arr[i];
	    }

	    ll mx=0,ans=0;
	    map<ll,ll> mp;
	    for(int i=n;i>=1;--i){
	    	mx = max(mx, ++mp[sum[i]]);
	    	if(arr[i]==0){
	    		ans+=mx;
	    		mx=0,mp.clear();
	    	}
	    }

	    ans+=mp[0];

	    cout<<ans<<endl;
	}
}