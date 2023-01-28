/*
https://codeforces.com/contest/1731/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// xor[l..r] = pf_xor[r]^pf_xor[l-1]
// Y = pf_xor[i]^pf_xor[j-1]
// pf_xor[j-1] = Y^pf_xor[i]
// Let Y is perfect square

void solve(){
	int n;
	cin>>n;

	int arr[n],mp[2*n];
	memset(arr,0,sizeof(arr));
	memset(mp,0,sizeof(mp));

	for(int i=0;i<n;++i){
		cin>>arr[i];
	}

	ll curr=0;
	mp[curr]++;

	ll ans = (n*1LL*(n+1)/2);
	for(int i=0;i<n;++i){
		curr^=arr[i];

		for(ll j=0;j*j<2*n;++j){
			if((curr^(j*j))<2*n){
				ans-=mp[curr^(j*j)];
			}
		}
		mp[curr]++;
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