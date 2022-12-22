/*
https://codeforces.com/contest/1749/problem/B
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
	    ll a[n],b[n];

		ll ans=0;
	    for(int i=0;i<n;++i) {
	    	cin>>a[i];
	    	ans+=a[i];
	    }

	    ll mx=0;
	    for(int i=0;i<n;++i) {
	    	cin>>b[i];
	    	ans+=b[i];
	    	mx = max(mx,b[i]);
	    }

	    cout<<ans-mx<<endl;
	}
}